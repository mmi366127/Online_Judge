#include <stdio.h>
typedef long long loli;

loli abs(loli x) {
    return x < 0 ? -x : x;
}

loli x, y, X, Y, r;


int main() {
    while(~scanf("%lld%lld%lld%lld%lld", &x, &y, &X, &Y, &r)) {
        puts(abs(x - X) + abs(y - Y) <= r ? "die" : "alive");
    }
    return 0;
}
