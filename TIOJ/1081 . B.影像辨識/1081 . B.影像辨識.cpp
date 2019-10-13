#include <stdio.h>
#include <string.h>
#define maxn 1024

char map[maxn][maxn];
char s[maxn];
int n, m;

void dfs(int x, int y) {
    if(map[x][y] != '1') return;
    map[x][y] = -1;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
    dfs(x + 1, y + 1);
    dfs(x - 1, y - 1);
    dfs(x + 1, y - 1);
    dfs(x - 1, y + 1);
}

int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        fgets(s, sizeof(s), stdin);
        for(int i = 0; i <= m; i++) {
            map[i][0] = map[i][n + 1] = -1;
        }
        for(int i = 1; i <= n; i++) {
            map[0][i] = map[m + 1][i] = -1;
            fgets(s, sizeof(s), stdin);
            for(int j = 1; j <= m; j++) {
                map[j][i] = s[j - 1];
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(map[j][i] == '1') {
                    dfs(j, i); ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
