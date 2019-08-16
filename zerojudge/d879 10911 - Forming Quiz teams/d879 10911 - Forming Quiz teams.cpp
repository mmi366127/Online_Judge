#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(a, b) (a) < (b) ? (a) : (b)
#define maxn 16


double matrix[maxn][maxn];
double dp[1 << maxn];
int x[maxn], y[maxn];
int n, kase = 0;
char s[20];


int main() {
    while(~scanf("%d", &n) && n) {
        n *= 2;
        for(int i = 0; i < n; i++) {
            scanf("%s %d %d", s, x + i, y + i);
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++)
                matrix[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
        for(int S = 0; S < (1 << n); S++) dp[S] = 1e9;
        dp[0] = 0.00;
        for(int S = 0; S < (1 << n); S++) {
            if(dp[S] == 1e9) continue;

            int i = __builtin_ctz(~S);

            for(int j = i + 1; j < n; j++) {
                if(!(S & (1 << j))) {
                    dp[S | (1 << i) | (1 << j)] = min(dp[S | (1 << i) | (1 << j)], dp[S] + matrix[i][j]);
                }
            }
        }
        printf("Case %d: %.2f\n", ++kase, dp[(1 << n) - 1]);
    }
    return 0;
}
