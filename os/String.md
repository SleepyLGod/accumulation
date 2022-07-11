## **String**

+ 两个字符串比较，必须总是使用`equals()`方法。

+ 要忽略大小写比较，使用`equalsIgnoreCase()`方法

+ 是否包含子串:`contains()`方法(参数是`CharSequence`而不是`String`，因为`CharSequence`是`String`的父类)

+ 搜索子串的更多的例子:

  ```java
  "Hello".indexOf("l"); // 2
  "Hello".lastIndexOf("l"); // 3
  "Hello".startsWith("He"); // true
  "Hello".endsWith("lo"); // true
  ```
  
+ 提取子串的例子(注意索引号是从`0`开始的)：

  ```java
  "Hello".substring(2); // "llo"
  "Hello".substring(2, 4); "ll"
  ```

+ 使用`trim()`方法可以移除字符串首尾空白字符。空白字符包括空格，`\t`，`\r`，`\n`

+ 另一个`strip()`方法也可以移除字符串首尾空白字符。它和`trim()`不同的是，类似中文的空格字符`\u3000`也会被移除

+ 有`isEmpty()`和`isBlank()`来判断字符串是否为**空**和**空白字符串**

+ `replace()`方法替换子串

+ 要分割字符串，使用`split()`方法

+ 拼接字符串使用静态方法`join()`，它用指定的字符串连接字符串数组

+ 字符串提供了`formatted()`方法和`format()`静态方法，可以传入其他参数，替换占位符，然后生成新的字符串

  ```java
  String s = "Hi %s, your score is %d!";
  System.out.println(s.formatted("Alice", 80));
  System.out.println(String.format("Hi %s, your score is %.2f!", "Bob", 59.5));
  ```
  + `%s`：显示字符串；
  + `%d`：显示整数；
  + `%x`：显示十六进制整数；
  + `%f`：显示浮点数。

  占位符还可以带格式，例如`%.2f`表示显示两位小数。如果你不确定用啥占位符，那就始终用`%s`，因为`%s`可以显示任何数据类型。

+ 把任意基本类型或引用类型转换为字符串，可以使用静态方法`valueOf()`

   要把字符串转换为其他类型，就需要根据情况。例如，把字符串转换为`int`类型：
  
   ```java
   int n1 = Integer.parseInt("123"); // 123
   int n2 = Integer.parseInt("ff", 16); // 按十六进制转换，255
   ```
  >
   把字符串转换为`boolean`类型：
  >
   ```java
   boolean b1 = Boolean.parseBoolean("true"); // true
   boolean b2 = Boolean.parseBoolean("FALSE"); // false
   ```
  >
   要特别注意，`Integer`有个`getInteger(String)`方法，它不是将字符串转换为`int`，而是把该字符串对应的系统变量转换为`Integer`：
  >
   ```java
   Integer.getInteger("java.version"); // 版本号，11
   ```
  >转换为char[]
  >
  >`String`和`char[]`类型可以互相转换，方法是：
  >```java
  >char[] cs = "Hello".toCharArray(); // String -> char[]
  >String s = new String(cs); // char[] -> String
  >```
  >如果修改了`char[]`数组，`String`并不会改变，这是因为通过`new String(char[])`创建新的`String`实例时，它并不会直接引用传入的`char[]`数组，而是会复制一份
  
+ 在Java中，char类型实际上就是两个字节的Unicode编码。如果我们要手动把字符串转换成其他编码，可以这样做：

```java
byte[] b1 = "Hello".getBytes(); // 按系统默认编码转换，不推荐
byte[] b2 = "Hello".getBytes("UTF-8"); // 按UTF-8编码转换
byte[] b2 = "Hello".getBytes("GBK"); // 按GBK编码转换
byte[] b3 = "Hello".getBytes(StandardCharsets.UTF_8); // 按UTF-8编码转换
// 注意：转换编码后，就不再是char类型，而是byte类型表示的数组。
```

​	如果要把已知编码的byte[]转换为String，可以这样做：

```java
byte[] b = ...
String s1 = new String(b, "GBK"); // 按GBK转换
String s2 = new String(b, StandardCharsets.UTF_8); // 按UTF-8转换
// 始终牢记：Java的String和char在内存中总是以Unicode编码表示。
```

------

