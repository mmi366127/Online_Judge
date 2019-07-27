#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define maxn 35
using namespace std;

bool Graph[maxn][maxn];
int dp[maxn][maxn][55];
int n, a, b, N;
char s[maxn];

int dfs(int i, int j, int dis) {
    if(dis == 0 && i == j) return 1;
    if(dp[i][j][dis] != -1) return dp[i][j][dis];
    dp[i][j][dis] = 0;
    for(int k = 1; k <= n; k++) {
        if(Graph[i][k]) {
            dp[i][j][dis] += dfs(k, j, dis - 1);
        }
    }
    return dp[i][j][dis];
}

int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for(int j = 1; j <= n; j++) {
            Graph[i][j] = s[j] - '0';
            dp[i][j][1] = s[j] - '0';
        }
    }
    scanf("%d%d%d", &a, &b, &N);
    int ans = 0;
    for(int i = 1; i <= N; i++)
        ans += dfs(a, b, i);
    printf("%d\n", ans);
    return 0;
}
