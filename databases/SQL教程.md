# **==SQL==教程 (Structured Query Language)**

## **主流关系数据库**

+ 目前，主流的关系数据库主要分为以下几类：

	+ 1. 商用数据库，例如：[Oracle](https://www.oracle.com/)，[SQL Server](https://www.microsoft.com/sql-server/)，[DB2](https://www.ibm.com/db2/)等；
	+ 2. 开源数据库，例如：[MySQL](https://www.mysql.com/)，[PostgreSQL](https://www.postgresql.org/)等；
	+ 3. 桌面数据库，以微软[Access](https://products.office.com/access)为代表，适合桌面应用程序使用；
	+ 4. 嵌入式数据库，以[Sqlite](https://sqlite.org/)为代表，适合手机应用和桌面程序。
	
	     

## **数据类型**

+ ```int ```

  >  4字节整数类型，范围约+/-21亿

+ ```bigint```

  > 8字节整数类型，范围约+/-922亿亿

+ ```real```  or  ```float(24)```

  > 4字节浮点数，范围约+/-10^38

+ ```double```

  > 8字节浮点数，范围约+/-10^308

+ ```decimal(m,n)```

  > 由用户指定精度的小数，例如，DECIMAL(20,10)表示一共20位，其中小数10位，通常用于财务计算

+ ```char(n)```

  > 存储指定长度的字符串，例如，CHAR(100)总是存储100个字符的字符串

+ ```varchar(n)```

  > 存储可变长度的字符串，例如，VARCHAR(100)可以存储0~100个字符的字符串

+ ```booleans```

  > 存储True或者False

+ ```DATE```

  > 存储日期，例如，2018-06-22

+ ```time```

  > 存储时间，例如，12:20:59

+ ```datetime```

  > 存储日期+时间，例如，2018-06-22 12:20:59

+ ```tinyint```

  > 0~255的整数

==通常来说，`BIGINT`能满足整数存储的需求，`VARCHAR(N)`能满足字符串存储的需求，这两种类型是使用最广泛的。==



## **语法特点**

	SQL 语言关键字不区分大小写
	但是，针对不同的数据库，对于表名和列名，有的数据库区分大小写，有的数据库不区分大小写。
	同一个数据库，有的在Linux上区分大小写，有的在Windows上不区分大小写。

所以，本教程约定：==SQL关键字总是大写，以示突出，表名和列名均使用小写==。



## **关系模型**

> + 关系模型本质上就是若干个存储数据的二维表，可以把它们看作很多Excel表
>
> + 表的每一行称为记录（Record），记录是一个逻辑意义上的数据
>
> + 表的每一列称为字段（Column），同一个表的每一行记录都拥有相同的若干字段
>
>   + 字段定义了数据类型（整型、浮点型、字符串、日期等），以及是否允许为`NULL`。注意`NULL`表示字段数据不存在。一个整型字段如果为`NULL`不表示它的值为`0`，同样的，一个字符串型字段为`NULL`也不表示它的值为空串`''`。
> +     在关系数据库中，关系是通过**主键**和**外键**来维护的。

### **主键**

> 对于关系表，有个很重要的约束，就是任意两条记录不能重复。不能重复不是指两条记录不完全相同，而是指能够通过某个字段唯一区分出不同的记录，这个字段被称为**主键**
>
> + 选取主键的一个基本原则是：不使用任何业务相关的字段作为主键
> + 因此，身份证号、手机号、邮箱地址这些看上去可以唯一的字段，均**不可**用作主键
> + 作为主键最好是完全业务无关的字段，我们一般把这个字段命名为`id`。常见的可作为`id`字段的类型有：
>   + 自增整数类型：数据库会在插入数据时自动为每一条记录分配一个自增整数，这样我们就完全不用担心主键重复，也不用自己预先生成主键；==最好使用```BIGINIT NOT NULL AUTO_INCREMENT```==
>   +  全局唯一GUID类型：使用一种全局唯一的字符串作为主键，类似`8f55d96b-8acc-4636-8cb8-76bf8abc2f57`。GUID算法通过网卡MAC地址、时间戳和随机数保证任意计算机在任意时间生成的字符串都是不同的，大部分编程语言都内置了GUID算法，可以自己预算出主键。

> ==联合主键==
>
> 关系数据库实际上还允许通过多个字段唯一标识记录，即两个或更多的字段都设置为主键，这种主键被称为联合主键。
>
> + 对于联合主键，允许一列有重复，只要不是所有主键列都重复即可

### **外键**

> 为了表达**一对多**的关系，在B表中加入一列 id_ ，其值与A表的某条记录相对应，由此直接根据id_这个列定位出B表的记录对应到A表的哪一条记录，这一列就是外键。
>
> + 外键通过定义外键约束实现
>
>   > 由于外键约束会降低数据库的性能，大部分互联网应用程序为了追求速度，并不设置外键约束，而是仅靠应用程序自身来保证逻辑的正确性。这种情况下，`class_id`仅仅是一个普通的列，只是它起到了外键的作用而已。
>
> ```sql
> ALTER TABLE students
> ADD CONSTRAINT fk_class_id
> FOREIGN KEY (class_id)
> REFERENCES classes (id);
> ```
>
> 其中，外键约束的名称```fk_class_id```可以任意，```FOREIGN KEY (class_id)```指定了```class_id```作为外键，```REFERENCES classes (id)```指定了这个外键将关联到```classes```表的```id```列（即classes表的主键）。
>
> 通过定义外键约束，关系数据库可以保证无法插入无效的数据。即如果`classes`表不存在`id=99`的记录，`students`表就无法插入`class_id=99`的记录。
>
> 要删除一个外键约束，也是通过`ALTER TABLE`实现的：
>
> ```sql
> ALTER TABLE students
> DROP FOREIGN KEY fk_class_id;
> ```
>
> 注意：删除外键约束并没有删除外键这一列。删除列是通过`DROP COLUMN ...`实现的
>
> + ==多对多==
>
> > 通过一个表的外键关联到另一个表，我们可以定义出一对多关系。有些时候，还需要定义“多对多”关系。例如，一个老师可以对应多个班级，一个班级也可以对应多个老师，因此，班级表和老师表存在多对多关系。
>
> 多对多关系实际上是通过两个一对多关系实现的，即通过一个中间表，关联两个一对多关系，就形成了多对多关系。
>
> `teachers`表：
>
> | id   | name   |
> | :--- | :----- |
> | 1    | 张老师 |
> | 2    | 王老师 |
> | 3    | 李老师 |
> | 4    | 赵老师 |
>
> `classes`表：
>
> | id   | name |
> | :--- | :--- |
> | 1    | 一班 |
> | 2    | 二班 |
>
> 中间表`teacher_class`关联两个一对多关系：
>
> | id   | teacher_id | class_id |
> | :--- | :--------- | :------- |
> | 1    | 1          | 1        |
> | 2    | 1          | 2        |
> | 3    | 2          | 1        |
> | 4    | 2          | 2        |
> | 5    | 3          | 1        |
> | 6    | 4          | 2        |
>
> 通过中间表`teacher_class`可知`teachers`到`classes`的关系：
>
> - `id=1`的张老师对应`id=1,2`的一班和二班；
> - `id=2`的王老师对应`id=1,2`的一班和二班；
> - `id=3`的李老师对应`id=1`的一班；
> - `id=4`的赵老师对应`id=2`的二班。
>
> 同理可知`classes`到`teachers`的关系：
>
> - `id=1`的一班对应`id=1,2,3`的张老师、王老师和李老师；
> - `id=2`的二班对应`id=1,2,4`的张老师、王老师和赵老师；
>
> 因此，通过中间表，我们就定义了一个“多对多”关系。
>
> + ==一对一==
>
>   > 如果业务允许，完全可以把两个表合为一个表
>   >
>   > 但是有的时候A表的x在B表中找不到y与x对应
>
> 还有一些应用会把一个大表拆成两个一对一的表，目的是把经常读取和不经常读取的字段分开，以获得更高的性能。例如，把一个大的用户表分拆为用户基本信息表user_info和用户详细信息表user_profiles，大部分时候，只需要查询user_info表，并不需要查询user_profiles表，这样就提高了查询速度。

### **索引**

> 索引是关系数据库中对某一列或多个列的值进行预排序的数据结构。通过使用索引，可以让数据库系统不必扫描整个表，而是直接定位到符合条件的记录，这样就大大加快了查询速度。
>
> 例如，对于`students`表：
>
> | id   | class_id | name | gender | score |
> | :--- | :------- | :--- | :----- | :---- |
> | 1    | 1        | 小明 | M      | 90    |
> | 2    | 1        | 小红 | F      | 95    |
> | 3    | 1        | 小军 | M      | 88    |
>
> 如果要经常根据`score`列进行查询，就可以对`score`列创建索引：
>
> ```sql
> ALTER TABLE students
> ADD INDEX idx_score (score);
> ```
>
> 使用`ADD INDEX idx_score (score)`就创建了一个名称为`idx_score`，使用列`score`的索引。索引名称是任意的，索引如果有多列，可以在括号里依次写上，例如：
>
> ```sql
> ALTER TABLE students
> ADD INDEX idx_name_score (name, score);
> ```
>
> 索引的效率取决于索引列的值**是否散列**，即该列的值如果越互不相同，那么索引效率越高。反过来，如果记录的列存在大量相同的值，例如`gender`列，大约一半的记录值是`M`，另一半是`F`，因此，对该列创建索引就没有意义。
>
> 可以对一张表创建多个索引。索引的优点是提高了查询效率，缺点是在插入、更新和删除记录时，需要同时修改索引，因此，索引越多，插入、更新和删除记录的速度就越慢。
>
> 对于主键，关系数据库会自动对其创建主键索引。使用主键索引的效率是最高的，因为主键会保证绝对唯一。
>
> ==唯一索引==
>
> 在设计关系数据表的时候，看上去唯一的列，例如身份证号、邮箱地址等，因为他们具有业务含义，因此不宜作为主键。
>
> 但是，这些列根据业务要求，又具有唯一性约束：即不能出现两条记录存储了同一个身份证号。这个时候，就可以给该列添加一个唯一索引。例如，我们假设`students`表的`name`不能重复：
>
> ```sql
> ALTER TABLE students
> ADD UNIQUE INDEX uni_name (name);
> ```
>
> 通过`UNIQUE`关键字我们就添加了一个唯一索引。
>
> 也可以只对某一列添加一个唯一约束而不创建唯一索引：
>
> ```sql
> ALTER TABLE students
> ADD CONSTRAINT uni_name UNIQUE (name);
> ```
>
> 这种情况下，`name`列没有索引，但仍然具有唯一性保证。
>
> 无论是否创建索引，对于用户和应用程序来说，使用关系数据库不会有任何区别。这里的意思是说，当我们在数据库中查询时，如果有相应的索引可用，数据库系统就会自动使用索引来提高查询效率，如果没有索引，查询也能正常执行，只是速度会变慢。因此，索引可以在使用数据库的过程中逐步优化。

## **查询数据**

###  **基本查询**

> ```sql
> SELECT * FROM <表名>
> ```
> 使用```SELECT * FROM students```时，```SELECT```是关键字，表示将要执行一个查询，```*```表示“所有列”，```FROM```表示将要从哪个表查询，本例中是```students```表。
>
> **`SELECT`语句其实并不要求一定要有`FROM`子句。我们来试试下面的`SELECT`语句**：
>
> > SELECT 100+200;
>
> 上述查询会直接计算出表达式的结果。虽然```SELECT```可以用作计算，但它并不是SQL的强项。但是，不带```FROM```子句的SELECT语句有一个有用的用途，**就是用来判断当前到数据库的连接是否有效**。许多检测工具会执行一条```SELECT 1```;来测试数据库连接。

### **条件查询**

> ```SQL
> SELECT * FROM <表名> WHERE <条件表达式>  
> ```
>
> 条件表达式：
>
> + <条件1> OR <条件2>
> + <条件1> AND <条件2>
> + NOT <条件>  
>   + 不常用，`NOT class_id = 2`其实等价于`class_id <> 2`
>
> **如果不加括号，条件运算按照`NOT、AND、OR`的优先级进行，即NOT优先级最高，其次是AND，最后是OR。加上括号可以改变优先**。
>
> **eg:** SELECT语句可以通过`WHERE`条件来设定查询条件，查询结果是满足查询条件的记录。例如，要指定条件“分数在80分或以上的学生”，写成`WHERE`条件就是`SELECT * FROM students WHERE score >= 80`。
>
> + **其中`=`表示`==`**
> + **字符串需要用单引号括起来**
> + **字符串比较根据ASCII码，中文字符比较根据数据库设置**
> + **%表示任意字符，例如'ab%'将匹配'ab'，'abc'，'abcd'**

### **投影查询**

> + 如果我们只希望返回某些列的数据，而不是所有列的数据，我们可以用`SELECT 列1, 列2, 列3 FROM ...`，让结果集仅包含指定列。这种操作称为投影查询。
>
> + `SELECT 列1, 列2, 列3 FROM ...`时，还**可以给每一列起个别名，这样，结果集的列名就可以与原表的列名不同。它的语法是`SELECT 列1 别名1, 列2 别名2, 列3 别名3 FROM ...`**。
>
> + 同样可以接`WHERE`条件

### **排序**

> 我们使用SELECT查询时，查询结果集通常是按主键排序。这也是大部分数据库的做法。
>
> + 可以加上`ORDER BY`子句，按照其他要求排序。
>
> ``` sql
> SELECT id, name, gender, score FROM students ORDER BY score;
> ```
>
> + 如果要反过来，按照成绩从高到底排序，我们可以加上`DESC`表示“倒序”：
>
> ``` sql
> SELECT id, name, gender, score FROM students ORDER BY score DESC;
> ```
>
> + 如果score列有相同的数据，要进一步排序，可以继续添加列名。例如，使用**`ORDER BY score DESC, gender`**表示先按score列倒序，如果有相同分数的，再按gender列排序。
>
> + 默认的排序规则是`ASC`：“升序”，即从小到大。`ASC`可以省略，即`ORDER BY score ASC`和`ORDER BY score`效果一样。
>
> + 如果有`WHERE`子句，那么`ORDER BY`子句要放到`WHERE`子句后面。

### **分页查询**

> 使用SELECT查询时，如果结果集数据量很大，比如几万行数据，放在一个页面显示的话数据量太大，不如分页显示，每次显示100条。要实现分页功能，实际上就是从结果集中显示第1~ 100条记录作为第1页，显示第101~200条记录作为第2页，以此类推。
>
> 因此，分页实际上就是**从结果集中“截取”出第M~N条记录**。这个查询可以通过**`LIMIT <M> OFFSET <N>`**子句实现。
>
> 例如，把结果集分页，每页3条记录。要获取第1页的记录，可以使用`LIMIT 3 OFFSET 0`，表示，对结果集从0号记录开始，最多取3条。注意**SQL记录集的索引从0开始**。
>
> ```sql
> SELECT id, name, gender, score
> FROM students
> ORDER BY score DESC
> LIMIT 3 OFFSET 0;
> ```
>
> 如果要查询第2页，那么我们只需要“跳过”头3条记录，也就是对结果集从3号记录开始查询，把`OFFSET`设定为3：`LIMIT 3 OFFSET 3`。类似的，查询第3页的时候，`OFFSET`应该设定为6。
>
> 由于第4页只有1条记录，因此最终结果集按实际数量1显示。`LIMIT 3`表示的意思是“最多3条记录”。
>
> 可见，==分页查询的关键在于，首先要确定每页需要显示的结果数量`pageSize`（这里是3），然后根据当前页的索引`pageIndex`（从1开始），确定`LIMIT`和`OFFSET`应该设定的值,这样就能正确查询出第N页的记录集==：
>
> - `LIMIT`总是设定为`pageSize`；
> - `OFFSET`计算公式为`pageSize * (pageIndex - 1)`。
>
> + `OFFSET`超过了查询的最大数量并不会报错，而是得到一个空的结果集。
> + `OFFSET`是可选的，如果只写`LIMIT 15`，那么相当于`LIMIT 15 OFFSET 0`。
> + 在MySQL中，`LIMIT 15 OFFSET 30`还可以简写成`LIMIT 30, 15`。
> + 使用`LIMIT <M> OFFSET <N>`分页时，随着`N`越来越大，查询效率也会越来越低。

### **聚合查询**

> 对于统计总数、平均数这类计算，SQL提供了专门的聚合函数，使用聚合函数进行查询，就是聚合查询，它可以快速获得结果。
>
> + `COUNT(*)`表示查询所有列的行数，要注意聚合的计算结果虽然是一个数字，但查询的结果仍然是一个二维表，只是这个二维表只有一行一列，并且列名是`COUNT(*)`。
>
>   通常，使用聚合查询时，我们应该给列名设置一个别名，便于处理结果
>
>   ```sql
>   SELECT COUNT(*) num FROM students;
>   ```
>
> 	| num  |
> 	| :--- |
> 	| 10   |
>
> 	+ `COUNT(*)`和`COUNT(id)`实际上是一样的效果。另外注意，聚合查询同样可以使用`WHERE`条件，因此我们可以方便地统计出有多少男生、多少女生、多少80分以上的学生等：
>
> 	  ```sql
> 	  SELECT COUNT(*) boys FROM students WHERE gender = 'M';
> 	  ```
>
> + | `SUM` | 计算某一列的合计值，该列必须为数值类型 |
>   | ----- | -------------------------------------- |
>   | `AVG` | 计算某一列的平均值，该列必须为数值类型 |
>   | `MAX` | 计算某一列的最大值                     |
>   | `MIN` | 计算某一列的最小值                     |
>
>   + 注意，`MAX()`和`MIN()`函数并不限于数值类型。如果是字符类型，MAX()和MIN()会返回 **排序最后和排序最前的字符**。
>
>   + 注意：如果聚合查询的`WHERE`条件没有匹配到任何行，**`COUNT()`会返回0，而`SUM()`、`AVG()`、`MAX()`和`MIN()`会返回`NULL`**。
>
>     + 计算男生平均成绩：
>
>     ```sql
>     SELECT AVG(score) average FROM students WHERE gender = 'M';
>     ```
>
> 	  + 每页3条记录，通过聚合查询获得总页数:
> 	  ```sql
> 	  SELECT CEILING(COUNT(*) / 3) FROM students;
> 	  ```
>
> + ==分组==
>
>   ```sql
>    # 按class_id分组:
>   SELECT COUNT(*) num FROM students GROUP BY class_id;
>   ```
>
> 	| num  |
> 	| :--- |
> 	| 4    |
> 	| 3    |
> 	| 3    |
>
> 	执行这个查询，`COUNT()`的结果不再是一个，而是3个，这是因为，**`GROUP BY`子句指定了按`class_id`分组，因此，执行该`SELECT`语句时，会把`class_id`相同的列先分组，再分别计算**，因此，得到了3行结果。
>
> 	```sql
> 	SELECT class_id, COUNT(*) num FROM students GROUP BY class_id;
> 	```
>
> 	| class_id | num  |
> 	| :------- | :--- |
> 	| 1        | 4    |
> 	| 2        | 3    |
> 	| 3        | 3    |
>
> 	我们再试试把`name`放入结果集
>
> 	| name | class_id | num  |
> 	| :--- | :------- | :--- |
> 	| NULL | 1        | 4    |
> 	| NULL | 2        | 3    |
> 	| NULL | 3        | 3    |
>
> 	不出意外，执行这条查询我们会得到一个语法错误，因为在任意一个分组中，只有`class_id`都相同，`name`是不同的，SQL引擎不能把多个`name`的值放入一行记录中。因此，**聚合查询的列中，只能放入分组的列**。
>
> 	也可以使用多个列进行分组。例如，我们想统计各班的男生和女生人数：
>
> 	```sql
> 	SELECT class_id, gender, COUNT(*) num FROM students GROUP BY class_id, gender;
> 	```
> 	
> 	| class_id | gender | num  |
> 	| :------- | :----- | :--- |
> 	| 1        | M      | 2    |
> 	| 1        | F      | 2    |
> 	| 2        | F      | 1    |
> 	| 2        | M      | 2    |
> 	| 3        | F      | 2    |
> 	| 3        | M      | 1    |

### **多表查询**

> 查询多张表的语法是：`SELECT * FROM <表1>, <表2>`
>
> 例如，同时从`students`表和`classes`表的“乘积”，即查询数据。这种一次查询两个表的数据，查询的结果也是一个二维表，它是`students`表和`classes`表的“乘积”，即`students`表的每一行与`classes`表的每一行都两两拼在一起返回。结果集的列数是`students`表和`classes`表的列数之和，行数是`students`表和`classes`表的行数之积。
>
> ```sql
> SELECT * FROM students, classes;
> ```
>
> 这种一次查询两个表的数据，查询的结果也是一个二维表，它是`students`表和`classes`表的“乘积”，即`students`表的每一行与`classes`表的每一行都两两拼在一起返回。结果集的列数是`students`表和`classes`表的列数之和，行数是`students`表和`classes`表的行数之积。
>
> 这种多表查询又称笛卡尔查询，使用笛卡尔查询时要非常小心，由于结果集是目标表的行数乘积，对两个各自有100行记录的表进行笛卡尔查询将返回1万条记录。
>
> 你可能还注意到了，上述查询的结果集有两列`id`和两列`name`，两列`id`是因为其中一列是`students`表的`id`，而另一列是`classes`表的`id`，但是在结果集中，不好区分。两列`name`同理。
>
> 要解决这个问题，我们仍然可以利用投影查询的“设置列的别名”来给两个表各自的`id`和`name`列起别名：
>
> ```sql
> SELECT
>     students.id sid,
>     students.name,
>     students.gender,
>     students.score,
>     classes.id cid,
>     classes.name cname
> FROM students, classes;
> ```
>
> 注意，多表查询时，要使用`表名.列名`这样的方式来引用列和设置别名，这样就避免了结果集的列名重复问题。但是，用`表名.列名`这种方式列举两个表的所有列实在是很麻烦，所以SQL还允许给表设置一个别名，让我们在投影查询中引用起来稍微简洁一点
>
> ```sql
> SELECT
>     s.id sid,
>     s.name,
>     s.gender,
>     s.score,
>     c.id cid,
>     c.name cname
> FROM students s, classes c;
> ```
>
> 多表查询也是可以添加`WHERE`条件的
>
> ```sql
> SELECT
>     s.id sid,
>     s.name,
>     s.gender,
>     s.score,
>     c.id cid,
>     c.name cname
> FROM students s, classes c
> WHERE s.gender = 'M' AND c.id = 1;
> ```
>
> | sid  | name | gender | score | cid  | cname |
> | :--- | :--- | :----- | :---- | :--- | :---- |
> | 1    | 小明 | M      | 90    | 1    | 一班  |
> | 3    | 小军 | M      | 88    | 1    | 一班  |
> | 6    | 小兵 | M      | 55    | 1    | 一班  |
> | 7    | 小林 | M      | 85    | 1    | 一班  |
> | 9    | 小王 | M      | 89    | 1    | 一班  |
>
> 这个查询的结果集每行记录都满足条件`s.gender = 'M'`和`c.id = 1`。添加`WHERE`条件后结果集的数量大大减少了。

### **连接查询**

> 连接查询是另一种类型的多表查询。连接查询对多个表进行JOIN运算，简单地说，就是先确定一个主表作为结果集，然后，把其他表的行有选择性地“连接”在主表结果集上。
>
> 例如，我们想要选出`students`表的所有学生信息，可以用一条简单的SELECT语句完成：
>
> ```sql
> SELECT s.id, s.name, s.class_id, s.gender, s.score FROM students s;
> ```
>
> | id   | name | class_id | gender | score |
> | :--- | :--- | :------- | :----- | :---- |
> | 1    | 小明 | 1        | M      | 90    |
> | 2    | 小红 | 1        | F      | 95    |
> | 3    | 小军 | 1        | M      | 88    |
> | 4    | 小米 | 1        | F      | 73    |
> | 5    | 小白 | 2        | F      | 81    |
> | 6    | 小兵 | 2        | M      | 55    |
> | 7    | 小林 | 2        | M      | 85    |
> | 8    | 小新 | 3        | F      | 91    |
> | 9    | 小王 | 3        | M      | 89    |
> | 10   | 小丽 | 3        | F      | 88    |
>
> 但是，假设我们希望结果集同时包含所在班级的名称，上面的结果集只有`class_id`列，缺少对应班级的`name`列。	现在问题来了，存放班级名称的`name`列存储在`classes`表中，只有根据`students`表的`class_id`，找到`classes`表对应的行，再取出`name`列，就可以获得班级名称。
>
> 
>
> + 我们先使用最常用的一种内连接——INNER JOIN来实现：	
>
> ```sql
> SELECT s.id, s.name, s.class_id, c.name class_name, s.gender, s.score
> FROM students s
> INNER JOIN classes c
> ON s.class_id = c.id;
> ```
>
> | id   | name | class_id | class_name | gender | score |
> | :--- | :--- | :------- | :--------- | :----- | :---- |
> | 1    | 小明 | 1        | 一班       | M      | 90    |
> | 2    | 小红 | 1        | 一班       | F      | 95    |
> | 3    | 小军 | 1        | 一班       | M      | 88    |
> | 4    | 小米 | 1        | 一班       | F      | 73    |
> | 5    | 小白 | 2        | 二班       | F      | 81    |
> | 6    | 小兵 | 2        | 二班       | M      | 55    |
> | 7    | 小林 | 2        | 二班       | M      | 85    |
> | 8    | 小新 | 3        | 三班       | F      | 91    |
> | 9    | 小王 | 3        | 三班       | M      | 89    |
> | 10   | 小丽 | 3        | 三班       | F      | 88    |
>
> 注意INNER JOIN查询的写法是：
>
> 1. 先确定主表，仍然使用`FROM <表1>`的语法；
>
> 2. 再确定需要连接的表，使用`INNER JOIN <表2>`的语法；
>
> 3. 然后确定连接条件，使用`ON <条件...>`，这里的条件是`s.class_id = c.id`，表示`students`表的`class_id`列与`classes`表的`id`列相同的行需要连接；
>
> 4. 可选：加上`WHERE`子句、`ORDER BY`等子句。
>
>    
>
> + 有内连接（INNER JOIN）就有外连接（OUTER JOIN）。我们把内连接查询改成外连接查询，看看效果:
>
>   ```SQL
>   SELECT s.id, s.name, s.class_id, c.name class_name, s.gender, s.score
>   FROM students s
>   RIGHT OUTER JOIN classes c
>   ON s.class_id = c.id;
>   ```
>
>   | id   | name | class_id | class_name | gender | score |
>   | :--- | :--- | :------- | :--------- | :----- | :---- |
>   | 1    | 小明 | 1        | 一班       | M      | 90    |
>   | 2    | 小红 | 1        | 一班       | F      | 95    |
>   | 3    | 小军 | 1        | 一班       | M      | 88    |
>   | 4    | 小米 | 1        | 一班       | F      | 73    |
>   | 5    | 小白 | 2        | 二班       | F      | 81    |
>   | 6    | 小兵 | 2        | 二班       | M      | 55    |
>   | 7    | 小林 | 2        | 二班       | M      | 85    |
>   | 8    | 小新 | 3        | 三班       | F      | 91    |
>   | 9    | 小王 | 3        | 三班       | M      | 89    |
>   | 10   | 小丽 | 3        | 三班       | F      | 88    |
>   | NULL | NULL | NULL     | 四班       | NULL   | NULL  |
>
>   和INNER JOIN相比，RIGHT OUTER JOIN多了一行，多出来的一行是“四班”，但是，学生相关的列如`name`、`gender`、`score`都为`NULL`。
>
>   这也容易理解，因为根据`ON`条件`s.class_id = c.id`，`classes`表的id=4的行正是“四班”，但是，`students`表中并不存在class_id=4的行。
>
> + 有RIGHT OUTER JOIN，就有LEFT OUTER JOIN，以及FULL OUTER JOIN。
>   + **INNER JOIN只返回同时存在于两张表的行数据**，由于`students`表的`class_id`包含1，2，3，`classes`表的`id`包含1，2，3，4，所以，INNER JOIN根据条件`s.class_id = c.id`返回的结果集仅包含1，2，3。
>   + **RIGHT OUTER JOIN返回右表都存在的行**。如果某一行仅在右表存在，那么结果集就会以`NULL`填充剩下的字段。
>   + **LEFT OUTER JOIN则返回左表都存在的行**。如果我们给students表增加一行，并添加class_id=5，由于classes表并不存在id=5的行，所以，LEFT OUTER JOIN的结果会增加一行，对应的`class_name`是`NULL`：
>   + 最后，我们使用**FULL OUTER JOIN，它会把两张表的所有记录全部选择出来，并且，自动把对方不存在的列填充为NULL**

## **修改数据**

关系数据库的基本操作就是增删改查，即==CRUD：Create、Retrieve、Update、Delete==。其中，对于查询，我们已经详细讲述了`SELECT`语句的详细用法。

而对于增、删、改，对应的SQL语句分别是：

- INSERT：插入新记录；
- UPDATE：更新已有记录；
- DELETE：删除已有记录。

### **INSERT**

> ```sql
> INSERT INTO <表名> (字段1, 字段2, ...) VALUES (值1, 值2, ...);
> ```
>
> 例如，我们向`students`表插入一条新记录，先列举出需要插入的字段名称，然后在`VALUES`子句中依次写出对应字段的值：
>
> ```sql
> -- 添加一条新记录
> INSERT INTO students 
> (class_id,name,gender,score) 
> VALUES
> (2,'大牛','M',80);
> ```
>
> 注意到我们并没有列出`id`字段，也没有列出`id`字段对应的值，这是因为`id`字段是一个自增主键，它的值可以由数据库自己推算出来。此外，如果一个字段有默认值，那么在`INSERT`语句中也可以不出现。

### **UPDATE**

>```SQL
>UPDATE <表名> SET 字段1=值1, 字段2=值2, ... WHERE ...;
>```
>
>如果要更新数据库表中的记录，我们就必须使用`UPDATE`语句。
>
>+ 例如，我们想更新`students`表`id=1`的记录的`name`和`score`这两个字段，先写出`UPDATE students SET name='大牛', score=66`，然后在`WHERE`子句中写出需要更新的行的筛选条件`id=1`：
>
>```sql
>-- 更新id=1的记录
>UPDATE students SET name='大牛',score=66 WHERE id>=5 AND id<=7;
>```
>
>+ 在`UPDATE`语句中，更新字段时可以使用表达式。例如，把所有80分以下的同学的成绩加10分：
>
>```sql
>-- 更新score<80的记录
>UPDATE students SET score=score+10 WHERE score<80;
>```
>
>+ 如果`WHERE`条件没有匹配到任何记录，`UPDATE`语句不会报错，也不会有任何记录被更新。
>
>+ `UPDATE`语句可以没有`WHERE`条件
>
>
>
>在使用MySQL这类真正的关系数据库时，`UPDATE`语句会返回更新的行数以及`WHERE`条件匹配的行数。
>
>例如，更新`id=1`的记录时：
>
>```mysql
>mysql> UPDATE students SET name='大宝' WHERE id=1;
>Query OK, 1 row affected (0.00 sec)
>Rows matched: 1  Changed: 1  Warnings: 0
>```
>
>MySQL会返回`1`，可以从打印的结果`Rows matched: 1 Changed: 1`看到。
>
>当更新`id=999`的记录时：
>
>```mysql
>mysql> UPDATE students SET name='大宝' WHERE id=999;
>Query OK, 0 rows affected (0.00 sec)
>Rows matched: 0  Changed: 0  Warnings: 0
>```
>
>MySQL会返回`0`，可以从打印的结果`Rows matched: 0 Changed: 0`看到。

 ### **DEIETE**

> ```sql
> DELETE FROM <表名> WHERE ...;
> ```
>
> 和`UPDATE`类似，`DELETE`语句也可以一次删除多条记录
>
> ```mysql
> -- 删除id=5,6,7的记录
> DELETE FROM students WHERE id>=5 AND id<=7;
> ```
>
> 如果`WHERE`条件没有匹配到任何记录，`DELETE`语句不会报错，也不会有任何记录被删除。
>
> 要特别小心的是，和`UPDATE`类似，不带`WHERE`条件的`DELETE`语句会删除整个表的数据。
>
> 
>
> 在使用MySQL这类真正的关系数据库时，`DELETE`语句也会返回删除的行数以及`WHERE`条件匹配的行数。
>
> 例如，分别执行删除`id=1`和`id=999`的记录：
>
> ```mysql
> mysql> DELETE FROM students WHERE id=1;
> Query OK, 1 row affected (0.01 sec)
> 
> mysql> DELETE FROM students WHERE id=999;
> Query OK, 0 rows affected (0.01 sec)
> ```

## **实用语句**

+ 插入或替换

```sql
-- 不必先查询，再决定是否先删除再插入
REPLACE INTO students 
(id, class_id, name, gender, score) 
VALUES(1, 1, '小明', 'F', 99) 
ON DUPLIACTE KEY UPDATE 
name='小明', gender='F',score=99;
-- 若id=1的记录不存在，REPLACE语句将插入新记录，否则，当前id=1的记录将被删除，然后再插入新记录。
```

+ 插入或更新
 ```SQL
 -- 插入一条新记录（INSERT），但如果记录已经存在，就更新该记录,更新的字段由UPDATE指定
 INSERT INTO students
 (id, class_id, name, gender, score)
 VALUES(1, 1, '小明', 'F', 99) 
 ON DUPLICATE KEY UPDATE
 name='小明', gender='F', score=99;
 ```

+ 插入或忽略

```sql
-- 如果我们希望插入一条新记录（INSERT），但如果记录已经存在，就啥事也不干直接忽略
INSERT IGNORE INTO students 
(id, class_id, name, gender, score)
VALUES (1, 1, '小明', 'F', 99);
```

+ 快照

```sql
-- 复制一份当前表的数据到一个新表,新创建的表结构和SELECT使用的表结构完全一致
-- 对class_id=1的记录进行快照，并存储为新表students_of_class1:
CREATE TABLE students_of_class1 
SELECT * FROM students
WHERE class_id=1;
```

+ 写入查询结果集

```sql
-- 如果查询结果集需要写入到表中，可以结合INSERT和SELECT，将SELECT语句的结果集直接插入到指定表中
CREATE TABLE statistics(
	id BIGINT NOT NULL AUTO_INCREMENT,
	class_id BIGINT NOT NULL,
	average DOUBLE NOT NULL,
	PRIMARY KEY (id)
);
-- 然后，我们就可以用一条语句写入各班的平均成绩
INSERT INTO statisticss
(class_id, average)
SELECT class_id, AVG(score)
FROM students
GROUP BY class_id;
-- 确保INSERT语句的列和SELECT语句的列能一一对应，就可以在statistics表中直接保存查询的结果
```

+ 强制使用指定索引

```sql
-- 指定索引的前提是索引idx_class_id必须存在
-- 在查询的时候，数据库系统会自动分析查询语句，并选择一个最合适的索引。但是很多时候，数据库系统的查询优化器并不一定总是能使用最优索引。如果我们知道如何选择索引，可以使用FORCE INDEX强制查询使用指定的索引。
SELECT * FROM students
FORCE INDEX (id_class_id)
WHERE class_id = 1
ORDER BY id DESC;
```

## **事务**

> 在执行SQL语句的时候，某些业务要求，一系列操作必须全部执行，而不能仅执行一部分。
>
> ```sql
> -- 一个转账工作
> -- 从id=1的账户给id=2的账户转账100元
> -- 第一步：将id=1的A账户余额减去100
> UPDATE accounts SET balance = balance - 100 
> WHERE id = 1;
> -- 第二步：将id=2的B账户加上100
> UPDATE accounts SET balance = balance + 100
> WHERE id = 2;
> ```
>
> 这两条SQL语句必须全部执行，或者，由于某些原因，如果第一条语句成功，第二条语句失败，就必须全部撤销。

### **简介**

> + 把多条语句作为一个整体进行操作的功能，被称为数据库*事务*。数据库事务可以确保该事务范围内的所有操作都可以**全部成功或者全部失败**。如果事务失败，那么效果就和没有执行这些```SQL```一样，不会对数据库数据有任何改动。
>
> + 特性：
>   - A：`Atomic`，原子性，将所有SQL作为原子工作单元执行，要么全部执行，要么全部不执行；
>   - C：`Consistent`，一致性，事务完成后，所有数据的状态都是一致的，即A账户只要减去了100，B账户则必定加上了100；
>   - I：`Isolation`，隔离性，如果有多个事务并发执行，每个事务作出的修改必须与其他事务隔离；
>   - D：`Duration`，持久性，即事务完成后，对数据库数据的修改被持久化存储
>
> + 对于单条SQL语句，数据库系统自动将其作为一个事务执行，这种事务被称为**隐式事务**。
>
> + 要手动把多条SQL语句作为一个事务执行，使用`BEGIN`开启一个事务，使用`COMMIT`提交一个事务，这种事务被称为**显式事务**，例如，把上述的转账操作作为一个显式事务：
>
>   ```SQL
>   BEGIN;
>   UPDATE accounts SET balance = balance - 100 WHERE id = 1;
>   UPDATE accounts SET balance = balance - 100 WHERE id = 2;
>   COMMIT;
>   ```
>
> + `COMMIT`是指提交事务，即试图把事务内的所有SQL所做的修改永久保存。如果COMMIT语句执行失败了，整个事务也会失败。
>
> + 有些时候，我们希望主动让事务失败，这时，可以用`ROLLBACK`回滚事务，整个事务会失败：
>
>   ```SQL
>   BEGIN;
>   UPDATE accounts SET balance = balance - 100 WHERE id = 1;
>   UPDATE accounts SET balance = balance - 100 WHERE id = 2;
>   ROLLBACK;
>   ```

### ==**隔离级别**==

> 对于两个并发执行的事务，如果涉及到操作同一条记录的时候，可能会发生问题。因为并发操作会带来数据的不一致性，包括脏读、不可重复读、幻读等。数据库系统提供了隔离级别来让我们有针对性地选择事务的隔离级别，避免数据不一致的问题。
>
> SQL标准定义了4种隔离级别，分别对应可能出现的数据不一致的情况：
>
> | Isolation Level  | 脏读（Dirty Read） | 不可重复读（Non Repeatable Read） | 幻读（Phantom Read） |
> | :--------------- | :----------------- | :-------------------------------- | :------------------- |
> | Read Uncommitted | Yes                | Yes                               | Yes                  |
> | Read Committed   | -                  | Yes                               | Yes                  |
> | Repeatable Read  | -                  | -                                 | Yes                  |
> | Serializable     | -                  | -                                 | -                    |

#### **Read Uncommitted**

> + 隔离级别最低
>
> + 一个事务会读到另一个事务更新后但未提交的数据，如果另一个事务回滚，那么当前事务读到的数据就是脏数据，这就是脏读（Dirty Read）
>
>   首先，我们准备好`students`表的数据，该表仅一行记录：
>
>   ```mysql
>   mysql> select * from students;
>   +----+-------+
>   | id | name  |
>   +----+-------+
>   |  1 | Alice |
>   +----+-------+
>   1 row in set (0.00 sec)
>   ```
>
>   然后，分别开启两个MySQL客户端连接，按顺序依次执行事务A和事务B：
>
>   | 时刻 | 事务A                                             | 事务B                                             |
>   | :--- | :------------------------------------------------ | :------------------------------------------------ |
>   | 1    | SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; | SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; |
>   | 2    | BEGIN;                                            | BEGIN;                                            |
>   | 3    | UPDATE students SET name = 'Bob' WHERE id = 1;    |                                                   |
>   | 4    |                                                   | SELECT * FROM students WHERE id = 1;              |
>   | 5    | ROLLBACK;                                         |                                                   |
>   | 6    |                                                   | SELECT * FROM students WHERE id = 1;              |
>   | 7    |                                                   | COMMIT;                                           |
>
>   当事务A执行完第3步时，它更新了`id=1`的记录，但并未提交，而事务B在第4步读取到的数据就是未提交的数据。
>
>   随后，事务A在第5步进行了回滚，事务B再次读取`id=1`的记录，发现和上一次读取到的数据不一致，这就是脏读。
>
>   可见，在Read Uncommitted隔离级别下，一个事务可能读取到另一个事务更新但未提交的数据，这个数据有可能是脏数据。

#### **Read Committed**

> + 在Read Committed隔离级别下，一个事务可能会遇到**不可重复读（Non Repeatable Read）**的问题，**在一个事务内，多次读同一数据**，在这个事务还没有结束时，如果另一个事务恰好修改了这个数据，那么，在第一个事务中，两次读取的数据就可能不一致。
>
>   我们仍然先准备好`students`表的数据：
>
>   ```mysql
>   mysql> select * from students;
>   +----+-------+
>   | id | name  |
>   +----+-------+
>   |  1 | Alice |
>   +----+-------+
>   1 row in set (0.00 sec)
>   ```
>
>   然后，分别开启两个`MySQL`客户端连接，按顺序依次执行事务A和事务B：
>
>   | 时刻 | 事务A                                           | 事务B                                           |
>   | :--- | :---------------------------------------------- | :---------------------------------------------- |
>   | 1    | SET TRANSACTION ISOLATION LEVEL READ COMMITTED; | SET TRANSACTION ISOLATION LEVEL READ COMMITTED; |
>   | 2    | BEGIN;                                          | BEGIN;                                          |
>   | 3    |                                                 | SELECT * FROM students WHERE id = 1;            |
>   | 4    | UPDATE students SET name = 'Bob' WHERE id = 1;  |                                                 |
>   | 5    | COMMIT;                                         |                                                 |
>   | 6    |                                                 | SELECT * FROM students WHERE id = 1;            |
>   | 7    |                                                 | COMMIT;                                         |
>
>   当事务B第一次执行第3步的查询时，得到的结果是`Alice`，随后，由于事务A在第4步更新了这条记录并提交，所以，事务B在第6步再次执行同样的查询时，得到的结果就变成了`Bob`，因此，在Read Committed隔离级别下，事务不可重复读同一条记录，因为很可能读到的结果不一致。

#### **Repeatable Read**

> + 一个事务可能会遇到`幻读（Phantom Read）`的问题
>
> + 幻读是指，在一个事务中，第一次查询某条记录，发现没有，但是，当试图更新这条不存在的记录时，竟然能成功，并且，再次读取同一条记录，它就神奇地出现了
>
>   + 我们仍然先准备好`students`表的数据：
>
>   ```mysql
>   mysql> select * from students;
>   +----+-------+
>   | id | name  |
>   +----+-------+
>   |  1 | Alice |
>   +----+-------+
>   1 row in set (0.00 sec)
>   ```
>
>   + 然后，分别开启两个MySQL客户端连接，按顺序依次执行事务A和事务B：
>
>   | 时刻 | 事务A                                               | 事务B                                             |
>   | :--- | :-------------------------------------------------- | :------------------------------------------------ |
>   | 1    | SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;    | SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;  |
>   | 2    | BEGIN;                                              | BEGIN;                                            |
>   | 3    |                                                     | SELECT * FROM students WHERE id = 99;             |
>   | 4    | INSERT INTO students (id, name) VALUES (99, 'Bob'); |                                                   |
>   | 5    | COMMIT;                                             |                                                   |
>   | 6    |                                                     | SELECT * FROM students WHERE id = 99;             |
>   | 7    |                                                     | UPDATE students SET name = 'Alice' WHERE id = 99; |
>   | 8    |                                                     | SELECT * FROM students WHERE id = 99;             |
>   | 9    |                                                     | COMMIT;                                           |
>
>   + 事务B在第3步第一次读取`id=99`的记录时，读到的记录为空，说明不存在`id=99`的记录。随后，事务A在第4步插入了一条`id=99`的记录并提交。事务B在第6步再次读取`id=99`的记录时，读到的记录仍然为空，但是，事务B在第7步试图更新这条不存在的记录时，竟然成功了，并且，事务B在第8步再次读取`id=99`的记录时，记录出现了。
>
>   可见，幻读就是没有读到的记录，以为不存在，但其实是可以更新成功的，并且，更新成功后，再次读取，就出现了。

 #### **Serializable**

> Serializable是最严格的隔离级别。在Serializable隔离级别下，所有事务按照次序依次执行，因此，脏读、不可重复读、幻读都不会出现。
>
> 虽然Serializable隔离级别下的事务具有最高的安全性，但是，由于事务是串行执行，所以效率会大大下降，应用程序的性能会急剧降低。如果没有特别重要的情景，一般都不会使用Serializable隔离级别。
>
> **默认隔离级别**
>
> 如果没有指定隔离级别，数据库就会使用默认的隔离级别。在MySQL中，如果使用InnoDB，默认的隔离级别是Repeatable Read。

