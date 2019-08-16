#include <stdio.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)
#define maxn 507

long long dp[maxn][maxn];
long long n, m, q, u, v, w;


int main() {
    while(~scanf("%lld%lld%lld", &n, &m, &q) && n) {
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        dp[i][j] = __LONG_MAX__;
        for(int i = 1; i <= n; i++) dp[i][i] = 0;
        for(int i = 0; i < m; i++) {
            scanf("%lld%lld%lld", &u, &v, &w);
            dp[u][v] = w;
            dp[v][u] = w;
        }
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    w = max(dp[i][k], dp[k][j]);
                    dp[i][j] = min(dp[i][j], w);
                }
            }
        }
        if(dp[1][n] > q) puts("GG");
        else puts("Save");
    }
    return 0;
}


