#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b

int n, tmp, ans;

int main() {
    while(~scanf("%d", &n)) {
        ans = -1;
        for(int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            ans = max(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
