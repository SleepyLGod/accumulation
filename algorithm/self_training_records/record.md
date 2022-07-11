### P 1030 [NOIP2001 普及组] 求先序排列

[👉题目链接]:https://www.luogu.com.cn/problem/P1030

> 题目描述：给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，长度 le 8≤8）。
>
> 输入格式：22行，均为大写字母组成的字符串，表示一棵二叉树的中序与后序排列。
>
> 输出格式：11行，表示一棵二叉树的先序。

```c++
# include <bits/stdc++.h>
using namespace std;
string mid;
string post;
void preorder(int, int, int);
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> mid >> post;
    int len = post.size() - 1;
    preorder(0, mid.size() - 1,len);
    // system("pause");
    return 0;
}
void preorder(int l, int r, int post_rootpos) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    if(l > r) { 
        return;
    }
    int position = mid.find(post[post_rootpos]);
    std::cout << mid[position];
    preorder(l, position - 1, post_rootpos - 1 - (r - position));
    preorder(position + 1, r, post_rootpos - 1);
}
```
###  P 1087 [NOIP2004 普及组] FBI 树

[👉题目链接]:https://www.luogu.com.cn/problem/P1087

```c++
#include <bits/stdc++.h>
using namespace std;
/*
 *0-b
 *1-i
 *FBI树是一种二叉树，
 *它的结点类型也包括F结点、B结点和I结点三种。
 *由一个长度为2^N的“01”串S可以构造出一棵FBI树T
 */
int n;
struct  node
{
   char data;
   node *left,*right;
};
char bfi[3]={'B','I','F'};
char match(string);
void create(node *&,string);
void postorder(node *);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int s = pow(2,n);
    string putin;
    putin.resize(s);
    cin>>putin;
    //node *root=nullptr;
    node *root(nullptr);
    create(root,putin);
    postorder(root);
    std::cout<<'\n';
    return 0;
}
char match(string s)
{
    int num_0 = s.find('0');
    int num_1 = s.find('1');
    if(num_0==string::npos&&num_1!=string::npos)
    return bfi[1];
    else if(num_0!=string::npos&&num_1==string::npos)
    return bfi[0];
    else return bfi[2];
}
void create(node *&root,string s)
{
    if(!s.length())
    {
        root=nullptr;
        return;
    }
    root = new node;
    root->data=match(s);
    create(root->left,s.substr(0,s.size()/2));
    create(root->right,s.substr(s.size()/2,s.size()/2));
}
void postorder(node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        std::cout<<root->data;
    }
}
```


### P 3371 【模板】单源最短路径（弱化版）

[👉题目链接]:https://www.luogu.com.cn/problem/P4779
[👉链式前向星方法]:https://www.luogu.com.cn/blog/2018--haha/solution-p3371

```c++
#include <bits/stdc++.h>
using namespace std;
const int  INF = 1e9;
const int MAXM = 5e5+10;
const int MAXN = 1e4+10;
int n,m,s;
int cnt = 0; // 边编号
// 链式前向星存储方法
struct node {
    int next; // 与它最近的父节点一样的边的编号
    int to;   // 此边的子节点
    int distance;
} edge[MAXM];
int head[MAXM];// 以某点为父节点引出的最后一条边
bool vis[MAXM];
int  dis[MAXN];
int read();
void createGraph();
void spfa();
void inint();
int main() {
    n = read();
    m = read();
    s = read();
    createGraph();
    spfa();
    for(int i = 1; i <= n; ++i) {
        if(dis[i] == INF) {
        	cout << INT_MAX << " ";
        } else { 
        	printf("%d ", dis[i]);
        }
    }
    return 0;
}
void createGraph() {
    int from;
    int to;
    int dis;
    for(int i = 1; i <= m; ++i) {
    	from = read();
    	to = read();
    	dis = read();
    	++cnt;
		// 注意：edge[cnt].next和head[1]
		// 存贮的都是结构体下标（即cnt的值）
		// 若要访问指向的边的编号，
		// 分别用edge[edge[cnt].next].to，edge[head[1]].to
		edge[cnt].next = head[from];//同一弧尾（尾-->头）的上一条边所对应的编号(兄弟)
		edge[cnt].to = to;//当前编号的节点的弧头
		edge[cnt].distance = dis;//本条边的权
		head[from] =cnt;//结点from（弧尾）的当前一个儿子存在了edge[cnt]里面
	}
}
void inint() { 
    // 初始化
    fill(dis,dis+n+1,INF);
    fill(vis+1,vis+MAXM-1,false);
}
void spfa() {
    // 最短路径算法（dp）
    inint(); // 初始化值
    queue<int>q;
    q.push(s);
    dis[s] = 0;
    vis[s] = true;// 起点进
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now]=false;
        for(int i = head[now]; i; i = edge[i].next) {
            // 同一个弧尾对应的所有弧头
            int v = edge[i].to;// 弧头
            if(dis[v] > dis[now] + edge[i].distance) {
                dis[v] = dis[now] + edge[i].distance;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
    }
}
}
int read() {
  int x=0;
  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    symbol=-1;
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}
```

