#include <stdio.h>
#include <string.h>
#define maxn 1005

int n, T, w, v;
int dp[maxn];

int main() {
    while(~scanf("%d%d", &T, &n)) {
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &w, &v);
            for(int j = T; j >= w; j--) {
                dp[j] = dp[j] > (dp[j - w] + v) ? dp[j] : (dp[j - w] + v);
            }
        }
        printf("%d\n", dp[T]);
    }
    return 0;
}
