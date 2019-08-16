#include <stdio.h>
#include <string.h>

#define putchar putchar_unlocked
#define getchar getchar_unlocked

char c, ans[16];
int n, t;

int rd() {
    for(c = getchar(); c < '0'; c = getchar())
        if(c == EOF) return 0;
    for(n = 0; c >= '0'; c = getchar())
        n = (n << 3) + (n << 1) + (c ^ '0');
    return 1;
}


int main() {
    ans[5] = 'A'; ans[7] = 'B';
    ans[2] = 'C'; ans[13] = 'D';
    ans[8] = 'E'; ans[12] = 'F';
    while(rd()) {
        for(;n--;) {
            t = 0;
            for(int i = 0; i < 4; i++) {
                for(c = getchar(); c < '0'; c = getchar());
                t = (t << 1) + (c ^ '0');
            }
            putchar(ans[t]);
        }
        putchar('\n');
    }
    return 0;
}
