#include <stdio.h>

int n, t, ans = 0;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if(t <= 10) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
