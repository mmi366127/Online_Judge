#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define X first
#define Y second
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define lowbit(X) ((X)&-(X))
#define MEM(X, val) memset((X), (val), sizeof(X));
#define eb emplace_back
#define pb push_back
#define ins insert
#define mp make_pair
#define YEE ios_base::sync_with_stdio(0); cin.tie()
#define maxn 18
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;

const loli INF = 0x3f3f3f3f3f3f3f3f;

loli A[maxn];
loli dp[maxn][1 << maxn] = {};
int n;


loli dfs(int x, int S) {
    if(dp[x][S]) return dp[x][S];
    dp[x][S] = INF;
    for(int i = 0; i < n; i++) {
        if(S & (1 << i)) {
            loli tmp = dfs(i, S ^ (1 << i));
            tmp += abs(i - x);
            if(tmp % A[x]) {
                tmp = (tmp / A[x] + 1) * A[x];
            }
            dp[x][S] = min(dp[x][S], tmp);
        }
    }
    return dp[x][S];
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", A + i);
    for(int i = 0; i < n; i++) {
        dp[i][0] = i + 1;
        if(dp[i][0] % A[i]) {
            dp[i][0] = dp[i][0] / A[i] + 1;
            dp[i][0] *= A[i];
        }
    }
    loli ans = INF; int mask = (1 << n) - 1;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dfs(i, mask ^ (1 << i)));
    }
    printf("%lld\n", ans);
    return 0;
}