### P 3884 [JLOI2009] 二叉树问题

[👉题目链接]:https://www.luogu.com.cn/problem/P3884

```c++
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int height;
    int father;
};
int n;
int maxheight;
int maxwidth;
vector<int>bitree[105];
int width[105]={0};
node treenode [105];
void dfs(int,int);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int fa,ch;
    //输入
    for(int i=1;i<n;++i)
    {
        cin>>fa>>ch;
        //node one = new node;
        node one;
        one.father=fa;
        treenode[ch]=one;
        bitree[fa].push_back(ch);
    }
    //求深
    dfs(1,1);
    //求宽    
    for(int i=1;i<=n;++i)
    {
        if(treenode[i].height>maxheight)
        maxheight=treenode[i].height;
        width[treenode[i].height]++;
        maxwidth=(maxwidth>width[treenode[i].height]?maxwidth:width[treenode[i].height]);
    }
    //查询
    int a,b;
    cin>>a>>b;
    int res=0;
    int tempA=a;
    int tempB=b;
    while(treenode[tempA].height!=treenode[tempB].height)
    {
        if(treenode[tempA].height>treenode[tempB].height)
        tempA=treenode[tempA].father;
        else 
        tempB=treenode[tempB].father;
    }
    while(tempB!=tempA)
    {
        tempA=treenode[tempA].father;
        tempB=treenode[tempB].father;
    }
    res=(treenode[a].height-treenode[tempA].height)*2+(treenode[b].height-treenode[tempA].height);
    cout<<maxheight<<'\n'<<maxwidth<<'\n'<<res<<'\n';
    return 0;
}
void dfs(int root,int h)
{
    if(h>maxheight)maxheight=h;
    treenode[root].height=h;
    for(int i=0;i<bitree[root].size();++i)
    dfs(bitree[root][i],h+1);
}
```
### P 4913 【深基16.例3】二叉树深度

[👉题目链接]:https://www.luogu.com.cn/problem/P4913

```c++
#include <bits/stdc++.h>
using namespace std;
int m,n;
const int MAXM = 1e4+10;
int read();
void createGraph();
void floyd();
void printroad();
int minn(int,int);
int q[MAXM];
int road_dis[MAXM][MAXM]={0};
int main()
{
    n=read();
    m=read();
    //cout<<n<<m;
    createGraph();
    floyd();
    printroad();
    return 0;
}
void createGraph()
{
    int i=1;
    int j=1;
    while(i<=m)
    q[i++]=read();
    for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
    road_dis[i][j]=read();
}
void floyd()
{
    for(int k=1;k<=n;++k)
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    road_dis[i][j]=minn(road_dis[i][j],(road_dis[i][k]+road_dis[k][j]));
}
void printroad()
{
    int ans = 0;
    for(int i=2;i<=m;++i)
    ans+=road_dis[q[i-1]][q[i]];
    cout<<ans;
}
int read()
{
  int x=0;
  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    symbol=-1; 
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}
int minn(int a,int b)
{
    return (a<b)?a:b;
} 
```

