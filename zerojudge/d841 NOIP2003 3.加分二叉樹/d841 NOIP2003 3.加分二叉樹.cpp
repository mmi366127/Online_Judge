#include <stdio.h>
#include <string.h>
#define maxn 40
typedef long long loli;


int val[maxn], s[maxn][maxn];
loli dp[maxn][maxn];
int n;


void dfs(int l, int r) {
    if(l > r) return;
    if(l == r) {
        printf("%d ", l);
        return;
    }
    printf("%d ", s[l][r]);
    dfs(l, s[l][r] - 1);
    dfs(s[l][r] + 1, r);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", val + i);
    }
    for(int i = 1; i <= n; i++) {
        dp[i][i] = val[i];
        dp[i][i-1] = 1;
        dp[i][i+1] = 1;
        s[i][i] = i;
    }
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            dp[i][i+len-1] = 0;
            for(int j = i; j < i + len; j++) {
                if(dp[i][j-1] * dp[j+1][i+len-1] + val[j] > dp[i][i+len-1]) {
                    dp[i][i+len-1] = dp[i][j-1] * dp[j+1][i+len-1] + val[j];
                    s[i][i+len-1] = j;
                }
            }
        }
    }
    printf("%d\n", dp[1][n]);
    dfs(1, n); puts("");
    return 0;
}
