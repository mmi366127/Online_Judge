#include <stdio.h>
#include <string.h>


int a, b, c, d, e, f;

int main() {
    while(~scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f)) {
        printf("%d\n", (a + b + c) * (a + b + c) -  a * a - c * c - e * e);
    }
    return 0;
}
