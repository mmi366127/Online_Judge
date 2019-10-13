#include <stdio.h>
#define maxn 200005

long long arr[maxn];
int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", arr + i);
    }
    if(n <= 2 * k + 1) {
        printf("%lld\n", arr[k + 1]);
        return 0;
    }
    long long ans = 0;
    int val = n % (2 * k + 1);
    if(val > k + 1 || val == 0) {
        for(int i = k + 1; i <= n; i +=  (2 * k + 1))
            ans += arr[i];
    } else {
        ans = arr[1];
        for(int i = 2 * k + 2; i <= n; i += (2 * k + 1))
            ans += arr[i];
    }
    printf("%lld\n", ans);
    return 0;
}
