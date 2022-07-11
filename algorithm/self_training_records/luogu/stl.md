## **Basic**

#### **快读函数**

```c++
inline int readInt() {
        int x = 0;
        int symbol = 1;
        char c = getchar();
        while (c < '0' || c > '9') {
            if (c == '-') {
                symbol = -1;
                c = getchar();
            }
        }
        while (c >= '0' && c <= '9') {
            x = (x << 3) + (x << 1) + (c ^ 48);
            c = getchar();
        }
        return x * symbol;

    }
```

#### **qsort**

> sort 使用时得注明：`using namespace std`;   或直接打 `std::sort()`  还得加上  `algorithm` 头文件

```c++
#include<algorithm>
using namespace std;
int main() {
    int a[20];
    cin>>a[i];
    sort(a,a+20);             //范围，很明显这里是a+20 注意，这是必要的，如果是a+19
    cout<<a[i]<<endl;
    return 0;
}
```

调用`qsort`的时候：

```c++
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b) {
    return *(int *)a-*(int *)b;      //*(int *)a表示先将空类型指针强转为int类型指针，在对该指针取其中的值
}
```

调用：

```c++
qsort (a, n, sizeof(int), cmp);
```

| 函数名                                                        | 用法                                                                                                          |
| ---------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- |
| sort (first, last)                                         | 对容器或普通数组中 [first, last) 范围内的元素进行排序，默认进行升序排序。                                                                |
| stable_sort (first, last)                                  | 和 sort() 函数功能相似，不同之处在于，**对于 [first, last) 范围内值相同的元素，该函数不会改变它们的相对位置**。                                       |
| partial_sort (first, middle, last)                         | 从 [first,last) 范围内，筛选出 middle-first 个最小的元素并排序存放在 [first，middle) 区间中。                                        |
| partial_sort_copy (first, last, result_first, result_last) | 从 [first, last) 范围内筛选出 result_last-result_first 个元素排序并存储到 [result_first, result_last) 指定的范围中。               |
| is_sorted (first, last)                                    | **检测 [first, last) 范围内是否已经排好序，默认检测是否按升序排序**。                                                                |
| is_sorted_until (first, last)                              | 和 is_sorted() 函数功能类似，唯一的区别在于，如果 [first, last) 范围的元素**没有排好序，则该函数会返回一个指向首个不遵循排序规则的元素的迭代器**。                   |
| void nth_element (first, nth, last)                        | 找到 [first, last) 范围内按照排序规则（默认按照升序排序）应该位于第 nth 个位置处的元素，并将其放置到此位置。同时使该位置左侧的所有元素都比其存放的元素小，该位置右侧的所有元素都比其存放的元素大。 |

```c++
bool mycomp(int i, int j) {
    return (i < j);
}
//以函数对象的方式实现自定义排序规则
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i < j);
    }
};
    
std::vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };
   
//调用第一种语法格式，对 32、71、12、45 进行排序  
std::sort(myvector.begin(), myvector.begin() + 4); 
//(12 32 45 71) 26 80 53 33
    
//调用第二种语法格式，利用STL标准库提供的其它比较规则（比如 greater<T>）进行排序
std::sort(myvector.begin(), myvector.begin() + 4, std::greater<int>()); 
//(71 45 32 12) 26 80 53 33
   
    
//调用第二种语法格式，通过自定义比较规则进行排序
std::sort(myvector.begin(), myvector.end(), mycomp2());
//12 26 32 33 45 53 71 80
```

程序中分别以函数和函数对象的方式自定义了具有相同功能的 mycomp 和 mycomp2 升序排序规则。需要注意的是，和为关联式容器设定排序规则不同，给 sort() 函数指定排序规则时，需要为其传入一个函数名（例如 mycomp ）或者函数对象（例如 std::greater<int>() 或者 mycomp2()）

#### find

```c++
    //find() 函数作用于普通数组
    char stl[] ="http://c.biancheng.net/stl/";
    //调用 find() 查找第一个字符 'c'
    char * p = find(stl, stl + strlen(stl), 'c');
    //判断是否查找成功
    if (p != stl + strlen(stl)) {
        cout << p << endl;
    }
    //find() 函数作用于容器
    std::vector<int> myvector{ 10,20,30,40,50 };
    std::vector<int>::iterator it;
    it = find(myvector.begin(), myvector.end(), 30);
```

---

## **vector**

```c++
#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<string> v1;
    v1.push_back("nhooo");
    v1.push_back(".com");
    for(vector<string>::iterator itr=v1.begin();itr!=v1.end();++itr) {
        cout<<*itr;
    }
    return 0; 
}
```

