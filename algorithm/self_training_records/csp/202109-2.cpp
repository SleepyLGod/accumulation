/**
 * @file 202109-2.cpp
 * @author dong
 * @brief 
 * @version 0.1
 * @date 2022-08-18
 * 
 * 遇到这种每个顺序序列节点上有增有减的题目，就可以考虑差分了
 * 
 * 一维差分：
 * 1.给定原始数组a = {a[1]、a[2]、…、a[n]}
 * 2.目的：构造出数组b = {b[1]、b[2]、b[3]、…、b[n]}，使得下面的条件成立：a[i] = b[1] + b[2] + … + b[i]。
 * 因此，数组b称为数组a的差分和，数组a称为数组b的前缀和。
 * 3.eg：将[l,r]区间中的数组元素a[i]均加上常数C，如果使用原始算法，则要扫描一下数组a，时间复杂度为O(n)；
 * 如果使用差分算法则时间复杂度仅为O(1)。具体步骤如下：
 * a.b[l] + C：当b[l] + C时，a[l]、a[l+1]、…、a[n]均会加C，原因是a[i] = b[1] + b[2] + … + b[i]
 * b.b[r + 1] - C：由于需求是将数组a中[l,r]区间中的元素均加C，
 *   因此需要将b数组中a[r+1, n]区间中的元素都减去C。
 *   这样做才能够抵消b[l] + C步骤中将数组a中[r + 1, n]区间中的元素多加的C给抵消掉，实现真正将[l,r]区间中的数组元素a[i]均加上常数C。

 * 非零段可以理解为孤立的岛屿，不同的岛屿之间用 0 分隔开。
 * 选择一个正整数p，将所有小于p pp的数都变为 0 ，可以理解为海平面上涨到 p 的位置，p 以下的部分都被淹没，求孤立岛屿数最大是多少。
 * 所有数字都被海水淹没了，显然只有 0 个岛屿。然后海平面逐渐下降，观察岛屿数量的变化。
 * 可以看出：每当一个凸峰出现，岛屿数就多了一个；
 * 而每当一个凹谷出现，原本相邻的两个岛屿就被这个凹谷连接在了一起，岛屿数减少一个。
 * 因此可以考虑差分。cnt[i] 表示海平面下降到 i 时，答案的变化量。
 * 若连续一段数字相同，可以把他们合并成一个点（1 2 1），这样对答案不会产生影响，可以使用 std::unique() 函数来去掉相邻重复元素
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <bits/stdc++.h>
#include <tuple>
#define forEachPlus(i, a, b) for (int i = (a); i <= (b); ++i)
#define forEachMinus(i, a, b) for (int i = (a); i >= (b); --i)
typedef long long ll;
const int N = 5e5 + 5;
const int M = 1e5 + 5;
int a[N];
int differ[M]; // differ[i] 表示海平面下降到 i 时，答案的变化量
int n;
int cnt; 
inline int readInt();
inline ll readLong();

int main() {
	// freopen("C:\\Users\\MARX HE\\Desktop\\input.txt","r",stdin);
	// freopen("C:\\Users\\MARX HE\\Desktop\\output.txt","w",stdout);
    n = readLong();
    forEachPlus(i, 1, n) {
        a[i] = readLong();
    }
    // 边界处理
    a[0] = 0;
    a[n + 1] = 0;
    // 去重 new n
    n = std::unique(a, a + n + 2) - a;
    forEachPlus(i, 1, n - 2) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) { 
            differ[a[i]]++;
        } else if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
            differ[a[i]]--;
        }
    } 
    int ans = 0;
    int sum = 0;
    forEachMinus(i, 10000, 1) { // or: forEachPlus (i, 1, 10000)
        sum += differ[i];
        ans = std::max(ans, sum); // 差分的前缀和即为单点的答案
    }
    printf("%d\n", ans);
    return 0;
}

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