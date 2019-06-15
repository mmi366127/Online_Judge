#include <stdio.h>

int n, kase = 0;

int main() {
    scanf("%d", &n);
    while(n--) {
        printf("%d. I don't say swear words!\n", ++kase);
    }
}
