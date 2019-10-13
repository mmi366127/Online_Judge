#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[100005];

int main() {
    while(fgets(s, sizeof(s), stdin)) {
        int flag, tmp, ans = 0;
        for(int i = 0; s[i]; i++) {
            if(isdigit(s[i])) {
                tmp = 0;
                if(i == 0 || s[i - 1] == ' ') flag = 1;
                else flag = 0;
                while(isdigit(s[i])) {
                    tmp = tmp * 10 + (s[i++] ^ '0');
                }
                if(s[i] != ' ' && s[i] != '\n') flag = 0;
                if(flag) ans += tmp;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
