// // VS Code C++ 测试代码 "Hello World"
// // 由 VSCodeConfigHelper 生成

// // 您可以在当前的文件夹（您第一步输入的文件夹）下编写代码。

// // 按下 F5（部分设备上可能是 Fn + F5）编译调试。
// // 按下 Ctrl + Shift + B 编译，但不运行。
// // 按下 Ctrl + F5（部分设备上可能是 Ctrl + Fn + F5）编译运行，但不调试。

// #include <iostream>
// //using namespace std; 
// /**
//  * 程序执行的入口点。
//  */
// int main()
//  {
//     // 在标准输出中打印 "Hello, world!"
//     std::cout << "Hello, world!" << std::endl;
//     int s;
//     scanf("%d",&s);
//     printf("%d",s);

// }

// // 此文件编译运行将输出 "Hello, world!"。
// // 按下 F5 后，您将在下方弹出的终端（Terminal）窗口中看到这一行字。

// // ** 重要提示：您以后编写其它代码时，请务必确保文件名不包含中文和特殊字符，切记！**

// // 如果遇到了问题，请您浏览
// // https://github.com/Guyutongxue/VSCodeConfigHelper/blob/master/TroubleShooting.md 
// // 获取帮助。如果问题未能得到解决，请联系开发者。



// #include <cstdio>
// #include <set>
// #include <algorithm>

// const int maxn = 100005;

// int n, ans, tx, tn;
// int a[maxn], sx[maxn], sn[maxn];

// int main() 
// {
// scanf("%d", &n);
// for (int i = 1; i <= n; ++i) scanf("%d", a + i);
// for (int i = 1; i <= n; ++i) 
// {
//     while (tn && a[sn[tn]] >= a[i]) --tn;
//     while (tx && a[sx[tx]] < a[i]) --tx;
//     int k = std::upper_bound(sn + 1, sn + 1 + tn, sx[tx]) - sn;
//     if (k != (tn + 1)) 
//     {
//     ans = std::max(ans, i - sn[k] + 1);
//     }
//     sn[++tn] = i;
//     sx[++tx] = i;
// }
//   printf("%d\n", ans);
//   return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int read();
// int erfen(int,int);
// int max(int,int);
// const int N=1e5+10;
// typedef unsigned long long ull;
// ull ans=0;
// int a[N],b[N],c[N];
// int top()1=0,top()2=0;
// int main()
// {
//   std::ios::sync_with_stdio(false);
//   int n=read();
//   for(int i=1;i<=n;++i)
//   {
//     c[i]=read();
//     while(top()1&&c[a[top()1]]<c[i])
//     top()1--;
//     while(top()2&&c[b[top()2]]>c[i])
//     top()2--;
//     int position = erfen (top()1,top()2);
//     if(position!=top()2+1)
//     ans=max(ans,i-b[position]+1);	//如果s2中有符合上面条件的数即当前的数，更新ans 
//     a[++top()1]=i;
//     b[++top()2]=i;
//   }
//   std::cout<<ans<<endl;
//   return 0;
// }

// int read()
// {
//   int x=0;
//   int symbol=1;
//   char ch = getchar();
//   while(ch<'0'||ch>'9')
//   {
//     if(ch=='-')
//     symbol=-1;
//     ch=getchar();
//   }
//   while(ch>='0'&&ch<='9')
//   {
//     x=(x<<3)+(x<<1)+ch-'0';
//     ch=getchar();
//   }
//   return x*symbol;
// }
//二分在s2中找第一个大于等于s1中c[i]的前一个数的值 
// int erfen(int top()1,int top()2)
// {
//   int l=1;
//   int r=top()2;
//   int mid;
//   while(l<=r)
//   {
//     mid=(l+r)>>1;
//     if(b[mid]>a[top()1])
//     r=mid-1;
//     else l=mid+1;
//   }
//   return l;
// }

// int max(int a,int b)
// {
//   return a>b?a:b;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int read();
// const int N = 100005;
// struct node
// {
//   int front;
//   int next;
// }a[N];
// inline void add(int bef,int now,int pos)
// {
//   if(pos==0)//left
//   {
//     a[now].next=bef;
//     a[now].front=a[bef].front;
//     a[a[bef].front].next=now;
//     a[bef].front=now;
//   }
//   else
//   {
//     a[now].next=a[bef].next;
//     a[now].front=bef;
//     a[bef].next=now;
//     a[a[now].next].front=now;
//   }
// }
// inline void print()
// {
//   std::ios::sync_with_stdio(false);
//   int p=a[0].next;
//   while(1)
//   {
//     cout<<p<<" ";
//     if(a[p].next!=-1)
//     p=a[p].next;
//     else break;
//   }
// }
// inline void del(int num)
// {
//   if(a[num].front==-1)return;
//   a[a[num].front].next=a[num].next;
//   a[a[num].next].front=a[num].front;
//   a[num].front=-1;
//   a[num].next=-1;
// }

// int main()
// {
//   int n,m;
//   n=read();
//   //int flag;
//   //a[0].front=-1;
//   a[0].next =1;
//   for(int i=1;i<=n;++i)
//     a[i].front=a[i].next=-1;
//   a[1].front=0;
//   for(int i=2;i<=n;++i)
//   {
//     int pos,bef;
//     bef=read();
//     pos=read();
//     add(bef,i,pos);
//   }
//   m=read();
//   for(int i=0;i<m;++i)
//   {
//     int num=read();
//     del(num);
//   }
//   print();
//   return 0;
// }

// int read()
// {
//   int x=0;
//   int symbol=1;
//   char ch = getchar();
//   while(ch<'0'||ch>'9')
//   {
//     if(ch=='-')
//     symbol=-1;
//     ch=getchar();
//   }
//   while(ch>='0'&&ch<='9')
//   {
//     x=(x<<3)+(x<<1)+ch-'0';
//     ch=getchar();
//   }
//   return x*symbol;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int read();
// struct nod
// {
//     int L, R;
// }a[100005];
// int n, m;
// inline void addRight(int x, int pos) { //插入右边 
//     a[x].L = pos;
//     a[a[pos].R].L = x;
//     a[x].R = a[pos].R;
//     a[pos].R = x;
// }
// inline void addLeft(int x, int pos) { //插入左边
//     a[x].R = pos;
//     a[a[pos].L].R = x;
//     a[x].L = a[pos].L;
//     a[pos].L = x;
// }
// inline void del(int x) {
//     if(a[x].L == -1) return;
//     a[a[x].L].R = a[x].R;
//     a[a[x].R].L = a[x].L;
//     a[x].L = -1;
//     a[x].R = -1; 
// }
// inline void go() {
//     int x = a[0].R;
//     while(1) {
//         cout<<x<<" ";
//         if(a[x].R == -1) break;
//         x = a[x].R;
//     }
// }
// inline void init() {
//     for(int i = 1; i <= n; ++i) a[i].L = a[i].R = -1;
//     a[1].R = -1; a[1].L = 0; a[0].R = 1;
// }
// int main() 
// {
//     n=read();
//     int cmd1, cmd2;
//     init();
//     for(int i = 2; i <= n; ++i) {
//         cmd1=read();
//         cmd2=read();
//         if(!cmd2) addLeft(i, cmd1);
//         else addRight(i, cmd1);
//     }
//     m=read();
//     for(int i = 1; i <= m; ++i) {
//         cmd1=read();
//         del(cmd1);
//     }
//     go();
//     return 0;
// }
// int read()
// {
//   int x=0;
//   int symbol=1;
//   char ch = getchar();
//   while(ch<'0'||ch>'9')
//   {
//     if(ch=='-')
//     symbol=-1;
//     ch=getchar();
//   }
//   while(ch>='0'&&ch<='9')
//   {
//     x=(x<<3)+(x<<1)+ch-'0';
//     ch=getchar();
//   }
//   return x*symbol;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int read();
// typedef long long ull;
// ull catalan[50];
// int main()
// {
//   std::ios::sync_with_stdio(false);
//   int n=read();
//   catalan[0]=catalan[1]=1;
//   for(int i=2;i<=n;++i)
//   {
//     for(int j=0;j<i;++j)
//     {
//      catalan[i]+=catalan[j]*catalan[i-j-1];
//     }
//   }
//   cout<<catalan[n];
//   return 0;
// }

