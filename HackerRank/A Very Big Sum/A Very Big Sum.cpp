#include <bits/stdc++.h>
using namespace std;

long long x, sum = 0;
int n;

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%lld", &x);
        sum += x;
    }
    printf("%lld\n", sum);
    return 0;
}
