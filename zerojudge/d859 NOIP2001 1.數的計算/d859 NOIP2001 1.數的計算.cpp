#include <stdio.h>
#include <string.h>
#define maxn 1005

int dp[maxn];
int n;

int main() {
    dp[0] = 1;
    for(int i = 1; i < maxn; i++) {
        dp[i] = 0;
        for(int j = 0; j * 2 <= i; j++) {
            dp[i] += dp[j];
        }
    }
    while(~scanf("%d", &n))
        printf("%d\n", dp[n]);
    return 0;
}
