#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;


int matrix[25][25], a[25][25];
int n;


int main() {
    while(~scanf("%d%d", &n, &matrix[1][1])) {
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == 1 && j == 1) continue;
                if(j == 1) {
                    matrix[i][j] = matrix[1][1] + i;
                } else {
                    matrix[i][j] = matrix[i][j - 1] * 17 % 103;
                    if((j ^ i) & 1) matrix[i][j] *= -1;
                }
            }
            for(int j = 1; j <= n; j++) {
                a[i][j] = a[i][j - 1] + matrix[i][j];
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                int tmp = 0;
                for(int k = 1; k <= n; k++) {
                    if(tmp < 0) tmp = a[k][j] - a[k][i - 1];
                    else tmp += a[k][j] - a[k][i - 1];
                    ans = max(ans, tmp);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
