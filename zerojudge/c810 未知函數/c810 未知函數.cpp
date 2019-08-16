#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <stdio.h>
#include <string.h>
#define maxn 100007
typedef long long loli;

const loli mod = 998244353;
const loli m = 998244351;

loli my_pow(loli a) {
    static loli ret, n;
    ret = 1;
    n = m;
    while(n) {
        if(n & 1) {
            ret = (ret * a) % mod;
        }
        n >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}

loli A[maxn], pre[maxn], low[maxn], a[maxn], b[maxn];
loli k, tmp, ans;
int n, q;

int main() {
    scanf("%d%d", &n, &q);
    for(int i = 0; i <= n; i++) {
        scanf("%lld", A + i);
        if(i > 0) pre[i] = (pre[i - 1] * i) % mod;
        else pre[i] = 1;
    }
    for(int i = 0; i <= n; i++) {
        if(!((n - i) & 1)) low[i] = (pre[n - i] * pre[i]) % mod;
        else low[i] = ((mod - pre[n - i]) * pre[i]) % mod;
        low[i] = my_pow(low[i]);
    }
    for(int i = 0; i < q; i++) {
        scanf("%lld", &k);
        if(k <= n) printf("%lld\n", A[k]);
        else {
            k = k % mod + mod;
            tmp = 1; ans = 0;
            for(int i = 0; i <= n; i++) {
                tmp = (tmp * (k - i)) % mod;
                a[i] = tmp;
            }
            tmp = 1;
            for(int i = n; i >= 0; i--) {
                tmp = (tmp * (k - i)) % mod;
                b[i] = tmp;
            }
            for(int i = 0; i <= n; i++) {
                if(i == 0) tmp = b[i + 1];
                else if(i == n) tmp = a[i - 1];
                else tmp = a[i - 1] * b[i + 1] % mod;
                ans += ((A[i] * tmp % mod) * low[i]) % mod;
                if(ans >= mod) ans -= mod;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
