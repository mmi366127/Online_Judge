#include <stdio.h>
/*
#define getchar getchar_unlocked
#define putchar putchar_unlocked
*/

char c;
int t;

int main() {
    scanf("%d", &t);
    while(t--) {
        int cnt = 0, flag = 1;
        for(c = getchar(); c < 'A'; c = getchar());
        for(; c >= 'A'; c = getchar()) {
            if(c == 'Y') cnt++;
            else {
                if(cnt == 0) flag = 0;
                cnt--;
            }
        }
        if(cnt) flag = 0;
        if(flag) {
            putchar('Y');
            putchar('E');
            putchar('S');
            putchar('\n');
        } else {
            putchar('N');
            putchar('O');
            putchar('\n');
        }
    }
    return 0;
}
