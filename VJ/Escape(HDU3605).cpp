#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define maxn 100005
using namespace std;

const int INF = 0x3f3f3f3f;

struct Dinic {
    struct Edge {
        int pre, to, flow;
        Edge(int a, int b, int c) :
            pre(a), to(b), flow(c) {}
    };
    vector<int> head, dis, cur;
    vector<Edge> edge;
    int op, ed;
    Dinic(int n) : head(n + 1, -1), cur(n + 1), dis(n + 1) {}
    void init() {
        fill(all(head), -1);
        edge.clear();
    }
    void add(int u, int v, int f) {
        edge.emplace_back(head[u], v, f);
        head[u] = edge.size() - 1;
        edge.emplace_back(head[v], u, 0);
        head[v] = edge.size() - 1;
    }
    bool bfs() {
        fill(all(dis), INF);
        queue<int> Q;
        Q.push(op), dis[op] = 0;
        while(Q.size()) {
            int x = Q.front();
            Q.pop();
            for(int i = head[x]; i != -1; i = edge[i].pre) {
                if(dis[edge[i].to] < INF || edge[i].flow <= 0) continue;
                dis[edge[i].to] = dis[x] + 1;
                Q.push(edge[i].to);
            }
        }
        return dis[ed] != INF;
    }
    int dfs(int x, int f = INF) {
        if(x == ed || f == 0)
            return f;
        int a, flow = 0;
        for(int &i = cur[x]; i != -1; i = edge[i].pre) {
            if(edge[i].flow && dis[edge[i].to] == dis[x] + 1) {
                a = dfs(edge[i].to, min(f, edge[i].flow));
                if(a > 0) {
                    flow += a; edge[i ^ 1].flow += a;
                    f -= a; edge[i].flow -= a;
                    if(f == 0) return flow;
                }
            }
        }
        return flow;
    }
    int solve(int a, int b) {
        op = a; ed = b;
        int ans = 0, f;
        while(bfs()) {
            for(int i = 0; i < cur.size(); i++)
                cur[i] = head[i];
            ans += dfs(op);
        }
        return ans;
    }
};

int n, m, p[15];
Dinic cute(maxn + 1500);

int main() {
    while(~scanf("%d%d", &n, &m)) {
        cute.init();
        for(int i = 1; i <= n; i++) {
            cute.add(0, i, 1);
            int nd = 0;
            for(int j = 0; j < m; j++) {
                int x; scanf("%d", &x);
                nd = nd * 2 + x;
            }
            cute.add(0, maxn + nd, 1);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d", p + i);
        }
        for(int i = 0; i < (1 << m); i++) {
            for(int j = 0; j < m; j++) {
                if(i & (1 << j)) {
                    cute.add(maxn + i, maxn + (1 << m) + j, INF);
                }
            }
        }
        for(int i = 0; i < m; i++) {
            cute.add(maxn + (1 << m) + i, maxn + 1500, p[i]);
        }
        puts(cute.solve(0, maxn + 1500) == n ? "YES" : "NO");
    }
    return 0;
}
