#include <bits/stdc++.h>
#define maxn 100007
using namespace std;

const int INF = 0x3f3f3f3f;

int SCC[maxn], CMI[maxn], CMX[maxn];
int vis[maxn], low[maxn], a[maxn];
vector<int> G[maxn], GG[maxn];
char instk[maxn];
stack<int> stk;
int t, id, ans;

void tarjan(int x) {
    vis[x] = low[x] = ++t;
    stk.push(x); instk[x] = 1;
    for(int i = 0; i < G[x].size(); i++) {
        int y = G[x][i];
        if(!vis[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if(instk[y]) {
            low[x] = min(low[x], vis[y]);
        }
    }
    if(low[x] == vis[x]) {
        int p = -1;
        id++;
        CMI[id] = CMX[id] = a[x];
        while(!stk.empty()) {
            p = stk.top(); stk.pop();
            instk[p] = 0;
            SCC[p] = id;
            CMI[id] = min(CMI[id], a[p]);
            CMX[id] = max(CMX[id], a[p]);
            if(p == x) break;
        }
    }
}

int dp[maxn], MI[maxn];

void dfs(int x, int pre, int mi) {
    bool flag = false;
    if(mi < MI[x]) MI[x] = mi, flag = true;
    int tmp = max(dp[pre], CMX[x] - MI[x]);
    if(tmp > dp[x]) dp[x] = tmp, flag = true;
    //printf("%d %d\n", x, dp[x]);
    ans = max(dp[x], ans);
    if(!flag) return;
    for(int i = 0; i < GG[x].size(); i++) {
        dfs(GG[x][i], x, MI[x]);
    }
}

int n, m, u, v, z;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &u, &v, &z);
        G[u].push_back(v);
        if(z == 2)
        G[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    memset(low, 0, sizeof(low));
    memset(instk, 0, sizeof(instk));
    t = 0, id = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) tarjan(i);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < G[i].size(); j++) {
            if(SCC[i] != SCC[G[i][j]]) {
                GG[SCC[i]].push_back(SCC[G[i][j]]);
            }
        }
    }
    ans = 0;
    memset(dp, -0x3f, sizeof(dp));
    for(int i = 1; i <= id; i++) {
        MI[i] = CMI[i];
    }
    dfs(SCC[1], 0, INF);
    printf("%d\n", ans);
    return 0;
}
