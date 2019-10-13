#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char dp[30000];
int arr[105];
int n, t;


int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", arr + i);
        sort(arr, arr + n);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1; int ans = n;
        for(int i = 0; i < n; i++) {
            if(dp[arr[i]]) ans--;
            for(int j = arr[i]; j < 30000; j++) {
                dp[j] |= dp[j - arr[i]];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
