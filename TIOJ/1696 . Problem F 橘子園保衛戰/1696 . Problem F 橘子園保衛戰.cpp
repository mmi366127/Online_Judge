#include <bits/stdc++.h>
#define all(X) X.begin(), X.end()
#define maxn 100007
#define LOG 20
typedef long long loli;
using namespace std;


int dis[maxn][LOG];
int dep[maxn], sz[maxn], Par[maxn];

vector<int> G[maxn];




int get_cent(int p) {
    static int fa[maxn], que[maxn], sz[maxn];
    int idx = 0;
    que[idx++] = p; fa[p] = -1;
    for(int i = 0; i < idx; i++) {
        int x = que[i];
        for(int j = 0; j < G[x].size(); j++) {
            if(G[x][j] != fa[x]) {
                fa[G[x][j]] = x;
                que[idx++] = G[x][j];
            }
        }
    }
    int ret = -1, mi = 1e9;
    for(int i = idx - 1; i >= 0; i--) {
        sz[i] = 1;
        int x = que[i], mx = 0;
        for(int j = 0; j < G[x].size(); j++) {
            if(G[x][j] != fa[x]) {
                sz[x] += sz[G[x][j]];
                mx = max(sz[G[x][j]], mx);
            }
        }
        mx = max(mx, idx - sz[x]);
        if(mx < mi) ret = x;
    }
    return ret;
}

void cent_deco(int x, int dep, int par) {
    x = get_cent(x);
    dfs();
}

int n, u, v;

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    printf("%d\n", get_cent(1));
    return 0;
}

