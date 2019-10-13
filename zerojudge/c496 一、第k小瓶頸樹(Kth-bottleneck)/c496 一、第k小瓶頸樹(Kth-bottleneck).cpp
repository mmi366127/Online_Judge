#include <bits/stdc++.h>
using namespace std;
typedef long long loli;
struct Edge {
    int u, v, w;
    Edge(int a, int b, int c) :
        u(a), v(b), w(c) {}
    bool operator < (const Edge &a) const {
        return w < a.w;
    }
};

struct DSU {
    vector<int> s, p;
    DSU(int n) : s(n + 1, 1), p(n + 1, -1) {}
    int find(int x) {
        return (p[x] == -1) ? x : (p[x] = find(p[x]));
    }
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(s[x] < s[y]) swap(x, y);
        s[x] += s[y];
        p[y] = x;
        return true;
    }
};

int n, m, k, u, v, w;
vector<Edge> edge;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        if(u != v) edge.emplace_back(u, v, w);
    }
    sort(edge.begin(), edge.end());
    int i, j, cnt = n - 1; DSU cute(n);
    for(i = 0; i < edge.size(); i++) {
        if(cute.join(edge[i].u, edge[i].v)) cnt--;
        if(cnt == 0) break;
    }
    for(; i < edge.size(); i++) {
        j = i; k--;
        if(k == 0) {
            printf("%d\n", edge[i].w);
            return 0;
        }
        while(j < edge.size() - 1 && edge[j].w == edge[j + 1].w) j++;
        i = j;
    }
    puts("-1");
    return 0;
}
