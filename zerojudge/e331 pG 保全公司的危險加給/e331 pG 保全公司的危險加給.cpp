#include <bits/stdc++.h>
#define maxn 1024
using namespace std;
typedef __int128_t loli;

const loli INF = ((loli)1 << 100);

template <class T>
void read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0LL; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
}

template <class T>
void put(T x) {
    static char buf[50], idx;
    if(x == 0LL) {
        puts("0");
        return;
    }
    for(idx = 0; x > 0; x /= 10) {
        buf[idx++] = (x % 10) ^ '0';
    }
    for(idx--; idx >= 0; idx--) {
        putchar(buf[idx]);
    }
    putchar('\n');
}

loli lx[maxn], ly[maxn], X[maxn], Y[maxn];
char vx[maxn], vy[maxn];
char valid[maxn][maxn];
loli G[maxn][maxn];
int match[maxn];
loli U, L, cut;
int t, n, k;

bool dfs(int x) {
    if(vx[x]) return false;
    vx[x] = true;
    for(int y = 0; y < n; y++) {
        if(valid[x][y] && !vy[y] && lx[x] + ly[y] == G[x][y]) {
            vy[y] = true;
            if(match[y] == -1 || dfs(match[y])) {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

void KM() {
    memset(match, -1, sizeof(int) * n);
    memset(ly, 0, sizeof(loli) * n);
    for(int i = 0; i < n; i++) {
        lx[i] = 0;
        for(int j = 0; j < n; j++) {
            if(valid[i][j] && G[i][j] > lx[i]) {
                lx[i] = G[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        while(true) {
            memset(vx, 0, sizeof(char) * n);
            memset(vy, 0, sizeof(char) * n);
            cut = INF;
            if(dfs(i))
                break;

            for(int j = 0; j < n; j++) {
                if(vx[j]) {
                    for(int k = 0; k < n; k++) {
                        if(!vy[k] && valid[j][k]) {
                            cut = min(cut, lx[j] + ly[k] - G[j][k]);
                        }
                    }
                }
            }
            //put(cut);
            if(cut == INF) {
                puts("no");
                return;
            }
            for(int j = 0; j < n; j++) {
                if(vx[j]) lx[j] -= cut;
                if(vy[j]) ly[j] += cut;
            }
        }
    }
    loli ans = 0;
    for(int i = 0; i < n; i++) {
        ans += G[match[i]][i];
    }
    put(-ans);
}

int main() {
    read(t);
    while(t--) {
        read(n), read(L), read(U), read(k);
        memset(valid, 1, sizeof(valid));
        while(k--) {
            int x, y;
            read(x), read(y);
            valid[x-1][y-1] = 0;
        }
        for(int i = 0; i < n; i++) {
            read(X[i]);
        }
        for(int i = 0; i < n; i++) {
            read(Y[i]);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!valid[i][j]) continue;
                loli tmp = X[i] + Y[j];
                if(tmp <= L) G[i][j] = 0LL;
                else if(tmp <= U) G[i][j] = L - tmp;
                else G[i][j] = L - U;
            }
        }
        KM();
    }
    return 0;
}
