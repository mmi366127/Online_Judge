#include <stdio.h>
#include <string.h>
#define maxn 1000007

int to[maxn], pre[maxn], head[maxn] = {};
int tot = 1;

void add(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}


int que[maxn], dis[maxn] = {};
int n, m, u, v, w;

int main() {
    scanf("%d%d", &n, &m);
    int idx = n;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        if(w == 1) {
            add(u, v);
        } else {
            add(u, ++idx);
            add(idx, v);
        }
    }
    int l, r;
    l = r = 0;
    dis[1] = 1; que[r++] = 1;
    while(l != r) {
        int x = que[l++];
        if(l >= maxn) l = 0;
        for(int i = head[x]; i; i = pre[i]) {
            if(!dis[to[i]]) {
                dis[to[i]] = dis[x] + 1;
                que[r++] = to[i];
                if(r >= maxn) r = 0;
            }
        }
    }
    printf("%d\n", dis[n] - 1);
    return 0;
}
