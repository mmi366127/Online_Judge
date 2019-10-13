#include <bits/stdc++.h>
#define maxn 1024
using namespace std;

char a[maxn], b[maxn];
char dp[maxn][maxn];
int q;

bool f(int i, int j) {
    if(i == 0 && j == 0) {
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];
    bool ret = false;
    if(islower(a[i])) {
        ret |= f(i - 1, j);
        if(a[i] - 'a' + 'A' == b[j]) {
            ret |= f(i - 1, j - 1);
        }
    } else if(a[i] == b[j]){
        ret |= f(i - 1, j - 1);
    }
    return dp[i][j] = ret;
}

int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%s%s", a + 1, b + 1);
        int len_a = strlen(a + 1);
        int len_b = strlen(b + 1);
        memset(dp, -1, sizeof(dp));
        puts(f(len_a, len_b) ? "YES" : "NO");
    }
    return 0;
}
