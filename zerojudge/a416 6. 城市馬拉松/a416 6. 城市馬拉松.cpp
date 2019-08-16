#include <bits/stdc++.h>
#define all(X) (X).begin(), (X).end()
#define maxn 1007
using namespace std;
struct Edge {
    int to, val;
    Edge(int a, int b) :
        to(a), val(b) {}
    bool operator < (const Edge &a) const {
        return val > a.val;
    }
};

const int INF = 0x3f3f3f3f;

vector<int> Nodd, dis, d;
vector<Edge> G[maxn];
int dp[(1 << 20) + 87];
int adj[21][21];
int n, m, s, t, u, v, w, ans = 0;

int SP(int s, vector<int> &dis) {
    static priority_queue<Edge> pq;
    while(pq.size()) pq.pop();
    fill(all(dis), INF);
    pq.push(Edge(s, 0)); dis[s] = 0;
    while(pq.size()) {
        int x = pq.top().to;
        int d = pq.top().val;
        pq.pop();
        if(dis[x] != d) continue;
        for(int i = 0; i < G[x].size(); i++) {
            int y = G[x][i].to, w = G[x][i].val;
            if(dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                pq.push(Edge(y, dis[y]));
            }
        }
    }
}

int dfs(int x) {
    if(dp[x] != -1) return dp[x];
    int ret = INF;
    for(int i = 0; i < Nodd.size(); i++) {
        if((1 << i) & x) {
            for(int j = i + 1; j < Nodd.size(); j++) {
                if((1 << j) & x) {
                    ret = min(ret, dfs(x ^ ((1 << i) | (1 << j))) + adj[i][j]);
                }
            }
        }
    }
    return dp[x] = ret;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    d.resize(n + 1, 0);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        d[u]++; d[v]++; ans += w;
    }
    d[s]++; d[t]++;
    for(int i = 1; i <= n; i++) {
        if(d[i] & 1) {
            Nodd.emplace_back(i);
        }
    }
    dis.resize(n + 1);
    for(int i = 0; i < Nodd.size(); i++) {
        SP(Nodd[i], dis);
        for(int j = 0; j < Nodd.size(); j++) {
            adj[i][j] = dis[Nodd[j]];
        }
    }
    memset(dp, -1, sizeof(dp)); dp[0] = 0;
    ans += dfs((1 << Nodd.size()) - 1);
    printf("%d\n", ans);
    return 0;
}
