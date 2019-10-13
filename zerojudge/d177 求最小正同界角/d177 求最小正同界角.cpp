#include <stdio.h>
typedef __int128_t loli;

template<class T> void read(T &x) {
    static char c, neg;
    for(c = getchar(); c < '-'; c = getchar());
    neg = (c == '-') ? -1 : 1;
    x = (neg == -1) ? 0 : (c ^ '0');
    for(c = getchar(); c >= '0'; c = getchar()) {
        x = x * 10 + (c ^ '0');
    }
    x *= neg;
}

template<class T> void put(T x) {
    if(x < 0) {
        putchar('-');
        put(-x);
        return;
    }
    if(x < 10) {
        putchar(x + '0');
        return;
    }
    put(x / 10);
    putchar((x % 10) + '0');
}

loli t;
int n;

int main() {
    read(n);
    while(n--) {
        read(t);
        t %= 360;
        if(t < 0) t += 360;
        put(t); putchar('\n');
    }
    return 0;
}
