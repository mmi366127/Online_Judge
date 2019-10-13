#include <stdio.h>
#include <string.h>

char s[10000], a[10000];

int main() {
    fgets(a, sizeof(a), stdin);
    fgets(s, sizeof(s), stdin);
    for(int i = 0; s[i]; i++)
        if(s[i] == '\n') s[i] = '\0';
    for(int i = 0; a[i]; i++)
        if(a[i] == '\n') a[i] = '\0';
    char *st = s;
    int len = strlen(a);
    while(1) {
        char *p = strstr(st, a);
        if(!p) {
            puts(st);
            break;
        }
        for(; st != p; st++) {
            putchar(*st);
        }
        putchar('\n');
        st += len;
    }
    return 0;
}
