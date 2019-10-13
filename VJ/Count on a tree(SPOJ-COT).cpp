#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define maxn 100005
using namespace std;
struct Node {
    int l, r, cnt;
    Node(int a = 0) :
        l(0), r(0), cnt(a) {}
};

Node ram[maxn * 20];
int tot = 0;

void modify(int l, int r, int pre, int &cur, int pos) {
    cur = ++tot; ram[cur] = ram[pre];
    ram[cur].cnt++;
    if(l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
        modify(l, mid, ram[pre].l, ram[cur].l, pos);
    else
        modify(mid + 1, r, ram[pre].r, ram[cur].r, pos);
}

int query(int l, int r, int a, int b, int c, int d, int k) {
    if(l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    int sum = ram[ram[a].l].cnt + ram[ram[b].l].cnt - ram[ram[c].l].cnt - ram[ram[d].l].cnt;
    if(sum >= k)
        return query(l, mid, ram[a].l, ram[b].l, ram[c].l, ram[d].l, k);
    else
        return query(mid + 1, r, ram[a].r, ram[b].r, ram[c].r, ram[d].r, k - sum);
}


int W[maxn], Tree[maxn], heavy[maxn], sz[maxn], dep[maxn], top[maxn], par[maxn];
vector<int> G[maxn];
vector<int> V;
int n, m, mx;

int get_id(int x) {
    return (lower_bound(all(V), x) - V.begin()) + 1;
}

void dfs(int x, int p, int d) {
    heavy[x] = -1;
    dep[x] = d; par[x] = p; sz[x] = 1;
    modify(1, mx, Tree[p], Tree[x], get_id(W[x]));
    for(int i = 0; i < (int)G[x].size(); i++) {
        if(G[x][i] == p) continue;
        dfs(G[x][i], x, d + 1);
        sz[x] += sz[G[x][i]];
        if(heavy[x] == -1 || sz[heavy[x]] < sz[G[x][i]])
            heavy[x] = G[x][i];
    }
}

void build() {
    memset(Tree, 0, sizeof(Tree));
    dfs(1, 0, 1);
    for(int i = 1; i <= n; i++) {
        if(par[i] == 0 || heavy[par[i]] != i) {
            for(int p = i; p != -1; p = heavy[p]) {
                top[p] = i;
            }
        }
    }
}

int lca(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]])
            v = par[top[v]];
        else
            u = par[top[u]];
    }
    return (dep[u] < dep[v]) ? u : v;
}



int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", W + i);
        V.push_back(W[i]);
    }
    sort(all(V)); V.erase(unique(all(V)), V.end());
    mx = V.size();
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    build();
    for(int i = 0; i < m; i++) {
        int u, v, k, LCA;
        scanf("%d%d%d", &u, &v, &k);
        LCA = lca(u, v);
        printf("%d\n", V[query(1, mx, Tree[u], Tree[v], Tree[LCA], Tree[par[LCA]], k) - 1]);
    }
    return 0;
}
