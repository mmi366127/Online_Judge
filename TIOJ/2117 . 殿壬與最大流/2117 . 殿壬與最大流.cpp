#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

bool used[maxn] = {}, vis[maxn] = {};
vector<pair<int, int> > G[maxn];
int n, q, u, v, x, y, tot = 0;
int idx[2][maxn];

void dfs(int x) {
    vis[x] = true;
    idx[0][x] = tot++;
    for(auto t : G[x]) {
        if(!vis[t.first]) {
            used[t.second] = true;
            dfs(t.first);
        }
    }
    idx[1][x] = tot++;
}

bool in(int a, int b) {
    return idx[0][b] <= idx[0][a] && idx[1][a] <= idx[1][b];
}

bool not_in(int a, int b) {
    return !(idx[0][b] < idx[0][a] && idx[1][a] < idx[1][b]);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }
    dfs(1);
    u = -1;
    for(int i = 1; i <= n; i++) {
        for(auto t : G[i]) {
            if(!used[t.second]) {
                u = i; v = t.first;
                break;
            }
        }
        if(u != -1) break;
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d", &x, &y);
        if(in(y, x)) {
            if((in(u, y) && not_in(v, x)) || (in(v, y) && not_in(u, x))) puts("2");
            else puts("1");
        } else if(in(x, y)) {
            if((in(u, x) && not_in(v, y)) || (in(v, x) && not_in(u, y))) puts("2");
            else puts("1");
        } else {
            if((in(u, x) && in(v, y)) || (in(v, x) && in(u, y))) {
                puts("2");
            } else puts("1");
        }
    }

    return 0;
}
