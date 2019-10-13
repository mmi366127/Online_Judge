#include <bits/stdc++.h>
#include "lib1481.h"
using namespace std;
#define maxn 2007


vector<pair<int, int> > G[maxn];
int n, k, u, v, tot = 0;
int ans[20007] = {};

void dfs(int x) {
    for(auto t : G[x]) {
        if(!ans[t.second]) {
            ans[t.second] = ++tot;
            dfs(t.first);
        }
    }
}


int main() {
    Init();
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    dfs(1);
    Possible();
    for(int i = 1; i <= k; i++) {
        Number(ans[i]);
        //printf("%d\n", ans[i]);
    }
    Finish();
    return 0;
}
