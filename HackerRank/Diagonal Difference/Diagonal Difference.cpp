#include <stdio.h>
#define abs(X) (X) < 0 ? -(X) : (X)

int a, b, n, x;

int main() {
    a = b = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &x);
            if(i == j) a += x;
            if(i + j == n - 1) b += x;
        }
    }
    printf("%d\n", abs(a - b));
    return 0;
}
