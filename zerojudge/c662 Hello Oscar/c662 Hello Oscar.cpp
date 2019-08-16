#include <stdio.h>
#include <string.h>
#define maxn 1007
typedef long long loli;

loli GCD(loli a, loli b) {
    if(!a || !b) return 0;
    while((a %= b) && (b %= a));
    return a + b;
}

loli LCM(loli a, loli b) {
    return (a * b / GCD(a, b));
}

char s[10000];
int A[maxn];
int n;

loli circle(int pos) {
    int tmp = A[pos], ret = 1;
    while(tmp != pos) {
        ret++;
        tmp = A[tmp];
    }
    return ret;
}

int main() {
    while(fgets(s, sizeof(s), stdin)) {
        n = 0;
        for(int i = 0; s[i]; ) {
            if('0' <= s[i] && s[i] <= '9') {
                int tmp = 0;
                while('0' <= s[i] && s[i] <= '9') {
                    tmp = (tmp * 10) + (s[i++] ^ '0');
                }
                A[n++] = tmp;
            } else i++;
        }
        loli ans = 1;
        for(int i = 0; i < n; i++) {
            ans = LCM(ans, circle(i));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
