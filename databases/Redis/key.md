# ==**KEY**==

> **基本语法**

```sql
redis 127.0.0.1:6379> COMMAND KEY_NAME
```

> **eg**
>
> ```sql
> redis 127.0.0.1:6379> SET runoobkey redis
> OK
> redis 127.0.0.1:6379> DEL runoobkey
> (integer) 1
> ```

## **基本命令**

+ del key

  > 存在时删除,返回被删除 key 的数量

+ dump key

  > 序列化给定 key ，并返回被序列化的值，如果 key 不存在，那么返回 nil 。
  >
  > 首先，我们在 redis 中创建一个 key 并设置值。
  >
  > ```
  > redis> SET greeting "hello, dumping world!"
  > OK
  > ```
  >
  > 现在使用 DUMP 序列化键值。
  >
  > ```sql
  > redis> DUMP greeting
  > "\x00\x15hello, dumping world!\x06\x00E\xa0Z\x82\xd8r\xc1\xde"
  > 
  > redis> DUMP not-exists-key
  > (nil)
  > ```
  >
  > > 序列化：把对象转化为可传输的字节序列过程称为序列化。
  > >
  > > 反序列化：把字节序列还原为对象的过程称为反序列化。
  > >
  > > 为什么需要序列化
  > >
  > > - 序列化最终的目的是为了对象可以跨平台存储，和进行网络传输。而我们进行跨平台存储和网络传输的方式就是IO，而我们的IO支持的数据格式就是字节数组。
  > > - 因为我们单方面的只把对象转成字节数组还不行，因为没有规则的字节数组我们是没办法把对象的本来面目还原回来的，所以我们必须在把对象转成字节数组的时候就制定一种规则（序列化），那么我们从IO流里面读出数据的时候再以这种规则把对象还原回来（反序列化）。
  > >
  > > - 如果我们要把一栋房子从一个地方运输到另一个地方去，序列化就是我把房子拆成一个个的砖块放到车子里，然后留下一张房子原来结构的图纸，反序列化就是我们把房子运输到了目的地以后，根据图纸把一块块砖头还原成房子原来面目的过程
  > >
  > > 什么时候使用序列化
  > >
  > > - **凡是需要进行“跨平台存储”和”网络传输”的数据，都需要进行序列化**。
  > > - 本质上存储和网络传输都需要经过把一个对象状态保存成一种跨平台识别的字节格式，然后其他的平台才可以通过字节信息解析还原对象信息。

+ exists key

  > 若 key 存在返回 1 ，否则返回 0
  >
  > ```
  > redis 127.0.0.1:6379> EXISTS runoob-new-key
  > (integer) 0
  > ```
  >
  > 现在我们创建一个名为 runoob-new-key 的键并赋值，再使用 EXISTS 命令。
  >
  > ```sql
  > redis 127.0.0.1:6379> set runoob-new-key newkey
  > OK
  > redis 127.0.0.1:6379> EXISTS runoob-new-key
  > (integer) 1
  > redis 127.0.0.1:6379>
  > ```

+ expire key seconds

  > + 设置 key 的过期时间，key 过期后将不再可用
  >
  > + 单位以秒计
  >
  > ```
  > redis 127.0.0.1:6379> SET runooobkey redis
  > OK
  > ```
  >
  > 为 key 设置过期时间：
  >
  > ```sql
  > redis 127.0.0.1:6379> EXPIRE runooobkey 60
  > (integer) 1
  > ```
  >
  > 以上实例中我们为键 runooobkey 设置了过期时间为 1 分钟，1分钟后该键会自动删除。

+ expireat key timestamp

  > + EXPIREAT 的作用和 EXPIRE 类似，都用于为 key 设置过期时间
  > + 不同在于 EXPIREAT 命令接受的时间参数是 UNIX 时间戳(unix timestamp)
  > + 设置成功返回 1 
  > + 当 key 不存在或者不能为 key 设置过期时间时(比如在低于 2.1.3 版本的 Redis 中你尝试更新 key 的过期时间)返回 0 
  >
  > ```sql
  > redis 127.0.0.1:6379> Expireat KEY_NAME TIME_IN_UNIX_TIMESTAMP
  > ```

+ pexpire key milliseconds

  > + 设置 key 过期时间的时间戳(unix timestamp) 以毫秒计

+ pexpireat key milliseconds-timestamp

  > + 设置 key 过期时间的时间戳(unix timestamp) 以毫秒计