### P 3375 【模板】KMP字符串匹配
[👉题目链接]:https://www.luogu.com.cn/problem/P3375
[👉大佬题解以及视频讲解]:https://www.luogu.com.cn/blog/yueying/solution-p3375

```c++
#include <cstdio>
#include <cstring>
char p[1000005], t[1000005];
int len1, len2;
int next[1000005], next2[1000005];
void do_next()
{
    next[0] = 0;
    int i = 1;
    int len = 0;
    while (i < len2)
    {
        if (t[i] == t[len])
            next[i++] = ++len;
        else
        {
            if (len > 0)
                len = next[len - 1];
            else
                next[i++] = len;
        }
    }
}
void kmp()
{
    int i = 0, j = 0;
    next2[0] = -1;
    for (int i = 1; i < len2; i++)
        next2[i] = next[i - 1];
    while (i < len1)
    {
        if (j == len2 - 1 && p[i] == t[j])
        {
            printf("%d\n", i - j + 1);
            j = next2[j];
            if (j == -1)
                j++;
        }
        if (p[i] == t[j])
        {
            j++;
            i++;
        }
        else
        {
            j = next2[j];
            if (j == -1)
            {
                i++;
                j++;
            }
        }
    }
}
int main()
{
    scanf("%s%s", p, t);
    len1 = strlen(p);
    len2 = strlen(t);
    do_next();
    kmp();
    for (int i = 0; i < len2; i++)
        printf("%d ", next[i]);
    return 0;
}
```

### P 1185 绘制二叉树

[👉题目链接]:https://www.luogu.com.cn/problem/P1185
[👉大佬讲解]:https://blog.csdn.net/crab_xbc/article/details/113686134?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162925289016780255249207%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=162925289016780255249207&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~sobaiduend~default-3-113686134.pc_v2_rank_blog_default&utm_term=P1185+%E7%BB%98%E5%88%B6%E4%BA%8C%E5%8F%89%E6%A0%91&spm=1018.2226.3001.4450

```c++
#include <bits/stdc++.h>
using namespace std;
const int  INF   = 1e9;
const int  MAXN  = 12;
const char node  = 'o';
const char ledge = '/';
const char redge = '\\';
int m,n;
int vis[MAXN][1<<MAXN]; //节点是否被删除
int pos[2][1<<MAXN];    //滚动数组存节点位置
//void inint();
void putin();
void print();
int read();
int min_(int,int);
int max_(int,int);
int main()
{    
    m=read(); //层数
    n=read(); //删去的点数
    // inint();
    putin();
    print();
    return 0;
}
// void inint() //不能用！！！！
// {
//     fill(vis,vis+MAXN*(1<<MAXN)-1,false);
//     fill(pos,pos+2*(1<<MAXN)-1,0);
// }
void putin()
{
    pos[0][0]=(1<<m)-(1<<(m-2));//套公式
    for(int i=0;i<n;++i)
    {
        int x=read();
        int y=read();
        vis[x-1][y-1]=true;//vis从（0，0）开始存
    }
    //删除的节点的子树也不存在了
    for(int i=1;i<m;++i)
    for(int j=0;j<1<<i;++j)
    if(vis[i-1][j>>1])
    vis[i][j]=true;
}
void print()
{
    //首行特殊先输出
    for(int i=0;i<pos[0][0]-1;++i)
    cout<<' ';
    puts("o");
    //滚动数组输出剩下
    for(int i=1;i<m;++i)//第0行的位置已知
    {
        //首先存放左右子树的坐标值
        for(int j=0;j<1<<i;++j)
        {
            //下一层位置判断
            pos[1][j]=pos[0][j>>1]+(j&1?1:-1);//j从0开始，正好与从1开始奇偶性相反
        }
        //翻上去一层
        swap(pos[0],pos[1]);
        //每一层开始输出
        //每条边的长度ei（i为这条边下的层数）一条边占多行
        for(int k=1; k<max_(( ( 1<<(m-i) )-( 1<<(m-i-2) ) ),2); ++k)
        {
            for(int x=1,y=0; y<1<<i; ++x)
            {
                if(x==pos[0][y])
                {
                    putchar(vis[i][y]?' ':(y&1 ? '\\':'/'));
                    pos[0][y]+=y&1?1:-1; //还原，等待下一个循环改动
                    ++y;
                }
                else
                putchar(' ');//先输出最左边的空格（相当于是：本层与下面的层构成的二叉树树根的位置（层数：m-i））
            }
            puts("");//换行
        }
        for(int j=1,k=0;k<1<<i;++j)
        {
            putchar(j==pos[0][k] && !vis[i][k++] ? 'o' :' ');
        }
        puts("");
    }
}
int read()
{
  int x=0;
  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    symbol=-1; 
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}
int max_(int a,int b)
{
    return a>b?a:b;
}
int min_(int a,int b)
{
    return a<b?a:b;
}

```

