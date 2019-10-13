#include <bits/stdc++.h>
#define all(X) (X).begin(), (X).end()
#define maxn 1005
using namespace std;
struct Edge {
    int to, pre;
};

const int INF = 0x3f3f3f3f;

vector<int> head(maxn, -1);
vector<int> dis(maxn);
vector<Edge> edge;


void add(int u, int v) {
    edge.push_back({v, head[u]});
    head[u] = edge.size() - 1;
}


int t, n, m, u, v, s;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        fill(all(head), -1);
        edge.clear();
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            add(u, v); add(v, u);
        }
        scanf("%d", &s);
        queue<int> Q; Q.push(s);
        fill(all(dis), INF);
        dis[s] = 0;
        while(Q.size()) {
            int x = Q.front(); Q.pop();
            for(int i = head[x]; i != -1; i = edge[i].pre) {
                int y = edge[i].to;
                if(dis[y] < INF) continue;
                dis[y] = dis[x] + 6;
                Q.push(y);
            }
         }
        for(int i = 1; i <= n; i++) {
            if(i == s) continue;
            printf("%d%c", (dis[i] == INF) ? -1 : dis[i], " \n"[i == n]);
        }
    }
    return 0;
}
