#include <bits/stdc++.h>
#define all(X) X.begin(), X.end()
#define maxn 1007
#define INF 1e9
typedef long long loli;
using namespace std;

loli a[maxn], b[maxn];
loli n, m, k, ans;


bool cal(loli x) {
    loli cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] * x < b[i]) return false;
        cnt += a[i] * x - b[i];
    }
    return  cnt >= k * m;
}

int main() {
    while(~scanf("%lld", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%lld", a + i);
        }
        scanf("%lld", &k);
        for(int i = 0; i < n; i++) {
            scanf("%lld", b + i);
        }
        scanf("%lld", &m);
        loli L = 0, R = INF, mid;
        while(R - L > 1) {
            mid = (L + R) >> 1;
            if(cal(mid))
                R = mid;
            else L = mid;
        }
        printf("%lld\n", R);
    }
    return 0;
}
