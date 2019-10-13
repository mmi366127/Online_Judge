#include <stdio.h>

long long C[25][25];
int n, k;

int main() {
    for(int i = 1; i < 25; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || i == j)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    scanf("%d", &n);
    while(~scanf("%d%d", &n, &k))
        printf("%lld\n", C[n][k]);
    return 0;

}
