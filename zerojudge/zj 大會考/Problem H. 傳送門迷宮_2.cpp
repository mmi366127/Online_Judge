#include <stdio.h>
#include <string.h>
#include <utility>
#include <queue>
#define maxn 1007
#define wall -2
#define road -1
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
int mx[] = {1, 0, 0, -1};
int my[] = {0, 1, -1, 0};

int id(int x, int y) {
    return x * 10000 + y;
}

char s[maxn];
int dis[maxn][maxn], MAP[maxn][maxn];
int n, m, a, b, c, d;

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dis[i][j] >= INF) printf("#");
            else printf("%d", dis[i][j]);

        } puts("");
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
    fgets(s, sizeof(s), stdin);
    for(int i = 0; i < n; i++) {
        fgets(s, sizeof(s), stdin);
        for(int j = 0; j < n; j++) {
            if(s[j] == '.') MAP[i][j] = road;
            else MAP[i][j] = wall;
        }
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        MAP[a][b] = id(c, d);
        MAP[c][d] = id(a, b);
    }
    dis[1][1] = 0;
    queue<pair<int,int>> Q;
    Q.push({1, 1});
    while(!Q.empty() && Q.size() < maxn*maxn) {
        int x = Q.front().X;
        int y = Q.front().Y;
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = x + mx[i];
            int yy = y + my[i];
            if(dis[xx][yy] > dis[x][y] + 1 && MAP[xx][yy] == road) {
                dis[xx][yy] = dis[x][y] + 1;
                Q.push({xx, yy});
            } else if(MAP[xx][yy] >= 0) {
                int px = MAP[xx][yy] / 10000;
                int py = MAP[xx][yy] % 10000;
                if(dis[px][py] > dis[x][y] + 1) {
                    dis[px][py] = dis[x][y] + 1;
                    Q.push({px, py});
                }
            }
        }
    }
    if(dis[n-2][n-2] >= INF) puts("-1");
    else printf("%d\n", dis[n-2][n-2]);
    return 0;
}