### P 3367 【模板】并查集

[👉题目链接]:https://www.luogu.com.cn/problem/P3367
[👉大佬讲解]:https://www.luogu.com.cn/blog/My-luoguBuoke-HZR/solution-p3367#

```c++
#include <bits/stdc++.h>
using namespace std;
const int  INF   = 1e9;
const int  MAXN  = 1e5+10;
int n,m;
int f[MAXN];
void init();
void operation(int);
int find(int);
int read();
int main()
{
/*     ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); */
    n=read();
    m=read();
    init();
    for(int i=1;i<=m;++i)
    {    
        int z=read();
        operation(z);
    }
    return 0;
}
void init()
{
    for(int i=1;i<=n;++i)
    f[i]=i;
}
//找老大（路径压缩）
int find(int k)
{
    if(f[k]==k)return k;
    return f[k]=find(f[k]);
}
void operation(int z)
{
    int x=read();
    int y=read();
    if(z==1)
    {
        //开始并查集
        int x1=find(x);
        int y1=find(y);
        f[x1]=y1;
    }
    else 
    if(find(x)==find(y))
    cout<<"Y"<<'\n';
    else 
    cout<<"N"<<'\n';
}
int read()
{
  int x=0;
  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    symbol=-1; 
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}
```

### P 5318 【深基18.例3】查找文献
[👉题目链接]:https://www.luogu.com.cn/problem/P5318

     DFS BFS板子题
```c++
#include <bits/stdc++.h>
using namespace std;
const int  INF   = 1e9;
const int  MAXN  = 1e6+10;
int n,m;//点、边
struct edge
{
    int tail;//弧尾
    int head;//弧头（弧尾指向弧头）
};
//存储每个顶点边的信息
vector<int>e[MAXN];//每个一维数组（行）不定长
//存边
vector<edge>s;
bool vis[MAXN];
void init();
void createGraph();
bool cmp(edge,edge);
void BFS(int);
void DFS(int);
int read();
int main()
{
    n=read();
    m=read();
    createGraph();
    init();
    DFS(1);
    cout<<'\n';
    init();
    BFS(1);
    cout<<'\n';
    system("pause");
    return 0;
}
void DFS(int x)
{
    vis[x]=true;
    cout<<x<<' ';
    for(int i=0;i<e[x].size();++i)
    if(!vis[s[e[x][i]].head])
    DFS(s[e[x][i]].head);
}
void BFS(int x)//层次遍历要调用队列
{
    queue<int>Q;
    cout<<x<<' ';
    Q.push(x);
    vis[x]=true;
    while(!Q.empty())
    {
        int now=Q.front();
        for(int i=0;i<e[now].size();++i)
        {
            if(!vis[s[e[now][i]].head])
            {
                Q.push(s[e[now][i]].head);
                cout<<s[e[now][i]].head<<' ';
                vis[s[e[now][i]].head]=true;
            }
        }
        Q.pop();
    }
}
bool cmp(edge x,edge y)
{
    if(x.head!=y.head)
    return x.head<y.head;
    else 
    return x.tail<y.tail;
}
//经典！！邻接表存法
void createGraph()
{
    for(int i=0;i<m;++i)
    {
        int u=read();
        int v=read();
        edge one ;
        one.tail=u;
        one.head=v;
        s.push_back(one);
    }
    sort(s.begin(),s.end(),cmp);
    for(int i=0;i<m;++i)
    e[s[i].tail].push_back(i);
}
void init()
{
    fill(vis,vis+MAXN-1,false);
}
int read()
{
  int x=0;
  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    symbol=-1; 
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}

```
### P 3956 [NOIP2017 普及组] 棋盘
[👉题目链接]:https://www.luogu.com.cn/problem/P3956

     八向DFS
