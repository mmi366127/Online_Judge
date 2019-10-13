#pragma GCC optimize("O3")
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define maxn 205
using namespace std;

const int INF = (1 << 20);

int dp[maxn][maxn];
int paper[maxn];
int n, m, t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d", paper + i);
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) dp[i][i] = 1;
        for(int len = 2; len <= n; len++) {
            for(int i = 1; i + len - 1 <= n; i++) {
                dp[i][i + len - 1] = INF;
                for(int j = i; j < i + len - 1; j++) {
                    if(paper[i] == paper[j + 1]) {
                        dp[i][i + len - 1] = min(dp[i][i + len - 1], dp[i][j] + dp[j + 1][i + len - 1] - 1);
                    } else {
                        dp[i][i + len - 1] = min(dp[i][i + len - 1], dp[i][j] + dp[j + 1][i + len - 1]);
                    }
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
