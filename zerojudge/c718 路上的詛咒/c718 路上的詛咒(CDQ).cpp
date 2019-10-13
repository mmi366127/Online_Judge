#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long loli;
struct Pt {
    int x, h, v, id;
    Pt(int a = 0, int b = 0, int c = 0, int d = 0) :
        x(a), h(b), v(c), id(d) {}
};

template<class T> void read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = x * 10 + (c ^ '0');
}

template<class T> void put(T x) {
    static char buf[20], idx;
    for(idx = 0; x; idx++) {
        buf[idx] = (x % 10) + '0';
        x /= 10;
    }
    if(idx == 0) putchar('0');
    else {
        for(idx--; idx >= 0; idx--) {
            putchar(buf[idx]);
        }
    }
    putchar('\n');
}

loli bit[maxn] = {};

void add(int x, loli v) {
    for(; x < maxn; x += x & (-x)) {
        bit[x] += v;
    }
}

loli query(int l, int r) {
    loli ret = 0;
    for(int x = r; x; x -= x & (-x)) {
        ret += bit[x];
    }
    for(int x = l - 1; x; x -= x & (-x)) {
        ret -= bit[x];
    }
    return ret;
}

int idx_edge[2][maxn], idx_node[2][maxn], h[maxn + maxn], v[maxn + maxn];
int dep[maxn], sz[maxn], par[maxn], heavy[maxn], top[maxn];
vector<Pt> G[maxn], V, tmp;
int n, m, times = 0;
loli ans[maxn];
Pt edge[maxn];

void dfs(int x, int p, int d) {
    dep[x] = d; par[x] = p;
    sz[x] = 1; heavy[x] = -1;
    for(auto y : G[x]) {
        if(y.x == p) continue;

        h[++times] = y.h;
        v[times] = y.v;
        idx_node[0][y.x] = times;
        idx_edge[0][y.id] = times;

        dfs(y.x, x, d + 1);

        h[++times] = y.h;
        v[times] = -y.v;
        idx_node[1][y.x] = times;
        idx_edge[1][y.id] = times;

        sz[x] += sz[y.x];
        if(heavy[x] == -1 || sz[heavy[x]] < sz[y.x])
            heavy[x] = y.x;
    }
}

void build() {
    h[++times] = 1;
    v[times] = 0;
    idx_edge[0][0] = times;
    idx_node[0][1] = times;
    dfs(1, -1, 1);
    h[++times] = 1;
    v[times] = 0;
    idx_edge[1][0] = times;
    idx_node[1][1] = times;

    for(int i = 1; i <= n; i++) {
        if(par[i] == -1 || heavy[par[i]] != i) {
            for(int p = i; p != -1; p = heavy[p]) {
                top[p] = i;
            }
        }
    }
    for(int i = 1; i <= times; i++) {
        V.emplace_back(i, h[i], v[i], 0);
    }
}

int lca(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] > dep[top[v]])
            u = par[top[u]];
        else
            v = par[top[v]];
    }
    return dep[u] < dep[v] ? u : v;
}

void CDQ(int l, int r) {
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    CDQ(l, mid), CDQ(mid + 1, r);
    int i, j, idx = l;
    for(i = mid + 1, j = l; i <= r; i++) {
        while(j <= mid && V[i].x >= V[j].x) {
            if(!V[j].id) add(V[j].h, V[j].v);
            j++;
        }
        if(V[i].id) {
            if(V[i].id > 0)
                ans[V[i].id] += query(V[i].h + 1, n);
            else
                ans[-V[i].id] -= query(V[i].h + 1, n);
        }
    }
    for(j--; j >= l; j--)
        if(!V[j].id) add(V[j].h, -V[j].v);
    for(i = mid + 1, j = l; i <= r; i++) {
        while(j <= mid && V[i].x >= V[j].x) {
            tmp[idx++] = V[j++];
        }
        tmp[idx++] = V[i];
    }
    while(j <= mid)
        tmp[idx++] = V[j++];
    for(i = l; i <= r; i++)
        V[i] = tmp[i];
}

int main() {
    read(n), read(m);
    V.reserve(maxn * 4);
    tmp.reserve(maxn * 4);
    for(int i = 1; i < n; i++) {
        int a, b;
        read(a), read(b), read(h[i]), read(v[i]);
        G[a].emplace_back(b, h[i], v[i], i);
        G[b].emplace_back(a, h[i], v[i], i);
    }
    build();
    memset(ans, -1, sizeof(ans));
    for(int i = 1; i <= m; i++) {
        int op, s, t, d;
        read(op); read(s); read(t); read(d);
        if(op) {
            int a = idx_edge[0][s], b = idx_edge[1][s];
            V.emplace_back(a, h[a], -v[a], 0);
            V.emplace_back(a, (h[a] = t), (v[a] = d), 0);
            V.emplace_back(b, h[b], -v[b], 0);
            V.emplace_back(b, (h[b] = t), (v[b] = -d), 0);
        } else {
            int LCA = lca(s, t);
            ans[i] = 0;
            V.emplace_back(idx_node[0][LCA], d, d, -i);
            V.emplace_back(idx_node[0][s], d, d, i);
            V.emplace_back(idx_node[0][LCA], d, d, -i);
            V.emplace_back(idx_node[0][t], d, d, i);
        }
    }
    tmp.resize(V.size());
    CDQ(0, V.size() - 1);
    for(int i = 1; i <= m; i++) {
        if(ans[i] != -1) put(ans[i]);
    }
    return 0;
}
