#include <stdio.h>
#include <string.h>
#define maxn 30
#define min(a, b) (a) < (b) ? (a) : (b)
#define abs(X) (X) < 0 ? -(X) : (X)

int a[maxn];
int n;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        int ans = (int)1e9;
        for(int i = 0; i < (1 << n); i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    tmp += a[j];
                } else {
                    tmp -=a[j];
                }
            }
            ans = min(ans, abs(tmp));
        }
        printf("%d\n", ans);
    }
    return 0;
}
