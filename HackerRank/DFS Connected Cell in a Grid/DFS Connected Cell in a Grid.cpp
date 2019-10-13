#include <bits/stdc++.h>
#define maxn 15
using namespace std;

int mx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int my[] = {1, -1, 0, 0, 1, -1, 1, -1};

char M[maxn][maxn];
int n, m, x;

int dfs(int x, int y) {
    if(!M[x][y]) return 0;
    M[x][y] = 0;
    int ret = 1;
    for(int i = 0; i < 8; i++) {
        ret += dfs(x + mx[i], y + my[i]);
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int  j = 1; j <= m; j++) {
            scanf("%d", &x); M[j][i] = x;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(M[j][i]) {
                ans = max(ans, dfs(j, i));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
 }
