#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, -1, 1};

char dp[2][maxn][maxn] = {};
int n, m, x, X, y, Y, k;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    cin >> y >> x >> Y >> X;
    cin >> k; int cur = 1;
    dp[0][x][y] = 1;
    for(int i = 0; i < k; i++) {
        cin >> x;
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                dp[cur][j][k] = 0;
            }
        }
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(dp[cur ^ 1][j][k]) {
                    dp[cur][(j + x) % m][k] = 1;
                    dp[cur][(j - x + 105 * m) % m][k] = 1;
                    dp[cur][j][(k + x) % n] = 1;
                    dp[cur][j][(k - x + 105 * n) % n] = 1;
                }
            }
        }
        cur ^= 1;
    }
    puts(dp[cur ^ 1][X][Y] ? "YES" : "NO");
    return 0;
}
