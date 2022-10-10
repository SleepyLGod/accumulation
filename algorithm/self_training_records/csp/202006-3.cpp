/**
 * @file 202006-2.cpp
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

inline std::string standard (std::string t) {
    t.erase(0, t.find_first_not_of(' '));
    t.erase(t.find_last_not_of(' ') + 1);
    return t;
}

struct Node {
    int type; // 1:新项目(表首项目)，2:子项目(非表首香茗居)，3:段落
    std::string value;
};
std::vector<Node> list;

int w;
int ans; 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string s;
    bool flag = false;
    std::cin >> w;
    // input and reduce
    while (std::getline(std::cin, s)) {
        if ((int)s.size() == std::count(s.begin(), s.end(), ' ')) { // blank line
            flag = true; // true != 0
        } else { // not blank line
            if (flag || list.empty()) { // blank in the last line or the first element
                if (s.size() >= 2 && s[0] == '*' && s[1] == ' ') { // new project
                    list.push_back({1, standard(s.substr(2))});
                } else { // paragraph
                    list.push_back({3, standard(s)}); 
                }
                flag = false;
            } else { // son project and son paragraph
                Node &last = list.back();
                if (last.type <= 2) { // not paragraph
                    if (s.size() >= 2 && s[0] == ' ' && s[1] == ' ') { // content in another line
                        last.value += ' ' + standard(s.substr(2));
                    } else if (s.size() >= 2 && s[0] == '*' && s[1] == ' ') { // new son project
                        list.push_back({2, standard(s.substr(2))});
                    } else { // paragraph
                        list.push_back({3, standard(s)});
                    }
                } else {
                    if (s.size() >= 2 && s[0] == '*' && s[1] == ' ') { // new project
                        list.push_back({1, standard(s.substr(2))});
                    } else { // paragraph
                        last.value += ' ' + standard(s);
                    }
                }
            }
        }
    }

    // output
    ans = 0;
    forEachPlus(i, 0, (int)list.size() - 1) {
        int type = list[i].type;
        std::string now = list[i].value;
        if (type != 2) {
            ++ans;
        }
        if (type == 3) { // paragraph
            forEachPlusJump(j, 0, (int)now.size() - 1, w) { // delete the space in the end
                while (j < (int)now.size() && now[j] == ' ') {
                    ++j;
                }
                ++ans;
            }
        } else {
            if (now.size() == 0) {
                ++ans;
            } else {
                forEachPlusJump(j, 0, (int)now.size() - 1, w) { // delete the space in the end
                    while (j < (int)now.size() && now[j] == ' ') {
                        ++j;
                    }
                    ++ans;
                }
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}