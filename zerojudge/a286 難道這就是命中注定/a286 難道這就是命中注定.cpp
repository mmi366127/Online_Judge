#include <stdio.h>
#include <string.h>

int abs(int x) {
    return x < 0 ? -x : x;
}

int sp(int x) {
    int ret = 0;
    while(x) {
        ret += x % 10;
        x /= 10;
    }
    if(ret < 10) return ret;
    else return sp(ret);
}

int special(int y, int m, int d) {
    int tmp = 0, ret = 0;
    while(y) {
        ret += y % 10;
        y /= 10;
    }
    while(m) {
        ret += m % 10;
        m /= 10;
    }
    while(d) {
        ret += d % 10;
        d /= 10;
    }
    return sp(ret);
}

int n, y, m, d, G, tmp;

int main() {
    while(~scanf("%d%d%d", &y, &m, &d)) {
        G = special(y, m, d); tmp = 0x3f3f3f3f;
        scanf("%d", &n); int ans = -1;
        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d", &y, &m, &d);
            if(abs((special(y, m, d) - G)) < tmp) {
                ans = i;
                tmp = abs((special(y, m, d) - G));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
