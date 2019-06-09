#include <bits/stdc++.h>
#define maxn 40007
using namespace std;

vector<int> G[maxn];
char vis[maxn];
int n, m, u, v;
bool flag;

void dfs(int x) {
    printf("%d\n", vis[x]);
    for(int i = 0; i < G[x].size(); i++) {
        if(vis[G[x][i]] == -1) {
            vis[G[x][i]] = 1 ^ vis[x];
            dfs(G[x][i]);
        } else if(vis[x] == vis[G[x][i]]) {
            flag = false;
        }
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 and m == 0) return 0;
        for(int i = 1; i <= n; i++) G[i].clear(), vis[i] = -1;
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        flag = true;
        for(int i = 1; i <= n; i++) {
            if(vis[i] == -1) {
                dfs(i);
            }
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
