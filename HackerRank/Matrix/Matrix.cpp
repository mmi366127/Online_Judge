#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
    Edge(int a, int b, int c) :
        u(a), v(b), w(c) {}
    bool operator < (const Edge &a) const {
        return w > a.w;
    }
};

struct DSU {
    vector<int> s, p;
    vector<bool> c;
    DSU(int n) : s(n + 1, 1), p(n + 1, -1), c(n + 1, false) {}
    int find(int x) {
        return p[x] < 0 ? x : (p[x] = find(p[x]));
    }
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y || (c[x] && c[y]))
            return true;
        if(s[x] < s[y])
            swap(x, y);
        p[y] = x;
        s[x] += s[y];
        c[x] = c[x] | c[y];
        return false;
    }
    void color(int x) {
        c[x] = true;
    }
};

vector<Edge> edge;
int n, k, u, v, w;

int main() {
    scanf("%d%d", &n, &k);
    DSU cute(n);
    for(int i = 1; i < n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edge.emplace_back(u, v, w);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d", &v);
        cute.color(v);
    }
    sort(edge.begin(), edge.end());
    long long ans = 0;
    for(auto t : edge) {
        if(cute.join(t.u, t.v))
            ans = ans + t.w;
    }
    printf("%lld\n", ans);
    return 0;
}
