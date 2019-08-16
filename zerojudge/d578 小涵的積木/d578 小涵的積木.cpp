#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxT 1000
typedef long long loli;

const loli P = 1e9 + 7;

int ans[maxT], idx = 0;
unsigned char T[4];
int cnt[4][256];
char s[2000];
int n, m;

int hash(char s[]) {
    loli ret = 0;
    for(int i = 0; s[i]; i++) {
        ret = ret * 143 + s[i];
        ret %= P;
    }
    return (int)ret;
}


int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        memset(cnt, 0, sizeof(cnt));
        int sz = n * m; getchar();
        for(int i = 1; i < sz; i++) {
            fgets(s, sizeof(s), stdin);
            *((int*)(T)) = hash(s);
            for(int i = 0; i < 4; i++) {
                cnt[i][T[i]]++;
            }
        }
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 256; j++) {
                if(cnt[i][j] % m != 0) {
                    T[i] = j;
                    break;
                }
            }
        }
        ans[idx++] = *(int*)T;
    }
    rewind(stdin);
    for(int i = 0; i < idx; i++) {
        scanf("%d%d", &n, &m); getchar();
        int sz = n * m, flag = 0;
        for(int j = 1; j < sz; j++) {
            fgets(s, sizeof(s), stdin);
            if(!flag && hash(s) == ans[i]) {
                puts(s);
                flag = 1;
            }
        }
    }
    return 0;
}
