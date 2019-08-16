#include <stdio.h>
#include <string.h>

long long dp[10000007];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = (((dp[i - 1] * (i - 1)) % m) + ((dp[i - 2] * (i - 2)) % m)) % m;
    }
    printf("%lld\n", dp[n]);
    return 0;
}
