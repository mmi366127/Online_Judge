#include <stdio.h>
#include <string.h>
#define maxn 30007
#define LOG 17


int to[maxn+maxn], pre[maxn+maxn], head[maxn], tot = 0;

void add_edge(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}



int par[maxn][LOG] = {};
int dep[maxn];
int n, m;

void dfs(int x, int p) {
    par[x][0] = p;
    for(int i = 1; i < LOG; i++) {
        par[x][i] = par[par[x][i-1]][i-1];
    }
    for(int i = head[x]; i != -1; i = pre[i]) {
        if(to[i] != p) {
            dep[to[i]] = dep[x]+1;
            dfs(to[i], x);
        }
    }
}


void build() {
    dep[1] = 1; dfs(1, 0);
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) {
        int _ =  u;
        u = v;
        v = _;
    }
    int d = dep[u] - dep[v];
    for(int i = 0; d; i++) {
        if(d & 1) {
            u = par[u][i];
        }
        d >>= 1;
    }
    if(u == v) return v;
    for(int i = LOG - 1; i >= 0; i--) {
        if(par[v][i] != par[u][i]) {
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
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
    build();
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        int LCA = lca(u, v);
        printf("%d %d\n", LCA, dep[u] - dep[LCA] + dep[v] - dep[LCA]);
    }
    return 0;
}
