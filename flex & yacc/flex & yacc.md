# **-lex与yacc/flex与bison入门**

----

## flex入门

> 在具有结构化输入的程序中，反复出现的两个任务是：将输入分隔成有意义的单元，然后找出这些单元之间的关系。而lex/flex所做的就是生成词法分析器，以完成上面提高的第一个任务。通过编写特定的代码，在使用flex编译之后，就可以生成词法分析器的C程序。
> 使用lex/flex制作词法分析器是很有必要的，因为lex将正则表达式转变为词法分析程序能够用来极快地扫描输入文本的形式，而且速度不依赖于词法分析程序尝试匹配的表达式的数量。这使得在绝大多数情况下，lex生成的词法分析器的速度都快速手写的程序。

一个来自于flex使用手册的结构：

```c
定义(definations)
%%
规则(rules)
%%
代码(user code)
```


flex的代码分为三个部分，由`%%`分割，这些部分可以为空，但为了让flex代码能够按照我们此前介绍的方法成功编译，需要加入部分内容，形成下方的新手框架：

```c
%{

%}

%%

%%
int main(int argc, char **argv)
{
  yylex()
  return 0;
}
int yywrap()
{
	return 1;
}
```
+ ①第一部分，较原框架加入了`%{ %}`，这对大括号内没有任何内容，所以目前起不到任何作用。加入这对大括号的目的是，在这个部分可以使用C语言代码进行预处理，例如使用`#include<stdio.h>`，或是定义宏、常量等等。
  ②第二部分，没有变化，这里的要写入的代码是重点内容，将在后续展开。
  ③第三部分，这个部分就是用来写C语言代码的，因此不需要使用`%{%}`括号对。在这里，我们添加了两个函数。接下来我们展开讲述这些内容。

+ 由于flex代码要先编译为C代码，显然需要一个`main`函数，所以需要我们手写一个`main`函数，这就是第一个函数的由来。此时想必有人会疑惑，那么`main`中调用的`fflex()`函数是什么呢，我们并没有定义它啊？

+ `yylex()`函数，其实会由第二部分我们写入的匹配规则自动生成，也就是说，它其实就是由lex产生的词法分析程序，当我们调用它时，才会正式开始词法分析。关于这个函数的具体内容，我们会在之后讲述。

+ 最后就是`yywarp`函数，这是一个约束函数，当它返回1时，代表扫描结束，此时结束程序。这个函数在读取多个文件时很有用处，关于它的进阶运用也会在未来而不是现在展开。

> 第二部分由多条规则（rule）组成，每条rule可以由**pattern**与**action**组成。
>   `pattern`使用正则表达式表示，含义为需要匹配的词的规则。
>   `action`使用代码表示，含义为成功匹配该词后执行的动作。

以下是flex中的pattern参考：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200919091730989.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NDAwNzYzMg==,size_16,color_FFFFFF,t_70#pic_center)

为了对第二部分有着进一步的感性认识，这里贴出一个代码，供学习者阅读：

```c
%{
int num=0;
int chars=0;
%}
%%
[a-zA-Z]+  { chars++; }
[1-9]+[0-9]* {num++;}
\n         
.          
%%
main(int argc, char **argv)
{
  yylex();
  printf("%8d%8d\n", num,chars);
}
int yywrap()
{
	return 1;
}
```

**程序解释：**
可以看到，在第一部分，我们用C代码定义了变量num和chars，它们都需要被写在两个花括号里。
第二部分，我们依次解释其中的规则。
①`[a-zA-Z]+` 表示匹配长度至少为1的连续字母串，当匹配到时，对chars做增1操作。（这里的动作的花括号可以省略）
②`[1-9]+[0-9]*` 表示匹配一个数字，该数字不能以0开头，当匹配到时，对num做增1操作。
③`\n`匹配换行符，不做任何操作
④`.`匹配任意字符（除`\n`外），不做任何操作

> 对于一些常见的疑惑，这里给出解释。

`Q1：`对于规则③④，既然不做任何操作，那么为什么要匹配呢？
`A1：`事实上，flex对任何没有匹配到的字符，会自动做原样输出操作。因此，对于那些不需要将其输出，而是需要将其忽略的pattern，应该进行匹配并做无操作处理。

