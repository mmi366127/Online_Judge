#include <stdio.h>
#include <string.h>
#define maxn 333

void solve(char s[]) {
    static int num[maxn], ans[maxn], len;
    memset(num, 0, sizeof(num));
    memset(ans, 0, sizeof(ans));
    len = strlen(s);
    if(len == 1 && s[0] == '0') {
        puts("1");
        return;
    }
    for(int i = 0; i < (len >> 1); i++) {
        char _ = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = _;
    }
    for(int i = 0; i < len; i++) {
        num[i] = s[i] ^ '0';
    }
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            ans[i + j] += num[i] * num[j];
        }
    }
    for(int i = 0; i < maxn - 1; i++) {
        if(ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    for(int i = 0; i < maxn - 1; i++) {
        ans[i] -= num[i];
        if(ans[i] < 0) {
            ans[i] += 10;
            ans[i + 1]--;
        }
    }
    ans[0] += 2;
    for(int i = 0; i < maxn - 1; i++) {
        if(ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    for(int i = maxn - 1; i >= 0; i--) {
        if(ans[i]) {
            while(i >= 0) {
                printf("%01d", ans[i--]);
            }
        }
    }
    putchar('\n');
}

char s[maxn];

int main() {
    while(~scanf("%s", s)) {
        solve(s);
    }
    return 0;
}


