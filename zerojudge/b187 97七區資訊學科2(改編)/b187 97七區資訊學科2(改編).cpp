#include <stdio.h>

int x;

int main() {
    puts("十六進位表示法  相對應的十進位表示法");
    while(~scanf("%X", &x)) {
        printf("      %X                %d\n", x, x);
    }
    return 0;
}
