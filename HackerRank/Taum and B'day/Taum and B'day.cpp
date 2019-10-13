#include <bits/stdc++.h>
using namespace std;
typedef long long loli;

int t, x, X, y, Y, Z, B, W;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d%d", &B, &W, &x, &y, &Z);
        X = min(x, y + Z); Y = min(y, x + Z);
        printf("%lld\n", (loli)X * B + (loli)Y * W);
    }
    return 0;
}
