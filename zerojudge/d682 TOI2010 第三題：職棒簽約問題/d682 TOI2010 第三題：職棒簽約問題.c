#include <stdio.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define swap(a, b) {int _ = a; a = b; b = _;}
#define maxn 57
#define maxm 10007

int dp[2][maxm];
int cost[maxn][maxn];
int cuteness[maxn][maxn];
int N, M, P, to, from, i, j, k, ans;

int main() {
    scanf("%d%d%d", &M, &N, &P);
    for(i = 0; i < N; i++) {
        for(j = 0; j < P; j++) {
            scanf("%d%d", &cost[i][j], &cuteness[i][j]);
        }
    }
    memset(dp, 0, sizeof(dp));
    to = 0, from = 1;
    for(i = 0; i < N; i++) {
        for(k = 0; k <= M; k++) dp[to][k] = dp[from][k];
        for(j = 0; j < P; j++) {
            for(k = M; k >= cost[i][j]; k--) {
                dp[to][k] = max(dp[to][k], dp[from][k - cost[i][j]] + cuteness[i][j]);
            }
        }
        swap(to, from);
    }
    ans = 0;
    for(i = 0; i <= M; i++) {
        ans = max(ans, dp[from][i]);
    }
    printf("%d\n", ans);
    return 0;
}
