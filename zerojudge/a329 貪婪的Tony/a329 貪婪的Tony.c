#include <stdio.h>
#include <string.h>
#define maxn 100007

const int mod = 1234567;

int n, m, i, j, k;
int dp[maxn];


int main() {
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    for(i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(k = 0; k < m; k++) {
            scanf("%d", &j);
            dp[j] = (dp[j] + dp[i]) % mod;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
