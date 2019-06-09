#include <bits/stdc++.h>
#define lowbit(X) ((X)&(-(X)))
#define all(X) X.begin(), X.end()
#define maxn 100007
typedef long long int loli;
using namespace std;

const loli mod = (1LL << 61) - 1;

int a[maxn];
vector<int> d;

loli bit[maxn], dp[maxn];

void add(loli &a, loli b) {
    a += b;
    if(a >= mod) a -= mod;
}

void add(loli bit[], int x, loli v) {
    while(x < maxn) {
        add(bit[x], v);
        x += lowbit(x);
    }
}

loli query(loli bit[], int x) {
    loli ret = 0;
    while(x) {
        add(ret, bit[x]);
        x -= lowbit(x);
    }
    return ret;
}

int T, n, k;


int main() {
    scanf("%d", &T);
    while(T--) {
        d.clear();
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            d.push_back(a[i]);
        }
        sort(all(d));
        d.erase(unique(all(d)), d.end());
        for(int i = 1; i <= n; i++) {
            a[i] = lower_bound(all(d), a[i]) - d.begin() + 1;
        }
        loli ans = n;
        for(int i = 1; i <= n; i++) {
            dp[i] = 1;
        }
        for(int l = 2; l <= k; l++) {
            memset(bit, 0, sizeof(loli) * (d.size() + 1));
            for(int i = 1; i <= n; i++) {
                add(bit, a[i], dp[i]);
                dp[i] = query(bit, a[i] - 1);
                add(ans, dp[i]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
