#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 1007


int n, ans_x, ans_y, dis;
int x[maxn], y[maxn];

int D(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d%d", x + i, y + i);
        }
        dis = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                tmp += D(i, j);
            }
            if(tmp < dis) {
                dis = tmp;
                ans_x = x[i];
                ans_y = y[i];
            } else if(tmp == dis) {
                if(x[i] < ans_x) {
                    ans_x = x[i];
                    ans_y = y[i];
                } else if(x[i] == ans_x) {
                    ans_y = ans_y < y[i] ? ans_y : y[i];
                }
            }
        }
        printf("%d %d\n%d\n", ans_x, ans_y, dis);
    }
    return 0;
}
