#include <stdio.h>

char c;

int main() {
    printf("Hey ");
    while((c = getchar()) != EOF) putchar(c);
    return 0;
}
