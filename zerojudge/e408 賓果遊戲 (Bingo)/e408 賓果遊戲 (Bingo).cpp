#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define X first
#define Y second
#define maxn 1024
using namespace std;

template<class T> void read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 1) + (x << 3) + (c ^ '0');
}

pair<int, int> Pos_A[1 << 20], Pos_B[1 << 20];
int cnt_A[2][maxn] = {}, cnt_B[2][maxn] = {};
int n, p, l;


int main() {
    read(n); read(p); read(l);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int tmp; read(tmp);
            Pos_A[tmp].X = j;
            Pos_A[tmp].Y = i;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int tmp; read(tmp);
            Pos_B[tmp].X = j;
            Pos_B[tmp].Y = i;
        }
    }
    int tmp, line_A = 0, line_B = 0;
    for(int i = 0; i < l; i++) {
        read(tmp);
        if(Pos_A[tmp].X) {
            cnt_A[0][Pos_A[tmp].X]++;
            if(cnt_A[0][Pos_A[tmp].X] == n) line_A++;
            cnt_A[1][Pos_A[tmp].Y]++;
            if(cnt_A[1][Pos_A[tmp].Y] == n) line_A++;
            if(Pos_A[tmp].X == Pos_A[tmp].Y) {
                cnt_A[0][0]++;
                if(cnt_A[0][0] == n) line_A++;
            }
            if(Pos_A[tmp].X + Pos_A[tmp].Y == n + 1) {
                cnt_A[1][0]++;
                if(cnt_A[1][0] == n) line_A++;
            }
        }
        if(Pos_B[tmp].X) {
            cnt_B[0][Pos_B[tmp].X]++;
            if(cnt_B[0][Pos_B[tmp].X] == n) line_B++;
            cnt_B[1][Pos_B[tmp].Y]++;
            if(cnt_B[1][Pos_B[tmp].Y] == n) line_B++;
            if(Pos_B[tmp].X == Pos_B[tmp].Y) {
                cnt_B[0][0]++;
                if(cnt_B[0][0] == n) line_B++;
            }
            if(Pos_B[tmp].X + Pos_B[tmp].Y == n + 1) {
                cnt_B[1][0]++;
                if(cnt_B[1][0] == n) line_B++;
            }
        }
        if(line_A >= p && line_B >= p) {
            printf("%d %d %d\n", tmp, line_A, line_B);
            puts("Draw");
            return 0;
        } else if(line_A >= p) {
            printf("%d %d %d\n", tmp, line_A, line_B);
            puts("The winner is Baluteshih");
            return 0;
        } else if(line_B >= p) {
            printf("%d %d %d\n", tmp, line_A, line_B);
            puts("The winner is Alan");
            return 0;
        }
    }
    printf("%d %d %d\n", tmp, line_A, line_B);
    puts("Draw");
    return 0;
}
