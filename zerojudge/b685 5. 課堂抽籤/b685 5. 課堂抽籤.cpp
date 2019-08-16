#include <stdio.h>
#include <string.h>
#define maxn 1007

const int mod = (int)1e6 + 7;

int rd() {
    static char c; int ret;
    for(c = getchar(); c < '0'; c = getchar())
        if(c == EOF) return 0;
    for(ret = 0; c >= '0'; c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ '0');
    return ret;
}

void prt(int x) {
    if(x < 10) {
        putchar(x + '0');
        return;
    }
    prt(x / 10);
    putchar(x % 10 + '0');
}

int T, n, m, cnt, circle, chain;

int p[maxn], s[maxn], A[maxn];
char zero[maxn];
int C[maxn][maxn];

int find(int x) {
    return p[x] < 0 ? x : (p[x] = find(p[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(s[x] > s[y]) {
        p[y] = x;
        s[x] += s[y];
    } else {
        p[x] = y;
        s[y] += s[x];
    }
    cnt--;
}

int main() {
    C[0][0] = 1;
    for(int i = 1; i < maxn; i++) {
        for(int j = 0; j <= i; j++) {
            if(i == j) C[i][j] = 1;
            else if(j == 0) C[i][j] = 0;
            else {
                C[i][j] = (((( i - 1 ) * C[i - 1][j]) % mod) + C[i - 1][j - 1]) % mod;
            }
        }
    }
    T = rd();
    while(T--) {
        n = rd(); m = rd(); cnt = n;
        memset(zero, 0, sizeof(zero));
        for(int i = 1; i <= n; i++) {
            p[i] = -1; s[i] = 1;
        }
        for(int i = 1; i <= n; i++) {
            A[i] = rd();
            if(A[i]) join(i, A[i]);
        }
        for(int i = 1; i <= n; i++) {
            if(A[i] == 0) {
                zero[find(i)] = 1;
            }
        }
        chain = circle = 0;
        for(int i = 1; i <= n; i++) {
            if(p[i] < 0 && zero[i]) {
                chain++;
            }
        }
        circle = cnt - chain;
        if((circle + (int)(chain > 0)) > m || cnt < m) prt(0), putchar('\n');
        else {
            prt(C[chain][m - circle]); putchar('\n');
        }
    }
}
