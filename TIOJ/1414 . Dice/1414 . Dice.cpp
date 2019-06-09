#include <bits/stdc++.h>
#define all(X) X.begin(), X.end()
#define maxn 107
typedef long long loli;
using namespace std;

int mx[] = {1,1,1,-1,-1,-1,0,0};
int my[] = {-1,0,1,-1,0,1,-1,1};

char M[maxn][maxn];
char s[maxn];
int n, m, ans1, ans2;

void dfs(int x, int y, char c) {
    if(c == '2') M[x][y] = '1';
    else M[x][y] = '2';
    for(int i = 0; i < 8; i++) {
        int xx = x + mx[i];
        int yy = y + my[i];
        if(M[xx][yy] == c) {
            dfs(xx, yy, c);
        }
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(M, 0, sizeof(M));
        for(int i = 1; i <= n ;i++) {
            scanf("%s", s);
            for(int j = 1; j <= m; j++) {
                M[j][i] = s[j - 1];
            }
        }
        /*for(int i = 1; i <= n ;i++) {
            for(int j = 1; j <= m; j++) {
                printf("%c", M[j][i]);
            } puts("");
        }*/
        ans1 = ans2 = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(M[j][i] == '2') {
                    ans2++;
                    dfs(j, i, '2');
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(M[j][i] == '1') {
                    ans1++;
                    dfs(j, i, '1');
                }
            }
        }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
