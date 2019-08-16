#include <bits/stdc++.h>
using namespace std;
typedef long long loli;

const loli mod = 998244353LL;

vector< vector<int> > G;
vector<loli> A, B;
int n, m, t, u, v;

int dfs(int x, int p) {
    int tmp, cnt = 1;
    for(auto y : G[x]) {
        if(y != p) {
            cnt += (tmp = dfs(y, x));
            A.push_back((loli)tmp * (n - tmp) % mod);
        }
    }
    return cnt;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        G.resize(n + 1);
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        A.clear(); B.clear();
        dfs(1, -1);
        sort(A.begin(), A.end());
        loli cost, ans = 0;
        for(int i = 0; i < m; i++) {
            scanf("%lld", &cost);
            B.push_back(cost);
        }
        sort(B.rbegin(), B.rend());
        for(int i = 0; i < m; i++) {
            if(i < A.size()) {
                ans = ans + ((A[i] * B[i]) % mod);
                if(ans >= mod) ans -= mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
