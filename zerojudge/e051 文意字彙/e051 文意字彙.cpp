#include <stdio.h>
#include <string.h>

char s[1005];
int len;

int main() {
    scanf("%s", s);
    len = strlen(s);
    for(int i = 1; i < len - 1; i++)
        s[i] = '_';
    puts(s);
    return 0;
}
