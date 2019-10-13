#include <stdio.h>
#include <string.h>
#define maxn 10005
#define maxm 1000005

int p[maxn], s[maxn], A[maxm], B[maxm], Q[maxm], ans[maxm];
char check[maxm] = {};
int n, m, q;

int find(int x) {
    return (p[x] == -1) ? x : (p[x] = find(p[x]));
}

int join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(s[x] < s[y]) {
        int _ = x;
        x = y;
        y = _;
    }
    p[y] = x;
    s[x] += s[y];
    return 1;
}

void init(int sz) {
    for(int i = 0; i <= sz; i++) {
        p[i] = -1; s[i] = 1;
    }
}


int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", A + i, B + i);
    }
    init(n);
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%d", Q + i);
        check[Q[i]] = 1;
    }
    int cnt = n;
    for(int i = 1; i <= m; i++) {
        if(check[i] == 0 && join(A[i], B[i])) cnt--;
    }
    for(int i = q; i > 0; i--) {
        ans[i] = cnt;
        if(join(A[Q[i]], B[Q[i]])) cnt--;
    }
    for(int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return  0;
}
