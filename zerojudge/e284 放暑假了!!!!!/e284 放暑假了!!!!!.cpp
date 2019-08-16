//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <stdio.h>

#define getchar getchar_unlocked
#define putchar putchar_unlocked

int n;
char c;


int main() {
    for(;1;) {
        for(c = getchar();c < '0'; c = getchar())
            if(c == EOF) return 0;
        n = c ^ '0';
        for(c = getchar(); c >= '0'; c = getchar())
            n = (n << 1) + (n << 3) + (c ^ '0');
        if(!n || (n - 1) & n) {
            putchar('N');
            putchar('o');
        } else {
            putchar('Y');
            putchar('e');
            putchar('s');
        }
        putchar('\n');
    }
    return 0;
}
