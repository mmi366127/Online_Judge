#include <stdio.h>
#include <string.h>
#define lowbit(X) ((X)&-(X))
#define maxn 100007

int bit[maxn];
int n, x;

#define getchar_unlocked getchar
#define putchar_unlocked putchar

int rd() {
    static char c;
    int ret;
    while((c = getchar_unlocked()) < '0') {
        if(c == EOF) return 0;
    }
    ret = c ^ '0';
    while((c = getchar_unlocked()) >= '0') {
        ret = (ret << 1) + (ret << 3) + (c ^ '0');
    }
    return ret;
}

void prt(int x) {
    static char buf[20], idx;
    idx = 0;
    while(x) {
        buf[idx++] = (x % 10) ^ '0';
        x /= 10;
    }
    for(idx--; idx >= 0; idx--) {
        putchar_unlocked(buf[idx]);
    }
    putchar_unlocked('\n');
}

int query(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

void update(int x) {
    while(x <= n) {
        bit[x]++;
        x += lowbit(x);
    }
}

int main() {
    while((n = rd())) {
        memset(bit, 0, 4 * n + 4);
        for(int i = 1; i <= n; i++) {
            x = rd();
            prt(i - query(x));
            update(x);
        }
    }
    return 0;
}
