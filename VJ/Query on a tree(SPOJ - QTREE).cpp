#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
struct Edge {
    int to, w, id;
    Edge(int a, int b, int c) :
        to(a), w(b), id(c) {}
};


const int INF = 0x3f3f3f3f;

struct Segment_Tree {
    int val[1 << 15];
    #define ls(x) (x << 1)
    #define rs(x) (x << 1 | 1)
    void pull(int x) {
        val[x] = max(val[ls(x)], val[rs(x)]);
    }
    void build(int A[], int x = 1, int L = 1, int R = maxn) {
        if(L == R) {
            val[x] = A[L];
            return;
        }
        int mid = (L + R) >> 1;
        build(A, ls(x), L, mid);
        build(A, rs(x), mid + 1, R);
        pull(x);
    }
    int query(int l, int r, int x = 1, int L = 1, int R = maxn) {
        if(l <= L && R <= r) {
            return val[x];
        }
        int mid = (L + R) >> 1;
        int ret = -INF;
        if(l <= mid)
            ret = max(query(l, r, ls(x), L, mid), ret);
        if(r > mid)
            ret = max(query(l, r, rs(x), mid + 1, R), ret);
        return ret;
    }
    void modify(int pos, int v, int x = 1, int L = 1, int R = maxn) {
        if(L == R) {
            val[x] = v;
            return;
        }
        int mid = (L + R) >> 1;
        if(pos <= mid)
            modify(pos, v, ls(x), L, mid);
        else
            modify(pos, v, rs(x), mid + 1, R);
        pull(x);
    }
}Tree;

int heavy[maxn], sz[maxn], top[maxn], par[maxn], dep[maxn];
int id[maxn], edge_pos[maxn], node_pos[maxn], ww[maxn];
vector<Edge> G[maxn];
int n, t;

void dfs(int x, int p, int d) {
    sz[x] = 1; heavy[x] = -1;
    par[x] = p; dep[x] = d;
    for(int i = 0; i < G[x].size(); i++) {
        if(G[x][i].to == p) continue;
        dfs(G[x][i].to, x, d + 1);
        sz[x] += sz[G[x][i].to];
        ww[G[x][i].to] = G[x][i].w;
        id[G[x][i].to] = G[x][i].id;
        if(heavy[x] == -1 || sz[heavy[x]] < sz[G[x][i].to])
            heavy[x] = G[x][i].to;
    }
    return;
}

void decomp() {
    dfs(1, -1, 1); int tot = 0;
    int tmp[maxn];
    for(int i = 1; i <= n; i++) {
        if(par[i] == -1 || heavy[par[i]] != i) {
            for(int p = i; p != -1; p = heavy[p]) {
                top[p] = i; node_pos[p] = ++tot;
                edge_pos[id[p]] = tot;
                tmp[tot] = ww[p];
            }
        }
    }
    Tree.build(tmp);
}

int query(int a, int b) {
    int ans = -INF;
    while(top[a] != top[b]) {
        if(dep[top[a]] > dep[top[b]]) {
            ans = max(ans, Tree.query(node_pos[top[a]], node_pos[a]));
            a = par[top[a]];
        } else {
            ans = max(ans, Tree.query(node_pos[top[b]], node_pos[b]));
            b = par[top[b]];
        }
    }
    if(dep[a] > dep[b])
        ans = max(ans, Tree.query(node_pos[heavy[b]], node_pos[a]));
    else
        ans = max(ans, Tree.query(node_pos[heavy[a]], node_pos[b]));
    return ans;
}

char s[100];

int main() {
   scanf("%d", &t);
   while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for(int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].emplace_back(v, w, i);
            G[v].emplace_back(u, w, i);
        }
        decomp();
        while(scanf("%s", s)) {
            if(s[0] == 'D') {
                break;
            }
            if(s[0] == 'Q') {
                int a, b;
                scanf("%d%d", &a, &b);
                printf("%d\n", query(a, b));
            } else {
                int idx,  v;
                scanf("%d%d", &idx, &v);
                Tree.modify(edge_pos[idx], v);
            }
        }
    }
    return 0;
}
