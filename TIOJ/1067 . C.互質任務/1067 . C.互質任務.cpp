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
#define maxn 1007
#define maxm 10007
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;


const loli INF = 0x3f3f3f3f3f3f3f3f;

int dp[2][maxm], a[maxn];
int n, m, cur;


int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        memset(dp, 0, sizeof(dp));
        cur = 1;
        for(int i = 0; i < n; i++) {
            memset(dp[cur], 0, sizeof(int) * m);
            for(int j = 0; j < m; j++) {
                int num = (j * 10 + a[i]) % m;
                if(!dp[cur ^ 1][j] && j) continue;
                if(dp[cur][num] < dp[cur ^ 1][j] + 1)
                    dp[cur][num] = dp[cur ^ 1][j] + 1;
            }
            for(int j = 0; j < m; j++)
                dp[cur][j] = max(dp[1][j], dp[0][j]);
            cur ^= 1;
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            if(__gcd(i, m) == 1) {
                ans = max(dp[cur ^ 1][i], ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
