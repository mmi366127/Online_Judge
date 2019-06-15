#include <stdio.h>
#include <string.h>


int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for(int i = a; i != b; i += c) {
        printf("%d ", i);
    }
    printf("%d\n", b);
    return 0;
}