| 函数                                                                                  | 描述                                   |
| ----------------------------------------------------------------------------------- | ------------------------------------ |
| [at(idx)](https://www.nhooo.com/cpp/cpp-vector-at-function.html)                    | 传回索引idx所指的数据，如果idx越界，抛出out_of_range。 |
| [back()](https://www.nhooo.com/cpp/cpp-vector-back-function.html)                   | 返回最后一个原始，不检查这个数据是否存在。                |
| [front()](https://www.nhooo.com/cpp/cpp-vector-front-function.html)                 | 返回第一个元素。                             |
| [swap()](https://www.nhooo.com/cpp/cpp-vector-swap-function.html)                   | 交换两个Vector。                          |
| [push_back()](https://www.nhooo.com/cpp/cpp-vector-push-back-function.html)         | 在Vector最后添加一个元素。                     |
| [pop_back()](https://www.nhooo.com/cpp/cpp-vector-pop-back-function.html)           | 它从向量中删除最后一个元素。                       |
| [empty()](https://www.nhooo.com/cpp/cpp-vector-empty-function.html)                 | 判断Vector是否为空（返回true时为空）              |
| [insert()](https://www.nhooo.com/cpp/cpp-vector-insert-function.html)               | 它将在指定位置插入新元素。                        |
| [erase()](https://www.nhooo.com/cpp/cpp-vector-erase-function.html)                 | 删除指定的元素。                             |
| [resize()](https://www.nhooo.com/cpp/cpp-vector-resize-function.html)               | 它修改向量的大小。                            |
| [clear()](https://www.nhooo.com/cpp/cpp-vector-clear-function.html)                 | 它从向量中删除所有元素。                         |
| [size()](https://www.nhooo.com/cpp/cpp-vector-size-function.html)                   | 返回Vector元素数量的大小。                     |
| [capacity()](https://www.nhooo.com/cpp/cpp-vector-capacity-function.html)           | 返回vector所能容纳的元素数量(在不重新分配内存的情况下）      |
| [assign()](https://www.nhooo.com/cpp/cpp-vector-assign-function.html)               | 它将新值分配给向量。                           |
| [operator=()](https://www.nhooo.com/cpp/cpp-vector-operator-equal-function.html)    | 它将新值分配给向量容器。                         |
| [operator[]()](https://www.nhooo.com/cpp/cpp-vector-operator-select-function.html)  | 它访问指定的元素。                            |
| [end()](https://www.nhooo.com/cpp/cpp-vector-end-function.html)                     | 返回最末元素的迭代器(实指向最末元素的下一个位置)            |
| [emplace()](https://www.nhooo.com/cpp/cpp-vector-emplace-function.html)             | 它将在位置pos之前插入一个新元素。                   |
| [emplace_back()](https://www.nhooo.com/cpp/cpp-vector-emplace-back-function.html)   | 它在末尾插入一个新元素。                         |
| [rend()](https://www.nhooo.com/cpp/cpp-vector-rend-function.html)                   | 它指向向量的第一个元素之前的元素。                    |
| [rbegin()](https://www.nhooo.com/cpp/cpp-vector-rbegin-function.html)               | 它指向向量的最后一个元素。                        |
| [begin()](https://www.nhooo.com/cpp/cpp-vector-begin-function.html)                 | 返回第一个元素的迭代器。                         |
| [max_size()](https://www.nhooo.com/cpp/cpp-vector-max-size-function.html)           | 返回Vector所能容纳元素的最大数量（上限）。             |
| [cend()](https://www.nhooo.com/cpp/cpp-vector-cend-function.html)                   | 它指向量中的last-last-element。             |
| [cbegin()](https://www.nhooo.com/cpp/cpp-vector-cbegin-function.html)               | 它指向量的第一个元素。                          |
| [crbegin()](https://www.nhooo.com/cpp/cpp-vector-crbegin-function.html)             | 它指的是向量的最后一个字符。                       |
| [crend()](https://www.nhooo.com/cpp/cpp-vector-crend-function.html)                 | 它指的是向量的第一个元素之前的元素。                   |
| [data()](https://www.nhooo.com/cpp/cpp-vector-data-function.html)                   | 它将向量的数据写入数组。                         |
| [shrink_to_fit()](https://www.nhooo.com/cpp/cpp-vector-shrink-to-fit-function.html) | 它减少了容量并使它等于向量的大小。                    |

```c++
vector v{1,2,3,4,5};
vector v1;
v1.assign(v.begin()+1,v.end()-1);

vector v;
v.assign(5,'C');
```

## **dequeue**

```c++
dequeue<type> name;
```

| 方法                                                                                 | 描述                  |
| ---------------------------------------------------------------------------------- | ------------------- |
| [assign()](https://www.nhooo.com/cpp/cpp-deque-assign-function.html)               | 它分配新内容并替换旧内容。       |
| [emplace()](https://www.nhooo.com/cpp/cpp-deque-emplace-function.html)             | 它将在指定位置添加一个新元素。     |
| [emplace_back()](https://www.nhooo.com/cpp/cpp-deque-emplace_back-function.html)   | 它在末尾添加一个新元素。        |
| [emplace_front()](https://www.nhooo.com/cpp/cpp-deque-emplace_front-function.html) | 它在双端队列的开头添加一个新元素。   |
| [insert()](https://www.nhooo.com/cpp/cpp-deque-insert-function.html)               | 它在指定位置之前添加一个新元素。    |
| [push_back()](https://www.nhooo.com/cpp/cpp-deque-push_back-function.html)         | 它在容器的末尾添加一个新元素。     |
| [push_front()](https://www.nhooo.com/cpp/cpp-deque-push_front-function.html)       | 它在容器的开头添加一个新元素。     |
| [pop_back()](https://www.nhooo.com/cpp/cpp-deque-pop_back-function.html)           | 它从双端队列中删除最后一个元素。    |
| [pop_front()](https://www.nhooo.com/cpp/cpp-deque-pop_front-function.html)         | 它从双端队列中删除第一个元素。     |
| [swap()](https://www.nhooo.com/cpp/cpp-deque-swap-function.html)                   | 它交换两个双端队列的内容。       |
| [clear()](https://www.nhooo.com/cpp/cpp-deque-clear-function.html)                 | 它将删除双端队列的所有内容。      |
| [empty()](https://www.nhooo.com/cpp/cpp-deque-empty-function.html)                 | 它检查容器是否为空。          |
| [erase()](https://www.nhooo.com/cpp/cpp-deque-erase-function.html)                 | 它删除元素。              |
| [max_size()](https://www.nhooo.com/cpp/cpp-deque-max_size-function.html)           | 它确定双端队列的最大大小。       |
| [resize()](https://www.nhooo.com/cpp/cpp-deque-resize-function.html)               | 它改变了双端队列的大小。        |
| [shrink_to_fit()](https://www.nhooo.com/cpp/cpp-deque-shrink_to_fit-function.html) | 它减少了内存以适合双端队列的大小。   |
| [size()](https://www.nhooo.com/cpp/cpp-deque-size-function.html)                   | 它返回元素数。             |
| [at()](https://www.nhooo.com/cpp/cpp-deque-at-function.html)                       | 它访问位置pos处的元素。       |
| [operator[]()](https://www.nhooo.com/cpp/cpp-deque-operator-select-function.html)  | 它访问位置pos处的元素。       |
| [operator=()](https://www.nhooo.com/cpp/cpp-deque-operator-equal-function.html)    | 它将新的内容分配给容器。        |
| [back()](https://www.nhooo.com/cpp/cpp-deque-back-function.html)                   | 它访问最后一个元素。          |
| [begin()](https://www.nhooo.com/cpp/cpp-deque-begin-function.html)                 | 它将迭代器返回到双端队列的开头。    |
| [cbegin()](https://www.nhooo.com/cpp/cpp-deque-cbegin-function.html)               | 它向双端队列的开头返回一个常量迭代器。 |
| [end()](https://www.nhooo.com/cpp/cpp-deque-end-function.html)                     | 它将迭代器返回到末尾。         |
| [cend()](https://www.nhooo.com/cpp/cpp-deque-cend-function.html)                   | 它将常量迭代器返回到末尾。       |
| [rbegin()](https://www.nhooo.com/cpp/cpp-deque-rbegin-function.html)               | 它将反向迭代器返回到开头。       |
| [crbegin()](https://www.nhooo.com/cpp/cpp-deque-crbegin-function.html)             | 它将常量反向迭代器返回到开头。     |
| [rend()](https://www.nhooo.com/cpp/cpp-deque-rend-function.html)                   | 它将反向迭代器返回到末尾。       |
| [crend()](https://www.nhooo.com/cpp/cpp-deque-crend-function.html)                 | 它将常量反向迭代器返回到末尾。     |
| front()                                                                            | 它访问最后一个元素。          |

```c++
deque deq={7,8,4,5};
deque::iterator itr;
deq.emplace(deq.begin(),1);

  deque d={'C','+'};
  deque::iterator itr=d.begin();
  ++itr;
  d.emplace(itr,'+');
```

```c++
deque<string> language={"java",".net","C"};
deque<string>::iterator itr=language.begin();
   ++itr;
   language.insert(itr, "C++");
// 指定位置pos之前insert:  java C++ .net C
```

```c++
deque<string> str={"C是一种编程语言"};
deque<string> str1={"java是一种编程语言"};
str.swap(str1);
```

```c++
deque<string> fruit = {"mango","apple","banana","kiwi"};
deque<string>::const_iterator itr;
itr=fruit.cbegin() + 3;
// 返回第四个元素开始的迭代器
```

```c++
dequei={10,20,30,40,50}; deque::const_reverse_iterator citr; 
for(citr=i.crbegin();citr!=i.crend();++citr) { 
 cout<<*citr;        
 cout<<" ";    
}
 //  50 40 30 20 10
```

## **list**

> - List是连续的容器，而vector是非连续的容器，即list将元素存储在连续的存储器中，而vector存储在不连续的存储器中。
> 
> - **向量（vector）中间的插入和删除是非常昂贵的，因为它需要大量的时间来移动所有的元素**。链表克服了这个问题，它是使用list容器实现的。
> 
> - **List支持双向，并为插入和删除操作提供了一种有效的方法。**
> 
> - **在列表中遍历速度很慢**，因为列表元素是按顺序访问的，而vector支持随机访问。

```c++
#include <list>
using namespace std;
list<int> l;
// 创建一个包含 n 个元素的 list 容器
std::list<int> values(10);
std::list<int> values(10, 5);
list<int> l{1,2,3,4};
list<int> new_list = {1,2,3,4};

std::list<int> value1(10);
std::list<int> value2(value1);

//拷贝普通数组，创建list容器
int a[] = { 1,2,3,4,5 };
std::list<int> values(a, a+5);
//拷贝其它类型的容器，创建 list 容器
std::array<int, 5>arr{ 11,12,13,14,15 };
std::list<int>values(arr.begin()+2, arr.end());//拷贝arr容器中的{13,14,15}
```

| 方法                                                                                | 描述                    |
| --------------------------------------------------------------------------------- | --------------------- |
| [insert()](https://www.nhooo.com/cpp/cpp-list-insert-function.html)               | 它将新元素插入到迭代器指向的位置之前。   |
| [push_back()](https://www.nhooo.com/cpp/cpp-list-push_back-function.html)         | 它在容器的末尾添加了一个新元素。      |
| [push_front()](https://www.nhooo.com/cpp/cpp-list-push_front-function.html)       | 它在前面增加了一个新元素。         |
| [pop_back()](https://www.nhooo.com/cpp/cpp-list-pop_back-function.html)           | 删除最后一个元素。             |
| [pop_front()](https://www.nhooo.com/cpp/cpp-list-pop_front-function.html)         | 删除第一个元素。              |
| [empty()](https://www.nhooo.com/cpp/cpp-list-empty-function.html)                 | 它检查列表是否为空。            |
| [size()](https://www.nhooo.com/cpp/cpp-list-size-function.html)                   | 它查找列表中存在的元素数。         |
| [max_size()](https://www.nhooo.com/cpp/cpp-list-max_size-function.html)           | 它找到列表的最大大小。           |
| [front()](https://www.nhooo.com/cpp/cpp-list-front-function.html)                 | 它返回列表的第一个元素。          |
| [back()](https://www.nhooo.com/cpp/cpp-list-back-function.html)                   | 它返回列表的最后一个元素。         |
| [swap()](https://www.nhooo.com/cpp/cpp-list-swap-function.html)                   | 当两个列表的类型相同时，它将交换两个列表。 |
| [reverse()](https://www.nhooo.com/cpp/cpp-list-reverse-function.html)             | 它反转了列表的元素。            |
| [sort()](https://www.nhooo.com/cpp/cpp-list-sort-function.html)                   | 它以递增的顺序对列表中的元素进行排序。   |
| [merge()](https://www.nhooo.com/cpp/cpp-list-merge-function.html)                 | 它合并两个排序的列表。           |
| [splice()](https://www.nhooo.com/cpp/cpp-list-splice-function.html)               | 它将新列表插入到调用列表中。        |
| [unique()](https://www.nhooo.com/cpp/cpp-list-unique-function.html)               | 它从列表中删除所有重复的元素。       |
| [resize()](https://www.nhooo.com/cpp/cpp-list-resize-function.html)               | 它更改列表容器的大小。           |
| [assign()](https://www.nhooo.com/cpp/cpp-list-assign-function.html)               | 它将一个新元素分配给列表容器。       |
| [emplace()](https://www.nhooo.com/cpp/cpp-list-emplace-function.html)             | 它将在指定位置插入一个新元素。       |
| [emplace_back()](https://www.nhooo.com/cpp/cpp-list-emplace_back-function.html)   | 它将在容器的末尾插入一个新元素。      |
| [emplace_front()](https://www.nhooo.com/cpp/cpp-list-emplace_front-function.html) | 它将在列表的开头插入一个新元素。      |

```c++
    std::list<int> values{ 1,2 };
    //第一种格式用法
    values.insert(values.begin() , 3);//{3,1,2}
    //第二种格式用法
    values.insert(values.end(), 2, 5);//{3,1,2,5,5}
    //第三种格式用法
    std::array<int, 3>test{ 7,8,9 };
    values.insert(values.end(), test.begin(), test.end());//{3,1,2,5,5,7,8,9}
    //第四种格式用法
    values.insert(values.end(), { 10,11 });//{3,1,2,5,5,7,8,9,10,11}
```

## **C++ STL关联式容器种类**

C++ STL 标准库提供了 4 种关联式容器，分别为 `map、set、multimap、multiset，`其各自的特点如表 1 所示。

| 关联式容器名称    | 特点                                                                                                                         |
| ---------- | -------------------------------------------------------------------------------------------------------------------------- |
| `map`      | 定义在 <map> 头文件中，使用该容器存储的数据，**其各个元素的键必须是唯一的（即不能重复）**，**该容器会根据各元素键的大小，默认进行升序排序（调用 std::less<T>）**。                            |
| `set`      | 定义在 <set> 头文件中，使用该容器存储的数据，**各个元素键和值完全相同，且各个元素的值不能重复（保证了各元素键的唯一性）**。**该容器会自动根据各个元素的键（其实也就是元素值）的大小进行升序排序（调用 std::less<T>）**。 |
| `multimap` | 定义在 **<map>** 头文件中，和 map 容器唯一的不同在于，**multimap 容器中存储元素的键可以重复**。                                                             |
| `multiset` | 定义在 **<set>** 头文件中，和 set 容器唯一的不同在于，**multiset 容器中存储元素的值可以重复（一旦值重复，则意味着键也是重复的）**。                                           |

> 除此之外，C++ 11 还新增了 4 种哈希容器，即 `unordered_map`、`unordered_multimap` 以及 `unordered_set`、`unordered_multiset`。严格来说，它们也属于关联式容器，**但由于哈希容器底层采用的是哈希表，而不是红黑树**，因此本教程将它们分开进行讲解。

**eg:**

```c++
#include <iostream>
#include <map> //使用 map 容器，必须引入该头文件
#include <string>
using namespace std;
int main() {
    //创建一个空的 map 关联式容器，该容器中存储的键值对，其中键为 string 字符串，值也为 string 字符串类型
    map<string, string> mymap;
    //向 mymap 容器中添加数据
    mymap["http://c.biancheng.net/c/"] = "C语言教程";
    mymap["http://c.biancheng.net/python/"] = "Python教程";
    mymap["http://c.biancheng.net/java/"] = "Java教程";
    //使用 map 容器的迭代器，遍历 mymap 容器，并输出其中存储的各个键值对
    for (map<string, string>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        //输出各个元素中的键和值
        cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}
```

## **set**

#### **构造函数/析构函数**

| 函数                                                                       | 描述              |
| ------------------------------------------------------------------------ | --------------- |
| [(constructor)](https://www.nhooo.com/cpp/cpp-set-constructor.html)      | 构造集             |
| [(destructor)](https://www.nhooo.com/cpp/cpp-set-destructor.html)        | set析构函数         |
| [operator=](https://www.nhooo.com/cpp/cpp-set-operator=()-function.html) | 将集合的元素复制到另一个集合。 |

```c++
   // 默认构造函数
   set<char> s;

   int evens[] = {2,4,6,8,10};
   // 范围构造函数
   set<int> myset (evens, evens+5); // 大小：5

   // 默认构造函数
   std::set<int> s1;
   s1.insert(5);
   s1.insert(10);
   // 复制构造函数 浅拷贝
   set<int> s2(s1);

   // 默认构造函数
   set<char> s1;
   s1.insert('x');
   s1.insert('y');
   // Move 构造函数
   set<char> s2(move(s1));

   // 初始化列表构造函数
   set<string> fruit {
      "orange", "apple", "mango", "peach", "grape"
   };
   
    std::set<std::string> copyset(myset);
    //等同于
    //std::set<std::string> copyset = myset

   
```

### 迭代器

| 函数                                                                 | 描述                     |
| ------------------------------------------------------------------ | ---------------------- |
| [begin](https://www.nhooo.com/cpp/cpp-set-begin-function.html)     | 返回一个指向集合中第一个元素的迭代器。    |
| [cbegin](https://www.nhooo.com/cpp/cpp-set-cbegin-function.html)   | 返回指向集合中第一个元素的const迭代器。 |
| [end](https://www.nhooo.com/cpp/cpp-set-end-function.html)         | 返回指向末尾的迭代器。            |
| [cend](https://www.nhooo.com/cpp/cpp-set-cend-function.html)       | 返回指向末尾的常量迭代器。          |
| [rbegin](https://www.nhooo.com/cpp/cpp-set-rbegin-function.html)   | 返回指向末尾的反向迭代器。          |
| [rend](https://www.nhooo.com/cpp/cpp-set-rend-function.html)       | 返回指向起点的反向迭代器。          |
| [crbegin](https://www.nhooo.com/cpp/cpp-set-crbegin-function.html) | 返回指向末尾的常量反向迭代器。        |
| [crend](https://www.nhooo.com/cpp/cpp-set-crend-function.html)     | 返回指向起点的常量反向迭代器。        |

### 容量

| 函数                                                                   | 描述               |
| -------------------------------------------------------------------- | ---------------- |
| [empty](https://www.nhooo.com/cpp/cpp-set-empty-function.html)       | 如果set为空，则返回true。 |
| [size](https://www.nhooo.com/cpp/cpp-set-size-function.html)         | 返回集合中元素的数量。      |
| [max_size](https://www.nhooo.com/cpp/cpp-set-max_size-function.html) | 返回集合的最大大小。       |

### 修饰符

| 函数                                                                           | 描述                  |
| ---------------------------------------------------------------------------- | ------------------- |
| [insert](https://www.nhooo.com/cpp/cpp-set-insert-function.html)             | 在集合中插入元素。           |
| [erase](https://www.nhooo.com/cpp/cpp-set-erase-function.html)               | 从集合中擦除元素。           |
| [swap](https://www.nhooo.com/cpp/cpp-set-swap-function.html)                 | 交换集合的内容。            |
| [clear](https://www.nhooo.com/cpp/cpp-set-clear-function.html)               | 删除集合中的所有元素。         |
| [emplace](https://www.nhooo.com/cpp/cpp-set-emplace-function.html)           | 构造新元素并将其插入到集合中。     |
| [emplace_hint](https://www.nhooo.com/cpp/cpp-set-emplace_hint-function.html) | 通过提示构造新元素并将其插入到集合中。 |

### 观测比较

| 函数                                                                       | 描述                |
| ------------------------------------------------------------------------ | ----------------- |
| [key_comp](https://www.nhooo.com/cpp/cpp-set-key_comp-function.html)     | 返回一个用于元素间值比较的函数。  |
| [value_comp](https://www.nhooo.com/cpp/cpp-set-value_comp-function.html) | 返回一个用于比较元素间的值的函数。 |

### 操作查找

| 函数                                                                         | 描述                       |
| -------------------------------------------------------------------------- | ------------------------ |
| [find](https://www.nhooo.com/cpp/cpp-set-find-function.html)               | 搜索具有给定键的元素。              |
| [count](https://www.nhooo.com/cpp/cpp-set-count-function.html)             | 获取与给定键匹配的元素数。            |
| [lower_bound](https://www.nhooo.com/cpp/cpp-set-lower_bound-function.html) | 返回指向大于（或等于）某值的第一个元素的迭代器。 |
| [upper_bound](https://www.nhooo.com/cpp/cpp-set-upper_bound-function.html) | 返回大于某个值元素的迭代器。           |
| [equal_range](https://www.nhooo.com/cpp/cpp-set-equal_range-function.html) | 返回集合中与给定值相等的上下限的两个迭代器。   |

### 分配器

| 函数                                                                             | 描述              |
| ------------------------------------------------------------------------------ | --------------- |
| [get_allocator](https://www.nhooo.com/cpp/cpp-set-get_allocator-function.html) | 返回用于构造集合的分配器对象。 |

## 非成员重载函数

| 函数                                                                                     | 描述               |
| -------------------------------------------------------------------------------------- | ---------------- |
| [operator==](https://www.nhooo.com/cpp/cpp-set-non-member-operator==.html)             | 检查两组是否相等。        |
| [operator!=](https://www.nhooo.com/cpp/cpp-set-non-member-operator!=.html)             | 检查两组是否相等。        |
| [operator<](https://www.nhooo.com/cpp/cpp-set-non-member-operator-less-than.html)      | 检查第一组是否小于其他组。    |
| [operator<=](https://www.nhooo.com/cpp/cpp-set-non-member-operator-less-than=.html)    | 检查第一组是否小于或等于其他。  |
| [operator>](https://www.nhooo.com/cpp/cpp-set-non-member-operator-greater-than.html)   | 检查第一个集合是否大于其他集合。 |
| [operator>=](https://www.nhooo.com/cpp/cpp-set-non-member-operator-greater-than=.html) | 检查第一个集合是否大于其他集合。 |
| [swap()](https://www.nhooo.com/cpp/cpp-set-non-member-swap-function.html)              | 交换两组元素。          |



## **pair**

> 专门用来将 2 个普通元素 first 和 second（可以是 C++ 基本数据类型、结构体、类自定的类型）创建成一个新元素`<first, second>`

注意，pair 类模板定义在`<utility>`头文件中，所以在使用该类模板之前，需引入此头文件。

```c++
#1) 默认构造函数，即创建空的 pair 对象
pair();
#2) 直接使用 2 个元素初始化成 pair 对象
pair (const first_type& a, const second_type& b);
#3) 拷贝（复制）构造函数，即借助另一个 pair 对象，创建新的 pair 对象
template<class U, class V> pair (const pair<U,V>& pr);
#4) 移动构造函数
template<class U, class V> pair (pair<U,V>&& pr);
#5) 使用右值引用参数，创建 pair 对象
template<class U, class V> pair (U&& a, V&& b);

// 调用构造函数 1，也就是默认构造函数
pair <string, double> pair1;
// 调用第 2 种构造函数
pair <string, string> pair2("STL教程","http://c.biancheng.net/stl/");  
// 调用拷贝构造函数
pair <string, string> pair3(pair2);
//调用移动构造函数
pair <string, string> pair4(make_pair("C++教程", http://c.biancheng.net/cplus/"));
// 调用第 5 种构造函数
pair <string, string> pair5(string("Python教程"), string("http://c.biancheng.net/python/")); 

pair1.first = "Java教程";
pair1.second = "http://c.biancheng.net/java/";
```

`<utility>`头文件中除了提供创建 pair 对象的方法之外，还为 pair 对象重载了 `<、<=、>、>=、==、!=` 这 6 的运算符，其运算规则是：对于进行比较的 2 个 pair 对象，**先比较 pair.first 元素的大小，如果相等则继续比较 pair.second 元素的大小**。

pair类模板还提供有一个 `swap() `成员函数，能够互换 2 个 pair 对象的键值对，其操作成功的前提是这 2 个 pair 对象的键和值的类型要相同.

### map

```c++
#include <map>
using namespace std;

std::map<std::string, int>myMap;
std::map<std::string, int>myMap{ {"C语言教程",10},{"STL教程",20} };
std::map<std::string, int>myMap {
    std::make_pair("C语言教程",10),std::make_pair("STL教程",20)
};
std::map<std::string, int>newMap(myMap);

// 创建一个会返回临时 map 对象的函数
std::map<std::string,int> disMap() {
    std::map<std::string, int>tempMap{ {"C语言教程",10},{"STL教程",20} };
    return tempMap;
}
// 调用 map 类模板的移动构造函数创建 newMap 容器
std::map<std::string, int>newMap(disMap());


// 下面程序手动修改了 myMap 容器的排序规则，令其作降序排序：
std::map<std::string, int, std::greater<std::string> >myMap{ 
    {"C语言教程",10},{"STL教程",20} 
};
```

另外需要注意的是，**使用 map 容器存储的各个键值对，键的值既不能重复也不能被修改**。换句话说，map 容器中存储的各个键值对不仅键的值独一无二，键的类型也会用 **const 修饰**，这意味着只要键值对被存储到 map 容器中，其键的值将不能再做任何修改。

| 成员方法             | 功能                                                                                                                                                                       |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| begin()          | 返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。                                                                                           |
| end()            | 返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。                                                                 |
| rbegin()         | 返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。                                                                                         |
| rend()           | 返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。                                                                                  |
| cbegin()         | 和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。                                                                                                                    |
| cend()           | 和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。                                                                                                                      |
| crbegin()        | 和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。                                                                                                                   |
| crend()          | 和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。                                                                                                                     |
| find(key)        | 在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。                                                     |
| lower_bound(key) | 返回一个指向当前 map 容器中第一个大于或等于 key 的键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。                                                                                     |
| upper_bound(key) | 返回一个指向当前 map 容器中第一个大于 key 的键值对的迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。                                                                                          |
| equal_range(key) | 该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对（map 容器键值对唯一，因此该范围最多包含一个键值对）。 |
| empty()          | 若容器为空，则返回 true；否则 false。                                                                                                                                                 |
| size()           | 返回当前 map 容器中存有键值对的个数。                                                                                                                                                    |
| max_size()       | 返回 map 容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。                                                                                                                                  |
| operator[]       | map容器重载了 [] 运算符，只要知道 map 容器中某个键值对的键的值，就可以向获取数组中元素那样，通过键直接获取对应的值。                                                                                                         |
| at(key)          | 找到 map 容器中 key 键对应的值，如果找不到，该函数会引发 out_of_range 异常。                                                                                                                       |
| insert()         | 向 map 容器中插入键值对。                                                                                                                                                          |
| erase()          | 删除 map 容器指定位置、指定键（key）值或者指定区域内的键值对。后续章节还会对该方法做重点讲解。                                                                                                                      |
| swap()           | 交换 2 个 map 容器中存储的键值对，这意味着，操作的 2 个键值对的类型必须相同。                                                                                                                             |
| clear()          | 清空 map 容器中所有的键值对，即使 map 容器的 size() 为 0。                                                                                                                                  |
| emplace()        | 在当前 map 容器中的指定位置处构造新键值对。其效果和插入键值对一样，但效率更高。                                                                                                                               |
| emplace_hint()   | 在本质上和 emplace() 在 map 容器中构造新键值对的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示键值对生成位置的迭代器，并作为该方法的第一个参数。                                                                                   |
| count(key)       | 在当前 map 容器中，查找键为 key 的键值对的个数并返回。注意，由于 map 容器中各键值对的键的值是唯一的，因此该函数的返回值最大为 1。                                                                                                |

```c++
    //创建空 map 容器，默认根据个键值对中键的值，对键值对做降序排序
    std::map<std::string, std::string, std::greater<std::string>>myMap;
    //调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
    myMap.emplace("C语言教程","http://c.biancheng.net/c/");
    myMap.emplace("Python教程", "http://c.biancheng.net/python/");
    myMap.emplace("STL教程", "http://c.biancheng.net/stl/");
    //输出当前 myMap 容器存储键值对的个数
    cout << "myMap size==" << myMap.size() << endl;
    //判断当前 myMap 容器是否为空
    if (!myMap.empty()) {
        //借助 myMap 容器迭代器，将该容器的键值对逐个输出
        for (auto i = myMap.begin(); i != myMap.end(); ++i) {
            cout << i->first << " " << i->second << endl;
        }
    }  
```

### unordered_map

```c++
#include <unordered_map>
using namespace std;

std::unordered_map<std::string, std::string> umap;
std::unordered_map<std::string, std::string> umap2(umap);

//返回临时 unordered_map 容器的函数
std::unordered_map <std::string, std::string > retUmap() {
    std::unordered_map<std::string, std::string> tempUmap {
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"},
        {"Linux教程","http://c.biancheng.net/linux/"} 
    };
    return tempUmap;
}
//调用移动构造函数，创建 umap2 容器
std::unordered_map<std::string, std::string> umap2(retUmap());

//传入 2 个迭代器，
std::unordered_map<std::string, std::string> umap2
(++umap.begin(),umap.end());
```

| 成员方法               | 功能                                                                                                                            |
| ------------------ | ----------------------------------------------------------------------------------------------------------------------------- |
| begin()            | 返回指向容器中第一个键值对的正向迭代器。                                                                                                          |
| end()              | 返回指向容器中最后一个键值对之后位置的正向迭代器。                                                                                                     |
| cbegin()           | 和 begin() 功能相同，只不过在其基础上增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。                                                                |
| cend()             | 和 end() 功能相同，只不过在其基础上，增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。                                                                 |
| empty()            | 若容器为空，则返回 true；否则 false。                                                                                                      |
| size()             | 返回当前容器中存有键值对的个数。                                                                                                              |
| max_size()         | 返回容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。                                                                                            |
| operator[key]      | 该模板类中重载了 [] 运算符，其功能是可以向访问数组中元素那样，只要给定某个键值对的键 key，就可以获取该键对应的值。注意，如果当前容器中没有以 key 为键的键值对，则其会使用该键向当前容器中插入一个新键值对。                  |
| at(key)            | 返回容器中存储的键 key 对应的值，如果 key 不存在，则会抛出 out_of_range 异常。                                                                           |
| find(key)          | 查找以 key 为键的键值对，如果找到，则返回一个指向该键值对的正向迭代器；反之，则返回一个指向容器中最后一个键值对之后位置的迭代器（如果 end() 方法返回的迭代器）。                                        |
| count(key)         | 在容器中查找以 key 键的键值对的个数。                                                                                                         |
| equal_range(key)   | 返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中键为 key 的键值对所在的范围。                                                                            |
| emplace()          | 向容器中添加新键值对，效率比 insert() 方法高。                                                                                                  |
| emplace_hint()     | 向容器中添加新键值对，效率比 insert() 方法高。                                                                                                  |
| insert()           | 向容器中添加新键值对。                                                                                                                   |
| erase()            | 删除指定键值对。                                                                                                                      |
| clear()            | 清空容器，即删除容器中存储的所有键值对。                                                                                                          |
| swap()             | 交换 2 个 unordered_map 容器存储的键值对，前提是必须保证这 2 个容器的类型完全相等。                                                                          |
| bucket_count()     | 返回当前容器底层存储键值对时，使用桶（一个线性链表代表一个桶）的数量。                                                                                           |
| max_bucket_count() | 返回当前系统中，unordered_map 容器底层最多可以使用多少桶。                                                                                          |
| bucket_size(n)     | 返回第 n 个桶中存储键值对的数量。                                                                                                            |
| bucket(key)        | 返回以 key 为键的键值对所在桶的编号。                                                                                                         |
| load_factor()      | 返回 unordered_map 容器中当前的负载因子。负载因子，指的是的当前容器中存储键值对的数量（size()）和使用桶数（bucket_count()）的比值，即 load_factor() = size() / bucket_count()。 |
| max_load_factor()  | 返回或者设置当前 unordered_map 容器的负载因子。                                                                                               |
| rehash(n)          | 将当前容器底层使用桶的数量设置为 n。                                                                                                           |
| reserve()          | 将存储桶的数量（也就是 bucket_count() 方法的返回值）设置为至少容纳count个元（不超过最大负载因子）所需的数量，并重新整理容器。                                                     |
| hash_function()    | 返回当前容器使用的哈希函数对象。                                                                                                              |

> 注意，对于实现互换 2 个相同类型 unordered_map 容器的键值对，除了可以调用该容器模板类中提供的 swap() 成员方法外，STL 标准库还提供了同名的 swap() 非成员函数。

```c++
    //创建空 umap 容器
    unordered_map<string, string> umap;
    //向 umap 容器添加新键值对
    umap.emplace("Python教程", "http://c.biancheng.net/python/");
    umap.emplace("Java教程", "http://c.biancheng.net/java/");
    umap.emplace("Linux教程", "http://c.biancheng.net/linux/");
    //输出 umap 存储键值对的数量
    cout << "umap size = " << umap.size() << endl;
    //使用迭代器输出 umap 容器存储的所有键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
```

| 参数                       | 含义                                                                                                                        |
| ------------------------ | ------------------------------------------------------------------------------------------------------------------------- |
| **<key,T>**              | 前 2 个参数分别用于确定键值对中键和值的类型，也就是存储键值对的类型。                                                                                      |
| **Hash = hash<Key>**     | 用于指明容器在存储各个键值对时要使用的哈希函数，默认使用 STL 标准库提供的 hash<key> 哈希函数。注意，默认哈希函数只适用于基本数据类型（包括 string 类型），而不适用于自定义的结构体或者类。                 |
| **Pred = equal_to<Key>** | 要知道，unordered_map 容器中存储的各个键值对的键是不能相等的，而判断是否相等的规则，就由此参数指定。默认情况下，使用 STL 标准库中提供的 equal_to<key> 规则，该规则仅支持可直接用 == 运算符做比较的数据类型。 |

> 总的来说，当无序容器中存储键值对的键为自定义类型时，默认的哈希函数 hash 以及比较函数 equal_to 将不再适用，只能自己设计适用该类型的哈希函数和比较函数，并显式传递给 Hash 参数和 Pred 参数。

## stack

```c++
#include <stack>
using namespace std;

```

| 成员函数                         | 功能                                                                           |
| ---------------------------- | ---------------------------------------------------------------------------- |
| empty()                      | 当 stack 栈中没有元素时，该成员函数返回 true；反之，返回 false。                                    |
| size()                       | 返回 stack 栈中存储元素的个数。                                                          |
| top()                        | **返回一个栈顶元素的引用，类型为 T&**。如果栈为空，程序会报错。                                          |
| push(const T& val)           | **先复制 val，再将 val 副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的**。                     |
| push(T&& obj)                | **以移动元素的方式将其压入栈顶**。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。                    |
| pop()                        | 弹出栈顶元素。                                                                      |
| emplace(arg...)              | arg... 可以是一个参数，也可以是多个参数，但它们都只用于构造一个对象，并在栈顶直接生成该对象，作为新的栈顶元素。                  |
| swap(stack<T> & other_stack) | 将两个 stack 适配器中的元素进行互换，需要注意的是，进行互换的 2 个 stack 适配器中存储的元素类型以及底层采用的基础容器类型，都必须相同。 |

## queue

```c++
std::deque<int> values{1,2,3};
std::queue<int> my_queue(values);

std::deque<int> values{1,2,3};
std::queue<int> my_queue1(values);
std::queue<int> my_queue(my_queue1);
//或者使用
//std::queue<int> my_queue = my_queue1;
```

| 成员函数                        | 功能                                                                               |
| --------------------------- | -------------------------------------------------------------------------------- |
| empty()                     | 如果 queue 中没有元素的话，返回 true。                                                        |
| size()                      | 返回 queue 中元素的个数。                                                                 |
| front()                     | 返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。                   |
| back()                      | 返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。                  |
| push(const T& obj)          | 在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。                           |
| emplace()                   | 在 queue 的尾部直接添加一个元素。                                                             |
| push(T&& obj)               | 以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。                 |
| pop()                       | 删除 queue 中的第一个元素。                                                                |
| swap(queue<T> &other_queue) | 将两个 queue 容器适配器中的元素进行互换，需要注意的是，进行互换的 2 个 queue 容器适配器中存储的元素类型以及底层采用的基础容器类型，都必须相同。 |

## priority_queue

> “First in，Largest out”

创建一个空的 priority_queue 容器适配器，第底层采用默认的 vector 容器，排序方式也采用默认的 `std::less<T>` 方法：

```c++
#include <queue>
using namespace std;

std::priority_queue<int> values;
//使用普通数组
int values[]{4,1,3,2};
std::priority_queue<int>copy_values(values,values+4);//{4,2,3,1}
//使用序列式容器
std::array<int,4>values{ 4,1,3,2 };
std::priority_queue<int>copy_values(values.begin(),values.end());
//{4,2,3,1}

int values[]{ 4,1,2,3 };
std::priority_queue<int, std::deque<int>, std::greater<int> >
    copy_values(values, values+4);//{1,3,2,4}

```

| 成员函数                           | 功能                                                                                                 |
| ------------------------------ | -------------------------------------------------------------------------------------------------- |
| empty()                        | 如果 priority_queue 为空的话，返回 true；反之，返回 false。                                                        |
| size()                         | 返回 priority_queue 中存储元素的个数。                                                                        |
| top()                          | 返回 priority_queue 中第一个元素的引用形式。                                                                     |
| push(const T& obj)             | 根据既定的排序规则，将元素 obj 的副本存储到 priority_queue 中适当的位置。                                                    |
| push(T&& obj)                  | 根据既定的排序规则，将元素 obj 移动存储到 priority_queue 中适当的位置。                                                     |
| emplace(Args&&... args)        | Args&&... args 表示构造一个存储类型的元素所需要的数据（对于类对象来说，可能需要多个数据构造出一个对象）。此函数的功能是根据既定的排序规则，在容器适配器适当的位置直接生成该新元素。  |
| pop()                          | 移除 priority_queue 容器适配器中第一个元素。                                                                     |
| swap(priority_queue<T>& other) | 将两个 priority_queue 容器适配器中的元素进行互换，需要注意的是，进行互换的 2 个 priority_queue 容器适配器中存储的元素类型以及底层采用的基础容器类型，都必须相同。 |
