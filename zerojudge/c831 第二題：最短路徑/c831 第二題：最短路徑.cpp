#include <stdio.h>
#include <string.h>

long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long abs(long long x) {
    return x < 0 ? -x : x;
}

long long l, r, b, t, XA, YA, XB, YB;


int main() {
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &l, &b, &r, &t, &XA, &YA, &XB, &YB);
    printf("%lld\n", min(r - l - abs(XA - XB), abs(XA - XB)) + min(t - b - abs(YA - YB), abs(YA - YB)));
    return 0;
}