`Q2：`既然点号.可以匹配任意字符，显然也能匹配到规则①②的pattern，那么它们会起效吗？
`A2：`flex拥有一套简单的消除歧义的规则，使词法分析程序工作的两条规则是：

1、flex模式只匹配输入字符或字符串一次；

2、flex执行当前输入的最长可能匹配的动作。第二条规则就解决了这个疑惑，显然，当匹配到任意一个字符时，它满足④的pattern，但flex会尽量向更长的pattern进行匹配，因此会继续向后读，直到后一个字符读入后将无法匹配任意一个pattern，此时才进行匹配。所以当满足数字或字母串（单词）的匹配规则时，它必然先匹配这两者。

`Q3：`虽然这么说，但还是有一个问题——如果我只输入一个数字1，那么程序会把它判定为①的pattern还是④的pattern呢？
`A3：`flex的规则有着隐藏优先级，即匹配长度相同时，将最上面的规则作为匹配结果。由于规则①在④的上面，所以显然会将其匹配成数字。

> **练习一·算式分割**

目标：我们可以将一个算式分为几个部分——数字（NUM），运算符（SIGN），左括号（LPA）和右括号（RPA）。现在希望让词法分析器可以分析出这四个部分，并将一个算式中的成分按格式打印出来。
本程序中数字的定义为正整数。你也可以对其做适当扩展，使得程序可以将实数匹配为数字。

希望得到的结果：

```c
输入： 1+2*(3/4)-5
输出：NUM SIGN NUM SIGN LPA NUM SIGN NUM RPA SIGN NUM
// 提示：在相应规则的action中使用print/printf进行输出，如果使用了C语言某个头文件的函数，记得在第一部分花括号内导入它。
```

```c
%{

%}

%%

[1-9]+[0-9]*  		printf("NUM ");
"+"|"-"|"*"|"/"  	       printf("SIGN ");
"("				   printf("LPA ");
")"				   printf("RPA ");

%%
main(int argc, char **argv)
{
  yylex();
  yywrap();
}
int yywrap()
{
	return 1;
}

```

如果你想匹配实数，那么你应该将规则①的pattern这样来写：
`(0|[1-9]+[0-9]*|[0-9]+.[0-9]+)`
看到这段正则表达式，你可能会有些疑惑。因为这个表达式似乎只能匹配正实数，而事实也是如此。可能出乎你的意料，一旦需要在算式中匹配负数，那么这个问题立刻就变成了一个语法上的问题。因为表示负数的符号与减号相同，而根据此前所说的flex匹配规则，程序会尽量匹配长的字符串，如果加入负数的匹配，则5-6这个表达式就永远会被匹配成两个NUM——毕竟词法分析和语法分析两个任务是互相隔离的，在词法分析器根本不知道你规定的语法，它当然也就不可能明白这是两个数在做运算还是单纯的两个数。
**在现在这个只掌握了flex的情况下，如果我们想要匹配到负数，最好的办法可能就是不用‘-’号表示负数，而改用其他的符号。**
看到这里，你也许就能明白，为什么在C语言中，语法上是正确的语句（a++ + ++b）在编译时会报错了。在做词法分析时，它被分析成了a ++ ++ +b，显然这样看的话在语法上是错误的。

>  **练习二·检查关键字与标识符**

目标：我们希望用flex制作这样一个程序，给出一段C语言代码，对其中每行代码进行分析，识别出其中的关键字和标识符（变量名与函数名），当找到关键字时输出KEY，找到标识符时输出MARK。在输入结束后，输出整段代码中关键字与标识符的数量。
为了简化程序，我们规定只有以下关键字，且它们大小写敏感：`if|else|int|double|return`
标识符的规则：由数字、字母和下划线组成，但要以字母为开头。

希望得到的结果：

```c
输入：
double test(int a, double b) {
  double c=(double) a;
  double d=b+c;
  if (d>0)
  return d;
  else
  return 0;
}

输出：
每行的输入都会形成相应的输出，请自行比对输出是否正确。
如对于第一行，会输出类似于以下的字符串：
KEY MARK KEY MARK KEY MARK

全部输入后，按两次Ctrl+C，结束输入，会类似于以下的输出：
MARK=10  KEY=10
数量正确即可

```

