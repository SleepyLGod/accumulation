/**
 * @file 202104-3.cpp
 * @author dong
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#define forEachPlus(i, a, b) for(int i = (a); i <= (b); ++i)
#define forEachMinus(i, a, b) for(int i = (a); i >= (b); --i)
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
const int N = 1e4+ 10;
const int MAX_SIZE = 20;
const int T_MAX = 1e9 + 10;
int pool_size;
int t_def;
int t_max;
int t_min;
std::string host;
int paper_cont;
struct IP {
    int time;
    int state;      // 0:未分配 1:待分配 2:占用 3:过期
    std::string user;
} ip[N];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> pool_size >> t_def >> t_max >> t_min >> host;
    std::cin >> paper_cont;

    std::string sender;
    std::string receiver;
    std::string type;
    int seq; // 次序
    int this_ip;
    int ddl;
    forEachPlus(i, 1, paper_cont) {
      std::cin >> seq >> sender >> receiver >> type >> this_ip >> ddl;
      forEachPlus(j, 1, pool_size) { // 处理状态
        // 0:未分配 1:待分配 2:占用 3:过期
        if (ip[j].state == 1 && ip[j].time <= seq) { // 转为未分配
          ip[j].state = 0;
          ip[j].user = "";
          ip[j].time = 0;
        } else if (ip[j].state == 2 && ip[j].time <= seq) {
          ip[j].state = 3;
          ip[j].time = 0;
        }
      }

      // 处理报文
      if (receiver == host || receiver == "*" || type == "REQ") {
        if (type != "DIS" && type != "REQ") {
          continue;
        }
        if ((receiver == "*" && type != "DIS") || (receiver == host && type == "DIS")) {
          continue;
        }
        if (type == "DIS") { // DIS paper reduce
          // 选取IP地址
          int select = -1;
          forEachPlus(tmp, 1, pool_size) {
            if (ip[tmp].state != 0 && ip[tmp].user == sender) {
              select = tmp;
              break;
            }
          }
          if (select == -1) {
            forEachPlus(tmp, 1, pool_size) {
              if (ip[tmp].state == 0) {
                select = tmp;
                break;
              }
            }
          }
          if (select == -1) {
            forEachPlus(tmp, 1, pool_size) {
              if (ip[tmp].state == 3) {
                select = tmp;
                break;
              }
            }
          }
          if (select != -1) { // 设置IP地址参数
            ip[select].state = 1;
            ip[select].user = sender;
            // 设置ddl
            if (ddl == 0) {
              ip[select].time = seq + t_def;
            } else if (t_min <= ddl - seq && ddl - seq <= t_max) {
              ip[select].time = ddl;
            } else if (ddl - seq < t_min) {
              ip[select].time = t_min + seq;
            } else if (ddl - seq > t_max) {
              ip[select].time = seq + t_max;
            }
            std::cout << host << " " << sender << " OFR " << select << " " << ip[select].time << std::endl;
          }
        } else if (type == "REQ") {
          // 1. check receiver
          if (receiver != host) {
            forEachPlus(tmp, 1, pool_size) {
              if (ip[tmp].user == sender && ip[tmp].state == 1) {
                ip[tmp].state = 0;
                ip[tmp].user = "";
                ip[tmp].time = 0;
              }
            }
          } else {
            // 2. check ip
            if (this_ip >= 1 && this_ip <= pool_size && ip[this_ip].user == sender) {
              ip[this_ip].state = 2;
              // 设置ddl
              if (ddl == 0) {
                ip[this_ip].time = seq + t_def;
              } else if (t_min <= ddl - seq && ddl - seq <= t_max) {
                ip[this_ip].time = ddl;
              } else if (ddl - seq < t_min) {
                ip[this_ip].time = t_min + seq;
              } else if (ddl - seq > t_max) {
                ip[this_ip].time = seq + t_max;
              }
              std::cout << host << " " << sender << " ACK " << this_ip << " " << ip[this_ip].time << std::endl;
            } else {
              std::cout << host << " " << sender << " NAK " << this_ip << " 0" << std::endl;
            }
          }
        }
      }
    }
    return 0;
}