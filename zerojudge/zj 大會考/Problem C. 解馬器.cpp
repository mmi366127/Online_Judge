#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxn 10007

char s[maxn];
int i, j;


int main() {
    fgets(s, sizeof(s), stdin);
    for(int i = 0, j = 0; isprint(s[i]); i++) {
        if(s[i] == '=') {
            int ans = 0;
            while(isprint(s[i])) {
                i++;
                if('0' <= s[i] && s[i] <= '9') {
                    ans = ans * 10 + (s[i] - '0');
                }
            }
            printf("%d\n", ans);
            return 0;
        }
    }
    return 0;
}