// int read()
// {
//   int x=0;
//   int symbol=1;
//   char ch = getchar();
//   while(ch<'0'||ch>'9')
//   {
//     if(ch=='-')
//     symbol=-1;
//     ch=getchar();
//   }
//   while(ch>='0'&&ch<='9')
//   {
//     x=(x<<3)+(x<<1)+ch-'0';
//     ch=getchar();
//   }
//   return x*symbol;
// }



// #include<bits/stdc++.h>
// using namespace std;
// stack<int>s;
// char ch;
// void suan(char*);
// int main()
// {
//   while(ch!='@')
//   {
//     ch=getchar();
//     suan(&ch);
//   }
//   std::cout<<s.top();
//   return 0;
// }
// void suan(char *ch)
// {
//   int m;int x,y;
//   switch (*ch)
//   {
//   case '+':
//     /* code */
//     x=s.top();
//     s.pop();
//     y=s.top();
//     s.pop();
//     s.push(x+y);
//     break;
//   case '-':
//     /* code */
//     x=s.top();
//     s.pop();
//     y=s.top();
//     s.pop();
//     s.push(y-x);
//     break;
//   case '*':
//     /* code */
//     x=s.top();
//     s.pop();
//     y=s.top();
//     s.pop();
//     s.push(x*y);
//     break;
//   case '/':
//     /* code */
//     x=s.top();
//     s.pop();
//     y=s.top();
//     s.pop();
//     s.push(y/x);
//     break;
//   default:
//   if(*ch>='0'&&*ch<='9')
//     {
//       std::ios::sync_with_stdio(false);
//       int temp=*ch-'0';
//       char t;
//       while(cin>>t&&t>='0'&&t<='9')
//         temp=temp*10+t-'0';
//       s.push(temp);
//     }
//     break;
//   }
// }


// #include<bits/stdc++.h>
// using namespace std;
// stack<int>s;
// char ch;
// int x,y;

// int main()
// {
//   while(ch!='@')
//   {
//     ch=getchar();
//       int m;
//   switch (ch)
//   {
//   case '+':
//     /* code */
//     x=s.top();
//     s.pop();
//     y=s.top();
//     s.pop();
//     s.push(x+y);
//     break;
//   case '-':
//     /* code */
//     x=s.top();
//     s.pop();
//     y=s.top();
//     s.pop();
//     s.push(y-x);
//     break;
//   case '*':
//     /* code */
//     x=s.top();
//     s.pop();
//     y=s.top();
//     s.pop();
//     s.push(x*y);
//     break;
//   case '/':
//     /* code */
//     x=s.top();
//     s.pop();
//     y=s.top();
//     s.pop();
//     s.push(y/x);
//     break;
//   default:
//     if(ch!='.')
//     {
//       m*=10;
//       m+=ch-'0';
//     }
//     else
//     {
//       s.push(m);
//       m=0;
//     }
//     break;
//   }
//   }
//   std::cout<<s.top();
//   return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// stack<long long>s;
// int read();
// int main()
// {
//   std::ios::sync_with_stdio(false);
//   char ch;
//   int x,y;
//   cin>>x;
//   s.push(x%10000);
//   while(cin>>ch>>y)
//   {
//     if(ch=='*')
//     {
//       x=s.top();
//       s.pop();
//       s.push(x*y%10000);
//     }
//     else
//     {
//       s.push(y%10000);
//     }
//   }
//   long long sum=0;
//   while(s.size())
//   {
//     sum+=s.top();
//     s.pop();
//     sum%=10000;
//   }
//   cout<<sum<<endl;
//   return 0;
// }
// int read()
// {
//   int x=0;
//   int symbol=1;
//   char ch = getchar();
//   while(ch<'0'||ch>'9')
//   {
//     if(ch=='-')
//     symbol=-1;
//     ch=getchar();
//   }
//   while(ch>='0'&&ch<='9')
//   {
//     x=(x<<3)+(x<<1)+ch-'0';
//     ch=getchar();
//   }
//   return x*symbol;
// }


// #include<bits/stdc++.h>
// using namespace std;
// stack<int>a;
// stack<int>b;
// int n,m,x;
// int main()
// {
// 	scanf("%d",&n);
// 	while(n--)
// 	{
// 		scanf("%d",&m);
// 		if(m==0)
// 		{
// 			scanf("%d",&x);
// 			a.push(x);
// 			if(b.empty()||x>b.top())
// 				b.push(x);
// 			else b.push(b.top());
// 		}
// 		else if(m==1)
// 		{
// 			a.pop();
// 			b.pop();
// 		}
// 		else
// 		{
// 			if(b.empty()) printf("0\n");
// 			else printf("%d\n",b.top());		
// 		}			
// 	}
// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int N;
// int order;
// int maxx;
// int max(int,int);
// typedef struct box
// {
//   int self;
//   int totalmax;
// }b;
// stack<b>boxes;
// // int read();
// int main()
// {
//   std::ios::sync_with_stdio(false);
//   //N=read();
//   cin>>N;    
//   maxx=0;
//   for(int i=0;i<N;++i)
//   {
//     // order=read();
//     cin>>order;
//     // b one;
//     // switch (order)
//     // {
//     // case 0:
//     //   /* code */
//     //   one.self=read();
//     //   one.totalmax=max(one.self,maxx);
//     //   maxx=one.totalmax;
//     //   boxes.push(one);
//     //   break;
//     // case 1:
//     //   /* code */
//     //   one=boxes.top();
//     //   boxes.pop();
//     //   break;
//     // case 2:
//     //   /* code */
//     //   if(!boxes.size())
//     //   cout<<0<<endl;
//     //   else 
//     //   {
//     //     one=boxes.top();
//     //     cout<<one.totalmax<<endl;
//     //   }
//     //   break;
//     // default:
//     //   break;
//     // }
//     if(order==0)
//     {
//       b one;
//       // one.self=read();
//       cin>>one.self;
//       one.totalmax=max(one.self,maxx);
//       maxx=one.totalmax;
//       boxes.push(one);
//     }
//     else if(order==1)
//     {
//       boxes.pop();      
//     }
//     else
//     {
//       if(boxes.empty())
//       printf("0\n");
//       else 
//       {
//         b one=boxes.top();
//         cout<<one.totalmax<<endl;
//       }      
//     }
//   }
//   return 0;
// }
// int max(int a,int b)
// {
//   return a>b?a:b;
// }



// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 3e6 + 10;
// int arr[maxn], ans[maxn], st[maxn], top = -1; 

// int main() 
// {
// 	int n;
// 	scanf("%d", &n);
// 	for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
// 	for (int i = n; i > 0; --i) {
// 		//将先进栈(后面的)且不大于arr[i]的值的坐标清除掉,
// 		//这一过程就是从i+1往后寻找第一个大于a_i的元素下标
// 		while (top != -1 && arr[st[top]] <= arr[i]) --top;  
// 		ans[i] = (top == -1 ? 0 : st[top]);	//top=-1表示之后没有大于arr[i]的值 
// 		st[++top] = i; //存储arr的数组下标 
// 	}
// 	for (int i = 1; i <= n; ++i) 
//   {
// 		if (i == 1) printf("%d", ans[i]);
// 		else printf(" %d", ans[i]);
// 	}
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// const int maxt = 1000 + 10;//最多的团队数
// int case1, n,m,num,teamNum,outNum;
// map<int, int> team;
// string str;
// int main()
//  {
// 	while (cin>>n && n) 
//   {//每个测试案例
// 		cout << "Scenario #" << ++case1 << endl;
// 		for (int i = 0; i < n; i++) 
//     {//n个团队
// 			cin >> m;
// 			for (int j = 0; j < m; j++)
//       {
// 				cin >> num;
// 				team[num] = i;//将团队编号和个人编号一一对应
// 			}
// 		}
// 		//定义队列，进行模拟
// 		queue<int> q1, q2[maxt];
//     //第一个是大团队队列，第二个是小团队队列，里面每个元素都是一个小团队队列。
// 		while (cin >> str && str[0] != 'S') 
//     {
// 			if (str[0] == 'E') 
//       {
// 				cin >> num;
// 				teamNum = team[num];
// 				if (q2[teamNum].empty())//判断小队队列是否有元素   
//         //(这里不能去q1中找是否有该小队，因为对于队列来说，只能边出队边遍历)
// 				{
// 					q2[teamNum].push(num);
// 					q1.push(teamNum);
// 				}
// 				else 
//         {
// 					q2[teamNum].push(num);
// 				}
// 			}
// 			else if (str[0] == 'D')
//        {
// 				teamNum = q1.front();
// 				outNum =  q2[teamNum].front();
// 				q2[teamNum].pop();//元素出队
// 				if (q2[teamNum].empty()) 
//         {//判断所在小队是否为空
// 					q1.pop();
// 				}
// 				cout << outNum << endl;
// 			}
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }




// #include<cstdio>
// #include<iostream>
// #include<algorithm>
// #include<cstdlib>
// #include<queue>
// using namespace std;
// typedef struct node{
// 	int x;
// 	int y; 
// }node; 
// node exmp,temp;
// int n; 
// #define MAXN 35
// int A[MAXN][MAXN],B[MAXN][MAXN];
// bool vis[MAXN][MAXN];
// queue <node> p;
// void dfs(int,int);
// int main()
// {
//   std::ios::sync_with_stdio(false);
//  	int i,j; 
//  	cin>>n;
//  	for(int i=1;i<=n;i++)
//  	 for(int j=1;j<=n;j++)
//      {
//  		cin>>A[i][j];
//  		B[i][j]=A[i][j]; 
//  		if(A[i][j]==1) 
//       	vis[i][j]=1;
// 	 }
//  	for(i=1;i<=n;i=i+n-1)
// 	 for(j=1;j<=n;j++)
// 	 	if(!vis[i][j])
// 	 		dfs(i,j); 
//  	 for(i=1;i<=n;i=i+n-1)
// 	 for(j=1;j<=n;j++)
// 	 	if(!vis[j][i]) 
// 	 		dfs(j,i);	 		
// 	for(i=1;i<=n;i++)
//   { 
// 		for(j=1;j<=n;j++)
// 			if(!vis[i][j]) 
//       cout<<"2"<<" " ;
// 			else 
//       cout <<B[i][j]<<" ";  		
// 		cout<<endl; 
// 		} 
// 		system("pause");
// 	return 0; 
//  }

// void dfs(int a,int b)//广度搜索 
// {
// 	int i,j,k; 
// 	exmp.x=a;
// 	exmp.y=b;
// 	p.push(exmp);
// 	while(!p.empty())
//   {
// 		temp=p.front();
// 		p.pop() ; 
// 		int x1=temp.x,y1=temp.y; 
// 		if(A[x1+1][y1]==0&&x1!=n&&!vis[x1+1][y1]) 
//     {
// 			vis[x1+1][y1]=1; 
// 			temp.x=x1+1;
//       temp.y=y1;
//       p.push(temp); 
// 		} 
// 		if(A[x1-1][y1]==0&&x1!=1&&!vis[x1-1][y1]) 
//     {
// 			vis[x1-1][y1]=1; 
// 			temp.x=x1-1;
//       temp.y=y1;
//       p.push(temp); 
// 		} 
// 		if(A[x1][y1+1]==0&&y1!=n&&!vis[x1][y1+1]) 
//     {
// 			vis[x1][y1+1]=1; 
// 			temp.x=x1;
//       temp.y=y1+1;
//       p.push(temp); 
// 		} 
// 		if(A[x1][y1-1]==0&&y1!=1&&!vis[x1][y1-1]) 
//     {
// 			vis[x1][y1-1]=1; 
// 			temp.x=x1;
//       temp.y=y1-1;
//       p.push(temp); 
// 		} 
// 	}	
// }




// #include<iostream>
// #include<cstdio>
// using namespace std;
// int a[1000005];//序列
// int n, k;//序列长度n，窗口长度k
// int q[1000005];//模拟队列的数组
// void minqueue() 
// {//求最小值
// 	int h = 0, t = -1;//队首h，队尾t
// 	for (int i = 0; i < n; ++i) 
// 	{
// 		while (h <= t && q[h] + k <= i)
// 			h++;
// 		while (h <= t && a[i] < a[q[t]])
// 			t--;
// 		q[++t] = i;
// 		if (i >= k - 1) 
// 		{
// 			printf("%d", a[q[h]]);
// 			if (i != n - 1)
// 				printf(" ");
// 		}
// 	}
// }
// void maxqueue() {//求最大值
// 	int h = 0, t = -1;//队首h，队尾t
// 	for (int i = 0; i < n; ++i) 
// 	{
// 		while (h <= t && q[h] + k <= i)
// 			h++;
// 		while (h <= t && a[i] > a[q[t]])
// 			t--;
// 		q[++t] = i;
// 		if (i >= k - 1) 
// 		{
// 			printf("%d", a[q[h]]);
// 			if (i != n - 1)
// 				printf(" ");
// 		}	
// 	}
// }
// int main() 
// {
// 	std::ios::sync_with_stdio(false);
// 	cin>>n>>k;
// 	for (int i = 0; i < n; ++i)
// 	cin>>a[i];
// 	minqueue();
// 	cout<<endl;
// 	maxqueue();
// 	return 0;
// }




