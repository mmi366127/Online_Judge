#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <string.h>
#define maxn 200005

long long A[maxn];
int n, q, l, r;

int main() {
    scanf("%d", &n); A[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", A + i); A[i] += A[i - 1];
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d", &l, &r);
        printf("%lld\n", A[r] - A[l - 1]);
    }
    return 0;
}

