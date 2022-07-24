## **C++**

----
+ 变量
  
  + ```c++
    类型的字节数与硬件、操作系统、编译有关。
    如采用 VS1029、x86 编译模式，则有：
    bool ：单字节布尔类型，取值false和true。
    char ：单字节有符号字符类型，取值-128~127。
    short ：两字节有符号整数类型，取值-32768~32767。
    int (即 long)：四字节有符号整数类型，
    float ：四字节有符号单精度浮点数类型
    double ：八字节有符号双精度浮点数类型
        
    默认整数常量（如 123）当作为 int 类型，
    默认浮点常量（如 12.3）当作 double 类型。
        
    ➢ long int 等价于 long ；
    ➢ long long 占用八字节；
    ➢ sizeof(char) ≤ sizeof(short) ≤ sizeof(int) ≤ sizeof(double) ;
    
    ➢ char 、 short 、 int 、 long 前加 unsigned 表示无符号数
    ```
  
  + ```c++
    ➢ 字符常量：
    ‘A’, ‘a’ , ‘9’ , ‘\’’(单引号),‘\\’(斜线),‘\n’(换新行), ‘\t’(制表符), ‘\b’(退格)
    ➢ 整型常量：
    9, 04, 0xA (int);
    9U, 04U, 0xAU (unsigned int);
    9L,04L,0xAL (long);
    9UL, 04UL,0xAUL (unsigned long),
    9LL,04LL,0xALL (long long);
    ➢ double常量：
    0.9, .3, 2E10, 2.E10, -2.5E-10
    ```
  
  + ```c++
    char: %c;
    short, int: %d; 
    long ：%ld;
    float ：%f; 
    double ：%lf;
    float, double ：%e 科学计数。
    十进制数用 %d
    无符号数十进制数用 %u
    八进制数用 %o
    十六进制用 %x
    自动选宽度小的e或f %g
        
    ➢ 可对%f或%lf设定宽度和精度及对齐方式
    “%-8.2f”：左对齐、总宽度8(包括符号位和小数部分)、精度为2位小数;
    
    可设定宽度和对齐：printf(“%5s”,”abc”)；
        
    ➢ 字符串常量的类型：
    “abc” 指向只读字符的指针即const char *
    ```
  
  + 变量的存储位置特性
  
    > 一个由 c/c++编译过的程序占用的内存分为一下几个部分
    >
    > + **栈区 `stack`**:由**编译器自动分配释放**，存放函数的参数值，局部变量的值等。这个栈的操作方式类似于数据结构中的**栈**。
    > + **堆区 `heap`:**一般由**程序员分配释放**，若程序员不释放，程序结束时可能由**OS回收**，注意它与数据结构中的堆是两回事，分配方式类似于**链表**。
    > + **全局区（静态区）`static`**:**全局变量和静态变量**的存储是放在一块的。初始化的全局变量和静态变量在一块区域，未初始化的全局变量和静态变量又放在相邻的另一块区域中。程序结束后由**系统释放**。
    > + **文字常量区**:**常量字符串**放在这里。程序结束后由**系统释放**。
    > + **程序代码区**: 存放函数体的2进制代码。
  
    >  根据变量的位置可以分为全局变量和局部变量
  
    >  根据变量的静态属性可以分为静态变量和非静态变量。
  
    >  根据变量的const属性可以分为const变量和非const变量。
  
    + 全局变量和局部变量的不同主要体现在变量的作用范围上
  
      全局变量的初始化分为两种，**非类对象的变量的初始话发生在函数的编译阶段**，如果我们没有显示的初始化，编译器会默认初始化，**类类型的全局变量的初始化发生在程序运行阶段的Main函数之前**。对于**局部变量，不会执行默认初始化，因此在使用局部变量之前必须先进行变量的初始化**。
  
    + 静态变量和非静态变量的初始化：
  
      静态变量根据其位置可以分为三种：全局静态变量、定义在**函数**中的静态变量以及定义在**类**中的静态变量。
  
      静态变量的初始化：编译器要求不同，有的要求必须主动完成初始化，有的编译器会完成默认初始化，但是值不确定。所以，在使用静态变量的时候，我们一般要求必须在定义的同时完成初始化。对于**g++**编译器，如果静态变量是全局或者函数的局部变量，都会完成默认初始化。**但是如果类包含静态数据成员，C++要求这个静态数据成员仅可以在类内部完成声明，然后在类外，且任何函数之外，完成静态成员的初始化，初始化可以赋初始值，也可以不赋值，不赋值会默认初始化。**
  
      初始化的形式如下：`int A::i = 1;`
  
      如果试图在类内初始化，编译器会报错：`ISO C++ forbids in-class initialization of non-const static member ‘A::k’`
  
      如果在函数内（比如main函数）试图初始化， 编译器同样会报错：`如果不初始化直接使用，由于未分配内存，还是会报错：undefined reference to A::k`
  
      类中的静态成员变量：类的静态成员存在于任何对象之外，对象中不包含任何与静态数据成员有关的数据，因此，静态数据成员不是由构造函数进行初始化的，类的静态数据成员的初始化过程必须在类的定义之外，相对的，类的非静态数据的初始化发生在类的构造函数中。
  
      由于类的静态数据成员所有类共有，所以，类在分配内存的时候并不会主动分配这个静态数据成员的内存，因此要求我们必须主动要求分配内存。必须在类外完成初始化的原因是因为，这个静态数据成员保存在数据段（全局区），如果在函数内初始化，意味着要求编译器在栈区这个变量分配内存，这也是错误的。
  
      **但是这中情况有一个例外，那就是如果类的静态数据成员是`const`, 那么 这个变量必须在类内完成初始化。**
  
    + 对于全局变量，如果程序仅由一个源文件构成，那么全局静态变量类同于全局变量，在编辑阶段进行初始化。**如果程序由多个源文件构成，那么全局静态变量仅对所在的源文件有效，而全局变量在整个程序中有效**。
    + 定义在函数中的静态变量：**定义在函数中的静态变量的作用是变量值的保持**，对于初始化而言，函数中的静态变量仅在定义时进行初始化，且在整个程序的运行中，函数中的静态变量只初始化一次。
  
    + `const`对象和非`const`对象的初始化：`const`对象必须在定义的时候进行初始化，引用的本质是一个`const`指针，因此引用也必须在定义的时候进行初始化。
  
    >  各种变量的存储位置：
  
    + 常规的变量**（非全局，非静态）保存在栈**上。
  
    + **动态数据等显示分配的内存**在堆上。
  
    + 全局变量和静态变量保存在数据段（全局区）
  
    + **const全局变量存放于只读数据段**，在第一次使用时为其分配内存。
  
      ```c++
      int a = 0; //全局初始化区 
      char *p1; //全局未初始化区 
      int main() { 
          int b;				// 栈 
          char s[] = "abc"; 	// 栈 
          char *p2; 			// 栈 
          char *p3 = "123456"; // 123456\0" 在常量区，p3在栈上
          static int c =0； 	// 全局（静态）初始化区 
          p1 = (char *)malloc(10); 
          p2 = (char *)malloc(20); 
          // 分配得来得10和20字节的区域就在堆区。 
          strcpy(p1, "123456"); //123456\0放在常量区，编译器可能会将它与p3所指向的"123456"优化成一个地方。
      } 
      ```
  
    + `BSS`引入
      内存分配区域 : 32位操作系统下为：1G内核态，3G用户态
      
      **`BSS`段 ：通常是指用来存放程序中 未初始化的全局变量、静态变量（全局变量未初始化时默认为0）的一块内存区域**
      
      **数据段 ：通常是指用来存放程序中 初始化后的全局变量和静态变量**
      
      **代码段 ：通常是指用来存放程序中 代码和常量**
      
      **堆 ：通常是指用来存放程序中 进程运行时被动态分配的内存段 ( 动态分配：malloc / new，动态释放：free / delete)** 需要程序员自己申请，并指明大小(
      
      **栈 ：**通常是指用来存放程序中用户临时创建的**局部变量、函数形参、数组**(局部变量未初始化则默认为垃圾值)。**在函数被调用时，其参数也会被压入发起调用的进程栈中，并且待到调用结束后，函数的返回值也会被存放回栈中**。由于栈的先进后出特点，所以栈特别方便用来保存/恢复调用现场。从这个意义上讲，我们可以把堆栈看成一个寄存、交换临时数据的内存区。它是由操作系统分配的，内存的申请与回收都由OS管理。
      
      ==堆（`heap`）和栈（`stack`）的区别==
      
      + 申请方式
  
      ➢ 栈: 由系统自动分配。
  
      ➢ 堆: 需要程序员自己申请，并指明大小。
  
      + 申请后系统的响应
  
      ➢ 栈：只要栈的剩余空间大于所申请空间，系统将为程序提供内存，否则将报异常提示栈溢出。
  
      ➢ 堆：首先应该知道操作系统有一个**记录空闲内存地址的链表**，当系统收到程序的申请时，会遍历该链表，**寻找第一个空间大于所申请空间的堆结点，然后将该结点从空闲结点链表中删除，并将该结点的空间分配给程序**，另外，对于大多数系统，会在这块内存空间中的**首地址处记录本次分配的大小，这样，代码中的delete语句才能正确的释放本内存空间**。另外，由于找到的堆结点的大小不一定正好等于申请的大小，系统会自动的将多余的那部分**重新放入**空闲链表中。
      
      + 申请大小的限制
      
      ➢ 栈：在**Windows下**,**栈是向低地址扩展的数据结构，是一块连续的内存的区域。**这句话的意思是**栈顶的地址和栈的最大容量是系统预先规定好的**，在WINDOWS下，栈的大小是2M（也有的说是1M，总之是一个编译时就确定的常数），如果申请的空间超过栈的剩余空间时，将提示**overflow**。因此，能从栈获得的空间较小。
      
      ➢ 堆：**堆是向高地址扩展的数据结构，是不连续的内存区域。**这是由于系统是用链表来存储的空闲内存地址的，自然是不连续的，而**链表的遍历方向是由低地址向高地址**。堆的大小受限于计算机系统中有效的虚拟内存。由此可见，堆获得的空间比较灵活，也比较大。 
      
      + 申请效率的比较：
      
      ➢ 栈:**由系统自动分配，速度较快**。但程序员是无法控制的。
  
      ➢ 堆:是**由new分配的内存，一般速度比较慢，而且容易产生内存碎片,不过用起来最方便. **
      另外，**在WINDOWS下，最好的方式是用`Virtual Alloc`分配内存，他不是在堆，也不是在栈,而是直接在进程的地址空间中保留一块内存，虽然用起来最不方便。但是速度快，也最灵活**。
      
      + 堆和栈中的存储内容
  
      ➢ 栈：**在函数调用时，第一个进栈的是主函数中后的下一条指令（函数调用语句的下一条可执行语句）的地址，然后是函数的各个参数，在大多数的C编译器中，参数是由右往左入栈的，然后是函数中的局部变量。注意静态变量是不入栈的**。 
      当本次函数调用结束后，**局部变量先出栈，然后是参数，最后栈顶指针指向最开始存的地址，也就是主函数中的下一条指令，程序由该点继续运行**。
      
      ➢ 堆：一般是在**堆的头部用一个字节存放堆的大小**。堆中的具体内容由程序员安排。
  
      + 存取效率的比较
  
      ➢ `bss`段的大小,记录在段表里,记录的是所有未初始化变量总共的大小,`bss`段只在段表里有个记录,但实际并不存在这个段.，每个未初始化的变量的大小放在了符号表里。
  
      ➢ 更详尽的例子：
  
      ```c++
      #include <iostream>
      using namespace std;
      int a = 0;	// 初始化的全局变量:保存在数据段
      char *p1;	// 未初始化的全局变量:保存在BSS段
      int main() {
          int b;	// 未初始化的局部变量:保存在栈上
          char s[] = "abc";	
          /* "abc"为字符串常量保存在常量区；数组保存在栈上，并将常量区的"abc\0"复制到该数组中。这个数组可以随意修改而不会有任何隐患，而"123"这个字符串依然会保留在静态区中。*/
          char *p2;// p2保存在栈上
          char *p3 = "123456";// p3保存在栈上，"123456\0"保存在data区的read-only部分
          /* 声明了一个指针p3并指向"123456\0"在静态区中的地址，事实上，p3应该声明为char const *，以免可以通过p3[i]='\n'这一类的语法去修改这个字符串的内容。如果这样做了，在支持“常量区”的系统中可能会导致异常，在“合并相同字符串”的编译方法下会导致其它地方的字符串常量古怪地发生变化。
       */
          static int c = 0; // 初始化的静态局部变量:保存在数据区（数据段）
          p1 = (char *)malloc(sizeof(char) * 10); // 分配的10字节区域保存在堆上
          p2 = (char *)malloc(sizeof(char) * 20); // 分配的20字节区域保存在堆上
          strcpy(p1, "123456");
          // "123456\0"放在常量区，编译器可能会将它与p3所指向"123456"优化成一个地方
          return 0;
      }
      ```
      
    + 在函数**内部**定义局部变量
  
      ➢ `auto` 默认值 
  
      ➢ `register `
  
      ➢ `static` 
  
      ➢ `extern`
  
    + 在函数**外**定义全局变量
  
      ➢ `static` 
  
      ➢ `extern` 默认值
  
  + `const, int, *`定义变量时不同顺序的含义(➢ 被`const`约束的变量在定义时必须初始化)
  
    + **`const int *a`**
  
      **表示声明一个指向常量整数的整型指针`a`。`a`指针本身可以被修改，但是`a`指向的整数不能被修改。**
  
      ```cpp
      const int *a = 0;
      const int b = 1;
      int c = 2;
      
      a = &b;   // 正确，因为b是常量整数
      a = &c;   // 正确，这里c隐式转换为常量整数
      *a = 10;  // 编译错误，因为*a表示a指针指向的整数，是常量不能修改
      ```
  
    + **`int const *a`**
  
      `const`这里修饰的是`*a`，而`*a`表示取`a`指针指向的值，为一个整数且为常量。该写法和`const int *a`等价。
  
    + **`int *const a`**
  
      这里`const`后面是`a`，`const`修饰的是`a`，而`a`表示指针变量名。
  
      **所以`int *const a`表示声明一个整型的常量指针变量。`a`指针本身不能被修改，但是`a`指向的整数可以被修改。**
  
      ```cpp
      int a = 0;
      int * const b = &a;  // 正确。常量定义是必须初始化
      *b = 2;  // 正确，指针指向的值可以被修改
      const int c = 10;
      b = &c;  // 错误，指针b不能被修改赋值为其他地址
      ```
  
    + **`const int const *a`**
  
      **`const int const *a`表示`a`指针不能被修改，同时`a`指向的整数也不能被修改。还可以写成：`const int * const a`。**
  
    + **补充**
  
      - **`const int a`和`int const a`等价，都声明一个整型常量**
      - 常量对象的地址**只能赋值给**指向常量对象的指针
      - 非常量对象的地址**可以赋值给**指向常量对象的指针
      - 常量定义是必须被初始化，因为常量不能被修改
      - 指向常量的指针常用于作为类成员方法或者函数参数，使用引用传递的同时，保证引用参数不被修改
      
      **修改`const`**
  
      ```c++
      const int yy = 100;
      *(int *) &yy = 123;
      // 等价于：
      *const_cast<int *>(&yy) = 123;
      ```
      
    + `EG`:
  
      ```c++
      char * const *pcpc;
      char ** q;
      // 不能修改 *pcpc 中的内容；可修改 pcpc、 ** pcpc。
      char c;
      char * const cpc=&c;
      pcpc =&cpc;
      ```
  
      ```c++
      // 如何让p能指向q，或者另一个新申请的空间
      char* const p = new char[10];
      char q[20];
      // ans:
      *(char **)&p = q ;
      *(char **)&p = new char[20];
      *const_cast<char**>(&p) = q;
      *const_cast<char**>(&p) = new char[20];
      ```
  
      ```c++
      char* pc = “hello”; // 编译时报错
      // 无法从 const char[6] 转换为 char *
      
      // 更正：
      char* pc = (char *)“hello”; // 有风险
      // 直接通过 pc 修改只读数据区
      const char *pc = “hello”; // 也有风险
      // 通过 pc数据类型的转换,修改只读数据区
      pc[0] = ‘H’; // 编译报错
      *(char *)&(pc[0]) = ‘H’; // 运行报错
      *(char *)pc = ‘H’; // 运行报错
      *(char *)(pc + 1) = ‘H’; // 运行报错
      // ➢ 对于只读数据段中的数据，如“hello”这样的常量串，在运行时不得修改，否则程序崩溃!!!!!
      // 保险做法
      char pa[10] = “hello”; 
      char pa[] = “hello” 
      ```
  
    + 讨论优化：
  
      ```c++
      const int yy = 100;
      cout <<“yy = ”<< yy << endl; // 显示 yy = 100
      *(int*)& yy = 123;
      cout <<"yy = "<< yy << endl; // 显示的 yy =100
      /*
      编译器看到 yy 是一个const int, 又给定了值100；
      就认为 yy不再会改变，后面直接用 100来代换了 yy。
      *(int *)&yy语句是执行了的，调试时看得到yy=123;
      但 cout 的结果是 yy =100. 定义 const int yy=xx; 就无
      法给 yy 一个常量值。
      */
      ```
  
      ```c++
      int xx = 100;
      const int yy = xx;
      下面同样一段程序的执行结果不同
      cout << “yy = ” << yy << endl; // 显示 yy = 100
      *(int*)& yy = 123;
      cout << “yy = ” << yy << endl; // 显示 123
      ```
  
    + `const `与 `#define `相比，有何优点？
  
       `const `常量有数据类型，编译器可对其进行类型安全检查 
  
       宏常量无数据类型，没有类型安全检查 
  
       宏替换时，可能出现预想不到的错误 `#define doubled(x) x*2 doubled(1+2) = ？ `
  
       在调试时，可对`const `常量进行调试
  
  + 变量的存储可访问特性
  
    + ➢ `const` 
    + ➢ `constexpr` 
    + ➢ `volatile` 
    + ➢ `mutable`
  
    > `C++ 11`中新增加了用于指示[常量表达式](https://www.zhihu.com/search?q=常量表达式&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"article"%2C"sourceId"%3A20206577})的`constexpr`关键字。在这里区分两者的用法。
  
    `const`和`constexpr`都可以来修饰对象和函数。
  
    修饰**对象**的时候两者之间最基本的区别是：
  
    - `const`修饰一个对象表示它是**常量**。这暗示对象一经初始化就不会再变动了，并且允许编译器使用这个特点优化程序。这也防止程序员修改了本不应该修改的对象。
    - `constexpr`是修饰一个**常量表达式**。但请注意`constexpr`**不**是修饰常量表达式的**唯一途径**。
  
    修饰**函数**的时候两者之间最基本的区别是：
  
    - `const`只能用于**非静态成员的函数**而不是所有函数。它保证成员函数不修改任何非静态数据。
  
    - `constexpr`可以用于**含参和无参函数**。[constexpr函数](https://www.zhihu.com/search?q=constexpr函数&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"article"%2C"sourceId"%3A20206577})适用于常量表达式，只有在下面的情况下编译器才会接受`constexpr`函数： 
    1. 函数体必须足够简单，除了typedef和[静态元素](https://www.zhihu.com/search?q=静态元素&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"article"%2C"sourceId"%3A20206577})，只允许有return语句。如构造函数只能有初始化列表，typedef和静态元素 (**实际上在`C++14`标准中已经允许定义语句存在于`constexpr`函数体内了**) 
      
    2. **参数和返回值必须是字面值类型**
  
    **➢ 常量表达式的概念如下**
  
    必须是**可以在编译阶段被识别的**。比如模版的参数／数组的大小。
  
    ```c++
    template <int N>
    class fixed_size_list {
        /*...*/ 
    };
    fixed_size_list<X> mylist;     // <-- X必须是字面值类型
    int numbers[X];   // <-- X必须是字面值类型
    ```
  
    但是**注意**下面两点：
  
    + 用`constexpr`修饰某物并不保证它一定在编译时被计算，也可以在运行时被计算。
  
    + 不用`constexpr`也可能是一个常量表达式，如
  
      ```c++
      int main() {
      const int N = 3;
      int num[N] = {1,2,3,};// N是一个常量表达式
      }
      // N在声明时初始化，满足常量表达式的标准，虽然没用constexpr
      ```
  
      事实上，**`const`本身和它的枚举类型若在声明时初始化那么就是一个常量表达式。**
  
      **`constexpr`函数是在使用需要它的代码时，可以在编译时计算其返回值的函数。在函数中若有常量表达式那么必须用`constexpr`**，仅仅满足常量表达式的条件是不够的:
      
      ```c++
      template <int N>
      class list {
      };
      constexpr int sqr1(int arg) {
          return arg*arg; 
      }
      int sqr2(int arg) {
          return arg*arg; 
      }
      int main() {
          const int X = 2;
          list<sqr1(X)> mylist1;	// 可以，因为sqr1时constexpr函数
          list<sqr2(X)> mylist2;	// 不可以，因为sqr2不是constexpr函数
          return 0;
      }
      ```
  
  
    ➢ 在修饰变量的时候
  
    修饰变量时没有必要同时使用`const`和`constexpr` 因为`constexpr`包含了 `const`的含义
  
    ```c++
    constexpr const int N = 5;
    constexpr int N = 5;
    // 两行的意思完全相同
    ```
  
    ➢ 然而注意有一些情况`const`和`constexpr`在修饰不同的东西，比如
  
    ```c++
    static constexpr int N = 3;
    int main() {
        constexpr const int *NP = &N;
        return 0;
    }
    ```
  
    在这里`constexpr`和`const`都必须要有。**`constexpr`表示NP指针本身是常量表达式，而`const`表示指向的值是一个常量**。去掉`const`之后无法编译，因为不能用正常指针指向常量。
  
    - 在修饰[成员函数](https://www.zhihu.com/search?q=成员函数&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"article"%2C"sourceId"%3A20206577})的时候
  
    在`C++ 11`中，对成员函数而言`constexpr`同样包含`const`的含义。然而在`C++ 14`中可能已经改变了。如
  
    ```c++
    constexpr void f();
    ```
  
    以后可能必须写成
  
    ```c++
    constexpr void f() const;
    ```
  
    虽然目前写成`const`仍然有效，但最好使用`constexpr`来防止以后修改大量代码的可能性。
    > **`volatile`关键字**
    >
    > C/C++ 中的 `volatile` 关键字和 `const` 对应，用来修饰变量
    >
    > ➢ ` volatile `关键字是一种类型修饰符，用它声明的类型**变量表示可以被某些编译器未知的因素更改**，比如：操作系统、硬件或者其它线程等。遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问。
    >
    > 声明时语法：**`int volatile vInt;`** **当要求使用 `volatile` 声明的变量的值的时候，系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据。而且读取的数据立刻被保存。**
    >
    > `volatile`用在如下的几个地方：
    >
    > - **中断服务程序中修改的供其它程序检测的变量**需要加 `volatile`；
    > - **多任务环境下各任务间共享**的标志应该加 `volatile`；
    > - **存储器映射的硬件寄存器**通常也要加 `volatile` 说明，因为每次对它的读写都可能由不同意义；
    >
    > **➢ `volatile` 指针**
    >
    > 和 `const` 修饰词类似,`const`有常量指针和指针常量的说法，`volatile`也有相应的概念：
    >
    > + 修饰由指针指向的对象、数据是 `const` 或 `volatile` 的：
    >
    > ```c++
    > const char* cpch;
    > volatile char* vpch;
    > ```
    >
    > 注意：对于 VC，这个特性实现在 VC 8 之后才是安全的。
    >
    > + 指针自身的值(一个代表地址的整数变量)，是 `const` 或 `volatile` 的：
    >
    > ```c++
    > char* const pchc;
    > char* volatile pchv;
    > ```
    >
    > **注意：**
    >
    > - (1) 可以把一个`非volatile int`赋给`volatile int`，但是不能把`非volatile对象`赋给一个`volatile对象`。
    > - (2) 除了基本类型外，对用**户定义类型**也可以用volatile类型进行修饰。
    > - (3) **C++中一个有`volatile`标识符的类只能访问它接口的子集**，一个由类的实现者控制的子集。用户只能用`const_cast`来获得对类型接口的完全访问。此外，`volatile`向`const`一样会从类传递到它的成员。
    >
    > **➢ 多线程下的`volatile`**
    >
    > 有些变量是用 `volatile` 关键字声明的。**当两个线程都要用到某一个变量且该变量的值会被改变时，应该用 `volatile` 声明，该关键字的作用是防止优化编译器把变量从内存装入 CPU 寄存器中**。如果变量被装入寄存器，那么两个线程**有可能一个使用内存中的变量，一个使用寄存器中的变量，这会造成程序的错误执行**。`volatile` 的意思是让编译器每次操作该变量时**一定要从内存中真正取出，而不是使用已经存在寄存器中的值**，如下：
    >
    > ```c++
    > volatile  BOOL  bStop  =  FALSE;
    > ```
    >
    > (1) 在一个线程中：
    >
    > ```c++
    > while (!bStop)  {  ...  }  
    > bStop = FALSE;  
    > return;    
    > ```
    >
    > (2) 在另外一个线程中，要终止上面的线程循环：
    >
    > ```c++
    > bStop  =  TRUE;  
    > while (bStop);  
    > //等待上面的线程终止，如果bStop不使用volatile申明，那么这个循环将是一个死循环，因为bStop已经读取到了寄存器中，寄存器中bStop的值永远不会变成FALSE，加上volatile，程序在执行时，每次均从内存中读出bStop的值，就不会死循环了。
    > ```
    >
    > 这个关键字是用来设定某个对象的存储位置在内存中，而不是寄存器中。因为**一般的对象编译器可能会将其的拷贝放在寄存器中用以加快指令的执行速度**，例如下段代码中：
    >
    > ```c++
    > ...  
    > int  nMyCounter  =  0;  
    > for (; nMyCounter < 100; nMyCounter++) {  
    > ...  
    > }  
    > ...
    > ```
    >
    > 在此段代码中，`nMyCounter` 的拷贝可能存放到某个寄存器中（循环中，对 `nMyCounter` 的测试及操作总是对此寄存器中的值进行），但是另外又有段代码执行了这样的操作：**`nMyCounter -= 1;`** 这个操作中，对 `nMyCounter` 的改变是对内存中的 `nMyCounter` 进行操作，于是出现了这样一个现象：`nMyCounter` 的改变不同步。
  
    > **`mutable`关键字**
    >
    > **➢ 类中的 `mutable`**
    >
    > `mutable` 从字面意思上来说，是「可变的」之意。
    >
    > 若是要「顾名思义」，那么这个关键词的含义就有些意思了。显然，「可变的」只能用来形容变量，而不可能是「函数」或者「类」本身。然而，既然是「变量」，那么它本来就是可变的，也没有必要使用 `mutable` 来修饰。**那么，`mutable` 就只能用来形容某种不变的东西了。**
    >
    > C++ 中，不可变的变量，称之为常量，使用 `const` 来修饰。然而，若是 `const mutable` 联用，未免让人摸不着头脑——到底是可变还是不可变呢？
    >
    > 事实上，`mutable` 是用来修饰一个 `const` 示例的部分可变的数据成员的。如果要说得更清晰一点，**就是说 `mutable` 的出现，将 C++ 中的 `const` 的概念分成了两种**。
    >
    > - 二进制层面的 `const`，也就是「绝对的」常量，在任何情况下都不可修改（除非用 `const_cast`）。
    > - 引入 `mutable` 之后，C++ 可以有逻辑层面的 `const`，也就是对一个常量实例来说，从外部观察，它是常量而不可修改；但是内部可以有非常量的状态。
    >
    > > 当然，所谓的「逻辑 `const`」，在 C++ 标准中并没有这一称呼。这只是为了方便理解，而创造出来的名词。
    >
    > **显而易见，`mutable` 只能用来修饰类的数据成员；而被 `mutable` 修饰的数据成员，可以在 `const` 成员函数中修改**。
    >
    > 这里举一个例子，展现这类情形。
    >
    > ```c++
    > class HashTable {
    >  public:
    >     //...
    >     std::string lookup(const std::string& key) const {
    >         if (key == last_key_) {
    >             return last_value_;
    >         }
    > 
    >         std::string value {
    >             this->lookupInternal(key)
    >         };
    > 
    >         last_key_   = key;
    >         last_value_ = value;
    > 
    >         return value;
    >     }
    > 
    >  private:
    >     mutable std::string last_key_
    >     mutable std::string last_value_;
    > };
    > ```
    >
    > 这里，我们呈现了一个哈希表的部分实现。显然，对哈希表的查询操作，在逻辑上不应该修改哈希表本身。因此，`HashTable::lookup` 是一个 `const` 成员函数。在 `HashTable::lookup` 中，我们使用了 `last_key_` 和 `last_value_` 实现了一个简单的「缓存」逻辑。当传入的 `key` 与前次查询的 `last_key_` 一致时，直接返回 `last_value_`；否则，则返回实际查询得到的 `value` 并更新 `last_key_` 和 `last_value_`。
    >
    > 在这里，`last_key_` 和 `last_value_` 是 `HashTable` 的数据成员。按照一般的理解，`const` 成员函数是不允许修改数据成员的。但是，另一方面，`last_key_` 和 `last_value_` 从逻辑上说，修改它们的值，外部是无有感知的；因此也就不会破坏逻辑上的 `const`。为了解决这一矛盾，我们用 `mutable` 来修饰 `last_key_` 和 `last_value_`，以便在 `lookup` 函数中更新缓存的键值。
    >
    > **➢ Lambda 表达式中的 `mutable`**
    >
    > C++11 引入了 `Lambda` 表达式，程序员可以凭此创建匿名函数。在 Lambda 表达式的设计中，捕获变量有几种方式；其中按值捕获（`Caputre by Value`）的方式不允许程序员在 Lambda 函数的函数体中修改捕获的变量。而以 `mutable` 修饰 Lambda 函数，则可以打破这种限制。
    >
    > ```cpp
    > int x{0};
    > auto f1 = [=]() mutable {x = 42;};  // okay, 创建了一个函数类型的实例
    > auto f2 = [=]()         {x = 42;};  // error, 不允许修改按值捕获的外部变量的值
    > ```
    >
    > 需要注意的是，上述 `f1` 的函数体中，虽然我们给 `x` 做了赋值操作，但是这一操作仅只在函数内部生效——即，实际是给拷贝至函数内部的 `x` 进行赋值——而外部的 `x` 的值依旧是 `0`。
  
  + `strlen(“abc”) == 3`，但要4个字节存储
  
  + ```c++
    x ：int
    &x    : int* 
    *(&x) : int
    (char *)&x : char*
    *(char *)&x : char
    ```
  
   + `&x` 表示地址，右值，无法`&(&x)`
  
   + `&x = 0x008ffa24` ×，不能将` int `转换为 `int* `
  
   + `&x = (int *)0x008ffa24` ×，=左操作数必须为左值，表达式必须是可修改的左值 
  
   + ```c++
     int y[5];
     &y[0] == (int*)&y[0] == (int*)y == (int*)&y
     ```
  
   + ```c++
     int z[3][4];
     int *q[3]; // 每个元素是指针,指针数组
     int (*w)[4]; // 数组指针
     w = z; // 行指针，指向Zd
     w = &(z[0]);
     w = (int(*)[4])&z[0][0];
     w = (int(*)[4])z[0];
     // 备注：
     &z[0] == &z[0][0] == z[0] == z == &z;
     
     int* m[10][20];
     int (*n)[10][20];
     指针数组
     ➢ 本质是数组
     ➢ 每个元素是一个指针
     ➢ 分配 10 * 20 * 4个字节的空间
     数组指针
     ➢ 本质是一个指针
     ➢ 只是一个变量
     ➢ 指向的是一个数组
     ➢ 分配 4 个字节的空间
     ```
  
   + 二级指针
  
     ```c++
     int x = 10;
     int *p1 = &x;
     int **p2;
     p2 = &p1;
     // 正确：
     **p2 = 20;
     *(&(*(&x))) = 20;
     // 错误：
     **(&(&x)) = 20;
     ```
  
   + ```c++
     char s[10] = "12345";
     printf("%c %x\n", *s, *s);
     printf("%d %x\n", *(short *)s, *(short*)s);
     printf("%d %x\n", *(int *)s, *(int *)s);
     // ans:
     1 31
     12849 3231
     875770417 34333231
         
     union data {
         char s[10];
         int x;
         short y;
         char c;
     };
     union data myUnion;
     strcpy_s(myUnion.s, "12345");
     printf("%c %x\n", myUnion.c, myUnion.c);
     printf("%d %x\n", myUnion.y, myUnion.y);
     printf("%d %x\n", myUnion.x, myUnion.x);
     // ans:
     1 31
     12849 3231
     875770417 34333231
     ```
  
   + ```c++
     0x 开头，十六进制 
     0 开头，八进制 
     0b 开头，二进制
     ```
  
   + ```c++
     ➢ 字节少的类型 向 字节多的类型转换:
     step 1：短变长，它的有/无符号特性保持不变；
     step 2：相等长度直接赋值
     ➢ 相同长度的有/无符号 整数类型的转换:直接复制拷贝 （int  float, 要进行类型转换）
     ➢ 长度长的类型向短类型转换:截断
     ```
  
   + ```c++
     ➢ if ( c1 + s1 + i1 + c2 + s2 + i2 > 3) …..
     最后的比较 运算 是 无符号比较
     ➢ if ( x > y ) ….. x，y 一个有符号，一个无符号
     无符号比较
     warning C4018: “>”: 有符号/无符号不匹配
     ➢ if ( x > 5 ) ….. 一个有类型，一个是无类型的数值
     按 明确的类型 进行比较
     ➢ 乘、除运算，若有一个运算数是有符号的，则采用 有符号 运算
     ```
  
   + 引用：
  
     + 有址引用`&`
  
       ```c++
       int x=10;
       int &y; // 错误语句，必须初始化引用
       int &y = 20; //错误语句，无法从“int”转换为“int &”
       int &y = (int *)malloc(sizeof(int)); // 无法从“int *”转换为“int &”
       y = &x; // 错误语句，无法从 int * 转换为 int
       int &y = x;
       int &y = *(int *)malloc(sizeof(int));
       ```
  
       ➢ 定义引用变量时就一定要正确初始化； 
  
       ➢ **引用变量中存放的是被引用变量的地址； 其本质是指针； **
  
       ➢ **在有串接（多级）引用时，都是指向最终被引用的变量； 与二级（多级）指针有很大的差别；** 
  
       ➢ 使用引用变量，**操作对象都是被引用的变量**
  
       ```c++
       // 返回结果为引用
       int& f( ) {
       	int t = 25;
       	return t;
       }
       int g() {
           int t = 25;
       	return t;
       }
       int& ff(int t) {
       	int *p = (int *)malloc(sizeof(int));
       	*p = t + 10; 
       	return *p;
       }
       
       int a = f();	// 执行后 a=25; f 函数编译有警告
       int &b = f();	// 执行后b 中的内容 为 t 的地址
       int y = g();	// 执行后 a=25,但实现的方法不同
       int &v = g( ); 	// × 无法从int 转换为 int &
       // &v 是有址引用；
       // int &v 是传统左值有址引用
       // 故 = 右边应为有址左值
       
       a = f(10) + f(20);
       // 显示 a = 60
       /*
       先执行 f(10), 返回函数f中变量t的地址
       再执行 f(20), 返回函数f中变量t的地址
       根据第1个返回地址，取相应单元的内容，为 30
       根据第2个返回地址，取相应单元的内容，为 30
       故 a =60
       */
       b = f(20) + f(10);
       // 显示 b = 40
       
       // 返回结果为引用
       a = ff(10) + ff(20) ;
       // 显示 a = 50
       b = ff(20) + ff(10);
       // 显示 b = 50
       // ff()删除引用 & 后，结果同样正确!!!!!!
           
       // 类比：
       int x=10;
       int &y = x;	// y中内容是x的地址
       int u = y;	// u中内容 = x中的内容，即 10
       int &v = y; // v中内容是x的地址
       // 与传统指针相比： 
       int a; 
       int &y = a : int *p = &a; 
       int u = y : int u = *p; 
       int &v = y ：int &v = (*p);
       ```
  
       ➢ 指针和引用有什么差别？ 
  
       ➢ 传引用比传指针安全，为什么？
  
       + 引用在创建时，必须初始化，即引用到一个有效的对象； 指针在定义时，可以不**初始化** 
       + 指针可以为`NULL` ；**引用必须与合法的存储单元关联，不存在`NULL`引用 **
       + 引用一旦被初始化为指向一个对象，就不能再改变为另 一个对象的引用；指针是可变的
  
       ```c++
       int *p = (int *)malloc(10 * sizeof(int));
       int &q = *(int *)malloc(10 * sizeof(int));
       p[i] = 20; 
       *(p+i) = 20; 
       *(&q+i) = 20; => *(&(*p)+i)=20 => *(p+i)=20;
       // 使用 q 相当于 *p;
       // p本身可改； 
       p = *(int *)malloc(20 *sizeof(int)); 
       // q本身不可改; 
       q = 20; // 实际上改的是 q 引用的单元
       ```
  
       ```c++
       int x;
       const int p =  x;
       int* const q = &x; 
       *(int **)&q = &x;
       (int *&)q = &x;
       ```
  
     + 无址引用`&&`
  
       `int &&x = 2；` `const int &&w = 3;`
  
     + **➢ 有址引用** 
  
       一般：被引用的对象有地址 `int x; int &y = x;` 可通过引用变量修改，引用变量是一个左值; (传统左值有址引用) 
  
       特殊：被引用的对象有地址`int x; const int &y = x; `**不能通过引用变量y修改,引用变量是一个右值**；(传统右值有址引用) 
  
       特 例： `const int &w = 2;` **不允许 `int &w = 2`;** **被引用对象存放在一个临时地址单元中；是一个无名地址；不能通过引用变量去修改**，传统右值有址引用 (更合适的说法：传统右值无址引用，`const int &&w = 2`)
  
       **➢ 无址引用**
  
       一般：被引用的对象**无（有名）地址，可通过引用变量修改**，引用变量是一个左值； (传统左值无址引用) `int &&x = 2; x = 3;` 
  
       特殊： 被引用的对象无地址, 不能通过引用变量修改，引用变量是一个右值； 传统右值无址引用 `const int && y = 4;  `
  
       ```c++
       int p; int &&q = p;	// 错，被引用对象有（有名）地址 
       const int p = 10; const int &&q = p; //错，被引用对象有地址
       ```
  
   + **枚举**
  
     ```c++
     enum WEEKDAY {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
     WEEKDAY z = Sun;
     ```
  
   + **数组**
  
     ```c++
     char c[6] = “abc”; 
     sizeof(c) == 6;
     strlen(c) == 3; // 不是4！
     
     char d[ ] = “abc”; 
     sizeof(d) == 4;
     
     const char* p = “abc”;
     sieof(p) == sizeof(void*) == 4, 
     p[0] == ‘a’,
     // “abc”看作字符指针
     “abc”[0] == ‘a’;
     *(“abc” + 1) == ‘b’。
     ```
  
   + **结构与联合**
  
     + 结构
  
       ```c++
       struct Person {
       	char* name;
       	int birthYear;
       	double salary;
       };
       Person zhang = {NULL, 1995, 100}, *p;
       
       Q：能否 Person zhang = {"ZhangSan",1995,100};?
       × 无法从 const char[9]转换为 char *;(const char* → char*)
        
       Q：能否 Person zhang = {(char *)"ZhangSan", 1995, 100};?
       语法正确，但后面若修改 zhang 的 name 指向的串，会导致程序崩溃。 strcpy_s(zhang.name, 6, “xu”);
       
       Q：能否 char* q = (char *)malloc(10);
       	   Person zhang = {q, 1995, 100}; ?
       zhang.name 与 q 指向相同的空间，当q指向的空间释放或修改，或者反过来，都会对另一方产生影响，极不安全，或者程序崩溃（如释放q, 再释放 zhang.name）;
       
       Q：能否 char q[10];
       	   Person zhang = {q, 1995, 100}; ?
       问题同上,只是q空间的分配方式有所变化;
       此外，执行 free(zhang.name) 会直接崩溃,因为空间不是分配在堆中。
       
       Q：zhang.name 正确的初始化的方法是什么？
       可以先初始化为一个空指针:zhang.name = NULL; 
       为指针分配要执向的空间；通过串拷贝等方式，为指针指向的空间赋值。
       zhang.name = (char *)malloc(10);
       strcpy_s(zhang.name, 10, ”xu”);
       ```
  
       **在结构体或者联合体中以位为单位定义成员变量所占的空间**
  
       ```c++
       struct A {
       	int i:3; // i为位段成员
       	int j:4; // j为位段成员
       	int k;
       } a; 
       // sizeof(a) == 8;
       a.i = 6;
       a.J = 9;
       // a的一个字节存放的数字：
       // 1 0 0 1 1 1 0
       // 1 0 0 1 指 9，j占四个位
       // 1 1 0 指 6，i占3个位
       ```
  
     + 联合
  
+  `80X86`系列汇编语言

  + 32位的寄存器

    > `EAX`、`EBX`、`ECX`、`EDX`、`ESI`、`EDI`、`EBP`、`ESP`

  + 6 种寻址方式 

    > 立即寻址 直接寻址 寄存器寻址 寄存器间接寻址 变址寻址 基址加变址寻址

+ **语法图**及**程序流程图**

  + ![image-20211206120423340](https://s2.loli.net/2021/12/07/fGRsEJxLzdvnr9q.png)

  + 标识符是由**下划线或字母**开始，后跟任意个由**下划线、字母、数字**组成的字符序列。

    **标识符**的语法图

    ![image-20211206120549618](https://s2.loli.net/2021/12/07/ZVfCboy9lTP5smq.png)

  + **程序流程图**

    ![image-20211206121415968](https://s2.loli.net/2021/12/08/fgriwunTlROsQo1.png)

+ **语句与函数**

  + ```c++
    // switch中再开一个{}可以定义变量
    switch (val) {  
    	case VAL: {
      		// This will work
      		int newVal = 42;  
      		break;
    	}
    	case ANOTHER_VAL:  
    		...
    		break;
    }
    ```

  + ```c++
    // 函数指针
    int fadd(int a, int b) { 
        cout << "add"; 
        return a + b; 
    }
    int fsubtract(int a, int b) { 
        cout << "subtract"; 
        return a - b; 
    }
    int (*q)(int, int) ; // 定义一个函数指针变量
    q = fadd; q = &fadd; // 等同写法
    int (*p[2])(int, int) = { fadd, fsubtract }; 函数地址表
    int z = p[i](20, 30); // i=0， 执行fadd
    ```

  + ```c++
    static_assert 
    用于提供静态断言服务，即在编译时判定执行条件是否满足，不满足则编译报错，输出相应的信息。
    static_assert(条件表达式，”输出信息”);
    程序运行之中的断言，条件不满足，运行异常中断。
        
    #include <assert.h>
    assert(条件表达式);
    ```

  + **函数**

    > **全局函数：**可被任何程序文件(`.cpp`)的程序调用， 只有全局main函数不可被调用。 
    >
    > **内联函数：** `inline` 可在程序文件内或类内说明或定义， 只能被当前程序文件的程序调用, 它是**文件局部作用域的**，可被编译优化(掉）。 
    >
    > **静态函数**： `static` 可在程序文件内或类内说明或定义, **类内的静态函数不是文件局部作用域的**， 程序文件内的静态函数是文件局部作用域的。
    >
    > > 调用老版本函数，注意在文件最开头加：` #define _CRT_SECURE_NO_WARNINGS`
    >
    > ```c++
    > int sum(int n, …) { 
    >     s=0;
    > 	int *ap;
    > 	ap=&n+1;
    > 	for (int k=0; k<n; k++)
    > 		s+=ap[k];
    > 	return s;
    > }
    > // 等价于：
    > int sum(int n, ...) { 
    >     int s = 0;
    > 	va_list ap;			// typedef char* va_list; 
    > 	va_start(ap, n); 	// ap=&n+1;
    > 	for (int k = 0; k < n; k++)
    > 		s += va_arg(ap, int); // s+=*ap; ap +=4;
    > 	va_end(ap); // ap = 0;
    > 	return s;
    > }
    > 
    > // typedef char* va_list; 
    > va_start(ap, n); // ap = (char *) &n +4;
    > #define va_start __crt_va_start
    > #define __crt_va_start(ap, x)
    > ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), __crt_va_start_a(ap, x)))
    > #define __crt_va_start_a(ap, v)
    > ((void)(ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v)))
    > 
    > va_arg(ap, int); // ap += 4;  *(int *)(ap-4)
    > #define va_arg __crt_va_arg
    > #define __crt_va_arg(ap, t)
    > (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
    > ```
    >
    > > 在**编译**函数调用语句时，生成了默认参数的传递语句。 通过将默认的实参值传递给形参，实现形参的初始化。(参数的值拷贝到一个临时空间，从临时空间取数作为参数)
    >
    > ```c++
    > void fr(int &u, int &v) {
    > 	cout << "u= " << u << " v = " << v << endl;
    > 	u = 20; v = 30;
    > } 
    > void frr(int &&u, int &&v) {
    > 	cout << "u= " << u << " v = " << v << endl;
    > 	u = 20; v = 30;
    > } 
    > void fcr(const int & u, const int & v) { 
    >     cout << "u= " << u << " v = " << v << endl;
    > 	// 不能修改 u、 v 引用的对象
    > }
    > 
    > // case 1:
    > int main() {
    > 	int x = 3, y = 4;
    > 	fr(++x, ++y); // 显示 u =4, v=5
    > 	cout << "x= " << x << " y = " << y << endl;
    > 	return 0; // 显示 x=20 y =30
    > }
    > // case 2:
    > int main() {
    > 	int x = 3, y = 4;
    > 	fr(x++, y++); // 语法错误，无法从int转换为int &
    > 	cout << "x= " << x << " y = " << y << endl;
    > 	return 0;
    > } 
    > // case 3:
    > int main() {
    > 	int x = 3, y = 4;
    > 	frr(x++, y++);
    > 	cout << "x= " << x << " y = " << y << endl;
    > 	return 0;  // 显示 x =4, y=5
    > } 
    > // case 4:
    > fcr(x++, y++); // 正确
    > ```
    >
    > **线程互斥及线程本地变量**
    >
    > ```c++
    > #include <iostream>
    > #include <thread>
    > #include <mutex>
    > using namespace std;
    > int counter = 0; //➢ 多线程共享一个全局变量 counter
    > mutex mtx;
    > void increase(int time) {
    > 	for (int i = 0; i < time; i++) {
    > 		// 当前线程休眠1毫秒
    > 		this_thread::sleep_for(chrono::milliseconds(1));
    > 		mtx.lock();
    > 		counter++;
    > 		mtx.unlock();
    > 		cout << " " << counter << " ";
    > 	}
    > }
    > int main(int argc, char** argv) {
    > 	std::thread t1(increase, 200);
    > 	std::thread t2(increase, 200);
    > 	t1.join();
    > 	t2.join();
    > 	cout <<endl<<"over counter = "<<counter<<endl;
    > 	return 0;
    > }
    > // Counter的总数是400，但显示的顺序不一定，如2在1前，20在19前等等
    > // 将increase函数中的 counter 显示也加入封锁段，显示完全是顺序的。
    > ```
    >
    > 
    >
    > **作用域**
    >
    > **`全局作用域`** 程序可由若干代码文件构成，整个程序为全局作用域。全局变量和函数属于此作用域。 
    >
    > **`代码文件作用域` **函数外的static变量和函数属此作用域。 
    >
    > **`函数体作用域` **函数局部变量和函数参数属于此作用域。
    >
    > 在函数体内又有更小的**`复合语句块作用域`**
    >
    > 最小的作用域是**`数值表达式`**：常量在此作用域。
    >
    > ```c++
    > #include <iostream>
    > using namespace std;
    > // 栈编程实例
    > struct STK {
    > 	int* e;
    > 	int v;
    > 	int t;
    > };
    > void create(STK* const stk, int v) {
    > 	stk->e = (int*)malloc(sizeof(int) * v);
    > 	stk->v = stk->e ? v : 0;
    > 	stk->t = 0;
    > }
    > STK* const push(STK* const stk, int x) {
    > 	if (stk->t >= stk->v) {
    >         return 0;
    >     }
    > 	stk->e[stk->t++] = x;
    > 	return stk;
    > }
    > int main() {
    > 	STK s;
    > 	STK s1;
    > 	create(&s, 10);
    > 	create(&s1, 10);
    > 	push(&s, 5);
    > 	push(push(push(&s, 9), 10), 15);
    > 	*push(&s, 20) = s1; 
    >     /*
    >     Q： 执行 *push(&s, 20) = s1;s 中的数据会有何变化？
    >     STK * push = stk;
    >     STK * const stk = &s;
    >     *push = s1; // <=> *stk = s = s1;
    >     */
    >     /*
    >     Q： 能否 写 push(&s, 15) = &s1; ？
    > 	= 的左操作数必须为左值。
    > 	无论 push前是否加 const, 它自动的是 const.
    > 	准确的类比
    > 	STK * const push = stk; // STK * const stk = &s;
    > 	push = &s1;
    >     */
    > 	return 0;
    > }
    > ```
    >
    
  + 
  
+ **类**

  ```c++
  struct Student {
  	char name[10];
  	short age; 
      float score;
  	char* remark;
  	Student(const char* name, short age, float score, const char* remark) { 
          int len;
  		strcpy(this->name, name);
  		(*this).age = age; 
  		Student::score = score;
  		len = strlen(remark);
  		this->remark = (char *)malloc(len + 1);
  		strcpy(this->remark, remark);
  	}    
      ~Student() {
  		if (remark) {
  			free(remark);
  			remark = NULL;
  		}
  	}
  };
  
  // 赋值函数
  // 1
  struct Student* Assign(struct Student* t, const struct Student* s) {
  	strcpy(t->name, s->name);
  	t->age = s->age;
  	t->score = s->score;
  	int len = strlen(s->remark) + 1;
  	if (t->remark) free(t->remark);
  	t->remark = (char *)malloc(len);
  	strcpy(t->remark, s->remark);
  	return t;
  } 
  Assign(&xu, &zhang);
  
  // 2
  Student& Student::Assign(const Student &s) {
  	strcpy(name, s.name);
  	age = s.age;
  	score = s.score;
  	int len = strlen(s.remark) + 1;
  	if (remark) {
          free(remark);
      }
  	remark = (char*)malloc(len);
  	strcpy(remark, s.remark);
  	return *this;
  } 
  xu.Assign(zhang);
  
  // 3
  Student& Student::operator = (const Student& s) {
  	strcpy(name, s.name);
  	age = s.age;
  	score = s.score;
  	int len = strlen(s.remark) + 1;
  	if (remark) {
          free(remark);
      }
  	remark = (char*)malloc(len);
  	strcpy(remark, s.remark);
  	return *this;
  }
  xu = zhang; 
  // 用 operator = 代替了函数 Assign. 赋值运算符重载
  ```

  + **`析构函数`** 只有**一个**析构函数； 函数名与类型相同，前面加 ~；**无返回； 无参数;** 可以写析构函数的调用语句；析构函数**并不释放**对象本身的空间； 只是做释放体外空间等工作。

    **`构造函数` **有**多个**构造函数； 函数名与类型相同； 无返回； 多种参数，以**支持重载**； 只能自动调用； **构造函数并不申请对象本身的空间； 只是做空间初始化等工作**。

    ```c++
    struct Student {
    	char name[10];
    	short age;
    	float score;
    	char* remark;
    	Student(const char* name, short age, float score, const char* remark);
    	Student(); // 无参的构造函数
    	void display_remark();
    	int get_age();
    	Student& operator =(const Student& s);
    	~Student();
    };
    
    Student::Student(const char* name, short age, float score, 
    const char* remark) {
    	int len;
    	if (name) {
            len = strlen(name);
    		if (len <= 9) {
                strcpy(this->name, name);
            } else { 
            	cout << "name is too long; cut string" << endl;
    			memcpy(this->name, name, 9);
    			this->name[9] = 0; 
            }
    	} else {
            this->name[0] = 0;
        }
    	(*this).age = age;
    	Student::score = score;
    	if (remark) { 
            len = strlen(remark);
    		this->remark = (char*)malloc(len + 1);
    		strcpy(this->remark, remark);
    	} else {
            this->remark = NULL;
        }
    }
    
    Student::Student() {
    	name[0] = 0;
    	age = 0;
    	score = 0;
    	remark = NULL;
    }
    
    Student::~Student() {
    	if (remark) {
    		free(remark);
    		remark = NULL;
    	}
    	cout << "deconstruct :" << name << endl;
    }
    
    void Student::display_remark() { 
        cout << "remark : " << remark << endl; 
    }
    
    int Student::get_age() { 
        return age; 
    }
    
    Student& Student::operator =(const Student& s) {
    	strcpy(name, s.name);
    	age = s.age;
    	score = s.score;
    	int len = strlen(s.remark) + 1;
    	if (remark) free(remark);
    	remark = (char*)malloc(len);
    	strcpy(remark, s.remark);
    	return *this;
    }
    
    #include "Student.h"
    #include <iostream>
    using namespace std;
    int main() { 
        Student xu("xuxy123456789012", 21, 90, "very good student");
    	Student zhang(0, 22, 95, 0);
    	Student yang; // 无参构造函数
    	Student li("lishi",20,85,"good");
    	Student ma(li); 
        // 以对象为参数的构造函数，实现浅拷贝
        /*
        默认的以对象有址引用为参数的构造函数
        Student stu2(stu1);
        简单地将 stu1 中变量空间中的内容都拷贝到 stu2 的变量中。
        浅拷贝存在的问题
        此空间在对象之外
        */
    	yang = zhang = xu;
    	cout << "xu . name " << xu.name << endl;
    	cout << "zhang . score = " << zhang.score << endl;
    	cout << "yang . remark =" << yang.remark << endl;
    	zhang.display_remark();
    	int x = zhang.get_age();
    	cout << "zhang . age = " << x << endl;
    	return 0;
    }
    
    // 默认的以对象无址引用为参数的构造函数
    Student(const Student& s);
    Student(Student&& s);
    ```

    **构造函数 **

    > + 执行到定义对象的代码时，被自动调用 
    >
    >   对于全局对象，在执行main()之前被自动调用
    >
    > + 当类中未定义构造函数时，编译器提供三个默认的构造函数：
    >
    >   无参构造函数、以对象引用为参数的构造函数 以对象无址引用为参数的构造函数
    >
    > + 当类中定义了构造函数时，不再提供默认的无参构造函数；
    >
    >   此时，若只定义一个对象，则必须定义一个无参的构造函数；
    >
    >    但此时依然提供默认的以对象引用为参数的构造函数；
    >
    > + 默认的以对象为参数的构造函数，实现的方式是简单拷贝(浅拷贝），对于指针成员，则会指向相同的空间

    无参构造函数 `类名();` 

    以对象有址引用为参数的构造函数 `类名(const 类名 &);` 

    以对象无址引用为参数的构造函数 `类名(类名 &&); `

    默认的三个构造函数的功能（以及取代） 

    **析构函数** 

    析构函数 `~类名(); `

    默认的析构函数的功能 

    **赋值函数** 

    以对象有址引用为参数的赋值函数 `类名 & operator = (const 类名 &); `

    以对象无址引用为参数的赋值函数 `类名 & operator = (类名 &&); `

    默认的二个赋值函数的功能 

    **隐含的参数** `this`

  + **类保留字**：`class`、`struct`或`union`可用来声明和定义类

  + **类的申明**： `class `类型名

  + 类的定义体花括号后要有分号作为结束标志

  + `private`：私有成员, 仅可被**本类**的函数成员访问 不能被派生类、其它类和普通函数访问 

    `protected`：受保护成员 可被**本类和派生类**的函数成员访问 不能被其它类函数成员和普通函数访问

    `public`：公有成员 可被任何函数成员和普通函数访问

    > `class`定义的类缺省访问权限为`private` 
    >
    > `struct`和`union`定义的类缺省访问权限为`public`

    **成员访问突破方法**

    ```c++
    class Student {
    private:
        int number;
        float score;
    public:
        char name[15];
    public:
        Student(int number, char *name, float score); //声明
        Student();
        void Modify(float score) {
            //声明与定义
            Student::score=score;
        }
        void Print(); // 在体外定义init 与 Print
    };
    
    int main(int argc, char* argv[]) {
    	Student stu1, stu2;
    	strcpy_s(stu1.name,”xu”);
    	stu1.number = 123; // ×
    	// error C2248: ‘number' : cannot access private member declared in class 'Student'
    	return 0;
    }
    
    // 用强制类型转换方法修改常变量
    *(int *)&stu1 = 123; // 用强制类型转换 number
    *((float *) &stu1+1)=99.5; // 未直接私有成员number,访问 score
    
    //用非正规方法访问私有成员
    // 定义一个结构，字段与类相同，然后转换为该结构类型
    struct TROJAN_HORSE {
    	int number;
    	float score;
    	char name[15];
    };
    ((TROJAN_HORSE ) &stu1) ->score = 99.9;
    
    ```

  + **内联**

    > success:
    >
    > ➢ 在类体内定义的**任何函数成员**都会自动内联； 
    >
    > ➢ 在**类内或类外 **使用`inline`保留字说明函数成员；
    >
    > failed:
    >
    > 如果函数有如下情况，则不会内联； 即使有 `inline `, 编译器也对`inline `视而不见:
    >
    > ➢ 有分支类型语句 **分支、循环、开关、函数调用**等； 
    >
    > ➢ **在定义函数体之前，就已被调用的函数**；
    >
    > ➢ 被定义为**虚函数或者纯虚函数**。

  + **匿名类** 定义类时，没有给出类名。

    ➢ 不可能在类体外定义成员函数；无法写 类名::函数名 

    ➢ **无法定义构造函数和析构函数；函数名与类名相同 **

    ➢ 定义匿名类的对象，**对象的使用与非匿名类相同**

    **无对象的匿名联合**

    ➢ 联合 → union 

    ➢ 匿名 → 定义union时，未给出名字 

    ➢ 无对象 → 定义union 时，未定义相应的对象 

    `union A { int x; int y; }a; `

    `union { int x; int y; } temp; `

    **无对象的匿名联合:`static union { int x; int y; };`**

    >  类似于：` static int x; static int &y=x;`

    ➢ 各个数据成员共享存储空间： **即地址相同，类型可以不同** 

    ➢ 成员与联合本身的**作用域**相同 

    ​	函数内定义的 `union`: 成员相当于函数内的**局部变量**； 

    ​	函数外定义的 `union`：成员相当于模块内的**静态变量**；

    ➢ 只能定义公开数据成员（即权限为 `public`）;

    ➢ **函数外**的无对象的匿名联合，存储特性是static, **`union`前必须有`static`;**

    ➢ **函数内**的无对象的匿名联合，union 可以有 static，**也可以无static**; 数据成员分别对应 静态局部变量、局部变量。

  + 位段：有几个二进制位来表示某种信息

    ```c++
    class SWITCH {
    	public:
    	int power:3;
    	int water:5;
    	int gas:4;
    }
    ```

  + `new `: 申请空间 自动调用构造函数初始化 

    `delete `: 自动调用析构函数 释放空间

    `malloc`: 申请空间

    `free `: 释放空间

    对于 **简单类型(没有构造、析构函数)**指针分配和释放内存 

    ➢ `new`和`malloc`、`delete`和`free`没有区别 

    ➢ 可混合使用，如`new`分配的内存用`free`释放。

    ```c++
    class ARRAY { //class体的缺省访问权限为private
    private:
    	int r , c; // 行数, 列数
    	int *a, // 数组元素存放区
    public: 
    	ARRAY(int x, int y) { 
    		r=x; 
            c=y;
    		a=new int[x * y]; // int型可用malloc
    	} 
    	~ARRAY() {
    		if (a) { 
    			delete []a; //可用free, 也可用delete a
    			a=0;
    		} 
    	}
    };
    
    // 对象数组初始化
    int x[5]; 	// 整数数组 x[0],x[1],x[2]…
    ARRAY q[5]; // 对象数组 q[0],q[1],q[2]…
    // 使用无参数的构造函数
    int x[5] = {0,1,2,3,4}; 
    ARRAY q[5] = {{对象q[0]的构造参数},……}; 
    ARRAY q[5] = {ARRAY(对象q[0]的构造参数),……}; 
    
    int x[5] {0,1,2,3,4}; 
    ARRAY q[5] {{对象q[0]的构造参数},……}; 
    
    int x[5] = {0,1}; 
    ARRAY q[5] = {{对象q[0]的构造参数}};// q[1],…,q[4] 要采用无参数的构造函数
    
    int ia[10]; // 整数数组 ia[0],ia[1],ia[2]…
    ARRAY oa[10]; // 对象数组 oa[0],oa[1],oa[2]…
    
    int *ap = new int[10]; // 数组指针
    ARRAY *aq = new ARRAY[10]; // 对象数组指针
    ARRAY *sq = new ARRAY(5,7); // 对象指针
    
    delete <指针> :
    delete sq;
    ▪ 指针指向非数组的单个实体
    ▪ 如sq指向对象，则自动调用析构函数，再释放对象所占的内存;
    
    delete [] <数组指针> :
    delete [] aq;
    ▪ 指针指向任意维的数组时使用
    ▪ 对所有对象(元素)自动调用析构函数。
    ▪ 若数组元素为简单类型，则可用delete <指针>代替;
        
    ```

  + `this`是一个隐含的`const`指针，不能移动或对该指针赋值。

    类的静态函数成员没有隐含的`this`指针。

    ```c++
    class TREE{
    	int value; 
    	TREE *left, *right;
    public:
    	TREE (int); 
    	~TREE( ); //this类型: TREE * const this
    	const TREE *find(int)const; //this类型: const TREE * const this
    };
    
    TREE::TREE(int value){ //隐含参数this指向要构造的对象
    	this->value=value; //等价于TREE::value=value
    	left=right=0; //C++提倡空指针NULL用0表示
    }
    const TREE* TREE::find(int v) const { //this指向调用对象
    	if(v==value) {
            return this; //this指向找到的节点
        }
    	if(v < value) {
            return left!=0?left->find(v):0; //查左子树
        }
    	return right!=0?right->find(v):0; //查右子树，调用时新this=left
    }
    
    ```

  + **初始化**

    ```c++
    Class A { ……};
    Class B {
    	int x;
    	const int y; // 只读成员
    	int &z; // 引用成员
    	static int u; // 静态成员
    	A a; // 对象成员
    	A *p;
    	A &q; // 引用成员，引用的是一个对象
    	B(……) { ………..}
    };
    
    //方法1 ：在定义变量时，直接初始化;
    class B {
    public:
    	int x=10; // 初始化 x=10
    	const int y=20; // 初始化 y= 20
    	int &z = x; // z 中的内容为 x的地址
    	A a{…..}; // 类似于构造函数，用{ } 代替( )
    	A *p = new A(…); 
    	A &q=a;
    };
    class A {
    public:
    	int x {10}; // 初始化 x=10;
    	int &y {x}; // y 中的内容为 x的地址
    	const int z{20};
    	int u=30;
    	A a{……};
    };
    Class B { 
        int x;
    	const int y;
    	int &z;
    	static int u;
    	A a;
    	A *p;
    	A &q;
    	B(int t1,int t2,……): y(t), z(t2), a(…), q(…) { ………..}
    };
    
    //类成员不能像一般的变量那样用 () 来初始化，用 = or {}
    ```

    ➢ 对象指针可在构造函数中初始化
    ➢ **静态成员在类外初始化**

    >  ➢ 如果**常变量、引用变量**在定义时未初始化，则在构造函数**前**进行初始化
    >
    > ​	类中有数据成员是一个**对象**时，也要在**构造函数前**进行初始化(构造函数	只能自动调用，不能写调用构造函数语句。)
    >
    > ​	数据成员是**对象指针**时，则可在**构造函数中初始化**。
    >
    > ​	`B(int t1,int t2,……): y(t), z(t2), a(…), q(…) { ………..}`
    >
    > ​	➢ 函数说明之后 
    >
    > ​	➢` {}` 之前 
    >
    > ​	➢ `：` 分隔 
    >
    > ​	➢ 各数据成员以逗号分隔 
    >
    > ​	➢ 用构造函数的形式给各变量赋初值， 如 `y(t) `
    >
    > ​	➢ 可以用列表的形式`{} `赋初值， 如 `y{t} `
    >
    > ​	➢ 不能采用 `=` 来初始化 :` y=t // error`
    >
    > ```c++
    > class A {
    > public:
    > static int v =30; // 错误语句，静态数据成员独立于对象而存在
    > static const int w=40; // 有const 约束，可赋值
    > const static int t =50; 
    > };
    > int A::v=30;
    > ```

  + **类及对象的内存布局**

    > **`#pragma pack(n)` **指明各数据成员的地址对齐方式, 对象数组中对象之间的对齐方式 

    `#pragma pack(1) `:  紧凑方式 默认是松散方式

     一个`int`类型的成员，其地址被4整除；一个`double`类型的成员, 其地址被8整除；**一个对象的大小能够被成员的最大长度整除**。

    ```c++
    // 松散模式
    struct MESSAGE {
    	char flag;
    	int size;
    	char buff[200];
    	double sum;
    };
    struct MESSAGE1 {
    	double sum;
    	int size;
    	char buff[200];
    	char flag;
    };
    cout << sizeof(MESSAGE) << endl; 
    cout << sizeof(MESSAGE1) << endl;
    cout << "MESSAGE : offset of sum :" << offsetof(MESSAGE, sum) << endl;
    cout << “MESSAGE1 : offset of flag :” << offsetof(MESSAGE1, flag);
    ```

    <img src="https://s2.loli.net/2021/12/09/MXvYNlgC2OH6dAn.png" alt="image-20211209211152720" style="zoom: 67%;" />

    ```c++
    struct alignas(16) MESSAGE2 {
    	double sum;
    	int size;
    	char buff[200];
    	char flag;
    };
    cout << sizeof(MESSAGE1) << endl; 
    cout << sizeof(MESSAGE2) << endl;
    cout << “MESSAGE1 : offset of flag :” << offsetof(MESSAGE1, flag);
    cout << “MESSAGE2 : offset of flag :” << offsetof(MESSAGE2, flag);
    ```

    <img src="C:/Users/86156/AppData/Roaming/Typora/typora-user-images/image-20211209211333412.png" alt="image-20211209211333412" style="zoom: 67%;" />

  + ➢ 在`.cpp` 文件中，`struct `用法 与`class `相同 可以有构造函数、析构函数、权限说明等； 

    差别：`class `默认的访问权限是 `private`; `struct `默认的访问权限是 `public`; 

    ➢ 在` .c` 文件中 `struct `中不能有函数，不能有权限说明； 在定义结构变量时，要写成 `struct xxx x` 之类的形式； 当然可以用`typedef `, 将` struct xxx ` 赋予新的名字。

  + **实例数据成员** ： 不同对象的数据成员各有独立的空间 

    **静态数据成员** ： 不同对象的静态数据成员共享存储同一空间； 对象的存储空间中，不包含静态数据成员。

    **实例函数成员** ： 对象的地址为第一参数，即隐含参数 this 

    **静态函数成员** ： 无对象的地址。

  + ➢ **实例数据成员指针** 指向 类的一个实例数据成员 

    ➢ 存放数据实例成员在类中的**偏移地址** 

    ➢ 存放的**不是一个对象中实例成员的地址** 

    ➢ 数据成员指针 不一定是 类的成员

    ```c++
    int *p; // 普通指针
    int 类名A :: *q; //成员指针// 指向 A 类中的一个 int 成员
    q = & 类名A :: A 中的int成员 ;
    ```

    ```c++
    class Student {
    public:
    	int number;
    	char name[15];
    	float score;
    public:
        ……
    }；
    Student xu(123,"Xuxiangyang",100);
    Student zhang(456,”Zhangsan”,99);
    int x = offsetof(Student, number); //取偏移地址
    Student * p; // 注意与成员指针的差别
    p = &xu; 
    p = &zhang;
    *(int *)((char *)p + x) = 100;
    
    class Student {
    public:
    int number;
    ……
    }；
    Student xu(123,"Xuxiangyang",100);
    Student zhang(456,”Zhangsan”,99);
    int *p = &xu.number; // p 指向对象xu中的number
    int Student::*q = &Student::number; // q数据成员指针
    // int Student::*q; q = &Student::number;
    cout << xu.*q <<endl; // cout << xu.number <<endl; 
    cout << zhang.*q <<endl;
    int *p = &Student::number; // 无法从 Student::* 转换为 int *
    ```

    ```c++
    // 普通数据指针
    class Student {
    private:
    	int number; …
    public:
    	int * getaddress1() {return &number; }
    	int getaddress2() { return int(&number); };
    }；
    Student xu(123,"Xu",100);
    int main() {
    	int *p;
    	int q;
    	p = xu.getaddress1();
    	q = xu.getaddress2();
    	cout << *p << endl;
    	cout << *(int *)q;
    }
    /*
    结果皆为 123
    p, q为xu.number的地址
    不是number 在类中的偏移地址
    */
    
    // 数据成员指针
    class Student {
    private:
    	int number; …
    public:
    	int* getaddress1() { return &number; }
    	int Student::*getaddress2() {
    		return &Student::number; 
        } 
    }；
    Student xu(123,"Xu",100);
    void main() {
    	int *p; 
    	int Student::*q;
    	p = xu.getaddress1();
    	q = xu.getaddress2();
    	cout<< *p;
    	cout<< xu.*q;
    }
    // 结果皆为 123
    ```

    ```C++
    int fadd(int x, int y) { return x+y; }
    int fsubtract(int x, int y) { return x-y; }
    int (*fp)(int, int);
    // 1
    fp = &fadd;
    result = (*fp)(10,20);
    // 2 等价于 1
    fp = fadd;
    result = fp(10,20);
    fp = fsubtract;
    result = fp(10,20);
    /*
    取函数地址时，有无 & 一样；
    调用函数指针时，有无 * 一样
    */
    
    class Student {
    public:
    	void SetNumber(int x) { number=x; }
    };
    Student xu(123,"Xu",100); 
    void (*pq)(int);	// 函数指针
    void (Student::*pf)(int);	// 成员函数指针
    pf = &Student::SetNumber;	
    (xu.*pf)(200);
    xu.SetNumber(200); // 等价语句
    ```

    **不能取构造函数的地址，否则通过函数指针就可实现手动调用**； 

    **可以取析构函数的地址，通过函数指针可以手动调用析构函数**。

    ▪ 使用**实例**成员指针访问成员时必须和对象关联 

    ▪ 使用**静态**成员指针时不必和对象关联

    ▪ 实例成员指针通过`.*`和`->*`访问对象成员 

    ▪ `.*`和`->*`优先级高， 结合性自左至右 

    ▪ `.*`左操作数为类的对象，右操作数为成员指针` int Student::*p; xu.*p ` 

    ▪ `->*`左操作数为对象指针，右操作数为成员指针` Student *q; q->*p`

    实例成员指针是一个偏移量，存放的不是成员地址，故**不能移动**： 

    ```c++
    int Student::*p; 
    p=p+1; // 非法 , 不能移动指针 
    int *q; 
    q = q+1; 
    ```

    实例成员指针**不能进行类型转换**： 

    ▪ 防止通过类型转换**间接实现指针移动**。

    ```c++
    struct A { //实例成员指针是偏移量
    	int m, n;
    }a={1,2}, b={3,4};
    void main(void) {
    	//以下p=0表示偏移，实现时实际<>0
    	int x, A::*p=&A::m; //p=0：m相对结构体的偏移
    	x=a.*p; //x=*(a的地址+p)=*(2000+0)=1
    	x=b.*p; //x=*(b的地址+p)=*(2008+0)=3
    	p=&A::n; //p=4：n相对结构体的偏移
    	x=a.*p; //x=*(a的地址+p)=*(2000+4)=2
    	x=b.*p; //x=*(b的地址+p)=*(2008+4)=4
    }
    
    
    struct A { //struct定义的类，进入类体缺省权限为public
    	int i, f(){ return 1;} ; //公有成员i、f( )
    private:
    	long j; //私有的成员j
    }a;
    void main(void) {
    int A::*pi=&A::i; //实例数据成员指针pi指向public成员A::i
    int(A::*pf)()=&A::f; //实例函数成员指针pf指向函数成员A::f
    long x=a.*pi+(a.*pf)(); //等价于x=a.*(&A::i)+(a.*(&A::f))()=a. i+a.f()
    pi++; pf+=1; //错误， pi不能移动，否则指向私有成员j，pf不能移动
    x=(long) pi; //错误，pi不能转换为长整型
    pi=(int A::*)x; //错误，x不能转换为成员指针
    }
    
    ```

  + **`const`、`volatile`和`mutable`**

    **`const`**

    > ```c++
    > class TUTOR {
    > 	char name[20];
    > 	const char sex; //性别为只读成员
    > 	int wage;
    > public:
    > 	TUTOR(const char *n, char g, int s): sex(g), wage(s){
    >     	strcpy_s(name,n);
    > 	}
    > 	const char *getname() const { 
    >     	return name; 
    > 	}
    > 	//函数体不能修改当前对象 函数的返回类型有 const 修饰
    > 	char *setname(const char *n) { 
    >     	strcpy_s(name, n); return name; 
    > 	}
    > };
    > 
    > TUTOR xu(“xuxy”,’M’,2000);
    > *xu.getname()=‘X’; // 不能给常量赋值
    > *xu.setname(“xuxiangyang”) =‘X’; // name 的首字母变成X
    > strcpy_s(xu.setname(“xu123”), 6, “hello”); //name 改为hello
    > 
    > const char * TUTOR::getname() const{ 
    > 	return name; 
    > } // 返回值类型是 const char *.
    > TUTOR xu("xuxy",'M',2000);
    > char *p；
    > p=xu.getname( ); // 无法从 const char * 转换为 char *
    > const char *q;
    > q = xu.getname( );
    > *xu.getname( ) = ‘X’; // 不能给常量赋值
    > // 等同 *q=‘X’; q[0]=‘X’;
    > // 表达式必须是可修改的左值
    > /*
    > getname 后面有一个 const, 即代表
    > const TUTOR * const this;
    > this->name 是const的
    > */
    > // 方法1 ：去掉 getname后的 const
    > char * TUTOR::getname() { return name; }
    > *xu.getname()=‘X’;
    > // 方法2 ： 返回时进行强制类型转换
    > char * TUTOR::getname() const { return (char *)name; }
    > *xu.getname()=‘X’;
    > 
    > ```

    **`volatile`**

    > ➢ **构造或析构**函数的参数表后不能出现`const`或`volatile `
    >
    > `classname(….) const; // error `
    >
    > 构造或析构时，`this`指向的对象应能修改且不随便变化。 
    >
    > ➢ **静态函数**成员参数表后不能出现`const`或`volatile`(无隐含 `this`)。 
    >
    > `static … ff( …) const; // error`

    **`mutable`**

    > ➢ 被`mutable `修饰的变量永远处于可变得状态，即使在 `const`函数中 
    >
    > ➢ `mutable`只能用来修饰数据成员 
    >
    > ➢ 不能与 `const`、`volatile `或 `static `同时出现

    参数表后出现`const`、`volatile`或`const volatile`会影响函数成员的重载：

    ▪ **普通对象**应调用参数表后不带`const`和`volatile`的函数成员； 

    ▪ `const`和`volatile`对象应分别调用参数表后出现 `const`和`volatile`的函数成员。 参数表后出现`volatile`，表示调用函数成员的对象是挥发对象，意味存在并发执行的进程，正在修改当前对象。

    ```c++
    class A {
    	int a; const int b; //b为const成员
    public:
    	int f(){a++; return a; } //this类型为： A * const this
    	int f()const{return a; } //this类型为：const A * const this。
    	int f()volatile{return a++; } //this类型为：volatile A * const this
    	int f()const volatile{ return a; }//this类型为：const volatile A* const this
    	A(int x) ：b(x) {a=x;} //不可在函数体内对b赋值修改
    } x(3); //等价于A x(3)
    const A y(6); // y不可修改
    const volatile A z(8); // z 不可修改
    
    void main(void) {
    	x.f(); //普通对象x调用int f(): this指向的对象可修改
    	y.f(); //只读对象y调用int f()const:this指向的对象不可修改
    	z.f(); //只读挥发对象z调用int f()const volatile:this指向的对象不可修改、挥发
    }
    ```

  + > **静态数据成员**

    `sizeof(类)`不包括静态成员

    ➢ 静态数据成员用 static 声明 

    ➢ 静态数据成员的访问控制可以是公有、保护和私有 

    ➢ **在类体内声明，在类体外定义并初始化** 

    ➢ 静态数据成员独立分配内存，(**不属于任何对象内存 **)

    ➢ 所有对象共享静态数据成员内存，任何对象修改该成员的值，都会**同时影响**其他对象关于该成员的值。 

    ➢ 用于描述类的总体信息，如对象总数、连接所有对象的链表表头等。

    + **局部类不能定义静态数据成员** 

      ```c++
      void f(void) { 
          class T { // T 是局部类 
              int c ; 
              static int d; // 错误 此规定合理吗？ 
          }； 
      } 
      ```

    + **联合体的数据成员必须共享存储空间**，而静态数据成员 各自独立分配存储单元，**联合不能定义静态数据成员**。 

      ```c++
      union UNTP{ static int c; static long d; }; //错误
      ```

    + **在构造函数中，可以给静态数据成员赋值，但不称为初始化**

    > **静态函数成员**

    ➢ 在函数的最前面加 static 

    ➢ 静态函数成员的**访问权限及继承规则同普通函数成员没有区别**，可以缺省参数、省略参数以及重载。 

    ➢ 普通函数成员的第一个参数是隐含this指针，指向调用该函数的对象； 

    ➢ 静态函数成员**没有this指针**，**若无参通常只应访问类的静态数据成员和静态函数成员**。

    ➢ 静态函数成员的调用和静态数据成员类似 

    ➢ `类名::静态函数成员(…)；` 推荐使用 

    ➢ `对象.静态函数成员(…) ；` 

    ➢ `对象.类名::静态函数成员(…)`

    ➢ 不能使用static定义构造函数、析构函数以及虚函数。

    ```c++
    class A{
    	int x; //普通成员必须在对象(同this相关)存在时才能访问
    	static int i;
    	static int f(){ return x + i; }; 
        //错：static int f()无this则无x
    public:
    	static int m() { return i; }; 
        //静态函数成员无this
    }a;
    int A::i=0; //私有的，体外定义并初始化
    void main(void) {
    	int i=A::f(); //错误，f私有的
    	i=A::m()+a.m()+a.A::m(); //正确，访问公有的静态函数成员
    	i=a.f(); //错误，f私有的不能访问
    	i=a.A::f(); //错误，f私有的不能访问
    }
    
    ```

    • **常函数成员要说明隐含this参数**。 

    • **常函数成员不能定义为没有this参数的静态函数成员**

    ```c++
    class A {
    static int f( )const // 错误
    { return 1; }
    };
    ```

    • 联合union不能定义静态数据成员，但可以定义静态函数成员。

    ```c++
    union A {
    int x,y;
    static void f( );
    };
    ```

    > **静态成员指针**

    ➢ 静态成员指针指向**类的静态数据（函数）成员**。 

    ➢ 变量、数据成员、普通函数和函数成员的参数和返回值都可以定义成静态成员指针类型。 

    ➢ 静态成员相当于**具有访问权限的变量和函数**，同普通变量和函数相比，除访问权限外没有区别，因此，静态成员指针和普通指针形式上也没有区别。 

    ➢ **静态成员指针存放静态成员==地址==**，**普通成员指针存放普通成员==偏移==**；

    静态成员指针可以**移动**，普通成员指针不 能移动；

    静态成员指针可以**转换类型**，普通成员指针不能转换类型。

    ```c++
    class P{
    	char name[20];
    public:
    	static int n;
    	static int getn() { return n; }
    	P(char *n) { strcpy_s(name, n); n++; }
    	~P( ) { n--; }
    }zan((char *)"zan");
    int P::n=0;
    void main(void){
    	int m;
    	int *d=&P::n; // d为静态成员指针；等价于d=&zan.n;
    	//静态成员指针 与 普通指针 没有差别
    	int (*f)()=&P::getn; //普通函数指针指向静态函数成员
    	m=*d + (*f)( );
    }
    
    struct A{
    	int a, *b, A::*u, A::*A::*x, A::**y, *A::*z;
    	static int c, A::*d;
    }z;
    int A::c=0, A::*A::d=&A::a; //静态数据成员初始化
    void main(void) { //注意优先级高低：“.”>“*”>“.*”
    int i, A::**m;
    z.a=5; z.u=&A::a; i=z.*z.u; //i=z.*&A::a=z.a=5
    z.x=&A::u; i=z.*(z.*z.x); 
    //i=z.*(z.*&A::u)=z.*z.u=z.a=5
    m=&A::d; m=&z.u; i=z.**m; //i=z.**&z.u=z.*z.u
    z.y=&z.u; i=z.**z.y; // i=z.**&z.u=z.*z.u=z.a=5
    z.b=&z.a; z.z=&A::b; i=*(z.*z.z); 
    //i=*(z.*&A::b)=*z.b=*&z.a
    }
    ```

    > **联合的成员指针**

    ➢ 联合可以**定义实例和静态成员**，故也可以定义实例和静态成员指针。 

    ➢ 联合的**实例数据成员共享内存**，**指向这些实例数据成员的指针存储的偏移量值实际上是相同的**。 

    ➢ 函数中**局部类**不能定义静态数据成员， **函数中的局部联合也不能定义静态数据成员**。 

    ➢ **全局类中的联合或全局联合可以定义静态数据成员**； 静态数据成员指针一般指向全局类中的联合或全局联合的静态数据成员。

+ **继承**

  + **单继承类**

    ```c++
    class <派生类名>: 【<派生控制符>】 <基类名>
    {
    <派生类新定义成员>
    <派生类重定义基类同名的数据和函数成员>
    <派生类声明恢复基类成员访问权限>
    };
    ```

    > **`<派生控制符>`**指明派生类采用什么方式从基类继承成员， 

    > `private`： 私有继承基类； `protected`：保护继承基类； `public`： 公有继承基类。

    ➢ **不论基类**是用`struct`定义的，还是用`class`定义的, **使用`class`定义派生类时，缺省的派生控制符为`private`; 使用`struct`定义派生类时，缺省的派生控制符为`public`**. 

    ➢ 使用 `union `定义的类，**既不能作为基类，也不能用 `union`定义派生类**。

    <img src="https://s2.loli.net/2021/12/10/fO4eWCYPljquidZ.png" alt="image-20211210093231078" style="zoom: 55%;" />

    ➢ 对于基类的私有成员，在派生类中不可访问， 因此，也**不能恢复或修改**其访问权限； 

    ➢ 对于基类的**保护成员、公有成员，可以修改其访问权限** 

    ➢ 语句格式：**`基类名::成员名`** 或 **`using 基类名::成员名 `**，**随便改权限**

    ➢ 对于修改或者恢复权限的成员，在派生类中**不能定义同名**成员。

    ➢ 标识符的**作用范围**越小，被访问到的优先级越高。 要访问作用范围更大的标识符，用“类名::”进行限定。 

    ➢ 面向对象作用域**关于标识符的作用范围从小到大**： 

    ① 作用于函数成员内 (局部变量)； 

    ② 作用于类或者派生类内； 

    ③ 作用于基类内 （基类的成员在派生类也可访问到）； 

    ④ 作用于虚基类内。

    ```c++
    class A {
    public: 
        int x;
    	int getx() {cout<<“class A”<<endl; return x;}
    };
    class B : public A {
    public: int x;
    	int getx() { cout<<“class B”<<endl; return x; }
    	int setx(int x) {
    		this->x=x; // (*this).x=x; B::x=x;
    		A::x=2*x;
            /*
            A::x = 2 * x;
    		B::A::x = 2 * x;
    		this->A::x = 2*x;
    		(*this).A::x = 2*x;
    		((A*)this)->x = 2 * x;
            */
    	}
    };
    B b; 
    Z = b.getx(); 
    Z = b.A::getx(); 
    ```

    创建一个对象时，调用相应的构造函数进行初始化 

    派生类**不能继承基类的构造函数、析构函数 **, 有自己的构造函数和析构函数 

    派生类**构造函数的格式**： 

    **`派生类名(参数表1)：基类名(参数表2),派生类成员的构造 { ……. 构造函数体 ………... }`** 

    若无“**`:基类名(参数表2)`**” ，执行**基类**中**无参数的构造函数** 

    **基类中的构造函数先于派生构造函数体执行 **

    基类中的构造、析构函数都要有相应的**访问权限** 不能是 `private`

    **单继承派生类只有一个基类或虚基类**，根据4个优先级确定构造顺序：

    ① 调用**派生类虚基类**的构造函数；**无论列出否，总会被执行**； 

    ② 调用**派生类基类**的构造函数，**无论列出与否，总会被执行**； 

    ③ **按照派生类数据成员声明的顺序**，依次**初始化**数据成员或调用相应构造函数，对象成员无论列出与否总会被构造； 

    ④ **最后执行派生类的构造函数体**。 

    **基类、对象成员不列出时自动调用无参构造函数**。 

    若虚基类或基类**只定义了带参数的构造函数**， 则派生类**需要使用带参数的构造函数**。

    ```c++
    class A{
    private: int a;
    public:
    A( ):a(8) { cout<<a<<" " ; }
    A(int x):a(x) { cout<<a<<" "; }
    ~A( ){ cout<<a; }
    };
    
    class B: private A{
    private: int b, c;
    const int d; //有只读成员d，故B必须定义构造函数
    A x, y, z;
    public:
    B(int v):b(v), y(b+2), x(b+1), d(b), A(v) {
    c=v; cout<<b<<c<<d; cout<<"C "; //b, c可再次赋值
    }
    ~B( ){ cout<<"D"; }
    };
    
    void main(void){ B z(1); }
    //输出结果：1 2 3 8 1 1 1 C D 8 3 2 1
    // 首先A(v),按照声明的顺序给b c d 赋值，之后构造 x y z 执行完构造函数体，先析构B，再析构 z y x A（v）
    
    // Q：← 能否删除无参的构造函数 A() ？
    // 不能 有语法错误,当构造B中对象成员Z时，没有合适的默认构造函数可用
    
    // Q：← 能否删除 A(v)？
    // 可以 自动调用无参构造函数 显示的第一个数字是 8
    
    // Q：若将 int b,c ; 移到 A x, y,z; 之下，结果如何？
    // 那麽b c在构造x y z之前没有值：
    // 输出：1 -858993459 -858993458 8 1 1 -858993460 C D 8 -858993458 -858993459 1
    
    ```

    变量 **q引用一个对象p**时，由对象`p`完成构造和析构。 

    `A p(…); A &q = p;` 不需要考虑 q 空间的释放，q本身只占4个字节, q的生命周期时，自动释放这4个字节。 

    若被q指向的对象是用`new`生成的， 用`delete q`析构对象，否则将产生内存泄漏。 `A *q = new A(10); delete q; `

    q**引用的对象**是用new生成的，应使用 `delete &q`析构对象，否则将产生内存泄漏。 `A & q = * new A(10); delete &q;`

    

    如果派生控制为`public`，派生类称为基类的**子类**， 基类则称为派生类的**父类**；

    ➢**父类指针可以直接指向子类对象** ，指完之后就是父类型

    父类可以**直接引用子类对象** 

    **无须通过强制类型转换， 编译时按父类说明的权限访问成员**。

    非父子类 可通过强制类型转换， 

    ➢ 基类指针指向派生类对象 

    ➢ 基类引用派生类对象

    ```c++
    class A {… }; class B: public A {…..};
    A *pa; B pb;
    // 直接转换 & 强制类型转换
    pa = &pb; pa = (A *)&pb;
    A &ra = pb; A &ra = (A &)pb;
    A &ra = *(A *)&pb;
    ```

    在**派生类函数成员内部** （**不论**父子关系），基类指针**可以直接指向**该派生类对象，基类被等同地当作派生类的父类

    在**派生类的友元函数中** **友元内部的基类指针也可以直接指向派生类对象**， 即对派生类的友元，基类被等同地当作派生类的父类。 

    ```c++
    class A{
    private:
    int h, i, j;
    static int k;
    };
    class B: A{ //等于class B: private A
    int m, n, p;
    static int q;
    };
    
    Size of int=4
    Size of A=12
    Size of B=24
    ```

  + 

+ **作用域**

  **面向对象的作用域 从小到大可以分为五级**： 

  ① 作用于表达式内 (常量) 

  ② 作用于函数成员内 (函数参数、局部变量、局部类型) 

  ③ 作用于类或派生类内 (数据/函数/类型 成员) 

  ④ 作用于基类内 (数据/函数/类型 成员) 

  ⑤ 作用于虚基类内 (数据/函数/类型 成员) 

  **虚基类 》基类 》类 /派生类 》成员函数 》表达式**

  **有同名符号时，指定是用哪儿定义的符号 (::) **

  **单目** **` ::`** 指定为全局标识符 全局类型名、全局变量名、全局函数名等

  **双目** **`:: `** 指定类或者名字空间中的枚举元素、数据成员、 函数成员、类型成员等。 用法：`类名::成员名`

  **`::`的优先级为最高级，结合性自左向右**

  ```c++
  :: x = 10; // 全局变量
  x = 20; // 局部变量
  ```

  > **`namespace `是C++引入的一种新作用域;**
  >
  > ➢ 名字空间必须在**全局作用域内用`namespace`定义**，不能在类、函数及函数成员内定义，**最外层**名字空间名称必须在全局作用域**唯一**; 
  >
  > ➢ **同一名字空间内的标识符名必须唯一**，不同名字空间内的标识符名可以相同; 
  >
  > ➢ 当程序引用**多个名字空间的同名成员**时，可以用**名字空间加作用域运算符`::`限定**。
  >
  > 名字空间可**分多次和嵌套**地用`namespace`定义
  >
  > ```c++
  > namespace A {
  > 	int x;
  > 	namespace B {
  > 		namespace C {
  > 			int k=4;
  > 		}
  > 	}
  > }
  > namespace AB = A::B;
  > using namespace A::B::C;
  > using namespace AB;//A::B无成员可用
  > ```
  >
  > 直接访问成员 `std::cout <<“hello”<< std::endl;`
  >
  > 引用名字空间的某一个成员 `using std::cout; cout<<“hello”<<std::endl;`
  >
  > 引用名字空间 `using namespace std; cout<<“hello”<<endl;`
  >
  > 先定义、后引用
  >
  > ```c++
  > namespace ALPHA { 	 //初始定义ALPHA
  > 	int x;
  > 	void g(int t); 	 //声明void g(int)
  > 	g(long t){ …… }; //定义void g(long)
  > }
  > namespace ALPHA { 	//扩展定义ALPHA
  > 	int y=5; 		//定义整型变量y
  > 	void g(void); 	//新函数void g(void)
  > }
  > using ALPHA::g; 	//声明引用名字空间void g(int)和g(long)
  > void main(void) {
  > 	g(ALPHA::x); 	//调用函数void g(int)
  > }
  > ```
  >
  > ```c++
  > namespace A { int x=1; };
  > namespace B { int y=2; };
  > namespace C { int z=3; }
  > namespace { int m=4; }
  > using namespace A; //此用法允许在全局作用域定义新x
  > using B::y; //此用法不允许在全局作用域定义y
  > int z=x+3; //访问A::x
  > int x=y+2; //访问B::y，，此时定义了一个全局变量 x
  > int v=::x+A::x; //用::区分全局变量x和名字空间成员x
  > //int y=4; //错误，当前作用域有变量y(B::y不是在全局作用域定义的)
  > int main(void){ return z; } //优先访问全局变量::z
  > ```
  >
  > 

  > **友元**： 不是本类的函数成员, 但可以像类的函数成员一样，访问该类的所有成员
  >
  > ```c++
  > class Student {
  > private:
  > 	int number;
  > 	char name[15];
  > 	float score;
  > public:
  > 	Student(int number1, char* name1, float score1);
  > 	Student() { };
  > 	Student(const Student &a);
  > 	void Print(); // 显示信息
  > 	friend void display(Student &a); // 显示信息
  > };
  > void Student::Print() { // 函数成员
  > 	cout << " name : " << name << " score: " << score << "\n";
  > }
  > void display(Student &s) { // 非 Student的函数成员，是友元
  > 	cout << " name : " << s.name << " score: " << s.score << "\n";
  > } // 访问私有成员
  > int main() { 
  >     Student stu1(……);
  > 	Stu1.Print();
  > 	display(stu1); 
  > }
  > ```
  >
  > 普通友元：C语言普通函数 display 声明为类的友元
  >
  > 缺点：破坏了类中信息隐藏的特性，可访问私有成员
  >
  > 优点：提高程序的运行效率 减少类型检查和安全性检查的时间开销
  >
  > **友元函数** 
  >
  > 友元函数不是声明该友元的当前类的成员 
  >
  > 不受访问权限的限制，可以在任何访问权限下用`friend `
  >
  > 可以访问当前类的**任何成员** 
  >
  > 一个函数可成为**多个类的友员** 
  >
  > ➢ 若**在类体定义**友元函数体，友元函数自动成为**内联函数** 
  >
  > ➢ 同其他内联函数一样，内联有可能失败。
  >
  > **友元类**
  >
  > ```c++
  > class A {
  > private:
  > 	int x;
  > public:
  > 	A(int x) { this->x = x; }
  > 	friend class B; // 类B 为类A的友元
  > }; 
  > // 类B的所有函数成员都是类A的友元,
  > // 均可访问A的私有成员
  > ```
  >
  > ➢ **类B的所有函数成员都是类A的友元 **
  >
  > ➢ 关系不传递 
  >
  > ➢ 友元关系不对称 
  >
  > ➢ static、virtual、friend 只能**单个**独立使用。
  >
  > ```c++
  > // 一个类的成员函数 能否成为另一个类的友元？
  > class B {
  > public: void display();
  > };
  > class A {
  > private:
  > int x;
  > public:
  > A(int x) { this->x = x; };
  > friend void B::display();
  > };
  > ```

  > 当有基类成员和派生类成员同名时
  >
  > ➢ **隐藏**：**通过派生类对象只能访问到派生类成员**，而无法访问到其基类的同名成员。 
  >
  > ➢ **覆盖**：通过派生类对象还能访问到基类的同名成员。 
  >
  > ​	**`派生类对象 . 基类名称 :: 成员名称`**
  >
  > ➢ 在派生类中， using特定基类数据成员后，不允许再在 派生类中定义同名数据成员，并且可以通过前述using改 变或指定新的访问权限。 ➢ 在派生类中， using特定基类函数成员后，还可以再在 派生类中定义同名函数成员，并且可以通过前述using改 变或指定基类成员继承后的访问权限

+ **多态**

  

+ 

