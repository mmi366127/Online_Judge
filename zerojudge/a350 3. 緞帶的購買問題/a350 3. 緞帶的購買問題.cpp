#include <stdio.h>
#include <string.h>

int cost[10] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
int C[10], type[100], dp[100];
int n, flag, ans;

int main() {
    scanf("%d", &n); n /= 8;
    for(int i = 0; i < 9; i++) {
        scanf("%d", C + i);
    }
    flag = 1; ans = 0;
    for(int i = 0; i < 9; i++) {
        if(C[i] && cost[i] > n) {
            puts("NO SOLUTION!!");
            return 0;
        }
    }
    while(flag) {
        memset(dp, 0, sizeof(dp));
        memset(type, 0, sizeof(type));

        dp[0] = 1;
        for(int i = 8; i >= 0; i--) {
            for(int j = 1; j <= C[i]; j++) {
                for(int k = n; k >= cost[i]; k--) {
                    if(dp[k - cost[i]] && !dp[k]) {
                        dp[k] = 1;
                        type[k] = i;
                    }
                }
            }
        }

        for(int i = n; i >= 0; i--) {
            if(dp[i]) {
                while(i != 0) {
                    C[type[i]] --;
                    i -= cost[type[i]];
                }
            }
        }
        ans++;
        flag = 0;
        for(int i = 0; i < 9; i++) {
            if(C[i] > 0) {
                flag = 1;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
