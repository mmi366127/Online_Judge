#include <stdio.h>
#include <string.h>

long long n;

int main() {
    scanf("%lld", &n);
    printf("%lld\n", (n < 0) ? (-n) * 2 : n * 2 - 1);
    return 0;
}
