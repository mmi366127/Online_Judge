#include <stdio.h>
#include <string.h>

int a, b, t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        if(b % a) puts("-1");
        else {
            printf("%d %d\n", a, b);
        }
    }
    return 0;
}
