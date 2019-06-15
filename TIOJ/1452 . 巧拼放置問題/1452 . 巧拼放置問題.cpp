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
#define maxn 14
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;


const loli INF = 0x3f3f3f3f3f3f3f3f;

loli dp[2][1 << maxn];
int n, m, cur;

loli dfs(int dep, int S, int now) {
    if(dep == m) {
        return dp[cur ^ 1][now];
    }
    loli ret = 0;
    if(S & (1 << dep)) {
        ret += dfs(dep + 1, S, now ^ (1 << dep));
        if(S & (1 << (dep + 1))) {
            ret += dfs(dep + 2, S, now);
        }
    } else {
        ret += dfs(dep + 1, S, now);
    }
    return ret;
}


int main() {
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 && m == 0) return 0;
        memset(dp, 0, sizeof(dp));
        cur = 1; dp[0][(1 << m) - 1] = 1;
        for(int i = 0; i < n; i++) {
            for(int S = 0; S < (1 << m); S++) {
                dp[cur][S] = dfs(0, S, (1 << m) - 1);
            }
            cur ^= 1;
        }
        printf("%lld\n", dp[cur ^ 1][(1 << m) - 1]);
    }
    return 0;
}
