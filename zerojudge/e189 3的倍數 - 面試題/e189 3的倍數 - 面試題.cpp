#include <stdio.h>

char s[100], table[100] = {};
int cnt;

int main() {
    for(int i = 0;  i < 100; i += 3)
        table[i] = 1;
    while(~scanf("%s", s)) {
        cnt = 0;
        for(int i = 0; i < s[i]; i++) {
            cnt += s[i] ^ '0';
        }
        puts(table[cnt] ? "YES" : "NO");
    }
    return 0;
}
