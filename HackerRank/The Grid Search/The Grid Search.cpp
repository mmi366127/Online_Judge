#include <bits/stdc++.h>
#define maxn 1024
using namespace std;
typedef long long loli;

const loli mod = 1000000007ll;

loli My_hash[maxn][maxn], B_hash[maxn][maxn], pre[maxn];
char A[maxn][maxn], B[maxn][maxn];
int t, R, C, r, c;


loli get_hash(int i, int L, int R) {
    loli ret = (My_hash[i][R] - My_hash[i][L - 1] * pre[R - L + 1] % mod) % mod;
    return (ret + mod) % mod;
}


bool check(int i, int j) {
    for(int a = i; a < i + r; a++) {
        if(get_hash(a, j, j + c - 1) != B_hash[a - i + 1][c]) return false;
    }
    return true;
}


int main() {
    pre[0] = 1;
    for(int i = 1; i < maxn; i++)
        pre[i] = pre[i - 1] * 29 % mod;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &R, &C);
        for(int i = 1; i <= R; i++) {
            scanf("%s", A[i] + 1);
        }
        scanf("%d%d", &r, &c);
        for(int i = 1; i <= r; i++) {
            scanf("%s", B[i] + 1);
        }
        memset(My_hash, 0, sizeof(My_hash));
        memset(B_hash, 0, sizeof(B_hash));
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                My_hash[i][j] = (My_hash[i][j - 1] * 29 + A[i][j]) % mod;
            }
        }
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                B_hash[i][j] = (B_hash[i][j - 1] * 29 + B[i][j]) % mod;
            }
        }
        bool flag = false;
        for(int i = 1; i <= R - r + 1; i++) {
            for(int j = 1; j <= C - c + 1; j++) {
                if(check(i, j)) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
