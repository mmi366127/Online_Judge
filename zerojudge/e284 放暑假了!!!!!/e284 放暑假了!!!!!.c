#include <stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked

long long n;

int rd() {
    static char c, neg;
    for(c = getchar(); c < '-'; c = getchar())
        if(c == EOF) return 0;
    neg = (c == '-') ? -1 : 1;
    n = (c == '-') ? 0 : (c ^ '0');
    for(c = getchar(); c >= '0'; c = getchar())
        n = (n << 3) + (n << 1) + (c ^ '0');
    n *= neg;
    return 1;
}

void Yes() {
    putchar('Y');
    putchar('e');
    putchar('s');
    putchar('\n');
}

void No() {
    putchar('N');
    putchar('o');
    putchar('\n');
}

int main() {
    while(rd()) {
        if(n > 0 && (n & (n - 1)) == 0) Yes();
        else No();
    }
}
