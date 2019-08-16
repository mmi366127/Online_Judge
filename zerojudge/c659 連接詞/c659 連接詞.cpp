#include <stdio.h>
#include <string.h>

char s[100], a[100];

int main() {
    scanf("%s", a); int flag = 1;
    while(~scanf("%s", s)) {
        if(flag)printf("%s ", s), flag = 0;
        else printf("%s %s ", a, s);
    }
}
