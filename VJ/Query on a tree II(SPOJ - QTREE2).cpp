#include <bits/stdc++.h>
#define maxn 30005
#define maxlg 15
#define int long long
using namespace std;

int w[maxn], pre[maxn], to[maxn], head[maxn], tot;

void add(int u, int v, int W) {
    pre[tot] = head[u];
    to[tot] = v;
    w[tot] = W;
    head[u] = tot++;
}


int par[maxn][maxlg], dep[maxn], dep_w[maxn];
int t, n, u, v, k;

void init() {
    memset(head, -1, sizeof(head));
    memset(par, 0, sizeof(par));
    tot = 0;
}

void dfs(int x, int p, int d, int dw) {
    par[x][0] = p; dep[x] = d; dep_w[x] = dw;
    for(int i = head[x]; i != -1; i = pre[i]) {
        if(to[i] == p) continue;
        dfs(to[i], x, d + 1, dw + w[i]);
    }
}

void build() {
    dfs(1, 0, 0, 0);
    for(int i = 1; i < maxlg; i++) {
        for(int j = 1; j <= n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
}

int query(int u, int v, int k) {
    int uu = u, vv = v;
    if(dep[u] < dep[v])
        swap(u, v);
    int dif = dep[u] - dep[v];
    for(int i = maxlg - 1; i >= 0; i--) {
        if(dif & (1 << i)) {
            u = par[u][i];
        }
    }
    int lca;
    if(u != v) {
        for(int i = maxlg - 1; i >= 0; i--) {
            if(par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }
        lca = par[u][0];
    } else lca = u;

    if(k == 0) return dep_w[uu] + dep_w[vv] - 2 * dep_w[lca];

    if(lca == uu) {
        k = dep[vv] - dep[lca] - k + 1;
        for(int i = maxlg - 1; i >= 0; i--) {
            if(k & (1 << i)) {
                vv = par[vv][i];
            }
        }
        return vv;
    }
    if(k <= dep[uu] - dep[lca] || lca == vv) {
        k--;
        for(int i = maxlg - 1; i >= 0; i--) {
            if(k & (1 << i)) {
                uu = par[uu][i];
            }
        }
        return uu;
    } else {
        k = dep[uu] + dep[vv] - 2 * dep[lca] - k + 1;
        for(int i = maxlg - 1; i >= 0; i--) {
            if(k & (1 << i)) {
                vv = par[vv][i];
            }
        }
        return vv;
    }
    return -1; // ??
}

char s[100];

 main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        init();
        for(int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%lld%lld%lld", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        build();
        while(~scanf("%s", s)) {
            if(s[1] == 'O') break;
            if(s[0] == 'K') {
                scanf("%lld%lld%lld", &u, &v, &k);
                printf("%lld\n", query(u, v, k));
            } else {
                scanf("%lld%lld", &u, &v);
                printf("%lld\n", query(u, v, 0));
            }
        }
        puts("");
    }
    return 0;
}
/*
1

6
1 2 1
2 4 1
2 5 2
1 3 1
3 6 2

KTH 1 4 1
KTH 1 4 2
KTH 1 4 3
*/
