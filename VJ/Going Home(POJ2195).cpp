#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
#define maxn 105
using namespace std;

const int INF = 0x3f3f3f3f;

struct KM {
    int lx[maxn], ly[maxn], match[maxn];
    char vx[maxn], vy[maxn];
    int G[maxn][maxn];
    int n;
    void init(int _) {
        n = _;
    }
    void add(int x, int y, int val) {
        G[x][y] = -val;
    }
    bool dfs(int x) {
        if(vx[x]) return false;
        vx[x] = true;
        for(int y = 1; y <= n; y++) {
            if(!vy[y] && lx[x] + ly[y] == G[x][y]) {
                vy[y] = true;
                if(match[y] == -1 || dfs(match[y])) {
                    match[y] = x;
                    return true;
                }
            }
        }
        return false;
    }
    int solve() {
        memset(ly, 0, sizeof(ly));
        memset(match, -1, sizeof(match));
        for(int i = 1; i <= n; i++) {
            lx[i] = 0;
            for(int j = 1; j <= n; j++) {
                lx[i] = max(lx[i], G[i][j]);
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
                    if(vx[j])
                    for(int k = 1; k <= n; k++) {
                        if(!vy[k])
                            cut = min(cut, lx[j] + ly[k] - G[j][k]);
                    }
                }
                if(cut == INF) {
                    // fail;
                    return -1;
                }
                for(int j = 1; j <= n; j++) {
                    if(vx[j]) lx[j] -= cut;
                    if(vy[j]) ly[j] += cut;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(match[i] != -1) ans += G[match[i]][i];
        }
        return -ans;
    }

}km;

int dis(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

vector< pair<int, int> > H, M;
char s[maxn];
int n, m;

int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        H.clear(); M.clear();
        for(int i = 1; i <= n; i++) {
            scanf("%s", s + 1);
            for(int j = 1; j <= m; j++) {
                if(s[j] == 'H') {
                    H.push_back({j, i});
                } else if(s[j] == 'm') {
                    M.push_back({j, i});
                }
            }
        }
        km.init(M.size());
        for(int i = 0; i < H.size(); i++) {
            for(int j = 0; j < M.size(); j++) {
                km.add(i + 1, j + 1, dis(H[i], M[j]));
            }
        }
        printf("%d\n", km.solve());
    }
    return 0;
}
