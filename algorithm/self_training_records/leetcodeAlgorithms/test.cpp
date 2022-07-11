#include<bits/stdc++.h>
using namespace std;
inline int readInt();  
const int maxn = 1;
int main() {
    printf("hello");
    return 0;
} 

inline int readInt() {
    int x = 0;
    int symbol = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            symbol = -1;
            c = getchar();
        }
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * symbol;
    
}