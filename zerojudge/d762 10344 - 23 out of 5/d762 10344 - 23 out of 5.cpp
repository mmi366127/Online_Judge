#include <stdio.h>

int a[5], b[5], flag;

void dfs(int dep, int val) {
    if(flag) return;
    if(dep >= 5) {
        if(val == 23) flag = 1;
        return;
    }
    dfs(dep + 1, val + b[dep]);
    dfs(dep + 1, val - b[dep]);
    dfs(dep + 1, val * b[dep]);
}

void dfs_p(int dep) {
    if(flag) return;
    if(dep >= 5) {
        dfs(1, b[0]);
        return;
    }
    for(int i = 0; i < 5; i++) {
        if(a[i] != -1) {
            b[dep] = a[i];
            a[i] = -1;
            dfs_p(dep + 1);
            a[i] = b[dep];
        }
    }
}




int main() {
    while(~scanf("%d%d%d%d%d", a, a+1, a+2, a+3, a+4)) {
        if(a[0] + a[1] + a[2] + a[3] + a[4] == 0) return 0;
        flag = 0;
        dfs_p(0);
        if(flag) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}
