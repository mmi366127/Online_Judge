#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000;

int dp[300][300] = {};
int n, m;

int main() {
    for(int i = 1; i < 300; i++) {
        dp[i][i] = 1;
        for(int j = i + 1; j < 300; j++) {
            dp[i][j] = dp[i][j - 1] * i + dp[i - 1][j - 1];
            dp[i][j] %= mod;
        }
    }
    while(~scanf("%d%d", &n, &m) && n && m) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += dp[i][m];
        }
        printf("%d\n", ans % mod);
    }
    return 0;
}
