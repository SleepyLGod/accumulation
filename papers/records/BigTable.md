# **BigTable: A Distributed Storage System for Structured Data**

> 主要是对于论文的理解

> 作为 Google 的大数据三架马车之一，Bigtable 依托于 Google 的 GFS、Chubby 及 SSTable 而诞生
>
> 用于解决 Google 内部**不同产品在对数据存储的容量和响应时延需求的差异化**
>
> 力求在确保**能够容纳大量数据的同时减少数据的查询耗时**
>
> Apache HBase 的设计很大程度上受到了 Bigtable 的影响

## **Data Model**

数据在若干 `Table `中， `Table `中的每个`Cell`（数据单元）的形式：

`(row:string, column:string, time:int64) → string`  行、列、时间戳三个维度，属于由字节串构成（string），最大64KB

假设我们想要保留一份可供许多不同项目使用的大量网页和相关信息的副本；让我们将这个特定的表称为 `Webtable`。在 `Webtable `中，我们将使用 URL 作为行键，将网页的各个方面作为列名，并将网页的内容存储在获取时的时间戳下的 `contents`: 列中，

<img src="https://s2.loli.net/2022/07/11/7HjDeXiBbKwv1cL.png" alt="image-20220711123729151"  />

存储网页的示例表的一部分。行名称是反向 URL。内容列族包含页面内容，锚列族包含引用页面的任何锚的文本。 CNN 的主页被 `Sports Illustrated `和` MY-look `主页引用，因此该行包含名为 `anchor:cnnsi.com` 和 `anchor:my.look.ca` 的列。每个锚单元都有一个版本；内容列有三个版本，时间戳为 `t3`、`t5 `和 `t6`。

**ROW**

单个行键下的每次读取或写入数据都是原子的，无论在该行中读取或写入的不同列的数量 

**---->** 使客户端更容易推理系统在并发存在时的行为更新到同一行

`BigTable`存数据的时候会按照`Cell`的`Row Key`（行键）对`Table`进行字典排序

行级事务支持，不支持跨行（类似`MongoDB`）

把一个`Table`按 Row 切分成若干个相邻的 Tablet，并将 Tablet 分配到不同的 Tablet Server 上存储  

**----->** 客户端查询较为接近的 Row Key 时 Cell 落在同一个 Tablet 上的概念也会更大，查询的效率也会更高。

**COLUMN**

Bigtable 会按照由若干个 Column 组成的 Column Family（列族）对 Table 的访问权限控制。

存储在列族中的所有数据通常属于同一类型（我们将同一列族中的数据压缩在一起）。

必须先创建列族，然后才能将数据存储在该族中的任何列键下；创建族后，可以使用族中的任何列键。

表中不同列族的数量很少（最多数百个），并且族在操作过程中很少改变。相反，一个表可能有无限数量的列。

Column Key 由 `family:qualifier` 的形式组成

用户在使用前必须首先声明 Table 中有哪些 Column Family，声明后即可在该 Column Family 中创建任意 Column。

由于同一个 Column Family 中存储的数据通常属于同一类型，Bigtable 还会对属于同一 Column Family 的数据进行合并压缩。

由于 Bigtable 允许用户以 Column Family 为单位为其他用户设定数据访问权限，数据统计作业有时也会从一个 Column Family 中读出数据后，将统计结果写入到另一个 Column Family 中

**TIMESTAMPS**

Table 中的不同 Cell 可以保存同一份数据的多个版本，以时间戳进行区分。

时间戳本质上为 64 位整数，可由 Bigtable 自动设定为数据写入的当前时间（微秒），也可由应用自行设定，但应用需要自行确保 Cell 间不会出现冲突。

对于拥有相同 Row Key 和 Column Key 的 Cell，Bigtable 会按照时间戳降序进行排序，如此一来最新的数据便会被首先读取。

在此基础上，用户还可以设定让 Bigtable 只保存最近若干个版本的数据或是时间戳在指定时间范围内的数据。

## **系统原理**

完整的 Bigtable 集群由两类节点组成：Master 和 Tablet Server。

**Master**:

+ 检测集群中的 Tablet Server 组成以及它们的加入和退出事件
+ 将 Tablet 分配至 Tablet Server
+ 均衡 Tablet Server 间的存储负载
+ 从 GFS 上回收无用的文件
+ 管理如 Table、Column Family 的创建和删除等 Schema 修改操作

**Tablet Server**

+ 管理若干个由 Master 指定的 Tablet
+ 处理针对这些 Tablet 的读写请求
+ 在 Tablet 变得过大时对其进行切分

若干个 Table，每个 Table 由若干个 Tablet 组成，每个 Tablet 都会关联一个指定的 **Row Key 范围**，那么这个 Tablet 就包含了该 Table 在该范围内的所有数据。

初始时，Table 会只有一个 Tablet，随着 Tablet 增大被 Tablet Server 自动切分，Table 就会包含越来越多的 Tablet。

### **Tablet 定位**

Bigtable 的 Tablet 之间会形成一个三层结构，类似B+树，具体如下：

