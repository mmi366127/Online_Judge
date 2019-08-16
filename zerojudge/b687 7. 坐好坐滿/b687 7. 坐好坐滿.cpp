#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 100007
#define LOG 17
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)
typedef long long loli;


loli N, M;
int ST[maxn][LOG];

int query(int l, int r) {
    static int k;
    k = (int)log2((r - l) + 1);
    return min(ST[l][k], ST[r - (1 << k) + 1][k]);
}

loli solve(loli h, loli w) {
    loli ret = 0;
    for(int i = 1; i + w - 1 <= N; i++) {
        int tmp = query(i, i + w - 1);
        if(tmp >= h) ret += tmp - h + 1;
    }
    return ret;
}

int main() {
    scanf("%lld%lld", &N, &M);
    for(int i = 1; i <= N; i++)
        scanf("%d", &ST[i][0]);
    for(int i = 1; (1 << i) <= N; i++) {
        for(int j = 1; j + (1 << i) - 1 <= N; j++)
            ST[j][i] = min(ST[j][i-1], ST[j + (1 << (i - 1))][i-1]);
    }
    loli ans = 0;
    for(loli i = 1; i * i <= M; i++) {
        if(M % i == 0) {
            loli a = i, b = M / i;
            if(b <= 100000LL) {
                ans += solve(a, b);
                if(a != b) ans += solve(b, a);

            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
