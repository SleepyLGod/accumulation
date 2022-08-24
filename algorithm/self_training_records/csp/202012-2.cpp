/**
 * @file 202012-2.cpp
 * @author dong
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * @cite http://118.190.20.162/view.page?gpid=T122
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

/*
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
*/
const int M_MAX = 1e5 + 10;
int m;
int n;
int ans;
typedef std::pair<int, int> int_pair;
int_pair a[M_MAX];
int prefix[M_MAX + 2];
int suffix[M_MAX + 2];
int position[M_MAX + 2];
int main() {
    m = readInt();
    forEachPlus(i, 1, m) {
        a[i].first = readInt();
        a[i].second = readInt();
    }
    std::sort(a + 1, a + 1 + m); // 按y(key)排序
    // 前缀和(挂科数)
    prefix[0] = 0;
    forEachPlus(i, 1, m) {
        // result == 0 => 挂科
        prefix[i] = prefix[i - 1] + (a[i].second == 0 ? 1 : 0);
    }
    // 后缀和(非挂科数)
    suffix[m + 1] = 0;
    forEachMinus(i, m, 1) {
        suffix[i] = suffix[i + 1] + (a[i].second == 1 ? 1 : 0);
    }
    int pos = 1;
    position[1] = 1;
    // key值即y相同的算第一个
    forEachPlus(i, 1, m) {
        if (a[i].first != a[i - 1].first) {
            pos = i;
        }
        position[i] = pos;
    }
    ans = 0;
    int tmp =  0;
    // 计算预测正确次数
    forEachPlus(i, 1, m) {
        int current = prefix[position[i] - 1] + suffix[i];
        if (current >= tmp) {
            tmp = current;
            ans = a[i].first;
        }
    }
    printf("%d\n", ans);
    return 0;
}