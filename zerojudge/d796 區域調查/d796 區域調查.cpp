#include <stdio.h>
#include <string.h>
#define swap(a, b) {int _ = a; a = b; b = _;}
#define maxn 300

long long arr[maxn][maxn], bit[maxn][maxn] = {};
int n, m;

void add(int x, int y, long long v) {
    for(int _ = x; _ < maxn; _ += _ & (-_)) {
        for(int __ = y; __ < maxn; __ += __ & (-__)) {
            bit[_][__] += v;
        }
    }
}

long long query(int x, int y) {
    long long ret = 0;
    for(int _ = x; _; _ -= _ & (-_)) {
        for(int __ = y; __; __ -= __ & (-__)) {
            ret += bit[_][__];
        }
    }
    return ret;
}


int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(bit, 0, sizeof(bit));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%lld", &arr[j][i]);
                add(j, i, arr[j][i]);
            }
        }
        for(int i = 0; i < m; i++) {
            long long k;
            int x, y, X, Y;
            scanf("%lld", &k);
            if(k == 1) {
                scanf("%d%d%d%d", &y, &x, &Y, &X);
                if(y > Y) {
                    swap(y, Y);
                }
                if(x > X) {
                    swap(x, X);
                }
                printf("%lld\n", query(X, Y) - query(X, y - 1) - query(x - 1, Y) + query(x - 1, y - 1));
            } else {
                scanf("%d%d%lld", &Y, &X, &k);
                add(X, Y, k - arr[X][Y]);
                arr[X][Y] = k;
            }
        }
    }
    return 0;
}