```c
%{
   int key=0;
   int mark=0;
%}

ALPHA [a-zA-Z]
MARK  {ALPHA}+[a-zA-Z0-9_]*
KEY   if|else|int|double|return

%%
{KEY}					printf("KEY ");key++;
{MARK}					printf("MARK "); mark++;
\n						printf("\n");
.

%%
int main(int argc, char **argv) {
  yylex();
  printf("MARK=%d  KEY=%d",mark,key);
  yywrap();
}
int yywrap() {
	return 1;
}

```

`定义`的编写格式为：`name definition`
`definition`其实就是第二部分要匹配的`pattern`。
从上面三个定义的例子中，我们可以看到一些内容。我们首先定义了ALPHA，其内涵就是单个字母；随后我们在MARK的定义中使用了定义ALPHA，这充分说明了**definition是可以嵌套定义的**。KEY则罗列了关键字。
显然，这样写有几个好处：通过嵌套定义可以减少错误；在第一部分定义，在第二部分匹配，可以让代码显得更加美观清楚。
此外，在第二部分使用定义时，为了与其他内容相区别，**使用花括号{}将其括起**。

> 我在这里给出两个**批处理文件**的写法，减少不必要的命令编写。

①首先，我们需要一个批处理文件，让我们能够定位到程序所在的位置，这样每次重新打开`cmd`时就可以快速定位了。为了让这个批处理程序能够成功运行，建议建立一个`program`文件夹，每个新的`yacc`程序都在`program`中再新建一个文件夹存放。

②之所以这样存放程序，是为了方便批处理程序的运行，现在给出两个批处理文件的内容。

```c
到达待编译文件所在的路径
批处理文件 toP.bat
假设program文件存放在E:\ComplierComplier路径下，有如下代码
---
@echo off
set str=%1
E:
cd E:\ComplierComplier\program\%str%
---
将四行代码复制到文本文件中，保存后将其扩展名改为.bat
为了方便调用，建议给该文件起一个简单的名字
这里我将其命名为toP，即goto program
---
使用方法： [批处理文件名][空格][文件夹名]

```

```c
自动翻译
批处理文件 toE.bat
---
flex 1.l
gcc lex.yy.c
---
命名方式同上。直接输入批处理文件名即可调用
该批处理文件只能自动翻译命名为1.l的文件，如果想要在使用批处理程序时
决定文件的名字，则将改为如下代码：
---
set str=%1
flex %str%.l
gcc lex.yy.c
---
注意写成如上形式时，在调用时格式为
[批处理文件名][空格][文件名]
同时文件名中不应该写上.l
如果想要写上，则将代码中的.l删去

```

③配置两个批处理文件
如果没有配置环境变量的话，cmd是找不到这两个批处理文件的，当然我们不需要再为了这两个文件去专门配置环境变量。此前我们为flex/bison和gcc都配置了环境变量，所以我们可以将这两个文件放到gcc.exe所在的路径中

④最后，在完成之后可以在cmd中进行测试了。假设在program文件夹中建立了文件夹0.01，里面存有文件1.l需要翻译，则直接打开cmd，输入

```
toP 0.01
toE
```

> **练习三·变量定义**

目标：虽然flex产生的程序没有语法分析的能力，但我们也可以通过额外加入的C语言代码来做一些小改进。假设输入的文本是以下形式的合法字符串（因为我们还没有检测输入是否合法的能力）：
`int a=5;
double b=2.2;
[类型] [变量名] [=] [正实数]
则我们对于每行这样的输入，有以下输出：
<[变量名],[类型],[值]>`

**希望得到的结果：**

```c
int a=5;			//input
<a,int,5>			//output
double b_def=2.33;	//input
<b_def,double,2.33>	//output 或为2.330000，只要值对就行
```

