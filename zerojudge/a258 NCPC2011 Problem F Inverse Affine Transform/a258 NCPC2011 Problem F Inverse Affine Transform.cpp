#include <stdio.h>
#include <string.h>


long long x, y;

long long Excalibur(long long a, long long b) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long ret = Excalibur(b, a % b);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return ret;
}

long long T, m, a, b, c, d, gcd;

int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld%lld%lld", &m, &a, &b);
        gcd = Excalibur(a, m);
        if(gcd > 1) {
            printf("No inverse, gcd(a,m)=%lld\n", gcd);
            continue;
        }
        if(x < 0) {
            x += ((-1 * x / m) + 1) * m;
            x %= m;
        }
        c = x;
        d = b * c;
        if(d < 0) {
            d += ((-1 * d / m) + 1) * m;
            d %= m;
        } else d %= m;
        d = m - d;
        printf("%d %d\n", c % m, d % m);
    }
}
