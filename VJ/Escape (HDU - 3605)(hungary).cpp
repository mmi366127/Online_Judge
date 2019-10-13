#include <stdio.h>
#include <string.h>
#include <vector>
#define maxn 100005
using namespace std;

vector<int> match[12];
int G[maxn][12];
bool vis[maxn];
int A[12];
int n, m;

int dfs(int x) {
    for(int y = 1; y <= m; y++) {
        if(!vis[y] && G[x][y]) {
            vis[y] = 1;
            if(match[y].size() < A[y]) {
                match[y].push_back(x);
                return 1;
            }
            for(int i = 0; i < match[y].size(); i++) {
                if(dfs(match[y][i])) {
                    match[y][i] = x;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 1; i <= m; i++) {
            match[i].clear();
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%d", &G[i][j]);
            }
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d", &A[i]);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++)
                vis[j] = 0;
            if(dfs(i)) cnt++;
            else break;
        }
        if(cnt == n) puts("YES");
        else puts("NO");
    }
    return 0;
}
