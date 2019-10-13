#include <stdio.h>
#include <string.h>

char s[20];

int main() {

    int sz_a = 0, sz_b = 0;

    while(~scanf("%s", s)) {
        if(s[1] == 'u') {
            scanf("%s", s);
            putchar('1');
            sz_a++;
        } else {
            if(sz_b == 0) {
                while(sz_a) {
                    sz_a--;
                    sz_b++;
                    putchar('5');
                }
            }
            putchar('4');
            sz_b--;
        }
    }
    putchar('\n');
    return 0;
}
