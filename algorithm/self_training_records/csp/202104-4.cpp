/**
 * @file 202104-4.cpp
 * @author dong
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * @cite http://118.190.20.162/view.page?gpid=T125
 * @details 打表 & DP
 * 等分点不能取有障碍的点
 * 两个障碍物构成的两种方案之间没有交集，就可以考虑分别考虑左右两个状态，即枚举障碍物的位置，然后进行求和
 * 当我们对约数进行枚举时，需要对重复的情况进行取舍，因此设置一个数组flag进行处理
 * 倒序枚举的原因：能在障碍物处种树的约数，已经被后面的使用过，实现代码为flag[d]=true;
 * f[i]表示前i-1个点的选法总和
 * f[i] = (f[i] + f[j] * cnt) % MOD;
 * @copyright Copyright (c) 2022
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
const int MOD = 1e9 + 7;
const int N = 1e3 + 10;
const int AI_SIZE = 1e5 + 10;
int n;
int a[N];
bool flag[AI_SIZE]; // 判断约数是否使用过
ll f[N]; // 状态数组
std::vector<int> vec[AI_SIZE]; // 存储约数
int ans;
int main () {
    // 初始化约数
    forEachPlus(i, 1, AI_SIZE - 1) {
        forEachPlusJump(j, 2 * i, AI_SIZE - 1, i) {
            // 逆向思维：i是j的约数,则j是i的倍数
            // 即：vec[j]是一个vector，存放j的在AI_SIZE范围内的约束i
            vec[j].push_back(i); 
        }
    }

#ifdef DEBUG
    forEachPlus(i, 1, 20) {
        printf("Case #%d: ", i);
        forEachPlus(j, 0, (int)vec[i].size() - 1) {
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
#endif

    n = readInt();
    forEachPlus(i, 0, n - 1) {
        a[i] = readInt();
    }
    f[0] = 1; // 只有一个左端点，全部都不选，只有一种选法
    // 枚举后 n - 1 个障碍物
    forEachPlus(i, 1, n - 1) {
        std::memset(flag, 0, sizeof(flag)); // 每次都要把标签清零
        // 从最后一个子区间的左端点开始，倒序枚举每一个子区间
        forEachMinus(j, i - 1, 0) {
            int length = a[i] - a[j]; // 子区间长度
            int cnt = 0; // 该区间内的选法数
            for (int k : vec[length]) { // 枚举区间长度length的每一个因数
                if (!flag[k]) { // k在之前没有使用过
                    cnt++;
                    flag[k] = true; 
                }
            }
            flag[length] = true; // 障碍物点不能种树
            // 对每个约数求和
            f[i] = (f[i] + f[j] * cnt) % MOD;
        }
    }
    // f[n-1]则代表所有的方案
    std::cout << f[n-1] << std::endl;
    return 0;
}
