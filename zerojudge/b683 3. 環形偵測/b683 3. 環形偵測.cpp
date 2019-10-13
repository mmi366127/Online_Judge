#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define X first
#define Y second
#define maxn 50
using namespace std;

int mx[] = {0, 0, 1, -1};
int my[] = {-1, 1, 0, 0};
char MAP[maxn][maxn] = {};
int n, m, tmp;

int GO(int x, int y, int px, int py) {
    if(MAP[x][y] == '7') return 0;
    int ret = -1e9;
    MAP[x][y] = '7';
    for(int i = 0; i < 4; i++) {
        int xx = x + mx[i];
        int yy = y + my[i];
        if(make_pair(xx, yy) != make_pair(px, py) && (MAP[xx][yy] == '.' || MAP[xx][yy] == '7')) {
            ret = GO(xx, yy, x, y) + 1;
            break;
        }
    }
    MAP[x][y] = '8';
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c = getchar();
            while(c != '.' && c != '#')
                c = getchar();
            MAP[j][i] = c;
        }
    }
    unsigned long long X = 0, Y = 0, Z = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(MAP[j][i] == '.') {
                tmp = GO(j, i, -1, -1);
                //return 0;
                if(tmp > 0) {
                    X++;
                    Y = Y + tmp;
                    Z = Z * tmp;
                }
            }
        }
    }
    printf("%llu %llu %llu\n", X, Y, Z);
    return 0;
}
