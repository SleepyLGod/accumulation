# **==Redis教程==**

> 基本数据结构：
>
> > ```string``` ：字符串
> >
> > ```Hash``` ：散列
> >
> > ```List``` ：列表
> >
> > ```Set``` ：集合
> >
> > ```Sorted Set``` ：有序集合

[Redis官网]:https://redis.io/
[源码地址]:https://github.com/redis/redis
[Redis 在线测试]:http://try.redis.io/
[Redis 命令参考]:http://doc.redisfans.com/
[Java、ruby、node.js实现实例]:http://github.com/josiahcarlson/redis-in-action
[spring框架中使用redis]:http:www.springsource.org/spring-data/redis

> 简介：

```mysql是关系型数据库；redis是非关系型数据库，不使用表。```

+ Redis支持数据的持久化，可以将内存中的数据保存在磁盘中，重启的时候可以再次加载进行使用。

+ Redis不仅仅支持简单的key-value类型的数据，同时还提供list，set，zset，hash等数据结构的存储。

+ Redis支持数据的备份，即master-slave模式的数据备份。

> 常用命令：

  ```markdown
  **启动Redis服务：**
  sudo systemctl start redis-server 或者 service redis-server start
  **关闭Redis服务：**
  sudo systemctl stop redis-server 或者service redis-server stop
  **重启Redis服务：**
  sudo systemctl restart redis-server或者service redis-server restart
  ```

