#include <stdio.h>
#include <string.h>
#define maxn 15

int dp[maxn][maxn], ans[maxn][maxn], m[maxn][maxn];
int n, i, j, s;
char S[maxn];


void mul(int a[maxn][maxn], int b[maxn][maxn], int c[maxn][maxn]) {
    static int ret[maxn][maxn];
    memset(ret, 0, sizeof(ret));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                ret[i][j] += b[i][k] * a[k][j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            c[i][j] = ret[i][j];
        }
    }
}


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", S);
        for(int j = 0; j < n; j++)
            m[i][j] = dp[i][j] = S[j] ^ '0';
    }
    scanf("%d%d%d", &i, &j, &s);
    i--, j--, s++;
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++)
        ans[i][i] = 1;
    for(int t = 0; t < s; t++) {
        mul(ans, dp, ans);
    }
    printf("%d\n", ans[i][j]);
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                m[i][j] |= m[i][k] & m[k][j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(m[i][j] == 0) {
                printf("%d\n%d\n", i + 1, j + 1);
                return 0;
            }
        }
    }
    printf("0\n0\n");
    return 0;
}
