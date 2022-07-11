# ==**String**==

+ set key value

  > + 设置指定 key 的值
  > + 如果 key 已经存储其他值， SET 就覆写旧值，且无视类型

+ get key

  > + 获取指定 key 的值
  > + 返回 key 的值，如果 key 不存在时，返回 nil
  > +  如果 key 不是字符串类型，那么返回一个错误

+ getrange key start end

  > + 返回 key 中字符串值的子字符
  >
  >   ```sql
  >   redis 127.0.0.1:6379> SET mykey "This is my test key"
  >   OK
  >   redis 127.0.0.1:6379> getrange mykey 0 3
  >   "This"
  >   redis 127.0.0.1:6379> GETRANGE mykey 0 -1
  >   "This is my test key"
  >   ```

+ getset key value

  > + 设置指定 key 的值，并返回 key 的旧值
  >
  > +  当 key 没有旧值时，即 key 不存在时，返回 nil
  >
  > + 当 key 存在但不是字符串类型时，返回一个错误
  >
  >   ```sql
  >   redis> GETSET db mongodb    # 没有旧值，返回 nil
  >   (nil)
  >           
  >   redis> GET db
  >   "mongodb"
  >           
  >   redis> GETSET db redis      # 返回旧值 mongodb
  >   "mongodb"
  >           
  >   redis> GET db
  >   "redis"
  >           
  >   ```

+ getbit key offset

  > + 用于对 key 所储存的字符串值，获取指定偏移量上的位(bit)
  >
  > + 字符串值指定偏移量上的位(bit)
  >
  > + 当偏移量 OFFSET 比字符串值的长度大，或者 key 不存在时，返回 0 
  >
  >   ```sql
  >   # 对不存在的 key 或者不存在的 offset 进行 GETBIT， 返回 0
  >           
  >   redis> EXISTS bit
  >   (integer) 0
  >           
  >   redis> GETBIT bit 10086
  >   (integer) 0
  >         
  >   # 对已存在的 offset 进行 GETBIT
  >       
  >     redis> SETBIT bit 10086 1
  >   (integer) 0
  >       
  >     redis> GETBIT bit 10086
  >   (integer) 1
  >       
  >   ```

+ mget key1 key2 key3 ...

  > + 返回所有(一个或多个)给定 key 的值
  >
  > + 如果给定的 key 里面，有某个 key 不存在，那么这个 key 返回特殊值 nil 
  >
  > + ```sql
  >   redis 127.0.0.1:6379> SET key1 "hello"
  >   OK
  >   redis 127.0.0.1:6379> SET key2 "world"
  >   OK
  >   redis 127.0.0.1:6379> MGET key1 key2 someOtherKey
  >   1) "Hello"
  >   2) "World"
  >   3) (nil)
  >   ```

+ setbit key offset

  > + 用于对 key 所储存的字符串值，设置或清除指定偏移量上的位(bit)
  >
  > + 返回指定偏移量原来储存的位
  >
  >   ```sql
  >   redis> SETBIT bit 10086 1
  >   (integer) 0
  >           
  >   redis> GETBIT bit 10086
  >   (integer) 1
  >           
  >   redis> GETBIT bit 100   # bit 默认被初始化为 0
  >   (integer) 0
  >   ```

+ setex key time_out value

  > + 为指定的 key 设置值及其过期时间
  >
  > + 如果 key 已经存在， SETEX 命令将会替换旧的值
  >
  >   ```sql
  >   redis 127.0.0.1:6379> SETEX mykey 60 redis
  >   OK
  >   redis 127.0.0.1:6379> TTL mykey
  >   60
  >   redis 127.0.0.1:6379> GET mykey
  >   "redis
  >   ```

+ setnx key value

  > + Redis Setnx（**SET** if **N**ot e**X**ists） 命令在指定的 key 不存在时，为 key 设置指定的值

+ 
