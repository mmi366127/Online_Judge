#include <stdio.h>

long long n, k, gcd;

long long GCD(long long a, long long b) {
    if(!a || !b) return a + b;
    while((a %= b) && (b %= a));
    return a + b;
}

int main() {
    scanf("%lld%lld", &n, &k);
    gcd = GCD(n, k); printf("%lld\n", n / gcd / 2 * gcd);
    return 0;
}
