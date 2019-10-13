#include <bits/stdc++.h>
#define maxn 1024
typedef __int128_t loli;
using namespace std;

const loli INF = ((loli)0x3f3f3f3f3f3f3fLL << 50 | 0x3f3f3f3f3f3f3fLL);

char valid[maxn][maxn];
loli path[maxn][maxn];
loli X[maxn], Y[maxn];
int n, T, k;
loli L, U;

void prt(loli x) {
    if(x < 10) {
        putchar(x + '0');
        return;
    }
    prt(x / 10);
    putchar(x % 10 + '0');
}

loli rd() {
    static char c; loli ret;
    for(c = getchar(); c < '0'; c = getchar());
    for(ret = 0; c >= '0'; c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ '0');
    return ret;
}

char vx[maxn], vy[maxn];
loli match[maxn], lx[maxn], ly[maxn];

bool dfs(int x) {
    if(vx[x]) return false;
    vx[x] = true;
    for(int y = 1; y <= n; y++) {
        if(valid[x][y] && !vy[y] && lx[x] + ly[y] == path[x][y]) {
            vy[y] = true;
            if(match[y] ==  -1 || dfs(match[y])) {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

void solve() {
    memset(ly, 0, sizeof(ly));
    for(int i = 1; i <= n; i++) {
        lx[i] = 0;
        for(int j = 1; j <= n; j++) {
            if(valid[i][j])
            lx[i] = max(lx[i], path[i][j]);
        }
    }
    memset(match, -1, sizeof(match));
    for(int i = 1; i <= n; i++) {
        while(1) {
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if(dfs(i)) {
                break;
            }
            loli cut = INF;
            for(int j = 1; j <= n; j++) {
                if(vx[j]) {
                    for(int k = 1; k <= n; k++) {
                        if(!vy[k] && valid[j][k]) {
                            cut = min(cut, lx[j] + ly[k] - path[j][k]);
                        }
                    }
                }
            }
            if(cut == INF) {
                printf("no\n");
                return;
            }
            for(int j = 1; j <= n; j++) {
                if(vx[j]) lx[j] -= cut;
                if(vy[j]) ly[j] += cut;
            }
        }
    }
    loli ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += path[match[i]][i];
    }
    prt(-ans); puts("");
    return;
}

int main() {
    T = rd();
    while(T--) {
        n = rd(); L = rd(); U = rd(); k = rd();
        memset(valid, 1, sizeof(valid));
        for(int i = 0; i < k; i++) {
            int x = rd(), y = rd();
            valid[x][y] = 0;
        }
        for(int i = 1; i <= n; i++) {
            X[i] = rd();
        }
        for(int i = 1; i <= n; i++) {
            Y[i] = rd();
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(valid[i][j]) {
                    loli tmp = X[i] + Y[j];
                    if(tmp < L) path[i][j] = 0;
                    else if(tmp < U) path[i][j] = tmp - L;
                    else path[i][j] = U - L;
                    path[i][j] *= -1;
                }
            }
        }
        solve();
    }
    return 0;
}

