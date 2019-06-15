#include <bits/stdc++.h>
#define pb push_back
#define all(X) X.begin(), X.end()
#define maxn 500
typedef long long loli;
using namespace std;

const loli INF = 0x3f3f3f3f3f3f3f3f;

vector<pair<loli, loli> > G[maxn];
loli U[maxn], C[maxn], d[maxn];
loli n, p, u, v, w;

loli dfs(int x) {
    if(C[x] != INF) return C[x];
    C[x] = 0;
    for(int i = 0; i < G[x].size(); i++) {
        loli tmp = dfs(G[x][i].first);
        if(tmp > 0) C[x] += (dfs(G[x][i].first) * G[x][i].second);
    }
    C[x] -= U[x];
    //printf("%d %d\n", x, C[x]);
    return C[x];
}

int main() {
    memset(d, 0, sizeof(d));
    memset(C, 0x3f, sizeof(C));
    scanf("%lld%lld", &n, &p);
    for(int i = 1; i <= n; i++) {
        scanf("%lld%lld", &u, &v);
        if(u) C[i] = u;
        U[i] = v;
    }
    for(int i = 0; i < p; i++) {
        scanf("%lld%lld%lld", &u, &v, &w);
        G[v].pb({u, w}); d[u]++;
    }
    for(int i = 1; i <= n; i++) {
        if(C[i] == INF) dfs(i);
    }
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        if(C[i] && d[i] == 0) flag = false;
        if(C[i] > 0 && d[i] == 0) printf("%d %d\n", i, C[i]);
    }
    //for(int i = 1; i <= n ;i++) printf("%lld %lld \n", i, C[i]);
    if(flag) puts("NULL");
    return 0;
}
