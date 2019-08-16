#include <stdio.h>
#include <string.h>
#define maxn 100

int n, a, b1, b2;
char s[maxn], out[maxn];

char *t = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int cvt(char c) {
    if('0' <= c && c <= '9') return c - '0';
    else return c - 'A' + 10;
}

int main() {
    while(~scanf("%s", s)) {
        scanf("%d%d", &b1, &b2);
        a = 0;
        for(int i = 0; s[i]; i++) {
            a = (a * b1) + cvt(s[i]);
        }
        int i = 0;
        while(a) {
            out[i++] = t[a % b2];
            a /= b2;
        }
        for(i--; i >= 0; i--) putchar(out[i]);
        putchar('\n');
    }
    return 0;
}
