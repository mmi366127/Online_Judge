#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
struct Edge {
    int u, v, w;
    bool operator < (const Edge &a) const {
        return w < a.w;
    }
    Edge(int a, int b, int c) :
        u(a), v(b), w(c) {}
};

int n, m, k, u, v, w;
int s[maxn], p[maxn];
vector<Edge> edge;

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

int MST() {
    for(int i = 1; i <= n; i++) {
        p[i] = -1; s[i] = 1;
    }
    int ret = 0, cnt = 0;
    for(Edge t : edge) {
        if(join(t.u, t.v)) {
            ret += t.w;
            cnt++;
        }
    }
    return (cnt == n - 1) ? ret : -1;
}


int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edge.emplace_back(u, v, w);
    }
    sort(edge.begin(), edge.end());
    int mi = MST();
    reverse(edge.begin(), edge.end());

    int mx = MST();
    if(mi == -1 || mx == -1) {
        puts("NIE");
        return 0;
    }
    if(mi <= k && k <= mx) {
        puts("TAK");
    } else {
        puts("NIE");
    }
    return 0;
}
