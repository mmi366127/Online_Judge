#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
#define min(a, b) (a) < (b) ? (a) : (b)
#define maxn 10007


char n[maxn], m[maxn];
int l, k, nl, ml, cur;
int dp[maxn][maxn];

const int nn = 1000;
const int mm = 1000;

void YEE(char a[], char b[]) {
    for(int i = 0; i < nn; i++) {
        a[i] = rand() % 26 + 'a';
    }
    for(int j = 0; j < mm; j++) {
        b[j] = rand() % 26 + 'a';
    }
}


int main() {
    //YEE(n+1, m+1);
    //l = 100, k = 1000;
    scanf("%s%s", n+1, m+1);
    scanf("%d%d", &l, &k);
    //memset(dp, 0, sizeof(dp));
    nl = strlen(n+1);
    ml = strlen(m+1);
    for(int i = 1; i <= nl; i++) {
        dp[i][0] = (i % l == 0) ? i / l : i / l + 1;
    }
    for(int i = 1; i <= ml; i++) {
        dp[0][i] = (i % l == 0) ? i / l : i / l + 1;
    }
    for(int i = 1; i <= nl; i++) {
        for(int j = 1; j <= ml; j++) {
            dp[i][j] = maxn;
            if(n[i] != m[j]) {
                for(int k = j - 1; k >= 0 && k >= j - l; k--) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + 1);
                }
                for(int k = i - 1; k >= 0 && k >= i - l; k--) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + 1);
                }
            } else {
                dp[i][j] = dp[i-1][j-1];
            }
            //printf("%d %d %d\n", i, j, dp[i][j]);
        }
    }
    //printf("%d\n", dp[nl][ml]);
    if(dp[nl][ml] > k) puts("Impossible");
    else printf("%d\n", dp[nl][ml]);
    return 0;
}