// #include <iostream>
// #include <map>
// #include <unordered_map>
// using namespace std;
// int read();
// unordered_map <int ,int > t;
// int main()
// {
// 		//std::ios::sync_with_stdio(false);
//         int n,Q,m;
//         n =read();
//         for(int i=1;i<=n;i++)
//         {
//             int x;
//             x=read();
//             t[x]=i;
//         }
//         Q=read();
//         for(int i=1;i<=Q;i++)
//         {
//             m=read();
//             std::cout<<t[m]<<std::endl;
//         }
// }
// int read()
// {
//   int x=0;
//   int symbol=1;
//   char ch = getchar();
//   while(ch<'0'||ch>'9')
//   {
//     if(ch=='-')
//     symbol=-1;
//     ch=getchar();
//   }
//   while(ch>='0'&&ch<='9')
//   {
//     x=(x<<3)+(x<<1)+ch-'0';
//     ch=getchar();
//   }
//   return x*symbol;
// }


// #include<iostream>
// #include<string>
// #include<stack>
// using namespace std;
// string a;
// int main()
// {
//     char s;
//     while (cin >> s)
//     {
//         if (s == 'E')
//         {
//             a = a + 'E';
//             break;
//         }
//         else
//             a = a+s;
//     }
//     int t = a.length();
//     int n = 0;
//     int x = 0, y = 0;
//     for (int i = 0; i < t; ++i)
//     {
//         if (a[i] == 'W')
//         {
//             x++;
//         }
//         if (a[i] == 'L')
//         {
//             y++;
//         }
//         if (x >= 11 || y >= 11)
//         {
//             if (x - y>= 2||y-x>=2)
//             {
//                 cout << x << ":" << y<<endl;
//                 x = 0;
//                 y = 0;
//             }
//         }
//         if (a[i] == 'E')
//         {
//             cout << x << ":" << y<<endl;
//             x = 0;
//             y = 0;
//         }
//     }
//     x = 0;
//     y = 0;
//     cout << endl;
//     for (int i = 0; i < t; ++i)
//     {
//         if (a[i] == 'W')
//         {
//             x++;
//         }
//         if (a[i] == 'L')
//         {
//             y++;
//         }
//         if (x >= 21 || y >= 21)
//         {
//             if (x - y >= 2 || y - x >= 2)
//             {
//                 cout << x << ":" << y<<endl;
//                 x = 0;
//                 y = 0;
//             }
//         }
//         if (a[i] == 'E')
//         {
//             cout << x << ":" << y<<endl;
//             x = 0;
//             y = 0;
//         }
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// #include<string.h>
// using namespace std;
// int n;
// typedef unsigned long long ull;
// ull hashmod(string);
// #define BIG(x) (str[x]>='A'&&str[x]<='Z')
// #define SMALL(x) (str[x]>='a'&&str[x]<='z')
// const int p=10000007;
// const int mod=1000000009;
// vector<ull>s;
// int main()
// {
//     string demo;
//     scanf("%d",&n);
//     ull count=0;
//     for(int i=0;i<n;++i)
//     {
//         std::cin>>demo;
//         s.push_back(hashmod(demo));
//     }
//     sort(s.begin(),s.end());
//     count=unique(s.begin(),s.end())-s.begin();
//     std::cout<<count<<std::endl;
//     system("pause");
//     return 0;
// }
// ull hashmod(string str)
// {
//     /*
//      *由于数据量比较大，
//      *所以我们算出字符串对应的10进制数以后再对mod取余，可以证明。
//      *当进制数为10^7级别，Mod为 10^9级别，产生冲突可能性会很小~
//     */
//     ull ans=0;
//     for(int i=0;i<str.size();++i)
//     if(BIG(i))
//     ans=(ans*p+str[i]-'A')%mod;
//     else if(SMALL(i))
//     ans=(ans*p+str[i]-'a'+26)%mod;
//     else 
//     ans=(ans*p+str[i]-'0'+52)%mod;
//     return ans;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// int x,y,z;
// typedef long long ll;
// const int MAX1 =(2e5+15);
// const int MAX2 =(5e3+15);
// class node
// {
//   public:
//   int next;
//   int priority;
//   friend bool operator <(const node &a,const node &b)
//   {
//     return a.priority > b.priority;
//   }
//   /*
//   OR:
//   bool operator <(const node &a)
//   {
//     return priority<a.priority;
//   }
//   */
// };
// priority_queue<node>q;
// bool vis[MAX2];
// vector<node>e[MAX2];
// ll primer();
// inline int read();
// int main()
// {
//     n=read();
//     m=read();
//     while(m--)
//     {
//       x=read();
//       y=read();
//       z=read();
//       e[x].push_back((node){y,z});
//       e[y].push_back((node){x,z});
//     } 
//     ll ans=primer();
//     cout<<ans<<endl;
//     system("pause");
//     return 0;
// }
// ll primer()
// {
//   ll ans=0;
//   q.push((node){1,0});//点
//   int count=0;
//   node temp;
//   while(!q.empty()&&count<=n)
//   {
//     temp=q.top();
//     q.pop();
//     if(vis[temp.next])
//     continue;
//     vis[temp.next]=true;
//     ans+=temp.priority;
//     count++;
//     for(int i=0;i<e[temp.next].size();++i)
//     {
//       if(!vis[e[temp.next][i].next])
//       {
//         q.push(node{e[temp.next][i].next,e[temp.next][i].priority});
//       }
//     }
//     return ans;
//   }
// }
// inline int read()
// {
//   int x=0;
//   int symbol=1;
//   char ch = getchar();
//   while(ch<'0'||ch>'9')
//   {
//     if(ch=='-')
//     symbol=-1;
//     ch=getchar();
//   }
//   while(ch>='0'&&ch<='9')
//   {
//     x=(x<<3)+(x<<1)+ch-'0';
//     ch=getchar();
//   }
//   return x*symbol;
// }

// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;

