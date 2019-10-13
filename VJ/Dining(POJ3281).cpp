#include <queue>
#include <stdio.h>
#include <vector>
#define maxn 105
#define all(X) (X).begin(), (X).end()
using namespace std;

const int INF = 0x3f3f3f3f;

struct Dinic {
    struct Edge {
        int pre, to, flow;
    };
    int op, ed;
    vector<int> head, dis, cur;
    vector<Edge> edge;
    Dinic(int n) : head(n + 1, -1), dis(n + 1), cur(n + 1) {}
    void add(int u, int v, int f) {
        edge.push_back({head[u], v, f});
        head[u] = edge.size() - 1;
        edge.push_back({head[v], u, 0});
        head[v] = edge.size() - 1;
    }
    bool bfs(int op, int ed) {
        fill(all(dis), INF);
        queue<int> Q;
        Q.push(op); dis[op] = 0;
        while(Q.size()) {
            int x = Q.front();
            Q.pop();
            for(int i = head[x]; i != -1; i = edge[i].pre) {
                if(edge[i].flow == 0 || dis[edge[i].to] < INF) continue;
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
            if(edge[i].flow > 0 && dis[edge[i].to] == dis[x] + 1) {
                a = dfs(edge[i].to, min(f, edge[i].flow));
                if(a > 0) {
                    flow += a; edge[i ^ 1].flow += a;
                    f -= a; edge[i].flow -= a;
                }
                if(f == 0) return flow;
            }
        }
        return flow;
    }
    int solve(int s, int t) {
        op = s; ed = t;
        int ans = 0;
        while(bfs(s, t)) {
            for(int i = 0; i < cur.size(); i++)
                cur[i] = head[i];
            ans += dfs(s);
        }
        return ans;
    }
};

int n, f, d;


int main() {
    scanf("%d%d%d", &n, &f, &d);
    Dinic cute(2 * n + f + d + 1);
    for(int i = 1; i <= n; i++) {
        int ff, dd, x;
        scanf("%d%d", &ff, &dd);
        for(int j = 0; j < ff; j++) {
            scanf("%d", &x);
            cute.add(x, f + i, 1);
        }
        for(int j = 0; j < dd; j++) {
            scanf("%d", &x);
            cute.add(f + n + i, 2 * n + f + x, 1);
        }
    }
    for(int i = 1; i <= n; i++) {
        cute.add(f + i, f + i + n, 1);
    }
    for(int i = 1; i <= f; i++) {
        cute.add(0, i, 1);
    }
    for(int i = 1; i <= d; i++) {
        cute.add(i + f +  2 * n, 2 * n + f + d + 1, 1);
    }
    printf("%d\n", cute.solve(0, 2 * n + f + d + 1));
    return 0;
}
