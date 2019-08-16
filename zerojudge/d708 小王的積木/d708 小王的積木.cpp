#include <stdio.h>
#include <string.h>

#define getchar getchar_unlocked
#define putchar putchar_unlocked

long long tmp, ans = 0;
char c, neg;
int n;

int main() {
    for(c = getchar(); c < '0';  c = getchar());
    for(n = 0; c >= '0'; c = getchar())
        n = (n << 3) + (n << 1) + (c ^ '0');
    for(n--;n--;) {
        tmp = 0;
        for(c = getchar(); c < '-'; c = getchar());
        tmp = (c == '-') ? 0 : (c ^ '0');
        neg = (c == '-') ? -1 : 1;
        for(c = getchar(); c >= '0'; c = getchar())
            tmp = (tmp << 3) + (tmp << 1) + (c ^ '0');
        tmp *= neg;
        ans ^= tmp;
    }
    printf("%lld\n", ans);
    return 0;
}