+ keys pattern

  > + 查找所有符合给定模式 pattern 的 key 
  >
  > + 符合给定模式的 key 列表 (Array)
  >
  >   首先创建一些 key，并赋上对应值：
  >
  >   ```sql
  >   redis 127.0.0.1:6379> set runoob1 redis
  >   OK
  >   redis 127.0.0.1:6379> SET runoob2 mysql
  >   OK
  >   redis 127.0.0.1:6379> SET runoob3 mongodb
  >   OK
  >   ```
  >
  >   查找以 runoob 为开头的 key：
  >
  >   ```sql
  >   redis 127.0.0.1:6379> KEYS runoob*
  >   1) "runoob3"
  >   2) "runoob1"
  >   3) "runoob2"
  >   ```
  >
  >   获取 redis 中所有的 key 可用使用 *****。
  >
  >   ```sql
  >   redis 127.0.0.1:6379> KEYS *
  >   1) "runoob3"
  >   2) "runoob1"
  >   3) "runoob2"
  >   ```

+ move key db

  > + 将当前数据库的 key 移动到给定的数据库 db 当中
  >
  > + 移动成功返回 1 ，失败则返回 0 
  >
  >   ```sql
  >   # key 存在于当前数据库
  >                 
  >   redis> SELECT 0                             # redis默认使用数据库 0，为了清晰起见，这里再显式指定一次。
  >   OK
  >                 
  >   redis> SET song "secret base - Zone"
  >   OK
  >                 
  >   redis> MOVE song 1                          # 将 song 移动到数据库 1
  >   (integer) 1
  >                 
  >   redis> EXISTS song                          # song 已经被移走
  >   (integer) 0
  >                 
  >   redis> SELECT 1                             # 使用数据库 1
  >   OK
  >                 
  >   redis:1> EXISTS song                        # 证实 song 被移到了数据库 1 (注意命令提示符变成了"redis:1"，表明正在使用数据库 1)
  >   (integer) 1
  >                 
  >   # 当 key 不存在的时候
  >                 
  >   redis:1> EXISTS fake_key
  >   (integer) 0
  >                 
  >   redis:1> MOVE fake_key 0                    # 试图从数据库 1 移动一个不存在的 key 到数据库 0，失败
  >   (integer) 0
  >                 
  >   redis:1> select 0                           # 使用数据库0
  >   OK
  >                 
  >   redis> EXISTS fake_key                      # 证实 fake_key 不存在
  >   (integer) 0
  >    # 当源数据库和目标数据库有相同的 key 时,不能复制到其中
  >              
  >   redis> SELECT 0                             # 使用数据库0
  >   OK
  >   redis> SET favorite_fruit "banana"
  >   OK
  >              
  >   redis> SELECT 1                             # 使用数据库1
  >   OK
  >   redis:1> SET favorite_fruit "apple"
  >   OK
  >              
  >   redis:1> SELECT 0                           # 使用数据库0，并试图将 favorite_fruit 移动到数据库 1
  >   OK
  >              
  >   redis> MOVE favorite_fruit 1                # 因为两个数据库有相同的 key，MOVE 失败
  >   (integer) 0
  >              
  >   redis> GET favorite_fruit                   # 数据库 0 的 favorite_fruit 没变
  >   "banana"
  >              
  >   redis> SELECT 1
  >   OK
  >              
  >   redis:1> GET favorite_fruit                 # 数据库 1 的 favorite_fruit 也是
  >   "apple"
  >              
  >   ```

+ persist key

  > + 移除给定 key 的过期时间，使得 key 永不过期

+ pttl key

  > + 以毫秒为单位返回 key 的剩余过期时间
  > + 当 key 不存在时，返回 -2 
  > +  当 key 存在但**没有设置**剩余生存时间时，返回 -1 

+ ttl key

  > + 当 key 不存在时，返回 -2 
  > + 当 key 存在但没有设置剩余生存时间时，返回 -1 
  > + 否则，以秒为单位，返回 key 的剩余生存时间

+ randomkey 

  > + 当数据库不为空时，返回一个 key
  >
  > +  当数据库为空时，返回 nil （windows 系统返回 null）
  >
  >   ```sql
  >   # 数据库不为空
  >               
  >   redis> MSET fruit "apple" drink "beer" food "cookies"   # 设置多个 key
  >   OK
  >               
  >   redis> RANDOMKEY
  >   "fruit"
  >               
  >   redis> RANDOMKEY
  >   "food"
  >               
  >   redis> KEYS *    # 查看数据库内所有key，证明 RANDOMKEY 并不删除 key
  >   1) "food"
  >   2) "drink"
  >   3) "fruit"
  >               
  >   # 数据库为空
  >            
  >   redis> FLUSHDB  # 删除当前数据库所有 key
  >   OK
  >            
  >   redis> RANDOMKEY
  >   (nil)
  >            
  >   ```