- 在 Chubby 中的一个 File 保存着 Root Tablet 的位置
- Root Tablet 保存着 `METADATA` Table 所有 Tablet 的位置
- `METADATA` Table 中保存着其他所有 Table 的 Tablet 的位置

[<img src="https://mr-dai.github.io/img/bigtable/tablet-hierarchy.jpg" alt="img" style="zoom: 67%;" />](https://mr-dai.github.io/img/bigtable/tablet-hierarchy.jpg)

值得注意的是，Root Tablet 是特殊的：**无论它的体积如何增长都不会被切分，保证唯一**。

`METADATA` 中的每一行都代表 Bigtable 中其他 Table 的一个 Tablet，其 **Row Key 由该 Tablet 的 Table 名及 Row Key 上限编码**而成。除了 Tablet 的位置信息外，`METADATA` 表也会保存一些其他有用的**元信息**，例如 Tablet 的事件日志等。

客户端想要定位某个 Tablet 时，便会递归地按照上述层次**向下**求得位置，并把中间获得的结果**缓存在自己的内存**中。

如果某一时刻客户端发现缓存在内存中的地址已不再有效，它便会再次递归地沿着上述层次向上，最终再次向下求得所需 Tablet 的位置。

### **集群成员变化与 Tablet 分配**

`Master `利用了 Chubby 来探测 Tablet Server 加入和离开集群的事件。

每个 Tablet Server 在 Chubby 上都会有一个对应的唯一文件，Tablet Server 在启动时便会拿到该文件在 Chubby 上的互斥锁，Master 则通过监听这些文件的父目录来检测 Tablet Server 的加入。如果 Tablet Server 失去了互斥锁，那么 Master 就会认为 Tablet Server 已退出集群。尽管如此，只要该文件仍然存在，Tablet Server 就会不断地尝试再次获取它的互斥锁；如果该文件已被删除（见下文），那么 Tablet Server 就会自行关闭。

在了解了集群中有哪些 Tablet Server 后，Master 便需要将 Tablet 分配给 Tablet Server。同一时间，一个 Tablet 只能被分配给一个 Tablet Server。Master 会通过向 Tablet Server 发送 Tablet 载入请求来分配 Tablet。除非该载入请求在 Master 失效前仍未被 Tablet Server 接收到，那么就可以认为此次 Tablet 分配操作已成功：Tablet Server 只会接受来自当前 Master 的节点的请求。当 Tablet Server 决定不再负责某个 Tablet 时，它也会发送请求通知 Master。

Master 在检测到 Tablet Server 失效（互斥锁丢失）后，便会将其负责的 Tablet 重新分配。为此，Master 会尝试在 Chubby 上获取该 Tablet Server 对应的文件的互斥锁，并在成功获取后删除该文件，确保 Tablet Server 能够正确下线。之后，Master 便可顺利将 Tablet 分配至其他 Tablet Server。

如果 Master 与 Chubby 之间的通信连接断开，那么 Master 便会认为自己已经失效并自动关闭。Master 失效后，新 Master 恢复的过程如下：

1. 在 Chubby 上获取 Master 独有的锁，确保不会有另一个 Master 同时启动
2. 利用 Chubby 获取仍有效的 Tablet Server
3. 从各个 Tablet Server 处获取其所负责的 Tablet 列表，并向其表明自己作为新 Master 的身份，确保 Tablet Server 的后续通信能发往这个新 Master
4. Master 确保 Root Tablet 及 `METADATA` 表的 Tablet 已完成分配
5. Master 扫描 `METADATA` 表获取集群中的所有 Tablet，并对未分配的 Tablet 重新进行分配

### **Tablet 读写与维护**

如上所述，Tablet 的数据实际上存储在 GFS 中，由 GFS 提供数据的冗余备份。Tablet 数据读操作与写操作的示意图如下：

[![img](https://mr-dai.github.io/img/bigtable/tablet.jpg)](https://mr-dai.github.io/img/bigtable/tablet.jpg)

可见，一个 Tablet 由若干个位于 GFS 上的 SSTable 文件、一个位于内存内的 MemTable 以及一份 Commit Log 组成。

在进行写操作时，Bigtable 首先会用先写日志（Write-Ahead Log）的方式，把此次变更记录到 Commit Log 中。而后，插入的数据会被放入到位于内存内的一个 MemTable 中，其中 MemTable 保持其内部的数据有序。而对于那些已经持久化的数据则会作为一个个 SSTable 文件保存在 GFS 中。

在进行读操作时，Tablet Server 也会进行相应的权限检查，而后会首先尝试从 MemTable 中获取所需的最新数据，如果无法查得再从 SSTable 中进行查找。

除外，Tablet Server 在收到操作请求时也会检查请求的用户是否有足够的权限，而允许执行的用户列表则存储在 Chubby 的一个文件中。

Tablet Server 在载入 Tablet 时，首先需要从 `METADATA` 表中获取 Tablet 对应的 SSTable 文件及 Commit Log 的日志，并利用 Commit Log 中的条目恢复出 Tablet 的 MemTable。

Memtable 与 SSTable 本身都采取了数据不可变的设计思路：更改操作产生的新条目以 Copy On Write 的方式放入到 MemTable 中；待 MemTable 内的条目数达到一定阈值后，Bigtable 便会将新到来的请求写入到另一个 MemTable，同时开始将旧的 MemTable 写入到新的 SSTable 文件中，该操作被称为 Bigtable 的 Minor Compaction。对于已在原有 SSTable 文件中的旧数据，Bigtable 也不会将其移除。

每一次 Minor Compaction 都会产生一个新的 SSTable 文件，而过多的 SSTable 文件会导致后续的读操作需要扫描更多的 SSTable 文件以获得最新的正确数据。为了限制 SSTable 文件数，Bigtable 会周期地进行 Merging Compaction，将若干个 SSTable 和 MemTable 中的数据原样地合并成一个 SSTable。

Bigtable 还会周期地执行一种被称为 Major Compaction 的特殊 Merging Compaction 操作：在这个过程中，Bigtable 除了会将若干个 SSTable 合并为一个 SSTable，同时将 SSTable 中那些应后续变更或删除操作而被标记为无效的条目移除。

### **额外优化**

上一章中我们聊了 Bigtable 写入数据和读取数据的基本过程，但仅有此还不足以让 Bigtable 支撑上游产品的实际使用需求。本章我们就来讲讲 Google 为了让 Bigtable 拥有实际可用的性能及可用性所做出的主要优化。

#### Locality Group

Bigtable 允许客户端为 Column Family 指定一个 Locality Group，并以 Locality Group 为基础指定其实际的文件存储格式以及压缩方式。

首先，在进行上面我们提到的 Compaction 操作时，Bigtable 会为 Tablet 中的每个 Locality Group 生成独立的 SSTable 文件。由此，用户便可将那些很少同时访问的 Column Famliy 放入到不同的 Locality Group 中，以提高查询效率。除外 Bigtable 也提供了其他基于 Locality Group 的调优参数设置，如设置某个 Locality Group 为 in-memory 等。

在压缩方面，Bigtable 允许用户指定某个 Locality Group 是否要对数据进行压缩以及使用何种格式进行压缩。值得注意的是，Bigtable 对 SSTable 的压缩是基于 SSTable 文件的 Block 进行的，而不是对整个文件直接进行压缩。尽管这会让压缩的效率下降，但这也使得用户在读取数据时 Bigtable 只需要对 SSTable 的某些 Block 进行解压。

#### 读缓存与 Bloom Filter

了解过 LSM Tree 的读者可能已经意识到，Bigtable 使用的存储方式正是 LSM Tree：这种存储方式可以将对磁盘的随机写转换为顺序写，代价则是读取性能的下降。LSM Tree 被应用在 Bigtable 上是合情合理的，毕竟 Bigtable 的文件实际上存储在 GFS 中，而 GFS 主要针对顺序写进行优化，对随机写的支持可以说是极差。那么 Bigtable 在使用 LSM Tree 确保了写入性能后，当然就要通过其他的方式来确保自己的读性能了。首先便是读缓存。

总的来说，Bigtable 的读缓存由两个缓存层组成：Scan Cache 和 Block Cache。Block Cache 会缓存从 GFS 中读出的 SSTable 文件 Block，提高客户端读取某个数据附近的其他数据的效率；Scan Cache 则在 Block Cache 之上，缓存由 SSTable 返回给 Tablet Server 的键值对，以提高客户端重复读取相同数据的效率。

除外，为了提高检索的效率，Bigtable 也允许用户为某个 Locality Group 开启 Bloom Filter 机制，通过消耗一定量的内存保存为 SSTable 文件构建的 Bloom Filter，以在客户端检索记录时利用 Bloom Filter 快速地排除某些不包含该记录的 SSTable，减少需要读取的 SSTable 文件数。

#### Commit Log

Bigtable 使用了 Write-Ahead Log 的做法来确保数据高可用，那么便涉及了大量对 Commit Log 的写入，因此这也是个值得优化的地方。

首先，如果 Bigtable 为不同的 Tablet 使用不同的 Commit Log，那么系统就会有大量的 Commit Log 文件同时写入，提高了底层磁盘寻址的时间消耗。为此，Tablet Server 会把其接收到的所有 Tablet 写入操作写入到同一个 Commit Log 文件中。

这样的设计带来了另一个问题：如果该 Tablet Server 下线，其所负责的 Tablet 可能会被重新分配到其他若干个 Tablet Server 上，它们在恢复 Tablet MemTable 的过程中会重复读取上一个 Tablet Server 产生的 Commit Log。为了解决该问题，Tablet Server 在读取 Commit Log 前会向 Master 发送信号，Master 就会发起一次对原 Commit Log 的排序操作：原 Commit Log 会按 64 MB 切分为若干部分，每个部分并发地按照 `(table, row name, log sequence number)` 进行排序。完成排序后，Tablet Server 读取 Commit Log 时便可只读取自己需要的那一部分，减少重复读取。



