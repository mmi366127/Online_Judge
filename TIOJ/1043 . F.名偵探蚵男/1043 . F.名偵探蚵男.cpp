#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

long long dp[10005], A[105];
int n, p;

int main() {
    while(~scanf("%d%d", &n, &p) && n) {
        memset(dp, 0, sizeof(long long) * (p + 1));
        for(int i = 0; i < n; i++) {
            scanf("%lld", A + i);
        }
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = A[i]; j <= p; j++) {
                dp[j] += dp[j - A[i]];
            }
        }
        printf("%lld\n", dp[p]);
    }
    return 0;
}