+ flushdb  

  > + 删除当前数据库所有 key

+ rename key newkey

  > + 改名成功时提示 OK ，失败时候返回一个错误。
  >
  > + 当 OLD_KEY_NAME 和 NEW_KEY_NAME 相同，或者 OLD_KEY_NAME 不存在时，返回一个错误
  >
  > + 当 NEW_KEY_NAME 已经存在时， RENAME 命令将覆盖NEW_KEY_NAME的旧值
  >
  >   ```sql
  >   redis> SET pc "lenovo"
  >   OK
  >                     
  >   redis> SET personal_computer "dell"
  >   OK
  >                     
  >   redis> RENAME pc personal_computer
  >   OK
  >                     
  >   redis> GET pc
  >   (nil)
  >                     
  >   redis:1> GET personal_computer      # 原来的值 dell 被覆盖了
  >   "lenovo"
  >   ```

+ renamenx key newkey

  > + 在新的 key 不存在时修改 key 的名称
  > + 修改成功时，返回 1 
  > + 如果 NEW_KEY_NAME 已经存在，返回 0

- scan cursor [MATCH pattern] [COUNT count]

  > + 用于迭代数据库中的数据库键
  >
  >   - cursor - 游标。
  >   - pattern - 匹配的模式。
  >   - count - 指定从数据集里返回多少元素，默认值为 10 
  >
  > + SCAN 命令是一个基于游标的迭代器，每次被调用之后， 都会向用户返回一个新的游标， 用户在下次迭代时需要使用这个新游标作为 SCAN 命令的游标参数， 以此来延续之前的迭代过程
  >
  > + SCAN 返回一个包含两个元素的数组， 第一个元素是用于进行下一次迭代的新游标， 而第二个元素则是一个数组， 这个数组中包含了所有被迭代的元素。如果新游标返回 0 表示迭代已结束。
  >
  > + 相关命令：
  >
  >   - [SSCAN](https://www.runoob.com/redis/sets-sscan.html) 命令用于迭代集合键中的元素，返回的每个元素都是一个集合成员。
  >
  >   - [HSCAN](https://www.runoob.com/redis/hashes-hscan.html) 命令用于迭代哈希键中的键值对，返回的每个元素都是一个键值对，一个键值对由一个键和一个值组成。
  >
  >   - [ZSCAN](https://www.runoob.com/redis/sorted-sets-zscan.html) 命令用于迭代有序集合中的元素（包括元素成员和元素分值）。
  >
  >  + **eg**
  >
  >    使用 SCAN 命令迭代：
  >
  >    ```sql
  >    redis 127.0.0.1:6379> scan 0   # 使用 0 作为游标，开始新的迭代
  >    1) "17"                        # 第一次迭代时返回的游标
  >    2)  1) "key:12"
  >        2) "key:8"
  >        3) "key:4"
  >        4) "key:14"
  >        5) "key:16"
  >        6) "key:17"
  >        7) "key:15"
  >        8) "key:10"
  >        9) "key:3"
  >       10) "key:7"
  >       11) "key:1"
  >    redis 127.0.0.1:6379> scan 17  # 使用的是第一次迭代时返回的游标 17 开始新的迭代
  >    1) "0"
  >    2) 1) "key:5"
  >       2) "key:18"
  >       3) "key:0"
  >       4) "key:2"
  >       5) "key:19"
  >       6) "key:13"
  >       7) "key:6"
  >       8) "key:9"
  >       9) "key:11"
  >    ```
  >    > 在上面这个例子中，第一次迭代使用 0 作为游标，表示开始一次新的迭代。第二次迭代使用的是第一次迭代时返回的游标 17 ，作为新的迭代参数。
  >    >
  >    > 显而易见，**SCAN命令的返回值**是一个包含两个元素的数组，第一个数组元素是用于进行下一次迭代的新游标，而第二个数组元素则是一个数组，这个数组中包含了所有被迭代的元素。
  >    >
  >    > 在第二次调用 SCAN 命令时，命令返回了游标 0 ，这表示迭代已经结束，整个数据集已经被完整遍历过了。
  >    >
  >    > **full iteration**：以 0 作为游标开始一次新的迭代，一直调用 SCAN 命令，直到命令返回游标 0 ，我们称这个过程为一次完整遍历。

+ type key

  > + 返回 key 的数据类型，数据类型有：
  >   - none (key不存在)
  >   - string (字符串)
  >   - list (列表)
  >   - set (集合)
  >   - zset (有序集)
  >   - hash (哈希表)

#### **更多命令请参考**：https://redis.io/commands
