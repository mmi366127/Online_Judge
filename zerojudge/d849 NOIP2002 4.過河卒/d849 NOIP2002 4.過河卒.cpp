#include <stdio.h>
#include <string.h>


long long dp[30][30];
int n, m, x, y;
char in(int x, int y) {
    return (x >= 0 && x <= n) && (y >= 0 && y <= m);
}

int mx[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int my[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < 9; i++) {
        if(in(x + mx[i], y + my[i])) {
            dp[x + mx[i]][y + my[i]] = -1;
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(dp[i][j] == -1) {
                dp[i][j] = 0;
            } else {
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }
    printf("%lld\n", dp[n][m]);
}
