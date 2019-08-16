#include <stdio.h>
#include <string.h>

int n, m;
char s[10000];

int code(char c) {
    if('A' <= c && c <= 'Z') {
        return c - 'A';
    } else if('a' <= c && c <= 'z') {
        return c - 'a' + 26;
    } else if('0' <= c && c <= '9') {
        return c - '0' + 52;
    } else if(c == '+') return 62;
      else if(c == '/') return 63;
}

void prt(int x) {
    static char buf[6];
    for(int i = 5; i >= 0; i--) {
        buf[i] = (char)(x & 1) + '0';
        x >>= 1;
    }
    printf("%s", buf);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        for(int j = 0; s[j]; j++) {
            prt(code(s[j]));
        }
        putchar('\n');
    }
    return 0;
}
