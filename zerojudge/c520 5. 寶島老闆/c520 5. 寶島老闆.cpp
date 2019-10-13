#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define X first
#define Y second
#define maxn 5005
using namespace std;

#define getchar getchar_unlocked

template<class T> void read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
}

int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};

queue< pair<int, int> > Q[2];
char MAP[maxn][maxn] = {};
int n, m, k, x, y;


int main() {
    read(n); read(m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c = getchar();
            while(c != '.' && c != '#') c = getchar();
            MAP[j][i] = c;
        }
    }
    int cur = 0, cnt = 0;
    read(k);
    for(int i = 0; i < k; i++) {
        read(y); read(x);
        if(MAP[x][y] == '.') {
            MAP[x][y] = 0; Q[cur].push(make_pair(x, y)); cnt++;
        }
        while(Q[cur ^ 1].size()) {
            x  = Q[cur ^ 1].front().X;
            y  = Q[cur ^ 1].front().Y;
            Q[cur ^ 1].pop();
            for(int dir = 0; dir < 4; dir++) {
                if(MAP[x + mx[dir]][y + my[dir]] == '.') {
                    cnt++; MAP[x + mx[dir]][y + my[dir]] = 0;
                    Q[cur].push(make_pair(x + mx[dir], y + my[dir]));
                }
            }
        }
        printf("%d\n", cnt); cur ^= 1;
    }
    return 0;
}
/*
6 6
######
##.#.#
#..#.#
#.##.#
#.#..#
######
4
2 3
5 4
2 5
5 2

5 5
.....
.....
.....
.....
.....
3
3 3
3 3
3 3

4 5
..#..
.#.#.
..#..
.....
2
2 3
2 3

3 2
..
..
..
3
1 1
3 2
1 1


*/