// const int maxn=2e5+15;
// const int mxn=5e3+15;
// struct node
// {
//     int t;int d;
//     bool operator < (const node &a) const
//     {
//         return d>a.d;
//     }
// };
// int n,m;
// int vis[mxn];
// vector <node> e[mxn];
// priority_queue <node> q;
// inline int read()
// {
//     char ch=getchar();
//     int s=0,f=1;
//     while (!(ch>='0'&&ch<='9')) {if (ch=='-') f=-1;ch=getchar();}
//     while (ch>='0'&&ch<='9') {s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
//     return s*f;
// }
// ll prim()
// {
//     ll ans=0;
//     int cnt=0;
//     q.push((node){1,0});
//     while (!q.empty()&&cnt<=n)
//     {
//         node k=q.top();q.pop();
//         if (vis[k.t]) continue;
//         vis[k.t]=1;
//         ans+=k.d;
//         cnt++;
//         for (int i=0;i<e[k.t].size();i++)
//         if (!vis[e[k.t][i].t]){
//             q.push((node){e[k.t][i].t,e[k.t][i].d});
//         }
//     }
//     return ans;
// }
// int main()
// {
//     n=read();m=read();
//     for (int i=1;i<=m;i++)
//     {
//         int x=read(),y=read(),z=read();
//         e[x].push_back((node){y,z});e[y].push_back((node){x,z});
//     }
//     printf("%lld",prim());
//     system("pause");
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// std::stack<int>num;
// std::stack<char>ope;
// string s;
// int abs1(int);
// int main()
// {
//   int next;
// while(std::cin>>s)
// {
//   char ch=s[0];
//   if(ch==']')break;
//   else
//   std::cin>>next;
//   if(ch=='F')
//   {
//     while (!ope.empty()&&ope.top()!='[')
//     {
//       int a=num.top();
//       num.pop();
//       int b=num.top();
//       num.pop();
//       if(ope.top()=='+')
//       num.push(a+b);
//       else if(num.top()=='-')
//       num.push(b-a);
//       else num.push(a*b);
//       ope.pop();
//     }
//     ope.push('+');
//     num.push(next);
//   }
//   if(ch=='B')
//   {
//     while (!ope.empty()&&ope.top()!='[')
//     {
//       int a=num.top();
//       num.pop();
//       int b=num.top();
//       num.pop();
//       if(ope.top()=='+')
//       num.push(a+b);
//       else if(num.top()=='-')
//       num.push(b-a);
//       else num.push(a*b);
//       ope.pop();
//     }
//     ope.push('-');
//     num.push(next);
//   }
//   if(ch=='R')
//   {

//   }
// }
//   system("pause");
//   return 0;
// }
// int abs1(int a)
// {
//   return (a<0)?a*-1:a;
// }


// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int M = 1e6+7;
// struct KMP
// {
// 	char p[M],t[M];//模式串p，文本串t，p在t中出现次数，及位置, 下标1-n 
// 	int nxt[M],n,m,f[M];//nxt[i]：模式串p下标i位置前缀和后缀最大匹配的长度。(不包括自身)
// 	//f[i]: 文本串t下标i位置后缀子串与模式串p后缀子串最大匹配的长度。
// 	void get_nxt()
// 	{
// 		nxt[1]=0;
// 		for(int i=2,j=0;i<=n;i++)
// 		{
// 			while(j>0&&p[j+1]!=p[i])j=nxt[j];
// 			if(p[j+1]==p[i])j++;
// 			nxt[i]=j;
// 		}
// 	}
// 	void gao() 
// 	{
// 		n=strlen(p+1),m=strlen(t+1);
// 		get_nxt();
// 		for(int i=1,j=0;i<=m;i++)
// 		{
// 			while(j>0&&(p[j+1]!=t[i]||j==n))j=nxt[j];
// 			if(p[j+1]==t[i])j++;
// 			f[i]=j;
// 			//if(f[i]==n)此时完成了一次匹配 
// 		}
// 	}
// }kmp;
 
// int main()
// {
// 	ios::sync_with_stdio(false);
//   	cin.tie(0);
// 	cin>>(kmp.t+1)>>(kmp.p+1);
// 	kmp.gao();
// 	for(int i=1;i<=kmp.m;i++)
// 		if(kmp.f[i]==kmp.n)cout<<i-kmp.n+1<<"\n";
// 	for(int i=1;i<=kmp.n;i++)cout<<kmp.nxt[i]<<" ";
// 	cout<<endl;
// 	return 0;
// }

// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;
// const int M = 1e6+7;
// void kmp(char *,char *,int,int,int *);
// void prefix_table(char *,int *,int);
//     char p[M];//big
//     char t[M];//little
//     int prefix[M]={0};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0);
//     // char p[M];//big
//     // char t[M];//little
//     // int prefix[M]={0};
//     std::cin>>p>>t;
//     int n=strlen(t);
//     int m=strlen(p);
//     prefix_table(t,prefix,n);
//     kmp(p,t,m,n,prefix);
//     for(int i=0;i<n;++i)
//     std::cout<<prefix[i];
//     system("pause");
//     return 0;
// }

// void prefix_table(char *t,int *prefix,int n)
// {
//     prefix[0]=0;
//     int i=1;
//     int len=0;
//     while(i<n)
//     {
//         if(t[i]==t[len])
//         {
//             ++len;
//             prefix[i]=len;
//             ++i;
//         }
//         else
//         {
//             if(len==0)
//             prefix[i++]=len;
//             else
//             len=prefix[len-1];
//         }
//     }
//     i=n;
//     for(;i>=1;--i)
//     {
//         prefix[i]=prefix[i-1];
//     }
//     prefix[0]=-1;
// }

// void kmp(char *p,char *t,int m,int n,int *prefix)
// {
//     int i=0;
//     int j=0;
//     while(i<m)
//     {
//         if( (j ==n-1) && p[i]==t[j])
//         {
//             std::cout<<i-j+1<<std::endl;
//             j=prefix[j];
//             if(j==-1)++j;
//         }
//         if(p[i]==t[j])
//         {
//             ++i;
//             ++j;
//         }
//         else
//         {
//             j=prefix[j];
//             if(j==-1)
//             {
//                 ++i;
//                 ++j;
//             }
//         }
//     }
// }


// #include <bits/stdc++.h>
// using namespace std;
// string mid;
// string post;
// void preorder(int,int,int);
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0);
//     std::cin>>mid>>post;
//     int len = post.size()-1;
//     preorder(0,mid.size()-1,len);
//     //system("pause");
//     return 0;
// }
// void preorder(int l,int r,int post_rootpos)
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(0);
//     if(l>r)return;
//     int position = mid.find(post[post_rootpos]);
//     std::cout<<mid[position];
//     preorder(l,position-1,post_rootpos-1-(r-position));
//     preorder(position+1,r,post_rootpos-1);
// }



// #include <bits/stdc++.h>
// using namespace std;
// /*
//  *0-b
//  *1-i
//  *FBI树是一种二叉树，
//  *它的结点类型也包括F结点、B结点和I结点三种。
//  *由一个长度为2^N的“01”串S可以构造出一棵FBI树T
//  */
// int n;
// struct  node
// {
//    char data;
//    node *left,*right;
// };
// char bfi[3]={'B','I','F'};
// char match(string);
// void create(node *&,string);
// void postorder(node *);
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n;
//     int s = pow(2,n);
//     string putin;
//     putin.resize(s);
//     cin>>putin;
//     //node *root=nullptr;
//     node *root(nullptr);
//     create(root,putin);
//     postorder(root);
//     std::cout<<'\n';
//     return 0;
// }
// char match(string s)
// {
//     int num_0 = s.find('0');
//     int num_1 = s.find('1');
//     if(num_0==string::npos&&num_1!=string::npos)
//     return bfi[1];
//     else if(num_0!=string::npos&&num_1==string::npos)
//     return bfi[0];
//     else return bfi[2];
// }
// void create(node *&root,string s)
// {
//     if(!s.length())
//     {
//         root=nullptr;
//         return;
//     }
//     root = new node;
//     root->data=match(s);
//     create(root->left,s.substr(0,s.size()/2));
//     create(root->right,s.substr(s.size()/2,s.size()/2));
// }
// void postorder(node *root)
// {
//     if(root)
//     {
//         postorder(root->left);
//         postorder(root->right);
//         std::cout<<root->data;
//     }
// }





// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// #include <map>
// #include <cmath>
// using namespace std;
// #define MAX_N 500000
// typedef long long lint;
// typedef pair<int, lint> PIL;//小技巧:PIL=pair+int+long long
// vector<PIL> g[MAX_N + 5];//存边
// int dep[MAX_N + 5];
// lint dp[MAX_N + 5];
// lint f[MAX_N + 5];//最大权值
 
// void dfs(int ind) {//求深度
//     for (int i = 0; i < g[ind].size(); i++) {//遍历边
//         int to = g[ind][i].first;
//         if (dep[to] != 0) continue;//如果已被访问，则是父节点，pass
//         dep[to] = dep[ind] + 1;//计数器+1
//         dfs(to);//继续遍历下一条边
//     }
//     return ;
// }
 
// bool cmp(int a, int b) {//按照深度排序
//     return dep[a] > dep[b];
// }
 
/* int main() {
    vector<int> ind_arr;
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) ind_arr.push_back(i);//输入
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(PIL(b, c));
        g[b].push_back(PIL(a, c));//建立一个无向边
    }
    dep[s] = 1;
    dfs(s);//以s为根节点求深度
    sort(ind_arr.begin(), ind_arr.end(), cmp);//按照深度排序
    for (int k = 0; k < ind_arr.size(); k++) {
        int ind = ind_arr[k];
        lint max_num = 0;
        for (int i = 0; i < g[ind].size(); i++) {
            int to = g[ind][i].first, c = g[ind][i].second;
            if (dep[to] <= dep[ind]) continue;//如果深度小于ind，则是子节点
            max_num = max(max_num, f[to] + c);//求出以ind为根节点的最大权值和
        }
        f[ind] = max_num;
        for (int i = 0; i < g[ind].size(); i++) {
            int to = g[ind][i].first, c = g[ind][i].second;
            if (dep[to] <= dep[ind]) continue;
            dp[ind] += dp[to] + max_num - (f[to] + c);//求需要补的时间单位，以达到时态同步
        }
    }
    cout << dp[s] << endl;//求出使用道具的次数
    return 0;
}
 */



/* #include <bits/stdc++.h>
using namespace std;
string preorder;
string midorder;
void postorder(int,int,int);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>midorder>>preorder;
    int len = preorder.size()-1;
    postorder(0,len,0);
    return 0;
}
void postorder(int l,int r,int pre_rootpos)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    if(l>r)return;
    int position = midorder.find(preorder[pre_rootpos]);
    postorder(l,position-1,pre_rootpos+1);
    postorder(position+1,r,pre_rootpos+position-l+1);
    cout<<midorder[position];
} */


/* #include <bits/stdc++.h>
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
} */


/*
给出每个节点的两个儿子节点，
建立一棵二叉树（根节点为 1），
如果是叶子节点，则输入0 0。
建好树后希望知道这棵二叉树的深度。
二叉树的深度是指从根节点到叶子结点时，
最多经过了几层。
*/
/* #include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
struct node
{
   int lch;
   int rch;
}Bitree[maxn];
int n;
int ans;
void create();
int read();
void dfs(int ,int);
inline int maxx(int,int);
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    n=read();
    create();
    dfs(1,1);
    printf("%d",ans);
    return 0;
}
void create()
{
    for(int i=1;i<=n;++i)
    {
        Bitree[i].lch=read();
        Bitree[i].rch=read();
    }
}
void dfs(int root,int depth)
{
    if((!Bitree[root].lch)&&(!Bitree[root].rch))
    {
        ans=maxx(ans,depth);
        return;
    }
    if(Bitree[root].lch)
    dfs(Bitree[root].lch,depth+1);
    if(Bitree[root].rch)
    dfs(Bitree[root].rch,depth+1);
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
inline int maxx(int a,int b)
{
    return a>b?a:b;
} */





/* #include <bits/stdc++.h>
using namespace std;
const int  INF = 1e9;
const int MAXM = 5e5+10;
const int MAXN = 1e4+10;
int n,m,s;
int cnt=0;//边编号
//链式前向星存储方法
struct node
{
    int next;//与它最近的父节点一样的边的编号
    int to;//此边的子节点
    int distance;
}edge[MAXM];
int head[MAXM];//以某点为父节点引出的最后一条边
bool vis[MAXM];
int  dis[MAXN];
int read();
void createGraph();
void spfa();
void inint();
int main()
{
    n=read();
    m=read();
    s=read();
    createGraph();
    spfa();
    for(int i=1;i<=n;++i)
    {
        if(dis[i]==INF)
        cout<<INT_MAX<<" ";
        else 
        printf("%d ",dis[i]);
    }
    return 0;
}
void createGraph()
{
    int from;int to;int dis;
    for(int i=1;i<=m;++i)
    {
    from=read();
    to=read();
    dis=read();
    ++cnt;
    
    // 注意：edge[cnt].next和head[1]
    // 存贮的都是结构体下标（即cnt的值）
    // 若要访问指向的边的编号，
    // 分别用edge[edge[cnt].next].to，edge[head[1]].to
    
    edge[cnt].next=head[from];//同一弧尾（尾-->头）的上一条边所对应的编号(兄弟)
    edge[cnt].to=to;//当前编号的节点的弧头
    edge[cnt].distance=dis;//本条边的权
    head[from]=cnt;//结点from（弧尾）的当前一个儿子存在了edge[cnt]里面
    }
}
void inint()//初始化
{
    fill(dis,dis+n+1,INF);
    fill(vis+1,vis+MAXM-1,false);
}
void spfa()//最短路径算法（dp）
{
    inint();//初始化值
    queue<int>q;
    q.push(s);dis[s]=0;vis[s]=true;//起点进
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        vis[now]=false;
        for(int i=head[now];i;i=edge[i].next)//同一个弧尾对应的所有弧头
        {
            int v = edge[i].to;//弧头
            if(dis[v]>dis[now]+edge[i].distance)
            {
                dis[v]=dis[now]+edge[i].distance;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }

        }
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
 */







/* #include <bits/stdc++.h>
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
} */



/* #include <bits/stdc++.h>
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
 */




/* #include <bits/stdc++.h>
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
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0); 
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
} */




/* #include <bits/stdc++.h>
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
 */



/* #include <bits/stdc++.h>
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
                if(f[x][y]+2<f[x_][y_]&& tag)//使用剪枝
                {
                    f[x_][y_]=f[x][y]+2;//更新金币数（减少了）
                    color[x_][y_]=color[x][y];//变色
                    DFS(x_,y_,0);    //tag改变
                    color[x_][y_]=-1;//回溯
                }
            }
            else if(color[x_][y_]==color[x][y])
            {
                if(f[x][y]<f[x_][y_])//剪枝
                {
                    f[x_][y_]=f[x][y];
                    DFS(x_,y_,1);
                }
            }
            else if(color[x_][y_]!=color[x][y])
            {
                if(f[x][y]+1<f[x_][y_])//剪枝
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
} */




/* #include <bits/stdc++.h>
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
} */




//归并排序法
/* #include <bits/stdc++.h>
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
 */




