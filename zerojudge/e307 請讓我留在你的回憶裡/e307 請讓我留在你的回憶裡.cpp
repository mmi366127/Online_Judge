#include <stdio.h>

char s[100000005];
char t[100000005];

int main() {
    fread(s, sizeof(s), 1, stdin);
    for(int i = 0, j = 0; s[i];) {
        if(s[i] == ' ') {
            int cnt = 0;
            while(s[i] == ' ') {
                cnt++; i++;
            }
            if(cnt & 1) t[j++] = ' ';
        } else t[j++] = s[i++];
    }
    puts(t);
    return 0;
}
