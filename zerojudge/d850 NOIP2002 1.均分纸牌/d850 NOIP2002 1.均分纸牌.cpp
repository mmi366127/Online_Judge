#include <stdio.h>
#include <string.h>
#define maxn 10007

int n, sum = 0;
int a[maxn];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }
    int ans = 0;
    sum /= n;
    for(int i = 1; i <= n; i++) {
        if(a[i] < sum) {
            a[i+1] -= sum - a[i];
            ans++;
        } else if(a[i] > sum) {
            a[i+1] += a[i] - sum;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
