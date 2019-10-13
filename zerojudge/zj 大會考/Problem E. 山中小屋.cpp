#include <stdio.h>
#include <string.h>
#define maxn 1077

int mx[] = {1, 0, 0, -1};
int my[] = {0, 1, -1, 0};
char vis[maxn][maxn];
int MAP[maxn][maxn];
int n, m, ans = 0;


int dfs(int x, int y) {
    int ret = 1;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int xx = x + mx[i];
        int yy = y + my[i];
        if(MAP[xx][yy] == MAP[x][y]) {
            if(!vis[xx][yy]) ret = dfs(xx, yy);
        } else {
            if(MAP[xx][yy] > MAP[x][y]) {
                ret = 0;
            }
        }
    }
    return ret;
}



int main() {
    scanf("%d%d", &n, &m);
    memset(MAP, -1, sizeof(MAP));
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &MAP[j][i]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!vis[j][i] && dfs(j, i)) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
