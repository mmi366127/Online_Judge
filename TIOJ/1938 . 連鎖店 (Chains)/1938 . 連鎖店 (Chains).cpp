#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 205;

int cur[maxn][maxn] = {}, pre[maxn][maxn] = {};
int n, m, a, b, c, d;

int get_val(int x, int y, int i) {
    x--, y--;
    return (a * i + b * x + c * y) % d;
}

int main() {
    while(~scanf("%d%d%d%d%d%d", &m, &n, &a, &b, &c, &d)) {
        for(int i = 0; i <= m; i++) {
            cur[i][0] = -INF;
            cur[0][i] = -INF;
            pre[i][0] = -INF;
            pre[0][i] = -INF;
        }
        for(int x = 1; x <= m; x++) {
            for(int y = 1; y <= m; y++) {
                pre[x][y] = max({pre[x - 1][y], pre[x][y - 1], get_val(x, y, 0)});
            }
        }
        for(int i = 1; i < n; i++) {
            for(int x = 1; x <= m; x++) {
                for(int y = 1; y <= m; y++) {
                    cur[x][y] = max({cur[x - 1][y], cur[x][y - 1], pre[x - 1][y - 1] + get_val(x, y, i)});
                    //printf("%d%c", cur[x][y], " \n"[y == m]);
                }
            }
            swap(cur, pre);
        }
        int ans = 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                ans = max(ans, pre[i][j]);//, printf("%d%c", pre[j][i], " \n"[j == m]);
        printf("%d\n", ans);
    }
    return 0;
}
