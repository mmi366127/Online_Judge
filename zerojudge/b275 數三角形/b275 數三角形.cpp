#include <stdio.h>
#include <string.h>
#define maxn 107


int x[maxn], y[maxn];
int n, ans = 0;

int YEE(int a, int b, int c) {
    int vx, vy, VX, VY;
    vx = x[b] - x[a];
    vy = y[b] - y[a];
    VX = x[c] - x[a];
    VY = y[c] - y[a];
    if((vx * VY -  VX * vy) != 0) return 1;
    return 0;
}


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", x + i, y + i);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(YEE(i, j, k)) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
