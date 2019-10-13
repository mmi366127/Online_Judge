#include <stdio.h>
#include <string.h>

int n, x;

int main() {
    while(~scanf("%d", &n)) {
        if(n == 1) {
            scanf("%d", &n);
            printf("%d\n", n);
            continue;
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
        }
        puts("0");
    }
    return 0;
}
