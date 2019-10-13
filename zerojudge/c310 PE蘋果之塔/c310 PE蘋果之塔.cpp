#include <stdio.h>
#include <string.h>
#define lowbit(X) (X & -(X))
#define maxn 100007


int bit[maxn];

void add(int x, int v) {
    while(x < maxn) {
        bit[x] += v;
        x += lowbit(x);
    }
}

int prefix(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

int query(int l, int r) {
    return prefix(r) - prefix(l-1);
}

void build(int a[], int n) {
    for(int i = 1; i <= n; i++) {
        bit[i] = a[i] - a[i - lowbit(i)];
    }
}

int pre[maxn], to[maxn], head[maxn], tot;

void add_edge(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}

int in[maxn], out[maxn], a[maxn], idx;


void dfs(int x, int p) {
    in[x] = ++idx; a[idx] = a[idx - 1] + 1;
    for(int i = head[x]; i != -1; i = pre[i]) {
        if(to[i] != p) {
            dfs(to[i], x);
        }
    }
    out[x] = ++idx; a[idx] = a[idx - 1];
}

int n, m, u, v, op;

int main() {
    scanf("%d", &n), tot = 0;
    memset(head, -1, sizeof(head));
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v); add_edge(v, u);
    }
    idx = 0;
    dfs(1, -1);
    build(a, idx);
    for(int i = 1; i <= n; i++) a[i] = 1;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &op);
        if(op == 2) {
            scanf("%d", &op);
            printf("%d\n", query(in[op], out[op]));
        } else {
            scanf("%d", &op);
            if(a[op]) add(in[op], -1);
            else add(in[op], 1);
            a[op] ^= 1;
        }
    }
    return 0;
}
