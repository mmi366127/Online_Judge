#include <stdio.h>
#include <string.h>
#define maxn 57
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)
char p[maxn], s[maxn];
char str[maxn][maxn];
int n, t, ans;

void init(int n) {
    for(int i = 0; i < n; i++) {
        s[i] = 1; p[i] = -1;
    }
    ans = 1;
}

int find(int x) {
    return p[x] < 0 ? x : (p[x] = find(p[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    p[y] = x;
    s[x] += s[y];
    ans = max(s[x], ans);
}

int lcs(char a[], char b[]) {
    static char dp[maxn][maxn];
    memset(dp, 0, sizeof(dp));
    int i, j;
    for(i = 1; i <= a[0]; i++) {
        for(j = 1; j <= b[0]; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[a[0]][b[0]];
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        init(n);
        for(int i = 0; i < n; i++) {
            scanf("%s", str[i] + 1);
            str[i][0] = strlen(str[i] + 1);
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int LCS = lcs(str[i], str[j]);
                if((double)LCS >= ((double)(min(str[i][0], str[j][0]))/2)) {
                    join(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
