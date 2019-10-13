#include <bits/stdc++.h>
#define maxn 10005
using namespace std;

vector<int> G[maxn], revG[maxn], GG[maxn];
bool vis[maxn] = {}, VIS[maxn] = {};
int scc[maxn] = {}, sz[maxn] = {};
int t, n, m, l, idx = 0;
vector<int> stk;


void dfs1(int x) {
    vis[x] = true;
    for(int y : G[x]) {
        if(!vis[y]) dfs1(y);
    }
    stk.push_back(x);
}

int dfs2(int x, int id) {
    if(scc[x]) return 0;
    int ret = 1;
    scc[x] = id;
    for(int y : revG[x]) {
        ret += dfs2(y, id);
    }
    return ret;
}

void dfs(int x) {
    if(VIS[x]) return;
    VIS[x] = true;
    for(int y : GG[x]) {
        dfs(y);
    }
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &l);
        for(int i = 1; i <= n; i++) {
            G[i].clear();
            GG[i].clear();
            revG[i].clear();
        }
        idx = 0;
        stk.clear();
        memset(scc, 0, sizeof(scc));
        memset(vis, 0, sizeof(vis));
        memset(VIS, 0, sizeof(VIS));
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            revG[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) dfs1(i);
        }
        for(int i = stk.size() - 1; i >= 0; i--) {
            if(!scc[stk[i]]) {
                idx++;
                sz[idx] = dfs2(stk[i], idx);
            }
        }
        for(int u = 1; u <= n; u++) {
            for(int v : G[u]) {
                if(scc[u] != scc[v])
                    GG[scc[u]].push_back(scc[v]);
            }
        }
        for(int i = 0; i < l; i++) {
            int x; scanf("%d", &x);
            dfs(scc[x]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(VIS[scc[i]]) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