```c++
#include <bits/stdc++.h>
using namespace std;
const int  INF   = 0x3f3f3f3f;
//C/C++，用0x3f3f3f3f表示无穷大，0xc0c0c0c0表示无穷小
const int  MAXN  = 110;
int n;int m;//棋盘的大小，棋盘上有颜色的格子的数量
int x,y,c;
int color[MAXN][MAXN];//颜色数组，-1表示无色，0和1表示其他颜色
int f[MAXN][MAXN];    //代表从（1，1）到达本坐标所需要的最少的钱数
int dir[4][2]= {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
void DFS(int,int,int);
inline bool judge(int,int);
inline void init();
void putin();
void ans();
int read();
int main()
{
    init();
    putin();
    DFS(1,1,1);
    ans();
    return 0;
}
void DFS(int x,int y,int tag)
//tag:传入的坐标代表的点是否有色，从而决定传入格子周围的格子是否可以通过花费2个金币的代价变色
{
    for(int i=0;i<4;++i)
    {
        int x_=x+dir[i][0];
        int y_=y+dir[i][1];
        if(judge(x_,y_))
        {
            if(color[x_][y_]==-1)//无色
            {
                if(f[x][y]+2<f[x_][y_]/*如上文所说剪枝*/ && tag/*可以变色*/)
                {
                    f[x_][y_]=f[x][y]+2;//更新金币数（减少了）
                    color[x_][y_]=color[x][y];//变色
                    DFS(x_,y_,0);    //tag改变
                    color[x_][y_]=-1;//回溯
                }
            }
            else if(color[x_][y_]==color[x][y])
            {
                if(f[x][y]<f[x_][y_])
                {
                    f[x_][y_]=f[x][y];
                    DFS(x_,y_,1);
                }
            }
            else if(color[x_][y_]!=color[x][y])
            {
                if(f[x][y]+1<f[x_][y_])
                {
                    f[x_][y_]=f[x][y]+1;
                    DFS(x_,y_,1);
                }
            }
        }
    }
}
void ans()
{
    if(f[n][n]==INF)
    cout<<-1<<'\n';
    else 
    cout<<f[n][n]<<'\n';
}
inline bool judge(int x,int y)
{
    return (x>0&&y>0&&x<=n&&y<=n);
}
inline void init()
{
    fill(color[0],color[0]+MAXN*MAXN,-1);
    fill(f[0],f[0]+MAXN*MAXN,INF);
    f[1][1]=0;
}
void putin()
{
    n=read();
    m=read();
    for(int i=1;i<=m;++i)
    {
        x=read();
        y=read();
        c=read();
        color[x][y]=c;
    }
}
int read()
{
  int x=0;
  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    symbol=-1; 
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}
```
### P 1038 [NOIP2003 提高组] 神经网络
[👉题目链接]:https://www.luogu.com.cn/problem/P1038

     拓扑排序(BFS)