//树状数组法
// #include <bits/stdc++.h>
// using namespace std;
// const int  INF   = 0x3f3f3f3f;
// //C/C++，用0x3f3f3f3f表示无穷大，0xc0c0c0c0表示无穷小
// const int  MAXN  = 5e5+10;
// void Discretization();//离散化
// int lowbit(int);
// //高效计算 lowbit(i)=2^k，
// //k 是将 i 表示成二进制以后，
// //从右向左数，遇到 1 则停止时，数出的 0 的个数
// void update(int,int);
// int query(int);
// int read();
// int n;
// int a  [MAXN];//维持树状数组
// int b  [MAXN];//输入的原始数组
// int dis[MAXN];//b离散化之后
// int main()
// {
//     n=read();
//     for(int i=1;i<=n;++i)
//     { b[i]=read();  dis[i]=b[i]; }
//     Discretization();
//     long long ans=0;
//     for(int i=n;i>=1;--i)
//     {
//         update(dis[i],1);
//         ans+=query(dis[i]-1);//得到之前有多少个比你大的数（逆序对）
//     }
//     printf("%lld",ans);
//     system("pause");
//     return 0;
// }
// void Discretization()//离散化
// {//dis已经输入好了
//     sort(b+1,b+n+1);
//     int len = unique(b+1,b+n+1)-(b+1);//离散化后的有效长度
//     for(int i=1;i<=n;++i)
//     dis[i]=lower_bound(b+1,b+len+1,dis[i]) - b;
// }
// //树状数组三件套
// int lowbit(int i)
// {
//     return i &-i;
// }
//     /**
//      * 单点更新
//      * 从下到上更新,注意,预处理数组,比原始数组的n大1,故预处理索引的最大值为 n
//      * @param i     原始数组索引 i
//      * @param delta 变化值 = 更新以后的值 - 原始值
//      */
// void update(int i,int delta)
// {
//     while(i<=n)
//     {
//         a[i]+=delta;
//         i+=lowbit(i);
//     }
// }
//     /**
//      * 查询前缀和
//      * 从右到左查询
//      * @param i 前缀的最大索引，即查询区间 [0, i] 的所有元素之和
//      */
// int query(int i)
// {
//     int sum=0;
//     while(i>0)
//     {
//         sum+=a[i];
//         i-=lowbit(i);
//     }
//     return sum;
// }
// int read()
// {
//   int x=0;
//   int symbol=1;
//   char ch = getchar();
//   while(ch<'0'||ch>'9')
//   {
//     if(ch=='-')
//     symbol=-1; 
//     ch=getchar();
//   }
//   while(ch>='0'&&ch<='9')
//   {
//     x=(x<<3)+(x<<1)+ch-'0';
//     ch=getchar();
//   }
//   return x*symbol;
// }





/* #include <bits/stdc++.h>
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
    while(i<ra&&j<rb)
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
 */



/*
#include <bits/stdc++.h>
using namespace std;
const int  INF   = 0x3f3f3f3f;
//C/C++，用0x3f3f3f3f表示无穷大，0xc0c0c0c0表示无穷小
const int  MAXN  = 110;
int read();
int main()
{
    system("pause");
    return 0;
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

*/


/* #include <bits/stdc++.h>
using namespace std;
const int  INF   = 0x3f3f3f3f;
//C/C++，用0x3f3f3f3f表示无穷大，0xc0c0c0c0表示无穷小
const int  MAXN  = 110;
int read();
int main()
{
    system("pause");
    return 0;
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
} */




/* #include <bits/stdc++.h>
using namespace std;
const int  INF   = 0x3f3f3f3f;
//C/C++，用0x3f3f3f3f表示无穷大，0xc0c0c0c0表示无穷小
const int  MAXN  = 110;
int read();
int main()
{
    system("pause");
    return 0;
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
} */



/*
#include <stdio.h> 
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm>
#include <string.h>
// const maxSize = 1e5 + 10;
using namespace std;
int main(){
    vector<int> arr;
    int nn;
    scanf("%d",&nn);
    for(int i=0;i<nn;++i){
        int x;
        scanf("%d",&x);
        arr.push_back(x);
    }
    vector<int> dp(arr.size(), 1);
    int maxn = 0, n = arr.size();
    for(int i = 1; i < n; ++i){
        //找到满足 j < i,arr[j] < arr[i],的最大dp[j]进行转移
        int res = 0;
        for(int j = 0; j < i; ++j){
            if(arr[i] > arr[j]) {
                res = max(res, dp[j]);
            }
        }
        dp[i] = res + 1;//加上arr[i]
        maxn = max(maxn, dp[i]); //找到最大长度
    }
    vector<int> ans(maxn);
    for(int i = n - 1, j = maxn; j > 0; --i){
        //逆向找到第一个满足所需大小的数
        if(dp[i] == j){
            ans[--j] = arr[i];//填入后继续寻找下一个数
        }
    }
    int ans_ = n-ans.size()-1;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < arr.size(); ++i){
        int yyds = arr[i];
        int flag = 0;
        for(int j=0; j<ans.size(); ++j){
            if(ans[j] == yyds){
                flag = 1;
                break;
            }
        }
        if(!flag){
            ans_ += yyds;
            break;
        }  
    }
    printf("%d",ans_);
    return 0;
}
*/

/*
int len = 1;
vector<int> d(n + 1, 0);
d[len] = nums[0];
for(int i=1; i<n; ++i){
    if(nums[i] > d[len]){
        d[++len] = nums[i];
    }else {
        int l = 1;
        int r = len;
        int pos = 0;
        while (l<=r)
        {
            int mid = (l + r) >> 1;
            if(d[mid] < nums[i]){
                pos = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        d[pos + 1] = nums[i];
    }
}
int ans = n-len-1;
sort(nums.begin(),nums.end());
for(int i = 1; i <= n; ++i){
    int yyds = nums[i];
    int flag = 0;
    for(int j=0; j<d.size(); ++j){
        if(d[j] == yyds){
            flag = 1;
            break;
        }
    }
    if(!flag){
        ans += yyds;
        break;
    }
}
*/




// class CRectangle {
//         int width, height;
//         int a = 111;
//       public:
//         CRectangle (int,int);
//         int area (void) {return (width*height);}
//     };
// CRectangle::CRectangle (int a, int b) {
//         width = a;
//         height = b;
// }
// class b extent CRectangle{
//     public:
//     int s;
// }
// int main () {
//     CRectangle rect (3,4);
//     CRectangle rectb (5,6);
//     cout << "rect area: " << rect.area() << endl;
//     cout << "rectb area: " << rectb.area() << endl;
//     // cout << rect.a ;
//     b mmmm (5,5);
//     cout<<mmmm.area();
//     return 0;
// }  
// class inner {
//    public:
//     inner() { cout << "Constructing" << endl; }
//     ~inner() { cout << "Destructing" << endl; }
// };
// class A {
// public:
//     A() {}
//     ~A() {}
//     void f1() {}
//     void f2() {}
// };

