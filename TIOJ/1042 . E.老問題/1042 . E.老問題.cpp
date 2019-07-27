#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 105
using namespace std;

const int INF = 2147483647;

int lx[maxn], ly[maxn], match[maxn];
char vx[maxn], vy[maxn];
int adj[maxn][maxn];
int n;

bool dfs(int x) {
    if(vx[x]) return false;
    vx[x] = true;
    for(int y = 1; y <= n; y++) {
        if(!vy[y] && lx[x] + ly[y] == adj[x][y]) {
            vy[y] = true;
            if(match[y] == -1 || dfs(match[y])) {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    while(~scanf("%d", &n) && n) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int tmp; scanf("%d", &tmp);
                adj[i][j] = max(0, tmp);
            }
        }
        memset(match, -1, sizeof(match));
        memset(ly, 0, sizeof(ly));
        for(int i = 1; i <= n; i++) {
            lx[i] = 0;
            for(int j = 1; j <= n; j++) {
                lx[i] = max(lx[i], adj[i][j]);
            }
        }
        for(int i = 1; i <= n; i++) {
            while(1) {
                memset(vx, 0, sizeof(vx));
                memset(vy, 0, sizeof(vy));
                if(dfs(i)) {
                    break;
                }
                int cut = INF;
                for(int j = 1; j <= n; j++) {
                    if(vx[j]) {
                        for(int k = 1; k <= n; k++) {
                            if(!vy[k]) {
                                cut = min(cut, lx[j] + ly[k] - adj[j][k]);
                            }
                        }
                    }
                }
                if(cut == INF) {
                    break;
                }
                for(int j = 1; j <= n; j++) {
                    if(vx[j]) lx[j] -= cut;
                    if(vy[j]) ly[j] += cut;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += adj[match[i]][i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
