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
    queue<pair<pair<int,int>,char>> Q;
    Q.push({{1,1}, 0});
    while(!Q.empty()) {
        int x = Q.front().X.X;
        int y = Q.front().X.Y;
        char stat = Q.front().Y;
        Q.pop();
        //printf("%d %d %d %d\n", x, y, stat, dis[x][y]);
        //print();
        if(MAP[x][y] < 0) {
            for(int i = 0; i < 4; i++) {
                int xx = x + mx[i];
                int yy = y + my[i];
                if(dis[xx][yy] == INF && MAP[xx][yy] != wall) {
                    dis[xx][yy] = dis[x][y] + 1;
                    Q.push({{xx, yy}, 0});
                }
            }
        } else {
            if(stat) {
                bool sealed = true;
                for(int i = 0; i < 4; i++) {
                    int xx = x + mx[i];
                    int yy = y + my[i];
                    if(dis[xx][yy] == INF && MAP[xx][yy] != wall) {
                        sealed = false;
                        dis[xx][yy] = dis[x][y] + 1;
                        Q.push({{xx, yy}, 0});
                    }
                }
                if(!sealed) {
                    int xx = MAP[x][y] / 10000;
                    int yy = MAP[x][y] % 10000;
                    dis[xx][yy] = dis[x][y] + 2;
                    Q.push({{xx, yy}, 1});
                }
            } else {
                int xx = MAP[x][y] / 10000;
                int yy = MAP[x][y] % 10000;
                dis[xx][yy] = dis[x][y];
                Q.push({{xx, yy}, 1});
            }
        }
    }
    //printf("%d\n", INF);
    if(dis[n-2][n-2] == INF) puts("-1");
    else printf("%d\n", dis[n-2][n-2]);
    return 0;
}

/*
6 2
######
#..#.#
#...##
##...#
#.#..#
######
1 2 4 1
2 1 1 4
*/
