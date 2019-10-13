#include <bits/stdc++.h>
#define maxn 8700
using namespace std;
typedef long long loli;

const loli mod = 1e9 + 7;

bitset<maxn> prime;
loli cnt[maxn], dp[2][maxn];
int q, n;


int main() {
    prime.set();
    prime[0] = prime[1] = false;
    for(int i = 2; i < maxn; i++) {
        if(prime[i]) {
            for(int j = i + i; j < maxn; j += i) {
                prime[j] = false;
            }
        }
    }
    scanf("%d", &q);
    while(q--) {
        memset(cnt, 0, sizeof(cnt));
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            cnt[x] ++;
        }
        dp[0][0] = 1;
        int cur = 1;
        for(int i = 0; i < maxn; i++) {
            if(cnt[i]) {
                for(int j = 0; j < maxn; j++) {
                    dp[cur][j] = dp[cur ^ 1][j] * (cnt[i] / 2 + 1);
                    if((i ^ j) < maxn) {
                        dp[cur][j] += dp[cur ^ 1][j ^ i] * ((cnt[i] + 1) / 2);
                    }
                    dp[cur][j] %= mod;
                }
                cur ^= 1;
            }
        }
        loli ans = 0;
        for(int i = 0; i < maxn; i++) {
            if(prime[i]) {
                ans = (ans + dp[cur ^ 1][i]) % mod;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
