#include <stdio.h>
#include <string.h>

char s[100];
int n, m;

int to_num(char c) {
    if('A' <= c && c <= 'Z') {
        return 10 + c - 'A';
    }
    if('a' <= c && c <= 'z') {
        return 10 + c - 'a';
    }
    return c - '0';
}

char to_char(int x) {
    if(x >= 10) {
        return 'A' + x - 10;
    }
    return x + '0';
}

int main() {
    while(~scanf("%d%s", &n, s)) {
        int idx = 0, tmp = 0, temp = 0;
        for(int i = 0; s[i]; i++) {
            tmp = tmp * n + to_num(s[i]);
        }
        scanf("%d%s", &n, s);
        for(int i = 0; s[i]; i++) {
            temp = temp * n + to_num(s[i]);
        }
        scanf("%d", &m);
        tmp += temp;
        while(tmp) {
            s[idx++] = to_char(tmp % m);
            tmp /= m;
        }
        while(--idx >= 0) putchar(s[idx]);
        putchar('\n');
    }
    return 0;
}
