#include <stdio.h>
#include <string.h>
#define maxn 1007
int a[maxn][maxn], dp[maxn], cost[maxn];
int n, m, p;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}


int main() {
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", cost + i);
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            int limit = min(p, i);
            int y = j - 1;
            if(y < 0) y = n - 1;
            int sum = a[y][i];
            for(int k = 1; k <= limit; k++) {
                dp[i] = max(dp[i], dp[i-k] + sum - cost[y]);
                if(y == 0) y = n - 1;
                else y--;
                sum += a[y][i-k];
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
