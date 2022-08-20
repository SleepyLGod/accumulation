/**
 * @file 202104-2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 按照题意处理即可。需要注意处理时间，如果没有合适处理则有可能得不了满分100分。
 * 所以需要使用前缀和，或者使用二维前缀和来实现
 * 
 * 前缀和用于n次不同的数列区间求和十分有效，可以避免大量重复求和计算
 * 一维前缀和：前 i 个数的和
 * 二维和行类似定义
 * 二维前缀和用于n次不同的子矩阵求和十分有效，可以避免大量重复求和计算
 * 数组prefixsum[]用来按行算前缀和，这样可以避免重复的算术求和计算。
 * 数组psum[]用来按子矩阵算前缀和，即二维前缀和，可以更加有效地避免重复的算术求和计算。
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <bits/stdc++.h>
#define forEachPlus(i, a, b) for (int i = (a); i <= (b); ++i)
#define forEachMinus(i, a, b) for (int i = (a); i >= (b); --i)
typedef long long ll;
int n;
int l;
int r;
int t;
const int N = 650;
const int M = 110;
int a[N][N];
int ans;
int psum[N][N];
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

int main() {
  n = readInt();
  l = readInt();
  r = readInt();
  t = readInt();
  // std::cout << "n: " << n << "l: " << l << "r: " << r << "t: " << t;
  std::memset(psum, 0, sizeof psum);
  forEachPlus(i, 1, n) { 
    forEachPlus(j, 1, n) {
      a[i][j] = readInt();
      psum[i][j] = psum[i][j - 1] + psum[i - 1][j] + a[i][j] - psum[i - 1][j - 1];
    }
  }
  ans = 0;
  forEachPlus(i, 1, n) {
    forEachPlus(j, 1, n) {
      // 首先确定像素块的上下左右范围
      int left_bound = std::max(j - r, 1);
      int right_bound = std::min(n, j + r);
      int up_bound = std::max(i - r, 1);
      int down_bound = std::min(i + r, n);
      int this_area =  (right_bound - left_bound + 1) * (down_bound - up_bound + 1);
      int sum_t = psum[down_bound][right_bound] - psum[down_bound][left_bound - 1] - psum[up_bound - 1][right_bound] + psum[up_bound - 1][left_bound - 1];
      if (sum_t <= this_area * t) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}