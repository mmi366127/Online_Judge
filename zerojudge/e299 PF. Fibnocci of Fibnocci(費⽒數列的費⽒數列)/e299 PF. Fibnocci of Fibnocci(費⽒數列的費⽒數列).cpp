#include <stdio.h>
#include <string.h>
typedef long long loli;

const loli M = 2000000016LL;
const loli mod = 1000000007LL;

loli M1[63][2][2];
loli M2[63][2][2];
loli tmp[2][2];

void mul(loli a[2][2], loli b[2][2], loli c[2][2], loli mod) {
    loli ret[2][2] = {};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                ret[i][j] = ret[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            c[i][j] = ret[i][j] % mod;
        }
    }
}

loli x;
int n;

int main() {
    M1[0][0][0] = 1; M1[0][1][0] = 1;
    M1[0][0][1] = 1; M1[0][1][1] = 0;
    M2[0][0][0] = 1; M2[0][1][0] = 1;
    M2[0][0][1] = 1; M2[0][1][1] = 0;
    for(int i = 1; i < 63; i++) {
        mul(M1[i - 1], M1[i - 1], M1[i], M);
        mul(M2[i - 1], M2[i - 1], M2[i], mod);
    }
    scanf("%d", &n);
    while(n--) {
        scanf("%lld", &x); x--;
        if(x < 0) {
            puts("0");
            continue;
        }
        memset(tmp, 0, sizeof(tmp));
        tmp[0][0] = tmp[1][1] = 1;
        for(int i = 0; x && i < 63; i++) {
            if(x & 1) {
                mul(tmp, M1[i], tmp, M);
            }
            x >>= 1;
        }
        x = tmp[0][0] - 1;
        memset(tmp, 0, sizeof(tmp));
        tmp[0][0] = tmp[1][1] = 1;
        for(int i = 0; x && i < 63; i++) {
            if(x & 1) {
                mul(tmp, M2[i], tmp, mod);
            }
            x >>= 1;
        }
        printf("%lld\n", tmp[0][0]);
    }
}
