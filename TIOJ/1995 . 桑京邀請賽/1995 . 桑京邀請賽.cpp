#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 2500005
#define maxm 1000005
using namespace std;

//#define getchar getchar_unlocked

inline void read(int &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
}

inline void put(int x) {
    static char buf[15];
    static int idx;
    for(idx = 0; x; idx++) {
        buf[idx] = x % 10;
        x /= 10;
    }
    for(idx--; idx >= 0; idx--) {
        putchar(buf[idx] + '0');
    }
    putchar('\n');
}


int L[maxm], R[maxm], T[maxn];
int n, m;


int main() {
    read(n), read(m);
    for(int i = 0; i < m; i++) {
        read(L[i]); read(R[i]);
    }
    for(int i = 1; i <= n; i++) {
        read(T[i]);
    }
    for(int i = 0; (1 << i) < n; i++) {
        for(int k = 0; k < m; k++) {
            if(L[k] < 0) continue;
            if(R[k] - L[k] < (1 << (i + 1))) {
                R[k] = max(T[L[k]], T[R[k] - (1 << i) + 1]);
                L[k] = -1;
            }
        }
        for(int k = 1; k <= n - (1 << (i + 1)) + 1; k++) {
            T[k] = max(T[k], T[k + (1 << i)]);
        }
    }
    for(int i = 0; i < m; i++)
        put(R[i]);
    return 0;
}
