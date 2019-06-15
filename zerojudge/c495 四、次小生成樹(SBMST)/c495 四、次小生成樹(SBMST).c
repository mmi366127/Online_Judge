#include<stdio.h>
#include<string.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)
#define maxn 100007
#define maxm 500007
#define LOG 20
typedef long long int loli;
typedef struct Edge {
    int u, v, w, pre;
    char mst;
}Edge;

const loli INF = 0x3f3f3f3f3f3f3f3f;
int par[maxn][LOG], dis[maxn][LOG];
int head[maxn], p[maxn], s[maxn], dep[maxn];
Edge edge[maxm], tmp[maxm], G[maxn+maxn];
int n, m, i, tot = 0;

void add(int u,int v,int w) {
    G[tot].v = v;
    G[tot].pre = head[u];
    G[tot].w = w;
    head[u] = tot++;
}

int find(int x) {
    return p[x] < 0 ? x : (p[x] = find(p[x]));
}

char join(int x,int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(s[x] < s[y]) {
        int __tmp = x;
        x = y;
        y = __tmp;
    }
    p[y] = x;
    s[x] += s[y];
    return 1;
}

void sort(int L,int R) {
    if(L == R) return;
    int mid = (L+R)>>1;
    int idx1 = L;
    int idx2 = mid+1;
    int idx = L;
    sort(idx1, mid);
    sort(idx2, R);
    while(idx1 <= mid && idx2 <= R) {
        if(edge[idx1].w < edge[idx2].w) {
            tmp[idx++] = edge[idx1++];
        } else {
            tmp[idx++] = edge[idx2++];
        }
    }
    while(idx1 <= mid) {
        tmp[idx++] = edge[idx1++];
    }
    while(idx2 <= R) {
        tmp[idx++] = edge[idx2++];
    }
    for(idx = L; idx <= R; idx++) {
        edge[idx] = tmp[idx];
    }
}

void dfs(int x, int d, int p) {
    dep[x] = d;
    for(int i = head[x]; i != -1; i = G[i].pre) {
        int y = G[i].v;
        if(y == p) continue;
        par[y][0] = x;
        dis[y][0] = G[i].w;
        dfs(y, d+1, x);
    }
}

void build() {
    memset(par, 0, sizeof(par));
    memset(dis, 0, sizeof(dis));
    dfs(1, 1, -1);
    for(int k = 1; k < LOG; k++) {
        for(int i = 1; i <= n; i++) {
            par[i][k] = par[par[i][k-1]][k-1];
            dis[i][k] = max(dis[i][k-1], dis[par[i][k-1]][k-1]);
        }
    }
}

int get_dis(int u, int v) {
    if(dep[u] < dep[v]) {
        int __tmp = u;
        u = v;
        v = __tmp;
    }
    int ret = -INF; int p = dep[u] - dep[v];
    for(int k = 0; p; k++) {
        if(p&1) {
            ret = max(ret, dis[u][k]);
            u = par[u][k];
        }
        p >>= 1;
    }
    if(u == v) return ret;
    for(int k = LOG-1; k >= 0; k--) {
        if(par[u][k] != par[v][k]) {
            ret = max(ret, dis[u][k]);
            ret = max(ret, dis[v][k]);
            u = par[u][k];
            v = par[v][k];
        }
    }
    ret = max(ret, dis[u][0]);
    ret = max(ret, dis[v][0]);
    return ret;
}





int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    loli ans1, ans2;
    ans1 = 0;
    sort(0, m-1);
    memset(p, -1, sizeof(int)*(n+1));
    memset(head, -1, sizeof(int)*(n+1));
    for(int i = 0; i <= n; i++) s[i] = 1;
    for(int i = 0; i < m; i++) {
        if(join(edge[i].u, edge[i].v)) {
            edge[i].mst = 1;
            add(edge[i].u, edge[i].v, edge[i].w);
            add(edge[i].v, edge[i].u, edge[i].w);
            ans1 = ans1 + edge[i].w;
        } else edge[i].mst = 0;
    }
    ans2 = INF;
    build();
    for(int i = 0; i < m; i++) {
        if(!edge[i].mst) {
            ans2 = min(ans2, edge[i].w - get_dis(edge[i].u, edge[i].v));
        }
    }
    printf("%lld %lld\n", ans1, ans1 + ans2);
    return 0;
}
