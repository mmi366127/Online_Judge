#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long loli;

const loli mod = 1000000007LL;

loli pre[maxn];
int cnt[2][45];
int n;



int main() {
    pre[0] = 1;
    for(int i = 1; i < maxn; i++) {
        pre[i] = pre[i - 1] * 2 % mod;
    }
    while(~scanf("%d", &n)) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) {
            loli x; scanf("%lld", &x);
            for(int j = 32; j >= 0; j--) {
                if(x & (1LL << j)) {
                    cnt[1][j]++;
                } else
                    cnt[0][j]++;
            }
        }
        loli ans = 0;
        for(int i = 0; i <= 32; i++) {
            if(cnt[1][i]) {
                ans = (ans + pre[n - 1] * pre[i]) % mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