```c++
#include <bits/stdc++.h>
using namespace std;
const int  INF   = 0x3f3f3f3f;
//C/C++，用0x3f3f3f3f表示无穷大，0xc0c0c0c0表示无穷小
const int  MAXN  = 110;
int n,p;
//链式前向星
int cnt=0;
struct edge
{
    int next;
    int to;
    int distance;
}e[10010];
int head[105];
int c[105];//兴奋程度
int u[105];//阈值
int in [105];//第I个边的入度
int out[105];//第i个点的出度
int flag=0;//能否兴奋
queue<int>Q;
void init();
void createGraph();
void topsort();
void print();
int read();
int main()
{
    init();
    n=read();
    p=read();
    createGraph();
    topsort();
    print();
    return 0;
}
void init()
{
    // fill(head,head+105,-1);
    memset(head,-1,sizeof(head));
}
void createGraph()
{
    for(int i=1;i<=n;++i)
    {
        c[i]=read();
        u[i]=read();
        if(!c[i]) 
        c[i]-=u[i];
    }
    for(int i=1;i<=p;++i)
    {
        int u=read();
        int v=read();
        int w=read();
        cnt++;
        e[cnt].next=head[u];
        e[cnt].to=v;
        e[cnt].distance=w;
        head[u]=cnt;
        out[u]++;
        in [v]++;
    }
}
void topsort()//BFS
{
    for(int i=1;i<=n;++i)
    if(!in[i])  Q.push(i);//输入层进队
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for(int i=head[now];i!=-1;i=e[i].next)
        {
            int head = e[i].to;//弧头
            --in[head];//入度-1
            if(!in[head])//入度减没了，此弧头的弧尾已经全部进队
            Q.push(head);
            if(c[now]>0)
            c[head]+=e[i].distance*c[now];
        }
    }
}
void print()
{
    for(int i=1;i<=n;i++)
    if(!out[i]&&c[i]>0)
    printf("%d %d\n",i,c[i]),flag=1;
    if(!flag)
    printf("NULL\n");
}
int read()
{
  int x=0;
  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    symbol=-1; 
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}

```

### P 1908 逆序对
[👉题目链接]:https://www.luogu.com.cn/problem/P1908

     树状数组  递归  离散化  归并排序
+ 归并排序法
     我们都知道，归并排序是通过把大区间一直分，分成小区间，然后小区间排序好了之后，再合并成大区间。也就是说在n*logn的复杂度的情况下给这个数组排了一下序列，在排序过程中加上一句代码ans+=mid-left+1，只要排在后面但是比前面的数小，位置差就是逆序数。
```c++
#include <bits/stdc++.h>
using namespace std;
const int  INF   = 0x3f3f3f3f;//C/C++，用0x3f3f3f3f表示无穷大，0xc0c0c0c0表示无穷小
const int  MAXN  = 5e5+10;
int a[MAXN];
int s[MAXN];
long long ans=0;
int n;
void mergeSort(int,int);
void putin();
int read();
int main()
{
    putin();
    mergeSort(1,n);
    printf("%lld\n",ans);
    system("pause");
    return 0;
}
void putin()
{
    n=read();
    for(int i=1;i<=n;++i)
    a[i]=read();
}
void mergeSort(int l,int r)
{
    if(l==r)    return;
    int mid = (l+r)>>1;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    int k=l,o=l,j=mid+1;
    while(o<=mid && j<=r)
    {
        if(a[o]<=a[j])//顺序
        {
            s[k]=a[o];
            k++;o++;
        }
        else //逆序
        {
            s[k]=a[j];
            ++k;++j;
            ans+=(long long)mid - o +1;
            //加上逆序对，因为之前已经归并排好了l~mid和mid+1~r的长度小的数组，故o~mid的数已经按升序排好了，都比j处的数字大
        }
    }
    //将剩余元素推入有序序列(剩余元素皆为序列最大值) 
    while(o<=mid) s[k++]=a[o++];
    while(j<=r)s[k++]=a[j++];
    for(k = l; k <= r; k++) a[k] = s[k];//复制回a数组中 
}
int read()
{
  int x=0;
  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    symbol=-1; 
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}

```
+ 树状数组法
     用树状数组，因为这道题数据的值域有点大，但是数量并不是很多，所以要对数据进行离散化处理，离散化之后，对数据进行插入，插入的时候，随便求一下当前这个数前面已经插入了多少个数，然后用这个数的位置来减去前面的数的个数，就是这个数的逆序数，所有的数的逆序数之和就是这整个数列的逆序数。
     > 一、 离散化
       数据很大，这会造成我们要开的空间很大，要用离散化压缩数组（可以保证小的数依旧小，大的数依旧大，对结果没有影响）
     
     [👉什么是离散化？]:https://blog.csdn.net/weixin_45884316/article/details/113244922
     [👉树状数组讲解]:https://blog.csdn.net/jwg2732/article/details/107876297?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-0.essearch_pc_relevant&spm=1001.2101.3001.4242
     [👉理解 lowbit 操作]:https://blog.csdn.net/lw_power/article/details/106965287
     
     > 二、求逆序对
       对于离散化后的数组dis，我们可以用桶排序的思想，将a [ d i s [ i ] ]加上1,然后我们统计a[1] 到a[dis[i]-1]的和ans，就是在这个数前面有多少个数比它小。
