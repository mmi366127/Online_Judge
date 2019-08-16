#include <stdio.h>
#include <string.h>
#define maxn 500005
#define maxN 1000005
struct Edge {
    int pre, to;
};

int head[maxN], tot = 0;
struct Edge edge[maxN];
int p[maxN] = {};

int find(int x) {
    return p[x] ? (p[x] = find(p[x])) : x;
}

void add(int u, int v) {
    edge[tot].to = v;
    edge[tot].pre = head[u];
    head[u] = tot++;
}

int par[maxN], top[maxN], sz[maxN], heavy[maxN], dep[maxN] = {};
int ans[maxn], X[maxn], Y[maxn];
int n, m, x, y;

void dfs(int x) {
    sz[x] = 1; heavy[x] = -1;
    for(int i = head[x]; i != -1; i = edge[i].pre) {
        dep[edge[i].to] = dep[x] + 1;
        dfs(edge[i].to);
        sz[x] += sz[edge[i].to];
        if(heavy[x] == -1 || sz[heavy[x]] < sz[edge[i].to]) {
            heavy[x] = edge[i].to;
        }
    }
}

void build(int N) {
    for(int i = 1; i <= N; i++) {
        if(!dep[i] && par[i] == -1) {
            dep[i] = 1;
            dfs(i);
        }
    }
    for(int i = 1; i <= N; i++) {
        if(par[i] == -1 || heavy[par[i]] != i) {
            for(int cur = i; cur != -1; cur = heavy[cur]) {
                top[cur] = i;
            }
        }
    }
}

int lca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] > dep[top[y]])
            x = par[top[x]];
        else
            y = par[top[y]];
    }
    return dep[x] < dep[y] ? x : y;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, 4 *(n + m + 1));
    memset(par, -1, 4 *(n + m + 1));
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", X + i, Y + i);
        if((x = find(X[i])) != (y = find(Y[i]))) {
            p[x] = p[y] = n + i;
            par[x] = n + i;
            par[y] = n + i;
            ans[i] = -1;
        } else {
            ans[i] = 0;
        }
    }
    for(int i = 1; i <= n + m; i++) {
        if(par[i] != -1) {
            add(par[i], i);
        }
    }
    build(n + m);
    for(int i = 1; i <= m; i++) {
        if(ans[i] == -1) {
            puts("Mukyu");
            continue;
        }
        printf("%d\n", lca(X[i], Y[i]) - n);
    }
    return 0;
}