事实上，flex在翻译为C文件时会产生一些自定义的函数和全局变量，如图所示：![在这里插入图片描述](https://img-blog.csdnimg.cn/20200919193117969.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NDAwNzYzMg==,size_16,color_FFFFFF,t_70#pic_center)

在这张表中，我们可以看到此前看到过的熟悉内容：`yylex()`与`yywrap()`，当然更多的是一些不认识的内容。现在，我们将目光专注于变量`yytext`，显然它就是被匹配的文本。
只要对它进行处理，就能实现我们的要求。

**警告**：请不要直接用字符指针指向`yytext`，由于一些`yytext`内部实现的原因，这样可能会造成意想不到的错误。

```c
%{
   #include<string.h>

   int statue;
   char name[20];
   
   int val_int=0;
   double val_double=0;
%}

ALPHA [a-zA-Z]
VAR   {ALPHA}+[a-zA-Z0-9_]*
KEY   int|double
DIGIT [0-9]
VALUE [1-9]+{DIGIT}*|{DIGIT}+\.{DIGIT}+

%%
{KEY}      { 
			if (yytext[0]=='i') 
				statue=1; 
			else 
				statue=2;
		}
{VAR}       strcpy(name,yytext);
{VALUE}  {
			if (statue==1)
				sscanf(yytext,"%d",&val_int);
			else if (statue==2)
				sscanf(yytext,"%lf",&val_double);
		}
;		 {
			if (statue==1)
				printf("<%s,int,%d>",name,val_int);
			else if (statue==2)
				printf("<%s,double,%lf>",name,val_double);
		}
\n		printf("\n");
.

%%
int main(int argc, char **argv) {
  yylex();
  yywrap();
}
int yywrap() {
	return 1;
}

```

> 此外，flex本身不只是写词法分析器的工具，它事实上也是一个优秀的工具，仅靠flex也能写出不错的程序

+ **使用`yyout`与`yyin`**

  现在我们想要在练习三的程序上做一点扩展，希望在运行时可以指定输入文件和输出文件，如下面所示：

  ```c
  a.exe  2.txt  3.txt
  //从2.txt读数据，向3.txt写数据
  ```
  事实上，对main函数做一点改变即可

  ```c
  int main(int argc, char **argv) {
    if (argc>1) {
      FILE *file;
  	file=fopen(argv[1],"r");
  	if(file)
  	  yyin=file;
    }
    if (argc>2)  {
  	FILE *file;
  	file=fopen(argv[2],"w");
  	if(file) {
  	  yyout=file;
  	  // freopen(argv[2],"w",stdout);
  	 }
    }
    yylex();
    yywrap();
  }
  ```
  这样就可以指定输入文件和输出文件了。当然，在试验时很多人会发现，虽然指定了输出文件，但输出还是打在了屏幕上。这是因为在第二部分我们使用的函数是`printf`而不是`fprintf`，所以测试时需要对代码再做一定调整。如果想不更改代码而直接看到效果，可以将main中那条被注释的代码取消注释。不过这条代码的效果并不是将`printf`变为`fprintf`，而是将原本要打在屏幕上的标准输出流重定向到了指定文件，事实上它并不能检测`yyout`是否成功改变了。
  当然，这也说明了一个事实，我们不一定需要改变`yyout`来指定输出的文件，直接用`freopen`函数也可以，这个函数是C语言的函数。

  接下来我们要对这个代码再做一定变化，原先我们只指定了一个输入文件和输出文件，现在我们希望可以指定多个输入文件和一个输出文件，一口气处理多个文件中的内容。
  对`main`的内容再做修改：
  （指定格式为：最后一个是输出文件，其余为输入文件）

  ```c
  int main(int argc, char **argv)
  {
    FILE *file;
    int fileNum=argc-1;
    if(fileNum>1)
    {
  	file=fopen(argv[fileNum],"w");
  	if(file)
  	{
  	  yyout=file;
  	  //freopen(argv[fileNum],"w",stdout);
  	 }
    }
    
    for(int i=1;i<=fileNum-1;i++)
    {
  	file=fopen(argv[i],"r");
  	if(file)
  	  yyin=file;
  	yylex(); 
    }
    
    if (fileNum==0)
  	yylex(); 
    yywrap();
  }
  ```

  >②扩展阅读推荐
  >《Lex与Yacc》是一本非常不错的书籍，有汉化版，推荐大家去阅读。在第二版的P19~P22里，作者用lex编写出了拥有一定语法分析能力的程序，这个程序可以让使用者自由定义任意单词的类型（当然各种类型是固定好的），然后程序在再次遇到该单词时会输出它的类型。很有挑战性，也非常有意思。
  >《flex.pdf》是flex的使用手册，网络上有汉化版流传，可以搜索阅读。

## bison/yacc入门

在使用flex分析出一段文本中的各个单元后，我们就要使用bison对这些单元间的联系进行分析，也就是语法分析。通常来说，bison/yacc会与flex/lex一同使用——如果你没有使用flex，你就要在bison代码中自己编写yylex()函数，这说明了两个工具的使用通常是密不可分的。
不同于flex的是,bison分析程序一般没有手写的分析程序那么快，所以很多人也会选择自己编写语法分析器。此外，语法分析的方式有很多种，而bison只能提供一部分，这也是一些人手写分析程序的原因。

**【flex与bison联合编译】**
通常来说，我们不能单独将bison代码编译成可执行文件，除非我们自己编写了yylex函数，但那并不是当前我们要讲述的内容。所以按照本文的惯例，我们会先对两个已经确保没有问题的代码文件进行联合编译。
通常将bison代码文件的扩展名命名为.y，这种命名方式来自于yacc，就像flex代码文件通常会命名为xx.l一样。
以下是两个文件的代码，在已经入门了flex之后，你也可以观察一下这些代码，看看在联合使用时，flex代码出现了怎样的变化，以及bison代码与flex代码之间的关系。

```c
/*test.l*/
%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(char *);
%}
NUM [1-9]+[0-9]*|0
%%

{NUM}		                	         return NUM;
"+"							return ADD;
"-"							 return SUB;
"*"							return MUL;
"/"							 return DIV;
[a-zA-Z_$]+[a-zA-Z_$0-9]*		return VAR;
\n                          		              return CR;
[ \t]+                    				 /* ignore whitespace */;
.
%%

```

```c
/*test.y*/
%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(char *);
%}

%token NUM ADD SUB MUL DIV VAR CR

%%
       line_list: line
                | line_list line
                ;
				
       line : expression CR  {printf("YES\n");}

      expression: term 
                | expression ADD term
	       | expression SUB term
                ;

            term: single
	        | term MUL single
	        | term DIV single
	        ;
				
	   single: NUM
		| VAR
		;
%%
void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}

int yywrap(){
    return 1;
}
int main()
{
    yyparse();
}

```

按照第一行的注释分别给两个文件命名，在CMD中来到文件所在路径，我们输入以下代码即可进行联合编译：

```shell
bison --yacc -dv test.y
flex test.l
gcc -o test y.tab.c lex.yy.c // 这里的test是指定生成的可执行文件的名字
```

如果此时你得到了可执行文件test.exe，说明你成功了，否则cmd会输出一些错误信息。
这也是一个很简单的程序，在cmd中执行它，它的功能是：判断一个算式是否合法。我们规定一个算式由single单元和运算符组成，single单元可以是正整数或是变量名，运算符为加减乘除。如果合法则输出YES，否则报错退出。

```shell
输入：1+a-b*3/4
输出：YES
输入：2**5-t
输出：报错退出
```

**【批处理简化】**
显然，flex与bison联合编译的代码更加复杂，如果每次都要填写，那可就令人伤脑筋了。因此如果想把注意力放在两者代码的编写上的话，还是建议使用批处理加速编译，如果你掌握了makefile的使用的话，使用makefile也是非常不错的选择。
这里给出两种批处理的写法：

```makefile
说明：直接对1.y和1.l进行编译
bison --yacc -dv 1.y
flex 1.l
gcc -o test y.tab.c lex.yy.c
使用方法：直接输名字运行该文件
```

```makefile
说明：给两个文件起同一个名字，然后给出名字编译
@echo off
set str=%1
@echo on
bison --yacc -dv %str%.y
flex %str%.l
gcc -o %str% y.tab.c lex.yy.c
使用方法：[bat文件名][空格][文件名]
```

如果想要分别指定.l和.y文件的名字，或者连生成文件的名字也想要指定，该怎么办呢？
看过本文的学习者，可能也对它们的写法有了一定的猜测。显然，在批处理中，%1可以引用第二个参数（第一个参数是批处理文件的名字），而%2则可以引用第三个参数。只要照样画葫芦，想必大家也能编写出输入多个参数的批处理文件。
**【代码分析与代码框架】**
在这一部分，我会带大家分析上面所使用到的两个代码，以此介绍联合使用时flex与bison代码的编写方法。为了省去上下查找代码的时间，在讲解时会将需要的代码再贴出来。
首先，我们来看flex的代码第一部分：

```c
%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(char *);
%}
NUM [1-9]+[0-9]*|0
%%
```

①`y.tab.h`是bison在翻译代码时自动生成的头文件（这也是为什么我们先翻译`.y`文件），如果不加上这个头文件，则编译会出错。
②`yyerror`是bison代码中要用到的报错函数，既然是bison的报错函数，那么为什么不在bison中定义呢？事实上我们在两个代码中都定义了这个函数，这是因为程序不仅在语法分析阶段会报错，词法分析阶段也是会报错的。其实bison会自动定义这个函数，但我们想要使用自己编写的报错函数的话，则要重新声明它，否则会报警告。（我们希望尽量不被警告）

接下来，看flex第二部分：

```c
{NUM}		                		return NUM;
"+"							return ADD;
"-"							 return SUB;
"*"							return MUL;
"/"							 return DIV;
[a-zA-Z_$]+[a-zA-Z_$0-9]*		return VAR;
\n                         				    return CR;
[ \t]+                   				  /* ignore whitespace */;
.
%%
```

可能有些学习者看到这里会有些疑惑，左边的pattern还认识，但是右边的action却变得陌生了。不仅全部变成了清一色的return，而且返回的值也看不懂，这些东西从来没有定义过啊！
事实上，这些符号的定义就在t.tab.h头文件中，它们都是一些互不相同的常量，这也是为什么不使用该头文件就会报错。那么这些符号是bison自动定义的吗？其实不是，我们会在编写bison代码时手动定义这些符号。
此外，在于bison一起使用时，flex的第三部分直接忽略不写，因为这些内容被搬到bison的第三部分去了。

接着，我们来看bison的代码，首先我要给出bison的代码框架，其实它与flex完全一致，格式都是为：

```c
定义(definations)
%%
规则(rules)
%%
代码(user code)

```

只不过在定义和规则部分，一些写法不同。
我们来看代码的第一部分：

```c
%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(char *);
%}

%token NUM ADD SUB MUL DIV VAR CR

%%
```

在本部分中，我们定义了`yylex()`函数和`yyerror()`函数，它们都是我们此前已经讲过的函数，`yylex`就是flex中的词法分析函数。我们需要定义这两个函数，否则可能会报警告。
此外，在C代码外，我们看到了bison的定义方式（之一）。
**在`%token`后面，跟着一些字符串，我们就是在这里定义了这些符号，它们会被翻译成C头文件，被flex引用，然后又通过`yylex()`函数`return`回来。**
如果你已经成功编译了这两个文件，那么打开y.tab头文件，观察里面的内容，在大约第50行，你可以看到如下内容：

```c
/* Tokens.  */
#define NUM 258
#define ADD 259
#define SUB 260
#define MUL 261
#define DIV 262
#define VAR 263
#define CR 264
```

这就是各个符号被定义的常数，当然，我们实际上完全不需要去关注它们具体的值是多少。我们也称这些符号为“标记”。
不过关于bison的标记值定义，还有一个小知识：0~255之间的标记值约定为字符值，由于`lex`还保留了像“文件结束”和“错误过程”这样的标记值，生成的标记值通常从258左右开始。因此，如果你在`flex`中匹配的是单个字符，其实可以直接返回`*yytext`，而不必返回一个符号，这是完全能行的。
接下来，我们看最关键的第二部分代码：

```c
%%
 line_list: line
                | line_list line
                ;
				
        line : expression CR  {printf("YES\n");}

expression: term 
                | expression ADD term
	       | expression SUB term
                ;

        term: single
	        | term MUL single
	        | term DIV single
	        ;
				
       single: NUM
		| VAR
		;
%%
```

想要读懂这部分的代码，你可能需要懂得`BNF`（巴克斯范式），以及明白什么是移进和归约，否则你会感到迷茫和不知所措。`BNF`是任何编译原理课程都会讲述的重点内容。

**一个简单形象的描述：**
假设我们想要分析英语句子的语法，现在给出一个句子：
`he gave me a book.`
如果我们想将它视作一个句子，那么可能会有以下的语法规则（我们用→表示由…组成）
<句子>→<主语><谓语><间接宾语><直接宾语>
<主语>→<代词>
<谓语>→<动词>
<间接宾语>→<代词>
<直接宾语>→<冠词><名词>
.------.
<代词>→he
<代词>→me
<冠词>→a
<名词>→book
<动词>→gave
.------.
显然，将单词归类为动名等词的动作是由flex完成的（**通常将这些不可再分的类称为终结符**）；而将这些终结符不断“合成”（归约），最后变成<句子>（**这些需要被合成的类被称为非终结符**）的任务，则是由bison来做，如果按照规则无法归约成句子，则说明输入是非法的。
此时我们再看这部分代码，为了方便区分，我们把非终结符全部大写，终结符全部小写。冒号其实就是例子中的→，表示由下面这些内容组成，而|号则表示这个非终结符有不同的归约方法。
一个例子：

```c
expression: expression '+' expression
		  | expression '-' expression
		  | NUM
		  ;
```

上面这个`BNF`就表达了这样的规则：一个数字是一个表达式；表达式+表达式还是表达式；表达式-表达式还是表达式。

**回过头来：**
第二部分规则的组成如下：`rule-> BNF action`
具体写法与flex没有太大的区别，对于`BNF`中每一个归约方法/产生式，都可以写上action。

```c
void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}

int yywrap(){
    return 1;
}
int main()
{
    yyparse();
}

```

很明显，这里给出了`yyerror`具体的报错操作；`yywrap`函数同之前在flex的讲述；而`yyparse`函数就是bison的语法分析函数。

>  **【小练习】**

```c
练习简介：
	在C语言中，我们常常需要定义变量，而定义变量是有语法规则的。
	现在我们希望编写一个分析器，判断一行定义变量的C代码是否合法。
目前我们希望以下定义方式合法：
  [类型] [变量名] ;
  [类型] [变量名] = [值];
  [类型]为int、double或char，字符的值用''括起。
  
  如果在定义变量时直接赋值，则需要满足以下规定：
  int型与char型的变量，值可以是整数或字符，不能为小数（不判断值是否会溢出）
  double型的变量，值可以是小数或整数，但不能是字符

测试数据：
  double a_test;
  int a=5;
  double b=2.33;
  char c='t';
  （以上都是合法输入）
  ...
  语法组合较多，请自行编写测试数据。

```

**小练习参考答案：**

```c
%{
	#include "y.tab.h"
	void yyerror(char *);
%}

INUM	[1-9]+[0-9]*|0
FNUM	[0-9]+\.[0-9]+
VAR 	[a-zA-Z_$]+[a-zA-Z_$0-9]*
CHAR	'.'

%%

"int"		return DEF_INT;
"double"	return DEF_DOUBLE;
"char"		return DEF_CHAR;
{INUM}		return INT;
{FNUM}		return DOUBLE;
{VAR}		return VAR;
{CHAR}		return CHAR;
"="			return EQ;
";"			return END;
"\n"		return CR;
%%

```

```c
/*仅前两部分*/
%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}
%token DEF_INT DEF_DOUBLE DEF_CHAR INT DOUBLE CHAR VAR EQ END CR

%%

	     line_list: line
			 | line_list line
			 ;
			 
		    line: define CR  {printf("YES\n");}
		 
	        define: DEF_INT VAR END
			 | DEF_DOUBLE VAR END
			 | DEF_CHAR VAR END
			 | DEF_INT VAR EQ INT END
			 | DEF_INT VAR EQ CHAR END
			 | DEF_DOUBLE VAR EQ DOUBLE END
			 | DEF_DOUBLE VAR EQ INT END
			 | DEF_CHAR VAR EQ CHAR END
			 | DEF_CHAR VAR EQ INT END

%%

```

这里对`bison`代码的第二部分进行讲解。
	首先`line_list`的定义是为**了方便读取多行输入**，否则当输入归约成`line`之后，会被程序自动`accept`，然后分析结束。此时想要读取多行输入进行判断，就必须循环调用`yyparse`。
	其次，`line`的定义是为了方便输出判断结果，`define`有多种归约方式，在每个`rule`中写上相同的动作不是一个好主意，因此**我们让`define`与回车符一起归约为`line`，此时说明输入语句已经成功归约为`define`，则可以输出`YES`**。
	最后，`define`规则直接用一大片的终结符进行表示，这样子写很简单，但看起来并不清晰，而且编写效率低下。因此`BNF`大多数时候都需要进行递归定义，能清晰有效地表达规则，但`BNF`的编写通常需要大量编译原理知识，比较考验编写者的水平。

> **【编写一个计算器】**
>
> 只有加减乘除四种功能的计算器。这个计算器的功能为，当输入合法时，输出这个表达式的值。

想必一些学习者会很为难：flex可以将识别出的词法返回给bison，但是该如何把某个识别出的数字的值传给bison呢？直接返回识别出的值是行不通的，因为其他pattern的返回值大多是符号，这些符号实际上就是数字常量，这意味着返回有些值时会被bison认为是某个符号，而且从bison规则的语法上来说这也是行不通的。
事实上，bison程序维护了两个栈，**一个是文法符号栈，用来进行语法上的归约和移进；另一个则是属性值栈，这个栈内的值是与文法符号栈一一对应的，当一个文法符号被压栈时，它的值也被压进了属性值栈。**因此，我们可以在属性值栈中寻找我们需要的值。
但是我们怎么寻找这个值呢？况且，bison也不知道某个pattern代表的是整数、小数或是其他东西，它到底把什么值压栈了呢？
此时，就要引入一个新的概念——**bison的全局变量`yylval`。在flex进行词法分析时，一旦分析成功，我们就在action中令`yylval`等于需要传入的值。**
（例子：在分析出一个整数之后，可以做`sscanf(yytext,"%d",&yylval);`操作）
这样，当文法符号返回并压栈时，yylval中的值就会被当做是这个符号的值而被压栈。
那么，`yylval`是不是什么值都能传输呢？当然没有那么简单。bison中还有一个宏，叫做`YYSTYPE`，表示`yylval`的数据类型。通常情况下，`YYSTYPE`定义为`int`型。如果想要更改，可以做如下操作：

```c
#define YYSTYPE double
```

即可将`yylval`的数据类型更变为`double`型。

但尽管如此，只能使用一种类型还是令人苦恼。绝大多数情况下，代码中不可能只有一种类型，字符型、布尔型、整数型、浮点型、字符串型……我们希望这些值都能够传给bison。因此，我们可以在**bison程序的第一部分**加入如下定义：

```c
%union{
  int inum;
  double fnum;
  char c;
  char * string;
  //其余类型随意加
}
```

这行代码的意义是，将`yylval`定义成了一个联合体类型，这样子，就可以很好地适应各种各样的情况了。

在说明了如何传递值之后，我们还需要知道，如何在bison中使用这些值。关于这方面的说明，只用文字比较难以表达，不如我们来看看，已经完成的计算器程序中，bison代码的第一二段吧。

```c
%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(char *);
%}

%union{
  int inum;
  double dnum;
}
%token ADD SUB MUL DIV CR
%token <inum> NUM
%type   <inum> expression term single

%%
       line_list: line
                      | line_list line
                      ;
				
 	      line : expression CR  {printf(">>%d\n",$1);}

  expression: term 
                      | expression ADD term   {$$=$1+$3;}
	             | expression SUB term    {$$=$1-$3;}
                      ;

	    term: single
    	   	    | term MUL single	    {$$=$1*$3;}
	       	    | term DIV single	      {$$=$1/$3;}
		    ;
				
	  single: NUM
		    ;
%%
void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}

int yywrap(){
    return 1;
}
int main()
{
    yyparse();
}
```

> 【高级bison】

这里存放了一些关于bison的知识点，对编译原理有一定掌握的人能够轻松看懂它。
`Q1`：如果语法规则中，出现了移进-归约冲突和归约-归约冲突，bison:会怎么做？
`A1`：当存在冲突时，bison将执行默认动作。当存在移进-归约冲突时，bison将进行移进。当存在归约-归约冲突时，bison将执行列出的第一条规则。对于任何冲突，它都会显示警告信息。所以应该书写明确的语法规则，这通常需要我们掌握一些消除模糊性的方法。

`Q2`：bison的第一部分，还有什么用以定义的符号吗？
`A2`：包括但不限于`%left`，`%right`，`%nonassoc`。它们也是定义文法中使用的终结符，定义形式与%token类似，但是他们定义的终结符具有某种优先级和结合性，`%left`表示左结合，`%right`表示右结合，`%nonassoc`表示不可结合（即它定义的终结符不能连续出现：例如`<`，如果文法中不允许出现形如`a<b<c`的句子，则`<`就是不可结合的）。而优先级关系则是以他们定义出现的顺序决定的，先定义的优先级低，最后定义的优先级最高，同时定义的优先级相同。

> 【推荐阅读】

+ 依旧是《Lex与Yacc》，经典之作；

+ bison的使用手册.
+ 如果还想提高掌握，不如去看看一些自制编程语言与编译器的书籍，或许对你有所帮助。以及，如果想提高实力，务必提升对编译原理基础知识的掌握。

