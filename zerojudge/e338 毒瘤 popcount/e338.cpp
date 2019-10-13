#pragma GCC optimize("Ofast")
#include <stdio.h>

#define putchar putchar_unlocked
#define getchar getchar_unlocked

template<class T> bool read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar())
        if(c == EOF) return false;
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
    return true;
}

template<class T> void put(T x) {
    static char buf[5], idx;
    for(idx = 0; x; idx++) {
        buf[idx] = (x % 10) ^ '0';
        x /= 10;
    }
    if(idx) {
        for(idx--; idx >= 0; idx--) {
            putchar(buf[idx]);
        }
    } else putchar('0');
    putchar('\n');
}

unsigned char table[256], in[4], ans;

int main() {
    for(int i = 0; i < 256; i++) {
        table[i] = __builtin_popcount(i);
    }
    while(read(*(int*)(in))) {
        ans = 0;
        for(int i = 0; i < 4; i++) {
            ans += table[in[i]];
        }
        put(ans);
    }
    return 0;
}
