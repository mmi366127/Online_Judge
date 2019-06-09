#include <bits/stdc++.h>
#define all(X) X.begin(), X.end()
#define maxn 507
typedef long long loli;
using namespace std;
struct Node {
    int x, y, h;
    bool operator < (const Node &a) const {
        return h > a.h;
    }
};


int mx[] = {1,-1,0,0};
int my[] = {0,0,1,-1};

int n, m;

bool in(int x, int y) {
    return (1 <= x && x <= n) && (1 <= y && y <= m);
}

priority_queue<Node> pq;
bool inq[maxn][maxn];
int M[maxn][maxn];
vector<int> V;

int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(M, 0, sizeof(M));
        memset(inq, 0, sizeof(inq));
        while(pq.size()) pq.pop();
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d", &M[j][i]);
                if(i == m || j == n || i == 1 || j == 1) {
                    pq.push({j, i, M[j][i]}); inq[j][i] = true;
                }
            }
        }
        loli ans = 0;
        while(pq.size()) {
            int x = pq.top().x;
            int y = pq.top().y;
            int h = pq.top().h;
            pq.pop();
            for(int i = 0; i < 4; i++) {
                int xx = x + mx[i];
                int yy = y + my[i];
                if(!inq[xx][yy] && in(xx, yy)) {
                    if(M[xx][yy] < h) {
                        ans = ans + h - M[xx][yy];
                        M[xx][yy] = h;
                    }
                    pq.push({xx, yy, M[xx][yy]});
                    inq[xx][yy] = true;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
