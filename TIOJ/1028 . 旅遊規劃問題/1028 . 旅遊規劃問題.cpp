#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge {
    int v, w;
    Edge(int a, int b) :
        v(a), w(b) {}
    bool operator < (const Edge &a) const {
        return w > a.w;
    }
};

const int INF = 0x3f3f3f3f3f3f3f3f;

int A[15], dp[15][1 << 15], pre[15][1 << 15], dis[15];
priority_queue<Edge> pq;
int n, m, u, v, w, k;
vector<Edge> G[15];

 main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    scanf("%lld", &k);
    int target = 0;
    for(int i = 0; i < k; i++) {
        scanf("%lld", A + i);
        target |= 1 << A[i];
    }
    for(int i = 0; i < n; i++) {
        dp[i][0] = 0;
        for(int j = 1; j < (1 << n); j++)
            dp[i][j] = INF;
    }
    for(int i = 1; i < (1 << n); i++) {
        if(i == (target & i)) {
            while(pq.size()) pq.pop();
            memset(dis, 0x3f, sizeof(dis));
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    dis[j] = dp[j][i ^ (1 << j)];
                    pq.push({j, dis[j]});
                }
            }
            while(pq.size()) {
                auto x = pq.top(); pq.pop();
                if(dis[x.v] != x.w) continue;
                for(auto y : G[x.v])  {
                    if(dis[y.v] > dis[x.v] + y.w) {
                        dis[y.v] = dis[x.v] + y.w;
                        pre[y.v][i] = x.v;
                        pq.push({y.v, dis[y.v]});
                    } else if(dis[y.v] == dis[x.v] + y.w && pre[y.v][i] > x.v)
                        pre[y.v][i] = x.v;
                }
            }
            for(int j = 0; j < n; j++)
                if(!(i & (1 << j))) dp[j][i] = dis[j];
        }
    }
    printf("Minimum travel distance: %lld\n", dp[A[0]][target^(1 << A[0])]);
    printf("Travel route:");
    while(true) {
        printf(" %d", A[0]);
        if(target & (1 << A[0])) target ^= 1 << A[0];
        if(!target) break;
        A[0] = pre[A[0]][target];

    }
    puts("");
    return 0;
}
