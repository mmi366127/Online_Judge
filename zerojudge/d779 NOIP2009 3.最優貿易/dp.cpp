#include <bits/stdc++.h>
#define maxn 100007
using namespace std;


const int INF = 0x3f3f3f3f;

vector<int> G[maxn];

int dp[maxn], MI[maxn], num[maxn];

void dfs(int x, int pre, int mi) {
    bool flag = false;
    if(mi < MI[x]) MI[x] = mi, flag = true;
    int tmp = max(dp[pre], num[x] - MI[x]);
    if(tmp > dp[x]) dp[x] = tmp, flag = true;
    if(!flag) return;
    for(int i = 0; i < G[x].size(); i++) {
        dfs(G[x][i], x, MI[x]);
    }
}

int n, m, a, b, c;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", num + i);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back(b);
        if(c == 2) G[b].push_back(a);
    }
    num[0] = INF;
    for(int i = 1; i <= n; i++) MI[i] = num[i];
    memset(dp, -0x3f, sizeof(dp));
    dfs(1, 0, INF);
    printf("%d\n", dp[n]);
    return 0;
}
