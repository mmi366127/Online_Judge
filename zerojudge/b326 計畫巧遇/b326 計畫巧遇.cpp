#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> G[maxn];
int n, m, u, v;

int heavy[maxn], dep[maxn], par[maxn], sz[maxn], top[maxn];
set<pair<int, int>> ans[maxn];

void dfs(int x, int p, int d) {
    dep[x] = d; heavy[x] = -1; par[x] = p, sz[x] = 1;
    for(int i = 0; i < G[x].size(); i++) {
        if(G[x][i] == p) continue;
        dfs(G[x][i], x, d - 1);
        sz[x] += sz[G[x][i]];
        if(heavy[x] == -1 || sz[heavy[x]] < sz[G[x][i]])
            heavy[x] = G[x][i];
    }
}

void build() {
    dfs(0, -1, INF);
    for(int i = 0; i < n; i++) {
        if(par[i] == -1 || heavy[par[i]] != i) {
            for(int p = i; p != -1; p = heavy[p]) {
                top[p] = i;
            }
        }
    }
}

int query(int x) {
    while(x != -1) {
        if(ans[top[x]].size()) {
            auto it = ans[top[x]].lower_bound(make_pair(dep[x], x));
            if(it != ans[top[x]].end())
                return it -> second;
        }
        x = par[top[x]];
    }
    return -1;
}

void modify(int x) {
    static set<pair<int, int>>::iterator it;
    if((it = ans[top[x]].find(make_pair(dep[x], x))) != ans[top[x]].end()) {
        ans[top[x]].erase(it);
        return;
    }
    ans[top[x]].insert(make_pair(dep[x], x));
}

char s[10];

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++)
            G[i].clear(), ans[i].clear();
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        scanf("%d", &m);
        build();
        for(int i = 0; i < m; i++) {
            scanf("%s%d", s, &v);
            if(s[0] == 'S') printf("%d\n", query(v));
            else modify(v);
        }
        puts("");
    }
    return 0;
}

