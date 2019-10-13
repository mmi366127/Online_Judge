#include <bits/stdc++.h>
#define maxn 505
using namespace std;

int G[maxn][maxn] = {};
int d[maxn] = {};
int m, x, y, mx;
vector<int> ans;

void dfs(int x) {
    for(int i = 1; i <= mx; i++) {
        if(G[x][i]) {
            G[x][i]--;
            G[i][x]--;
            d[x]--;
            d[i]--;
            dfs(i);
        }
    }
    ans.push_back(x);
}

int main() {
    while(~scanf("%d", &m) && m) {
        memset(G, 0, sizeof(G));
        memset(d, 0, sizeof(d));
        mx = 0; ans.clear();
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            G[x][y]++; G[y][x]++;
            d[x]++; d[y]++;
            mx = max(mx, max(x, y));
        }
        x = maxn;
        for(int i = 1; i <= mx; i++) {
            if(d[i] & 1) {
                x = i;
                break;
            } else if(d[i]) x = min(x, i);
        }
        dfs(x);
        reverse(ans.begin(), ans.end());
        for(int t : ans) printf("%d\n", t);
        puts("");
    }
    return 0;
}

