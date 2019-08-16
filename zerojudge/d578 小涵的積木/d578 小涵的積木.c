#include <stdio.h>
#include <string.h>


int cnt[1024][128];
char s[1024];
int n, m;

int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        memset(cnt, 0, sizeof(cnt));
        int sz = n * m; getchar();
        for(int i = 1; i < sz; i++) {
            fgets(s, sizeof(s), stdin);
            for(int j = 0; ; j++) {
                cnt[j][s[j]]++;
                if(s[j] == 0) break;
            }
        }
        for(int i = 0; i < 1024; i++) {
            for(int j = 0; j < 128; j++) {
                if(cnt[i][j] % m != 0) s[i] = j;
            }
        }
        printf("%s", s);
    }
    return 0;
}
