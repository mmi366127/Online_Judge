#include <stdio.h>
#include <string.h>
#define limit 4

char ans[20];
int n, t;

int cal() {
    int tmp, neg, ret = 0;
    for(int i = 1; i <= n;) {
        tmp = i; neg = ans[i] == '-' ? -1 : 1;
        i++;
        while(ans[i] == ' ')  {
            if(i < 10) tmp = tmp * 10 + i;
            else tmp = tmp * 100 + i;
            i++;
        }
        ret += neg * tmp;
    }
    return ret;
}

void dfs(int dep, int len) {
    if(len >= limit) return;
    if(dep > n) {
        if(cal() == 0) {
            printf("1");
            for(int i = 2; i <= n; i++) {
                printf("%c%d", ans[i], i);
            } puts("");
        }
        return;
    }
    ans[dep] = ' ';
    dfs(dep + 1, len + 1);
    ans[dep] = '+';
    dfs(dep + 1, 0);
    ans[dep] = '-';
    dfs(dep + 1, 0);
}

int main() {
    ans[1] = '+';
    while(~scanf("%d", &n)) {
        dfs(2, 0);
    }
    return 0;
}
