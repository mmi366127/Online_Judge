#include <stdio.h>
#include <string.h>
#define maxn 2097159
typedef long long int loli;

const int mod = (int)1e9 + 7;
int YEE[maxn];

loli power(loli a, int n) {
    loli tmp = a, ret = 1;
    while(n) {
        if(n&1) {
            ret = (ret * tmp)%mod;
        }
        tmp = (tmp * tmp)%mod;
        n >>= 1;
    }
    return ret;
}

void init() {
    YEE[0] = 1;
    for(int i = 1; i < maxn; i++) {
        YEE[i] = ((loli)YEE[i - 1] * i)% mod;
    }
}

loli solve(int n) {
    loli ret = YEE[n*2];
    loli tmp = power(YEE[n], mod - 2);
    ret = (((ret * tmp) % mod) * tmp)%mod;
    ret = (ret * power(n+1, mod - 2))%mod;
    return ret;
}


int main() {
    init();
    int n, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", solve(n));
    }
    return 0;
}
