#include <stdio.h>
#include <string.h>
#define maxn 25
long long int dp[maxn], n;

int main() {
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for(int i = 2; i < maxn; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    while(~scanf("%lld", &n)) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}
