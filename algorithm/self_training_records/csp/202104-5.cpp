/**
 * @file template.htmlinclude 
 * @author dong
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * @cite http://118.190.20.162/view.page?gpid=T124
 * @details Dijkstra 扩展欧几里得算法 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <bits/stdc++.h>
#define forEachPlus(i, a, b) for(int i = (a); i <= (b); ++i)
#define forEachMinus(i, a, b) for(int i = (a); i >= (b); --i)
#define forEachPlusJump(i, a, b, t) for(int i = (a); i <= (b); i += (t))
#define forEachMinusJump(i, a, b, t) for(int i = (a); i >= (b); i -= (t))
typedef long long ll;
inline int readInt() {
  int ans = 0;
  int symbol = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
        symbol = -1;
    }
    ch = getchar();
  }
  while(ch >= '0' && ch <= '9') {
    ans = (ans << 3) + (ans << 1) + ch - '0';
    ch = getchar();
  }
  return ans * symbol;
} 
inline ll readLong() {
    ll ans = 0;
    int symbol = 1;
    char ch = getchar();
    char las = ' ';
    while(!isdigit(ch)) { // isdigit() 判断某个字符型是否为数字
        las = ch;
        ch = getchar();
    }
    while (isdigit(ch)) {
        ans = (ans << 1) + (ans << 3) + ch - '0';
        ch = getchar();
    }
    if (las == '-') {
        symbol = -1;
    }
    return ans * symbol;
}
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;
const LL INF = 0x3f3f3f3f3f3f3f3fll;

int n, m; // 站点数n，线路数m

struct Node {
    int cid; // 线路号
    int sum; // 当前点在线路cid上距离起点的距离
    int pid; // 当前点在线路cid上的编号
};

LL len[N]; // len[i]: 线路i的长度
vector<Node> ps[N]; // 线路i上经过编号为j的点上的线路
vector<PII> line[N]; // line[i][j] = {ver, y} :线路i上编号为j的站点号为ver的点到下一个站点的距离为y
bool st[N]; // dijkstra中的判重数组
int pid[N]; // pid[i] = j : 线路i上最早拿到疫苗的点的编号为j
LL dist[N]; // dist[i] ：线路i最早拿到疫苗的时间
LL ans[N]; // 站点i最早拿到疫苗的时间


// 扩展欧几里得算法
LL exgcd(LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL r = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return r;
}

void dijkstra() {
    // 初始化dist数组
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < m; ++i) {
        int d = 0;
        for (int j = 0; j < line[i].size(); ++j) {
            if (line[i][j].x == 1) { // 站点号为1
                dist[i] = d;
                pid[i] = j;
                break;
            }
            d += line[i][j].y;
        }
    }

    for (int i = 0; i < m; ++i) {
        // 选点
        int t = -1;
        for (int j = 0; j < m; ++j) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        st[t] = true; // 标记

        vector<PII>& l = line[t]; // l为线路t
        LL d = dist[t]; // 线路t最早拿到疫苗的时间

        // 遍历线路t上的点
        for (int j = pid[t], k = 0; k < l.size(); j = (j + 1) % l.size(), ++k) {
            for (auto& c : ps[l[j].x]) {
                if (st[c.cid]) continue; // 非常重要
                LL a = d, b = len[t];
                LL x = c.sum, y = len[c.cid];
                LL X, Y;

                LL D = exgcd(b, y, X, Y);
                if ((x - a) % D) continue; // 不满足扩展欧几里得算法的条件
                X = (x - a) / D * X;
                y /= D;
                X = (X % y + y) % y;

                if (dist[c.cid] > a + b * X) {
                    dist[c.cid] = a + b * X;
                    pid[c.cid] = c.pid;
                }
            }
            d += l[j].y;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int cnt; // 线路i上的站点数
        cin >> cnt;
        int sum = 0;
        for (int j = 0; j < cnt; ++j) {
            int ver, t; // 站点号，到下一站的时间
            cin>>ver>>t;
            ps[ver].push_back({i, sum, j});
            line[i].push_back({ver, t});
            sum += t;
        }
        len[i] = sum;
    }

    dijkstra();

    memset(ans, 0x3f, sizeof ans);
    for (int i = 0; i < m; ++i) {
        if (dist[i] == INF) continue; // 很重要
        LL d = dist[i]; // 线路i最早拿到疫苗的时间
        for (int j = pid[i], k = 0; k < line[i].size(); j = (j + 1) % line[i].size(), ++k) {
            int ver = line[i][j].x;
            ans[ver] = min(ans[ver], d);
            d += line[i][j].y;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (ans[i] == INF) puts("inf");
        else printf("%lld\n", ans[i]);
    }
    return 0;
}
