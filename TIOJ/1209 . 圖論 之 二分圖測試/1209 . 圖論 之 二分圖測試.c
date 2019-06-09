#include <stdio.h>
#include <string.h>
#define maxn 100000



int p[maxn], s[maxn];

int find(int x) {
    return p[x] < 0 ? x : (p[x] = find(p[x]));
}

char join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 1;
    if(s[x] < s[y]) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    p[y] = x;
    s[x] += s[y];
    return 0;
}

int n, m, u, v;

int main() {
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 && m == 0) return 0;
        for(int i = 1; i <= 2 * n; i++) {
            p[i] = -1, s[i] = 1;
        }
        char flag = 1;
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            if(find(u) == find(v) || find(u + n) == find(v + n)) {
                flag = 0;
            } else {
                join(u, v + n);
                join(u + n, v);
            }
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