```c++
#include <bits/stdc++.h>
using namespace std;
const int  INF   = 0x3f3f3f3f;
//C/C++，用0x3f3f3f3f表示无穷大，0xc0c0c0c0表示无穷小
const int  MAXN  = 5e5+10;
void Discretization();//离散化
int lowbit(int);
//高效计算 lowbit(i)=2^k，
//k 是将 i 表示成二进制以后，
//从右向左数，遇到 1 则停止时，数出的 0 的个数
void update(int,int);
int query(int);
int read();
int n;
int a  [MAXN];//维持树状数组
int b  [MAXN];//输入的原始数组
int dis[MAXN];//b离散化之后
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    { b[i]=read();  dis[i]=b[i]; }
    Discretization();
    long long ans=0;
    for(int i=n;i>=1;--i)
    {
        update(dis[i],1);
        ans+=query(dis[i]-1);//得到之前有多少个比你大的数（逆序对）
    }
    printf("%lld",ans);
    system("pause");
    return 0;
}
void Discretization()//离散化
{//dis已经输入好了
    sort(b+1,b+n+1);
    int len = unique(b+1,b+n+1)-(b+1);//离散化后的有效长度
    for(int i=1;i<=n;++i)
    dis[i]=lower_bound(b+1,b+len+1,dis[i]) - b;
}
//树状数组三件套
int lowbit(int i)
{
    return i &-i;
}
    /**
     * 单点更新
     * 从下到上更新,注意,预处理数组,比原始数组的n大1,故预处理索引的最大值为 n
     * @param i     原始数组索引 i
     * @param delta 变化值 = 更新以后的值 - 原始值
     */
void update(int i,int delta)
{
    while(i<=n)
    {
        a[i]+=delta;
        i+=lowbit(i);
    }
}
    /**
     * 查询前缀和
     * 从右到左查询
     * @param i 前缀的最大索引，即查询区间 [0, i] 的所有元素之和
     */
int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=a[i];
        i-=lowbit(i);
    }
    return sum;
}
int read()
{
  int x=0;
  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    symbol=-1; 
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}
```

### P1309 [NOIP2011 普及组] 瑞士轮
[👉题目链接]:https://www.luogu.com.cn/problem/P1309
     模拟   递归    排序    归并排序    快速排序
  + 分析与解：
