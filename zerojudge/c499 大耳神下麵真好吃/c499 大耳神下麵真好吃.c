#include <stdio.h>
#include <string.h>
#define maxn 1007

short dp[maxn][maxn];
char a[maxn], b[maxn];


int main() {
    int n, m, t;
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    scanf("%d", &t);
    n = strlen(a + 1);
    m = strlen(b + 1);
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
            }
        }
    }
    if(dp[n][m] >= t) puts("kwa nini unaendesha");
    else puts("sitini na tisa");
    return 0;
}