// int main(int argc, char *argv[]) {
//     // inner *p = new inner[10];
//     // delete p;
//     set<int> a;
//     for(int i=1;i<=6;++i)
//     {
//         a.insert(i);
//     }
//     cout<<*(a.upper_bound(4));
//     return 0;
// }
// // int main() {
// //     //  int *x, y;  char c = 'a';  printf("%d %d %d\n", sizeof(x), sizeof(y), c);
// //     //cout<<(int)(11.0/3+0.5)<<endl<<11.0/3<<endl<<11/3<<endl<<(float)11 / 3;
// //     // char *buf = (char *) malloc(100);
// //     // scanf("%s", buf + 5);
// //     // printf("%c", buf[5]);
// //     cout << 0 << endl;
// //     cout << fixed << setprecision(3) << 0 << endl;
// //     cout << (2 == 2 ? 0 : 1 )<< endl;
// //     cout << (sizeof(1), 1 > 2) << endl;
// //     int a;
// //     int &aRef = a;

// //     double b;
// //     double &bRef = b;
// //     cout<<sizeof(aRef)<<"  "<<sizeof(bRef);
// //     system("pause");
// //     return 0;
// // }


/* #include <stdio.h> 
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){

    vector<int> arr;
    int nn;
    scanf("%d",&nn);
    for(int i=0;i<nn;++i){
        int x;
        scanf("%d",&x);
        arr.push_back(x);
    }
    int n = arr.size();
    vector<int> d(n + 1, -1), p(n);
    int len = 1;//初始化长度为1，元素为序列第一个数字
    d[len] = arr[0];
    p[0] = 1;
    for(int i = 1; i < n; ++i) {
        if(arr[i] > d[len]) {
            //此时将该数字添加到末尾
            d[++len] = arr[i];
            p[i] = len;
        } else {
            //二分查找恰好合适的位置
            int left = 1, right = len, pos = 0;
            while(left <= right) {
                int mid = (left + right) / 2;
                if(d[mid] < arr[i]) {
                    pos = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            //对该位置数字进行更新
            d[pos + 1] = arr[i];
            p[i] = pos + 1;
        }
    }
    vector<int> ans(len);
    //逆向查找对应序列值
    for(int i = n - 1; i >= 0; --i) {
        if(p[i] == len) {
            ans[--len] = arr[i];
        }
    }

    // vector<int> dp(arr.size(), 1);
    // int maxn = 0, n = arr.size();
    // for(int i = 1; i < n; ++i){
    //     //找到满足 j < i,arr[j] < arr[i],的最大dp[j]进行转移
    //     int res = 0;
    //     for(int j = 0; j < i; ++j){
    //         if(arr[i] > arr[j]) {
    //             res = max(res, dp[j]);
    //         }
    //     }
    //     dp[i] = res + 1;//加上arr[i]
    //     maxn = max(maxn, dp[i]); //找到最大长度
    // }
    // vector<int> ans(maxn);
    // for(int i = n - 1, j = maxn; j > 0; --i){
    //     //逆向找到第一个满足所需大小的数
    //     if(dp[i] == j){
    //         ans[--j] = arr[i];//填入后继续寻找下一个数
    //     }
    // }

    int ans_ = n-ans.size()-1;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < arr.size(); ++i){
        int yyds = arr[i];
        int flag = 0;
        for(int j=0; j<ans.size(); ++j){
            if(ans[j] == yyds){
                flag = 1;
                break;
            }
        }
        if(!flag){
            ans_ += yyds;
            break;
        }  
    }
    printf("%d",ans_);
    return 0;
} */

// #include <iostream>
// #define N 10100
// using namespace std;
// int a[N],n,len = 1;
// int Min,Max;
// int main()
// {
//     scanf("%d",&n);
//     for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
//     Max = a[1];
//     for (int i = 2;i <= n;i++)
//     {
//         if(a[i] > Max)
//         {
//             Max = a[i];
//             len++;
//         }
//         else
//         {
//             if(!Min) Min = a[i];
//             else Min = min(Min,a[i]);
//         }
//     }
//     if(Min) printf("%d",n - len + Min - 1);
//     else printf("0");
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int px[] = {-1, 0, 1, 0};   
// int py[] = {0, -1, 0, 1};
// int flag = 0;
// bool visited[10][10] = {false};
// int    graph[10][10];
// int read()
// {
//   int x=0;
//   int symbol=1;
//   char ch = getchar();
//   while(ch<'0'||ch>'9')
//   {
//     if(ch=='-')
//     symbol=-1; 
//     ch=getchar();
//   }
//   while(ch>='0'&&ch<='9')
//   {
//     x=(x<<3)+(x<<1)+ch-'0';
//     ch=getchar();
//   }
//   return x*symbol;
// } 
// bool judge()
// int main(){
//     int n = read();
//     for(int i = 0; i < n; ++i){
//         for(int j = 0; j < n; ++j){
//             graph[i][j] = read();
//         }
//     }
    
//     return 0;
// }


// #include<iostream>
// using namespace std;
// int &f() {
//     int i = 10;
//     int &j = i;
//     return j;
// }
// int g() {
//     int j = 20;
//     return j;
// }
// int main(void) {
//     int &ri = f();
//     int rj = g();
//     printf("ri=%d\trj=%d\n", ri, rj, 1, 2, 3, 4, 5, 6);
//     int &gi = f();
//     int gj = g();
//     printf("gi=%d\tgj=%d", gi, gj);
// }
 // namespace std;


// #include <bits/stdc++.h>
// using namespace std;
// int read();

// int main() {
//     int n;
//     ios::sync_with_stdio (false);
//     cin.tie(0);
//     cin >> n;
//     int (*w)[4];
//     return 0;
// }

// int read() {
//     int x = 0;
//     int symbol = 1;
//     char ch = getchar();
//     while (ch < '0' || ch < '9') {
//         if (ch == '-') {
//             symbol = -1;
//         }
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9') {
//         x = (x << 3) + (x << 1) + ch - '0';
//         ch = getchar();
//     }
//     return x * symbol;
// }

// #include<bits/stdc++.h>
// using namespace std;
// inline int readInt();  
// const int maxn = 1;
// int main() {
//     printf("hello");
//     return 0;
// } 

// inline int readInt() {
//     int x = 0;
//     int symbol = 1;
//     char c = getchar();
//     while (c < '0' || c > '9') {
//         if (c == '-') {
//             symbol = -1;
//             c = getchar();
//         }
//     }
//     while (c >= '0' && c <= '9') {
//         x = (x << 3) + (x << 1) + (c ^ 48);
//         c = getchar();
//     }
//     return x * symbol;
    
// }

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <chrono>

std::deque<int> q;
std::mutex mu;
std::condition_variable condi;

void function_1() {
	int count = 10;
	while (count > 0) {
		std::unique_lock<std::mutex> locker(mu);
		q.push_back(count);
		locker.unlock();
		condi.notify_one();			//通知一个等待线程激活   condi.notify_all()激活所有线程
		count--;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void function_2() {
	int data = 100;
	while (data > 1) {
		std::unique_lock<std::mutex> locker(mu);
		condi.wait(locker,			// 解锁locker,并进入休眠  收到notify时又重新加锁
			[]() { return !q.empty(); });   // 如果q不为空 线程才会被激活
		data = q.front();
		q.pop_front();
		locker.unlock();

		std::cout << data << std::endl;
	}
}
int main() {
	std::thread t1(function_1);
	std::thread t2(function_2);

	t1.join();
	t2.join();
	
	return 0;
}

 

