#include <stdio.h>
#include <string.h>
#define maxn 107

int field[maxn][maxn];

int dfs(int x,int y) {
    if(!field[x][y]) return 0;
    int ret = field[x][y];
    field[x][y] = 0;
    ret += dfs(x+1, y);
    ret += dfs(x, y+1);
    ret += dfs(x-1, y);
    ret += dfs(x, y-1);
    return ret;
}

int main() {
    int n, m, mx, cnt, tmp;
    while(~scanf("%d%d", &n, &m)) {
        cnt = mx = 0;
        memset(field, 0, sizeof(field));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%d", &field[j][i]);
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(field[j][i]) {
                    tmp = dfs(j, i);
                    if(tmp > mx) mx = tmp;
                    cnt++;
                }
            }
        }
        printf("%d\n%d\n", cnt, mx);
    }
    return 0;
}
