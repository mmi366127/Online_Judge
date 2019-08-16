#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <string.h>

int n, A, B, x, y, k;
char a[20], b[20];

int main() {
    while(~scanf("%d", &n)) {
        scanf("%s %s", a, b);
        A = B = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &k, &x, &y);
            if(x > y) A += k;
            else B += k;
        }
        if(A != B) puts(A > B ? a : b);
        else puts("Tie");
    }
    return 0;
}
