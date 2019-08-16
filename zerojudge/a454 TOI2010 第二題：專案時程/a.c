
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 100000

int to[maxn], pre[maxn], head[maxn], tot;

void add(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}

int w[maxn], que[maxn], dis[maxn];
int n, m, u, v, T, l, r;
char inq[maxn], d[maxn];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(head, -1, 4*n+4);
        memset(d, 0, n+1);
        for(int u = 1; u <= n; u++) {
            scanf("%d", w + u);
            scanf("%d", &m);
            for(int i = 0; i < m; i++) {
                scanf("%d", &v);
                add(u, v); d[v] = 1;
            }
        }
        memset(dis, 0, 4*n+4);
        memset(inq, 0, n+1);
        l = r = 0;
        for(int i = 1; i <= n; i++) {
            if(!d[i]) {
                que[r++] = i;
            }
        }
        while(l != r) {
            int x = que[l++];
            inq[x] = 0;
            if(l >= maxn) l = 0;
            for(int i = head[x]; i != -1; i = pre[i]) {
                if(dis[to[i]] < dis[x] + w[x]) {
                    dis[to[i]] = dis[x] + w[x];
                    if(!inq[x]) {
                        que[r++] = to[i];
                        inq[to[i]] = 1;
                        if(r >= maxn) r = 0;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = (dis[i]+w[i]) > ans ? (dis[i]+w[i]) : ans;
        printf("%d\n", ans);
    }
    return 0;
}
