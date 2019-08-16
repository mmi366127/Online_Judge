#include <stdio.h>
#include <string.h>


char s[1000], ans[1000];
int a, b, i;

int main() {
    while(~scanf("%s", s)) {
        a = b = i = 0;  int cnt = 1;
        for(i = 0; s[i] != '.' && s[i]; i++) {
            a = a * 10 + s[i] - '0';
        }
        for(; s[i]; i++) {
            if('0' <= s[i] && s[i] <= '9') b = b * 10 + s[i] - '0', cnt *= 10;
        }
        i = 0;
        while(a) {
            ans[i++] = (a & 1) + '0';
            a >>= 1;
        }
        i--;
        while(i >= 0) {
            putchar(ans[i]);
            i--;
        }
        if(b) {
            putchar('.');
            double tmp = (double)b / cnt;
            double __ = 0.5;
            while(tmp > 0.0) {
                if(tmp >= __) {
                    putchar('1');
                    tmp -= __;
                } else {
                    putchar('0');
                }
                __ /= 2.0;
            }
        }
        putchar('\n');
    }
    return 0;
}
