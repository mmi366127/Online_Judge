#include <bits/stdc++.h>
#define maxn 21
using namespace std;

const int INF = 0x3f3f3f3f;

int n, t, i, j, k, S, tmp;
int Matrix[maxn][maxn];
int dp[1 << maxn];


int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(dp, 0x3f, sizeof(int) * (1 << n));
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &Matrix[i][j]);
            }
        }
        int all = (1 << n) - 1;
        dp[0] = 0;
        for(S = 0; S < all; S++) {
            if(dp[S] == INF) continue;

            i = __builtin_ctz(~S);
            for(j = i + 1; j < n; j++)
                if(!(S & (1 << j)))
                for(k = j + 1; k < n; k++)
                    if(!(S & (1 << k)))
                        dp[S | (1 << i) | (1 << j) | (1 << k)] = min(dp[S | (1 << i) | (1 << j) | (1 << k)], dp[S] + Matrix[i][j] + Matrix[j][k] + Matrix[k][i]);
        }
        printf("%d\n", dp[all]);
    }
    return 0;
}
