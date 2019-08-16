#pragma GCC optimize("O3")
#include <stdio.h>
#include <string.h>
#define maxn 105

long long A[maxn][maxn], B[maxn][maxn], C[maxn][maxn];
int a, b, c, d;

int main() {
    while(~scanf("%d%d%d%d", &a, &b, &c, &d)) {
        if(b !=  c) {
            puts("Error");
            continue;
        }
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                scanf("%lld", &A[j][i]);
            }
        }
        for(int i = 0; i < c; i++) {
            for(int j = 0; j < d; j++) {
                scanf("%lld", &B[j][i]);
            }
        }
        memset(C, 0, sizeof(C));
        for(int i = 0; i < d; i++) {
            for(int j = 0; j < a; j++) {
                for(int k = 0; k < b; k++) {
                    C[i][j] += B[i][k] * A[k][j];
                }
            }
        }
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < d; j++) {
                printf("%lld ", C[j][i]);
            }
            puts("");
        }
    }
    return 0;
}

