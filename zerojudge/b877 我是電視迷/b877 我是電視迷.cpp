#include <stdio.h>

int a, b, ans = 0;

int main() {
    scanf("%d%d", &a, &b);
    while(a != b) a = (a + 1) % 100, ans++;
    printf("%d\n", ans);
    return 0;
}
