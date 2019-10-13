#include <stdio.h>
#include <string.h>
#define maxn 100005
#define maxm 200005



int top[maxn], sz[maxn], dep[maxn], dep_w[maxn], heavy[maxn], par[maxn];
int head[maxn], W[maxm], pre[maxm], to[maxm], tot = 0;
int city[maxn], tmp[maxn], times[maxn], t = 0;
int n, k, u, v, w;

void sort(int l, int r) {
    if(r - l == 1) return;
    int m = (l + r) >> 1;
    sort(l, m); sort(m, r);
    int i, j, idx = l;
    for(i = l, j = m; i < m; i++) {
        while(j < r && times[city[j]] < times[city[i]]) {
            tmp[idx++] = city[j++];
        }
        tmp[idx++] = city[i];
    }
    while(j < r) tmp[idx++] = city[j++];
    for(idx = l; idx < r; idx++)
        city[idx] = tmp[idx];
}


void add(int u, int v, int w) {
    to[tot] = v;
    W[tot] = w;
    pre[tot] = head[u];
    head[u] = tot++;
}

void dfs(int x, int p) {
    par[x] = p; heavy[x] = -1;
    sz[x] = 1;
    times[x] = t++;
    for(int i = head[x]; i != -1; i = pre[i]) {
        if(to[i] == p) continue;
        dep[to[i]] = dep[x] + 1;
        dep_w[to[i]] = dep_w[x] + W[i];
        dfs(to[i], x);
        sz[x] += sz[to[i]];
        if(heavy[x] == -1 || sz[heavy[x]] < sz[to[i]])
            heavy[x] = to[i];
    }
}

void build() {
    dep_w[0] = 0;
    dep[0] = 0;
    dfs(0, -1);
    for(int i = 0; i < n; i++) {
        if(par[i] == -1 || heavy[par[i]] != i) {
            for(int p = i; p != -1; p = heavy[p]) {
                top[p] = i;
            }
        }
    }
}

int lca(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] > dep[top[v]])
            u = par[top[u]];
        else
            v = par[top[v]];
    }
    return dep[v] < dep[u] ? v : u;
}

int dis(int u, int v) {
    return dep_w[u] + dep_w[v] - 2 * dep_w[lca(u, v)];
}


int main() {
    scanf("%d%d", &n, &k);
    memset(head, -1, sizeof(int) * (n + 1));
    for(int i = 1; i < n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    build();
    long long tmp, ans = 0;
    for(int i = 0; i < k; i++) {
        scanf("%d", &u); tmp = 0;
        if(u == 1) continue;
        for(int j = 0; j < u; j++) {
            scanf("%d", city + j);
            tmp = tmp + dep_w[city[j]];
        }
        sort(0, u);
        for(int j = 0; j < u - 1; j++) {
            tmp = tmp - dep_w[lca(city[j], city[j + 1])];
        }
        tmp = tmp - dep_w[lca(city[u - 1], city[0])];
        tmp = tmp + tmp;
        long long temp, mx = 0, nd = -1;
        for(int j = 1; j < u; j++) {
            temp = dis(city[0], city[j]);
            if(temp > mx) {
                mx = temp;
                nd = city[j];
            }
        }
        if(nd == -1) return -87;
        mx = 0;
        for(int j = 0; j < u; j++) {
            if(city[j] == nd) continue;
            temp = dis(nd, city[j]);
            if(temp > mx) {
                mx = temp;
            }
        }
        tmp = tmp - mx;
        ans = ans + tmp;
    }
    printf("%lld\n", ans);
    return 0;
}
