#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define X first
#define Y second
#define maxn 200005
using namespace std;
struct Edge {
    int u, v; long long w;
    Edge(int a, int b, long long c) :
        u(a), v(b), w(c) {}
    bool operator < (const Edge &a) const {
        return w < a.w;
    }
};

struct DSU {
    vector<int> s, p;
    DSU(int n) : s(n + 1, 1), p(n + 1, -1) {}
    int find(int x) {
        return (p[x] < 0) ? x : (p[x] = find(p[x]));
    }
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(s[x] < s[y])
            swap(x, y);
        p[y] = x;
        s[x] += s[y];
        return true;
    }
    long long size(int x) {
        return s[find(x)];
    }
};


pair<long long, int> Q[maxn];
long long n, m, q, x, y, w;
long long ans[maxn];
vector<Edge> edge;


int main() {
    scanf("%lld%lld%lld", &n, &m, &q);
    for(int i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &x, &y, &w);
        edge.emplace_back(x, y, w);
    }
    for(int i = 0; i < q;  i++) {
        scanf("%lld", &Q[i].X);
        Q[i].Y = i;
    }
    DSU cute(n); long long val = 0;
    sort(edge.begin(), edge.end());
    sort(Q, Q + q);
    for(int i = 0, j = 0; i < q; i++) {
        while(j < m && edge[j].w <= Q[i].X) {
            if(cute.find(edge[j].u) != cute.find(edge[j].v)) {
                val = val + cute.size(edge[j].u) * cute.size(edge[j].v);
                cute.join(edge[j].u, edge[j].v);
            }
            j++;
        }
        ans[Q[i].Y] = val;
    }
    for(int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
