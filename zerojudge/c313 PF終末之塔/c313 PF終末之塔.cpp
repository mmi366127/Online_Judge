#include<stdio.h>
#include<string.h>
#define swap(a, b) {int __tmp = a; a = b; b = __tmp;}
#define max(a, b) (a) > (b) ? (a) : (b)
#define maxn 200007
#define LOG 25
typedef struct Edge{
    int to, pre, w;
}Edge;

Edge edge[maxn+maxn];
int par[maxn][LOG];
int dis[maxn][LOG];
int head[maxn], dep[maxn], bin[LOG];

int n, q, i, u, v, w, tot = 0;

void add(int u, int v, int w) {
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].pre = head[u];
    head[u] = tot++;
}

void dfs(int x, int p, int d) {
    dep[x] = d;
    for(int i = head[x]; i != -1; i = edge[i].pre) {
        int y = edge[i].to;
        if(p == y) continue;
        par[y][0] = x;
        dis[y][0] = edge[i].w;
        dfs(y, x, d+1);
    }
}

void build() {
    bin[0] = 1;
    for(int i = 1; i < LOG; i++) {
        bin[i] = bin[i-1] << 1;
    }
    par[1][0] = -1;
    dis[1][0] = 0;
    dfs(1, -1, 1);
    for(int k = 1; k < LOG; k++) {
        for(int i = 1; i <= n; i++) {
            par[i][k] = par[par[i][k-1]][k-1];
            dis[i][k] = max(dis[i][k-1], dis[par[i][k-1]][k-1]);
        }
    }
}

int solve(int u,int v) {
    if(dep[u] < dep[v])
        swap(u, v);
    int ret = -1, p = u;
    for(int k = LOG-1; k >= 0; k--) {
        if(dep[par[p][k]] >= dep[v]) {
            ret = max(dis[p][k], ret);
            p = par[p][k];
        }
    }
    if(p == v) return ret;
    for(int k = LOG-1; k >= 0; k--) {
        if(par[p][k] != par[v][k]) {
            ret = max(ret, dis[p][k]);
            ret = max(ret, dis[v][k]);
            p = par[p][k];
            v = par[v][k];
        }
    }
    ret = max(ret, dis[p][0]);
    ret = max(ret, dis[v][0]);
    return ret;
}

int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(int) * (n+1));
    for(int i = 1; i < n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    build();
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d%d", &u, &v);
        printf("%d\n", solve(u, v));
    }
    return 0;
}
