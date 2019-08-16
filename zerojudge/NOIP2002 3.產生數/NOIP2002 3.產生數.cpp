#include <stdio.h>
#include <string.h>

int k, u, v, ans[100], d[10];
char M[10][10], s[50];


int main() {
    memset(M, 0, sizeof(M));
    for(int i = 0; i < 10; i++) {
        M[i][i] = 1;
    }
    scanf("%s %d", s, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d%d", &u, &v);
        M[u][v] = 1;
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                M[j][k] |= M[j][i] & M[i][k];
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        d[i] = 0;
        for(int j = 0; j < 10; j++) {
            if(M[i][j]) d[i]++;
        }
    }
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    for(int i = 0; s[i]; i++) {
        for(int j = 0; j < 100; j++) {
            ans[j] = ans[j] * d[s[i]-'0'];
        }
        for(int j = 0; j < 100; j++) {
            if(ans[j] >= 10) {
                ans[j+1] += ans[j] / 10;
                ans[j] %= 10;
            }
        }
    }
    int p;
    for(p = 99; ans[p] == 0; p--);
    for(; p >= 0; p--) {
        printf("%d", ans[p]);
    }
    puts("");
    return 0;
}
