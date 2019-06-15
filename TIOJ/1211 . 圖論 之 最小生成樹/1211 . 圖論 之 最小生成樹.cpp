#include <bits/stdc++.h>
#define X first
#define Y second
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define lowbit(X) ((X)&-(X))
#define MEM(X, val) memset((X), (val), sizeof(X));
#define pb push_back
#define ins insert
#define mp make_pair
#define YEE ios_base::sync_with_stdio(0); cin.tie()
#define maxn 10007
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;
struct Edge {
    int u, v;
    loli w;
    bool operator < (const Edge &a) const {
        return w < a.w;
    }
};

const loli INF = 0x3f3f3f3f3f3f3f3f;
vector<Edge> edge;

struct DS {
    vector<int> s, p;
    DS(int n) : s(n + 1, 1), p(n + 1, -1){}
    int find(int x) {
        return (p[x] < 0) ? x : (p[x] = find(p[x]));
    }
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(s[x] < s[y])
            swap(x, y);
        s[x] += s[y];
        p[y] = x;
        return true;
    }
    int size(int x) {
        return s[find(x)];
    }
};


int n, m, u, v, w;

int main() {
    YEE;
    while(cin >> n >> m && n) {
        edge.clear();
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edge.pb({u, v, w});
        }
        sort(all(edge));
        DS cute(n);
        loli ans = 0;
        for(int i = 0; i < m; i++) {
            if(cute.join(edge[i].u, edge[i].v)) {
                ans += edge[i].w;
            }
        }
        if(cute.size(1) != n) cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}
