#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <stdio.h>
#define bufsize (1 << 23)

#define putchar putchar_unlocked
#define getchar getchar_unlocked

char c;
long long a, b;

char get() {
    static char buf[bufsize], *s = buf, *t = buf;
    return (s == t && (t = (s = buf) + fread_unlocked(buf, 1, bufsize, stdin), s == t) ? 0 : *s++);
}

void prt(long long x) {
    static char idx, buf[20];
    for(idx = 0; x; x /= 10) {
        buf[idx++] = (x % 10) + '0';
    }
    for(idx--; idx >= 0; idx--) {
        putchar(buf[idx]);
    }
}


int main() {
    while(1) {
        for(c = get(); c < '0'; c = get())
            if(c == EOF || c == 0) return 0;
        for(a = 0; c >= '0'; c = get())
            a = (a << 3) + (a << 1) + (c ^ '0');
        for(c = get(); c < '0'; c = get())
            if(c == EOF || c == 0) return 0;
        for(b = 0; c >= '0'; c = get())
            b = (b << 3) + (b << 1) + (c ^ '0');
        prt(a + b); putchar('\n');
    }
    return 0;
}



