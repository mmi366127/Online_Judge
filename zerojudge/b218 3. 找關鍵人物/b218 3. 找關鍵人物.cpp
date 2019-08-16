#include <stdio.h>
#include <string.h>
#define maxn 100000
typedef long long loli;

int to[maxn], pre[maxn], head[maxn], tot;

void add(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}

loli V[maxn];
int n;

loli dfs(int x, int p) {
    loli tmp, cnt = 1; V[x] = 0;
    for(int i = head[x]; i != -1; i = pre[i]) {
        if(to[i] == p) continue;
        tmp = dfs(to[i], x);
        cnt += tmp;
        V[x] += (tmp * (n - tmp - 1));
    }
    V[x] += (cnt - 1) * (n - cnt);
    return cnt;
}


int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for(int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    dfs(1, -1); loli mx = 0, ans = -1;
    for(int i = 1; i <= n; i++) {
        if(V[i] > mx) {
            mx = V[i];
            ans = i;
        }
    }
    printf("%d %lld\n", ans, mx / 2);
    return 0;
}
