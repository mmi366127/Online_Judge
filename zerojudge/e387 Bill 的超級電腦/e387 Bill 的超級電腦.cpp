#include <stdio.h>
#include <math.h>
#define min(a, b) (a) < (b) ? (a) : (b)
#define maxn 20

const double INF = 1e9;

double dp[maxn][1 << maxn];
double x[maxn], y[maxn];
double dis[maxn][maxn];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", x + i, y + i);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dis[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++)
            dp[j][i] = INF;
    }
    for(int i = 0; i < n; i++)
        dp[i][1 << i] = 0.00;
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(dp[j][i] == INF) continue;
            for(int k = 0; k < n; k++) {
                if((1 << k) & i) continue;
                dp[k][i ^ (1 << k)] = min(dp[k][i ^ (1 << k)], dp[j][i] + dis[j][k]);
            }
        }
    }
    double ans = INF;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dp[i][(1 << n) - 1]);
    }
    printf("%.2f\n", ans);
    return 0;
}