```对于这道题，最容易想到的算法恐怕就是每轮比赛前都用快排排一次，然后再根据选手的实力值决定胜负。但是这样算下来，时间复杂度达到了O(R*(N*logN+N)),但实际动作的次数还要加一个常数倍，因为一共有2*N个人。把数据范围看一下，就知道这种算法肯定是要超时的，因此只要还有时间，应该尝试更为高效的算法。很容易可以知道，每轮比赛结束后，胜利者和失败者两个群体中内部的顺序是不会被打乱的。也就是说，第一轮比赛后每一对人中的胜利者拿来排序之后跟原来他们比赛前的顺序是一样的，当然失败者的一群人也一样。因此，很容易就想到之前那个算法为什么不够高效了，因为快排的效率高是针对随机的数列的，而这里每一轮比赛下来，有许多人（一半人）的相对顺序已经确定了，因此就想到了归并排序，这样，每一轮比赛后用O(N)的复杂度归并一次就好，而不用快排，那样会损失掉已有的信息。这样，估算下来，时间就够了。值得注意的事，在第一轮比赛前，并不知道待比赛选手的排名，而这时又不可能得到任何已有的信息，因为本来直接给出的初始值s是无序的，所以这时应使用快排（这里我直接用了C++标准库里现成的），而且要注意初始值相同的情况，但这里已经是细节，不是重点了。```

```c++
#include <bits/stdc++.h>
using namespace std;
const int  INF   = 0x3f3f3f3f;
//C/C++，用0x3f3f3f3f表示无穷大，0xc0c0c0c0表示无穷小
const int  MAXN  = 2e6+10;
int n,r,q;//有2*N 名选手、R 轮比赛，以及我们关心的名次Q
struct fuck
{
    int num;//编号
    int mark;//目前分数
    int w;//实力值
};
//归并套装
//ans存每一轮比赛后的结果，按名次来排，要归并，总得有两个有序的数组，所以就拿a来存赢的，b来存输的，至于为什么a，b有序，上面已经说过了
fuck a[MAXN],b[MAXN],ans[MAXN];
bool cmp(const fuck& ,const fuck&);
void merge(int,int);
void compete();
void putin();
int read();
int main()
{
    putin();
    sort(ans+1,ans+1+2*n,cmp);
    for(int i=1;i<=r;++i)
    compete();
    printf("%d\n",ans[q].num);
    return 0;
}
bool cmp(const fuck& a,const fuck& b)
{
    if(a.mark==b.mark)
    return (a.num<b.num);//总分相同的，约定编号较小的选手排名靠前
    else 
    return (a.mark>b.mark);//总分从高到低
}
void compete()
{//每调用一次solve(),就会求出下一轮的比赛结果，所以主程序中调用了r次来求出r轮后的结果
    int ra=1,rb=1;
    long long m=2*n;
    for(long long i=1;i<=m;i+=2)//两两相邻的才比较
    {
        if(ans[i].w<=ans[i+1].w)
        {
            ans[i+1].mark++;
            a[ra++]=ans[i+1];
            b[rb++]=ans[i];
        }
        else
        {
            ans[i].mark++;
            a[ra++]=ans[i];
            b[rb++]=ans[i+1];
        } 
    }
    merge(ra,rb);
}
void merge(int ra,int rb)
{
    int i=1,j=1,k=1;
    while(i<ra&&j<rb)//不是<=、>=我艹！！!
    {
        if(cmp(a[i],b[j]))
        ans[k++]=a[i++];
        else
        ans[k++]=b[j++];
    }
    while(i<ra)ans[k++]=a[i++];
    while(j<rb)ans[k++]=b[j++];
}
void putin()
{
    n=read();
    r=read();
    q=read();
    long long m=2*n;
    for(long long i=1;i<=m;++i)
    {
        ans[i].mark=read();
        ans[i].num=i;
    }
    for(long long i=1;i<=m;++i)
    ans[i].w=read();
}
int read()
{
  int x=0;  int symbol=1;
  char ch = getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-') symbol=-1; 
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<3)+(x<<1)+ch-'0';
    ch=getchar();
  }
  return x*symbol;
}

```
### P 1090 [NOIP2004 提高组] 合并果子 / [USACO06NOV] Fence Repair G
[👉题目链接]:https://www.luogu.com.cn/problem/P1090
     贪心   二叉堆  优先队列
```c++

```
