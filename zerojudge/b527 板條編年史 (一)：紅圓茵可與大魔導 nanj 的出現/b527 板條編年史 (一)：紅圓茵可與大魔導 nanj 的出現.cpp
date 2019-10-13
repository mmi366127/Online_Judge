#include <stdio.h>
#define maxn 100075

const int mod = 10007;

char dp[maxn] = {};
int arr[25];
int n;

int main() {
    scanf("%d", &n); int sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        sum += arr[i];
    }
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = sum; j >= arr[i]; j--) {
            dp[j] |= dp[j - arr[i]];
        }
    }
    int flag = 0;
    for(int i = sum - 1; i > 0; i--) {
        if(dp[i] && i % mod == (sum - i) % mod) {
            flag = 1;
            break;
        }
    }
    puts(flag ? "YES" : "NO");

    return 0;
}
