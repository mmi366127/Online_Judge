#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define X first
#define Y second
#define maxn 25
using namespace std;
typedef pair<int, int> pii;
struct Data {
    pii pos; int val;
    Data(int x, int y, int  v) {
        pos = make_pair(x, y); val = v;
    }
    bool operator < (const Data &a) const {
        return val > a.val;
    }
};

const int INF = 0x3f3f3f3f;

int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};


int MAP[maxn][maxn], dis[maxn][maxn], ans[maxn][maxn][maxn][maxn];
int n;

void SP(int x, int y) {
    priority_queue<Data> pq;
    memset(dis, 0x3f, sizeof(dis));
    pq.push(Data(x, y, MAP[x][y]));
    dis[x][y] = MAP[x][y];
    while(pq.size()) {
        auto cur = pq.top(); pq.pop();
        x = cur.pos.X; y = cur.pos.Y;
        for(int i = 0; i < 4; i++) {
            int xx = x + mx[i];
            int yy = y + my[i];
            if(MAP[xx][yy] >= 0 && dis[xx][yy] > dis[x][y] + MAP[xx][yy]) {
                dis[xx][yy] = dis[x][y] + MAP[xx][yy];
                pq.push(Data(xx, yy, dis[xx][yy]));
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(MAP, 0xff, sizeof(MAP));
    memset(ans, 0x3f, sizeof(ans));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &MAP[j][i]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int tmp = MAP[i][j];
            MAP[i][j] = 0;
            for(int x = 1; x <= n; x++) {
                for(int y = 1; y <= n; y++) {
                    SP(x, y);
                    for(int xx = 1; xx <= n; xx++) {
                        for(int yy = 1; yy <= n; yy++) {
                            ans[x][y][xx][yy] = min(ans[x][y][xx][yy], dis[xx][yy]);
                        }
                    }
                }
            }
            MAP[i][j] = tmp;
        }
    }
    scanf("%d", &n);
    while(n--) {
        int sx, sy, ex, ey;
        scanf("%d%d%d%d", &sy, &sx, &ey, &ex);
        printf("%d\n", ans[sx][sy][ex][ey]);
    }
    return 0;
}
