#include <bits/stdc++.h>
#define maxn 1007
using namespace std;
struct Pt {
    int x, y, val;
    bool operator < (const Pt &a) const {
        return val > a.val;
    }
};

const int INF = 0x3f3f3f3f;

int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};

int dis[maxn][maxn];
char M[maxn][maxn];
int n, m, T;
char c;

int in(int x, int y) {
    return (0 < x && x <= m) && (0 < y && y <= n);
}

int main() {
    for(c = getchar(); c < '0'; c = getchar());
    for(T = 0; c >= '0'; c = getchar())
        T = (T << 3) + (T << 1) + (c ^ '0');
    while(T--) {
        for(c = getchar(); c < '0'; c = getchar());
        for(n = 0; c >= '0'; c = getchar())
            n = (n << 3) + (n << 1) + (c ^ '0');
        for(c = getchar(); c < '0'; c = getchar());
        for(m = 0; c >= '0'; c = getchar())
            m = (m << 3) + (m << 1) + (c ^ '0');
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(c = getchar(); c < '0'; c = getchar());
                M[j][i] = (c ^ '0');
                dis[j][i] = INF;
            }
        }
        priority_queue<Pt> pq;
        pq.push({1, 1, M[1][1]});
        dis[1][1] = M[1][1];
        while(pq.size()) {
            Pt x = pq.top(); pq.pop();
            if(x.x == m && x.y == n) break;
            if(x.val != dis[x.x][x.y]) continue;
            for(int i = 0; i < 4; i++) {
                int xx = x.x + mx[i];
                int yy = x.y + my[i];
                if(in(xx, yy) && dis[xx][yy] > dis[x.x][x.y] + M[xx][yy]) {
                    dis[xx][yy] = dis[x.x][x.y] + M[xx][yy];
                    pq.push({xx, yy, dis[xx][yy]});
                }
            }
        }
        printf("%d\n", dis[m][n]);
    }
    return 0;
}
