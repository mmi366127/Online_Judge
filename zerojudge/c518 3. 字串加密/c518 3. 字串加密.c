#include <stdio.h>
#include <string.h>
#define maxn 10000007


char s[maxn], a[maxn], b[maxn];
char next[128];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < 128; i++) next[i] = i;
    scanf("%s%s%s", s, a, b);
    for(int i = 0; i < m; i++) {
        for(char c = 'A'; c <= 'Z'; c++)
            if(next[c] == a[i]) next[c] = b[i];
        for(char c = 'a'; c <= 'z'; c++)
            if(next[c] == a[i]) next[c] = b[i];
        for(char c = '0'; c <= '9'; c++)
            if(next[c] == a[i]) next[c] = b[i];
    }
    for(int i = 0; i < n; i++) {
        putchar(next[s[i]]);
    }
    putchar('\n');
    return 0;
}
