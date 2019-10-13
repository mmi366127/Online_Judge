#include <stdio.h>
#include <stdlib.h>
#define maxn 25



int n, m, flag, u, v;
char dp[1 << 20];
int adj[maxn];

void out(int x) {
    for(int i = 0; i < n; i++) {
        if((1 << i) & x) printf("1");
        else printf("0");
    }
    puts("");
}


int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        memset(adj, 0, sizeof(int) * n);
        memset(dp, 0, sizeof(char) * (1 << n));
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            u--, v--;
            adj[u] |= (1 << v);
            adj[v] |= (1 << u);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) dp[1 << i] = 1;
        for(int i = 1; i < (1 << n); i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i] && (i & (1 << j)) == 0 && (adj[j] & i) != 0)
                    dp[i | (1 << j)] = 1;
            }
        }
        for(int i = 0; i < (1 << n); i++) if(dp[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
