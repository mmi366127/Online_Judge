#include <stdio.h>
#define maxn 1005

int x[maxn], y[maxn];
int n;

int dis2(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", x + i, y + i);
    }
    int a, b, tmp = -1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(dis2(i, j) > tmp) a = i, b = j, tmp = dis2(i, j);
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}
