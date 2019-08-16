#include <stdio.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define maxn 100000

double dp[maxn];
int cost[maxn];
double v[maxn];
int n, T, S, V, type, idx = 0;

int main() {
    scanf("%d%d", &n, &T);
    for(int i = 0; i <= T; i++) dp[i] = 0.00;
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &S, &V, &type);
        if(type == 1) {
            double all = (double)S;
            for(int k = 1; k < S; k <<= 1) {
                cost[idx] = k;
                v[idx] = (double)k / all * (double)V;
                S -= k; idx++;
            }
            if(S) {
                cost[idx] = S;
                v[idx] = (double)S / all * (double)V;
                idx++;
            }
        } else {
            cost[idx] = S;
            v[idx] = V;
            idx++;
        }
    }
    for(int i = 0; i < idx; i++) {
        for(int j = T; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + v[i]);
        }
    }
    printf("%.0f\n", dp[T]);
    return 0;
}
