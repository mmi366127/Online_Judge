#include <stdio.h>
#include <string.h>

int YEE(int x) {
    if(x == 0) return 0;
    return (x - 1) % 9 + 1;
}

int n;

int main() {
    while(~scanf("%d", &n)) {
        printf("%d\n", YEE(n));
    }
    return 0;
}
