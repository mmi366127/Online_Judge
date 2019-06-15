#include <stdio.h>
#include <string.h>
#define maxn 5007
typedef long long int loli;

const loli mod = 10000000LL;

loli dp[maxn], cute[maxn];

void init() {
    memset(dp, 0, sizeof(dp));
    memset(cute, 0, sizeof(cute));
    dp[0] = dp[1] = 1;
    cute[0] = 1;
    cute[1] = 2;
    for(int i = 2; i < maxn; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * cute[i - j - 1];
            dp[i] %= mod;
        }
        for(int j = 0; j <= i; j++) {
            cute[i] += dp[j] * dp[i - j];
            cute[i] %= mod;
        }
    }
}

int main() {
    init(); int n;
    while(~scanf("%d", &n)) {
        printf("%d\n", dp[n]);
    }
    return 0;
}
