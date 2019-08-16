#include <stdio.h>

int base[2][81];
int n;

#define getchar_unlocked getchar
#define putchar_unlocked putchar

int rd() {
    static char c;
    int ret;
    while((c = getchar_unlocked()) < '0')
        if(c == EOF) return 0;
    ret = c ^ '0';
    while((c = getchar_unlocked()) >= '0')
        ret = (ret << 3) + (ret << 1) + (c ^ '0');
    return ret;
}

void init() {
    int idx = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(i != 0 && i != j) {
                base[0][idx] = i;
                base[1][idx] = j;
                idx++;
            }
        }
    }
}


int main() {
    init();
    while(n = rd()) {
        n--;
        int len = n / 81 + 3;
        int pos = n % 81;
        for(int i = 0; i < len; i++) {
            putchar_unlocked(base[i&1][pos] + '0');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
