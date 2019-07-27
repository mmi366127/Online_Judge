#include <stdio.h>
#include <string.h>
#define lowbit(X) ((X)&-(X))
#define maxn 1087

int bit[maxn][maxn] = {};
int n, x, y, x1, x2, y1, y2, v, op;

void add(int x, int y, int v) {
    for(int _x = x; _x <= n; _x += lowbit(_x)) {
        for(int _y = y; _y <= n; _y += lowbit(_y)) {
            bit[_x][_y] += v;
        }
    }
}

int query(int _x, int _y) {
    int ret = 0;
    for(int x = _x; x; x -= lowbit(x)) {
        for(int y = _y; y; y -= lowbit(y)) {
            ret += bit[x][y];
        }
    }
    return ret;
}

int query(int x1, int x2, int y1, int y2) {
    return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}

int main() {
    scanf("%d", &n);
    while(~scanf("%d", &op)) {
        if(op == 1) {
            scanf("%d%d%d", &x, &y, &v);
            x++; y++; add(x, y, v);
        } else {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1++; x2++; y1++; y2++;
            printf("%d\n", query(x1, x2, y1, y2));
        }
    }
    return 0;
}
