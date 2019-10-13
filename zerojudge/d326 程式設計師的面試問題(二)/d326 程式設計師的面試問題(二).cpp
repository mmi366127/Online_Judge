#include <stdio.h>

int v, a, b;
char s[40];

int main() {
    while(~scanf("%d%d%d", &v, &a, &b)) {
        for(int i = 0; i < 32; i++) {
            s[31 - i] = (v & 1) ^ '0';
            v >>= 1;
        }
        s[31 - a] = b ^ '0';
        puts(s);
    }
    return 0;
}
