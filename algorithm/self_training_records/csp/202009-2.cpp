/**
 * @file 202009-2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <bits/stdc++.h>
#define forEachPlus(i, a, b) for (int i = (a); i <= (b); ++i)
#define forEachMinus(i, a, b) for (int i = (a); i >= (b); --i)
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
int n;
int t;
int k;
int xl;
int yl;
int xr;
int yr;
int main() {
    n = readInt();
    k = readInt();
    t = readInt();
    xl = readInt();
    yl = readInt();
    xr = readInt();
    yr = readInt();
    int ansForPassby = 0;
    int ansForStay = 0;
    int flagForPassby = 0;
    int flagForStay = 0;
    int cnt = 0;
    forEachPlus(i, 1, n) {
        forEachPlus(j, 1, t) {
            int x = readInt();
            int y = readInt();
            if (x < xl || x > xr || y < yl || y > yr) {
                cnt = 0;
            } else {
                if (!flagForPassby) {
                    flagForPassby = 1;
                }
                if (!flagForStay) {
                    cnt++;
                    if (cnt == k) {
                        flagForStay = 1;
                    }
                }
            }
        }
        if (flagForPassby) {
            ansForPassby++;
        }
        if (flagForStay) {
            ansForStay++;
        }
        flagForPassby = 0;
        flagForStay = 0;
        cnt = 0;
    }
    printf("%d\n%d\n", ansForPassby, ansForStay);
    return 0;
}
