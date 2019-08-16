#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define maxn 100000

int to[maxn], pre[maxn], head[maxn], tot;

void add(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}

int w[maxn], dp[maxn];
int n, m, u, v, T;

int dfs(int x) {
    if(dp[x]) return dp[x];
    int ret = 0;
    for(int i = head[x]; i != -1; i = pre[i]) {
        ret = max(dfs(to[i]), ret);
    }
    return dp[x] = (ret + w[x]);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n); tot = 0;
        memset(head, -1, 4*n+4);
        memset(dp, 0, 4*n+4);
        for(int u = 1; u <= n; u++) {
            scanf("%d", w + u);
            scanf("%d", &m);
            for(int i = 0; i < m; i++) {
                scanf("%d", &v);
                add(v, u);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = dfs(i) > ans ? dfs(i) : ans;
        printf("%d\n", ans);
    }
    return 0;
}
