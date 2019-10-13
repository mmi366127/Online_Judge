#include <bits/stdc++.h>
using namespace std;

long long sum = 0;
int mi, mx, x;

int main() {
    mi = 1e9;  mx = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &x);
        sum = sum + x;
        mx = max(mx, x);
        mi = min(mi, x);
    }
    printf("%lld %lld\n", sum - mx, sum - mi);
    return 0;
}
