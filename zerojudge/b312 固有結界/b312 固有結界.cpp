#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define maxn 5007
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int,int>> G[maxn];
vector<int> dis(maxn);


int dijkstra(int s,int t) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    fill(dis.begin(), dis.end(), INF);
    dis[s] = 0; pq.push({0, s});
    while(!pq.empty()) {
        int x = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(dis[x] != d) continue;
        if(x == t) return dis[t];
        for(auto y : G[x]) {
            if(dis[y.first] > dis[x] + y.second) {
                dis[y.first] = dis[x] + y.second;
                pq.push({dis[y.first], y.first});
            }
        }
    }
}

int main() {
    int n, m, s, t, u, v, w;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    printf("%d\n", dijkstra(s, t));
    return 0;
}
