#include <stdio.h>
#include <string.h>
#define maxn 60

int pre_x[maxn][maxn], pre_y[maxn][maxn], dp[maxn][maxn] = {};
char a[maxn], b[maxn];
int n, m;


int main() {
    scanf("%s%s", a + 1, b + 1);
    n = strlen(a + 1);
    m = strlen(b + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                pre_x[i][j] = i - 1;
                pre_y[i][j] = j - 1;
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                if(dp[i - 1][j] > dp[i][j - 1]) {
                    pre_x[i][j] = i - 1;
                    pre_y[i][j] = j;
                    dp[i][j] = dp[i - 1][j];
                } else {
                    pre_x[i][j] = i;
                    pre_y[i][j] = j - 1;
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    if(!dp[n][m]) {
        puts("E");
        return 0;
    }
    char ans[maxn] = {};
    int px, py, x = n, y = m;
    while(1) {
        px = pre_x[x][y];
        py = pre_y[x][y];
        if(px + 1 == x && py + 1 == y) {
            ans[dp[x][y] - 1] = a[x];
        }
        x = px;
        y = py;
        if(x + y == 0) break;
    }
    puts(ans);
    return 0;
}
