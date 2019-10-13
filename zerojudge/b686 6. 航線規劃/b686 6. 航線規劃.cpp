#include <bits/stdc++.h>
#define maxn 505
using namespace std;
struct PrPr {
    int u, v, w, id;
    PrPr(int a, int b, int c, int d) :
        u(a), v(b), w(c), id(d) {}
    bool operator < (const PrPr &a) const {
        return w > a.w;
    }
};

const int INF = 0x3f3f3f3f;

int R[maxn], G[maxn][maxn], ans[200005];
vector< pair<int, int> > V;
int n, m, q, u, v, w;
vector<PrPr> Q;


int main() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", R + i);
        V.emplace_back(R[i], i);
    }
    memset(G, 0x3f, sizeof(G));
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = G[v][u] = min(w, G[u][v]);
    }
    for(int i = 0; i < q; i++) {
        scanf("%d%d%d", &w, &u, &v);
        Q.emplace_back(u, v, w, i);
    }
    sort(Q.begin(), Q.end());
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    for(int i = 0, j = 0; i < Q.size(); i++) {
        while(j < V.size() && Q[i].w <= V[j].first) {
            for(int _ = 1; _ <= n; _++) {
                for(int __ = 1; __ <= n; __++) {
                    G[_][__] = min(G[_][__], G[_][V[j].second] + G[V[j].second][__]);
                }
            }
            j++;
        }
        if(R[Q[i].u] >= Q[i].w && R[Q[i].v] >= Q[i].w) ans[Q[i].id] = G[Q[i].u][Q[i].v];
        else ans[Q[i].id] = INF;
    }
    for(int i = 0; i < q; i++) {
        if(ans[i] != INF) printf("%d\n", ans[i]);
        else puts("-1");
    }
    return 0;
}
/*
6 5 5
5 4 1 3 2 6
1 3 3
1 4 1
2 4 6
2 5 1
3 5 2
1 1 2
2 1 2
3 1 2
4 1 2
1 5 3
*/
