#include <stdio.h>
#include <string.h>

char A[20][20], out[20], used[20], pre[20];
int n, tmp;


void dfs(int len) {
    if(len >= n) {
        for(int i = 0; i < len; i++) {
            if(out[i] != pre[i]) {
                putchar(out[i]);
            }
        }
        putchar('\n');
        strcpy(pre, out);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!used[i] && A[i][len]) {
            out[len] = i + 'A';
            used[i] = 1;
            dfs(len + 1);
            used[i] = 0;
        }
    }
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        A[i][j] = 1;
        for(int i = 0; i < n; i++) {
            while(~scanf("%d", &tmp) && tmp) {
                A[i][tmp - 1] = 0;
            }
        }
        memset(used, 0, sizeof(used));
        memset(pre, 0, sizeof(pre));
        dfs(0); putchar('\n');
    }
    return 0;
}
