#include <stdio.h>
#include <string.h>

int n, pre, cur;

int main() {
    scanf("%d", &n); pre = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &cur); printf("%d ", cur - pre);
        pre = cur;
    }
    return 0;
}
