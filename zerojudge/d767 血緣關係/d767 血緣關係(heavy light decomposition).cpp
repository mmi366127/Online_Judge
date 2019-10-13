#include <stdio.h>
#include <string.h>
#define maxn 30007

int pre[maxn+maxn], to[maxn+maxn], head[maxn], tot;

void add_edge(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}


int n, m, u, v;

int heavy[maxn], top[maxn], dep[maxn], sz[maxn], par[maxn];


void dfs(int x, int p) {
    par[x] = p; sz[x] = 1;
    for(int i = head[x]; i != -1; i = pre[i]) {
        if(to[i] == p) continue;
        dep[to[i]] = dep[x] + 1;
        dfs(to[i], x);
        sz[x] += sz[to[i]];
        if(heavy[x] == -1 || sz[to[i]] > sz[heavy[x]])
            heavy[x] = to[i];
    }
}

void YEE() {
    memset(heavy, -1, sizeof(heavy));
    dep[1] = 0; dfs(1, -1);
    for(int i = 1; i <= n; i++) {
        if(par[i] == -1 || heavy[par[i]] != i) {
            int p = i;
            while(p != -1) {
                top[p] = i;
                p = heavy[p];
            }
        }
    }
}


int lca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] > dep[top[y]]) {
            x = par[top[x]];
        } else {
            y = par[top[y]];
        }
    }
    return dep[x] < dep[y] ? x : y;
}


int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int tmp = 1;
        while(tmp) {
            scanf("%d", &tmp);
            if(tmp) {
                add_edge(i, tmp);
                add_edge(tmp, i);
            }
        }
    }
    YEE();
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        int LCA = lca(u, v);
        printf("%d %d\n", LCA, dep[u] - dep[LCA] + dep[v] - dep[LCA]);
    }
    return 0;
}
