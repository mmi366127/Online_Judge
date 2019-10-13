#include <stdio.h>
#include <string.h>
#define maxn 1007
typedef long long loli;

const loli mod = 100000007LL;

int val[maxn][maxn];


loli power(loli a, loli n) {
    loli ret = 1;
    while(n) {
        if(n & 1) {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

int n, m, q, x, y;
loli sum;


int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        sum = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%d", &val[j][i]);
                sum = sum * val[j][i] %  mod;
            }
        }
        scanf("%d", &q);
        for(int i = 0; i < q; i++) {
            scanf("%d%d", &y, &x);
            printf("%lld\n", sum * power(val[x][y], mod - 2) % mod);
        }
    }
    return 0;
}
