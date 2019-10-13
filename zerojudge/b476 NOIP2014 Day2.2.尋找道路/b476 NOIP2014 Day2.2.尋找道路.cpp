#include <stdio.h>
#include <string.h>
#define maxn 20007
#define maxm 400007


int to[maxm], pre[maxm], head[maxn], tot;

void add(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}
int que[maxn * 3], dis[maxn];
char can_chose[maxn], vis[maxn];
int n, m, s, t, l, r, u, v;

void dfs(int x) {
    if(vis[x - n]) return;
    vis[x - n] = 1;
    for(int i = head[x]; i != -1; i = pre[i]) {
        dfs(to[i]);
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(head, -1, 4 * (2*n+1)), tot = 0;
        memset(dis, -1, 4 * (n+1));
        memset(vis, 0, n+1);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v + n, u + n); // reversed graph
        }
        scanf("%d%d", &s, &t);
        dfs(t + n);
        for(int x = 1; x <= n; x++) {
            can_chose[x] = 1;
            for(int i = head[x]; i != -1; i = pre[i]) {
                if(!vis[to[i]]) {
                    can_chose[x] = 0;
                    break;
                }
            }
        }
        if(!can_chose[s]) {
            puts("-1");
            continue;
        }
        l = r = 0;
        que[r++] = s;
        dis[s] = 0;
        while(l != r) {
            int x = que[l++];
            for(int i = head[x]; i != -1; i = pre[i]) {
                if(can_chose[to[i]] && dis[to[i]] == -1) {
                    dis[to[i]] = dis[x] + 1;
                    que[r++] = to[i];
                    if(r >= maxn * 3) r = 0;
                }
            }
        }
        printf("%d\n", dis[t]);
    }
    return 0;
}
