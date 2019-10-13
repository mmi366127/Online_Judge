#include <bits/stdc++.h>
#define maxn 505
using namespace std;

const int INF = 100000000;

int dp[maxn][maxn], Graph[maxn][maxn];
int n, m, u, v, w;

void init(int n) {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = Graph[i][j] = INF;
}

void find_ring() {
    int ans = INF;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i < k; i++) {
            for(int j = i + 1; j < k; j++) {
                ans = min(ans, Graph[k][i] + dp[i][j] + Graph[j][k]);
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    if(ans == INF) puts("No solution.");
    else printf("%d\n", ans);
}


int main() {
    scanf("%d%d", &n, &m);
    init(n);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        dp[u][v] = dp[v][u] = Graph[u][v] = Graph[v][u] = w;
    }
    find_ring();
    return 0;
}
