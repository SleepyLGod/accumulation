## **简介**
>  + `MySQL Client`的可执行程序是`mysql`，`MySQL Server`的可执行程序是`mysqld`。
>
> + 命令行程序`mysql`实际上是MySQL客户端，真正的MySQL服务器程序是`mysqld`，在后台运行。

>  + MySQL Client和MySQL Server的关系如下：
>
>  ```java
>  ┌──────────────┐  SQL   ┌──────────────┐
>  │ MySQL Client │───────>│ MySQL Server │
>  └──────────────┘  TCP   └──────────────┘
>  ```

> + 在 MySQL Client 中输入的 SQL 语句通过 TCP 连接发送到 MySQL Server。默认端口号是3306，即如果发送到本机MySQL Server，地址就是`127.0.0.1:3306`。

>  + 也可以只安装MySQL Client，然后连接到远程MySQL Server。假设远程MySQL Server的IP地址是`10.0.1.99`，那么就使用`-h`指定IP或域名：
>
>  ```mysql
>  mysql -h 10.0.1.99 -u root -p
>  ```

## **基本指令**
+ 启动shell

  ``mysql -u root -p``

+ 退出shell

  ``exit``  或  ```quit```


+ 列出数据库

  ```	SHOW DATABASES;```

+ 创建数据库

  `CREATE DATABASE test;`

+ 删除一个数据库

  `DROP DATABASE test;`

+ 切换为当前数据库

  `USE test;`

+ 列出当前数据库的所有表

  `SHOW TABLES;`

+ 要查看一个表的结构

  `DESC students;`

+ 查看创建表的SQL语句

  `SHOW CREATE TABLE students;`

+ 删除表

  `DROP TABLE students;`

+ 修改表: 

  + 如果要给`students`表新增一列`birth`:

    **``ALTER TABLE students ADD COLUMN birth VARCHAR(10) NOT NULL;`**

  + 要修改`birth`列，例如把列名改为`birthday`，类型改为`VARCHAR(20)`：

    **`ALTER TABLE students CHANGE COLUMN birth birthday VARCHAR(20) NOT NULL;`**

  + 删除列

    **`ALTER TABLE students DROP COLUMN birthday;`**

## **JAVA中使用**

> 使用 JDBC 连接 MySQL 数据库。
>
> Java 连接 MySQL 需要驱动包，最新版下载地址为：**http://dev.mysql.com/downloads/connector/j/**，解压后得到 jar 库文件，然后在对应的项目中导入该库文件。
>
> **MySQL 8.0 以上版本的数据库连接有所不同：**
>
> - 1、MySQL 8.0 以上版本驱动包版本 [mysql-connector-java-8.0.16.jar](https://static.runoob.com/download/mysql-connector-java-8.0.16.jar)。
> - 2、**com.mysql.jdbc.Driver** 更换为 **com.mysql.cj.jdbc.Driver**。
> - MySQL 8.0 以上版本不需要建立 SSL 连接的，需要显示关闭。
> - allowPublicKeyRetrieval=true 允许客户端从服务器获取公钥。
> - 最后还需要设置 CST。
>
> 加载驱动与连接数据库方式如下：
>
> ```mysql
> Class.forName("com.mysql.cj.jdbc.Driver");
> conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test_demo?useSSL=false&allowPublicKeyRetrieval=true&serverTimezone=UTC","root","password");
> ```
>
>

