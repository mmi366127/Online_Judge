#include <stdio.h>
#include <string.h>
#define min(a, b) (a) < (b) ? (a) : (b)
#define maxn 1007
#define maxm 1000000


int GCD(int a, int b) {
    if(!a || !b) return 0;
    while((a %= b) && (b %= a));
    return a + b;
}


int pre[maxm], to[maxm], head[maxn], tot;

void add(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}

int low[maxn], vis[maxn];
int cnt, t;

void dfs(int x, int p) {
    low[x] = vis[x] = ++t;
    int ch = 0,  flag = 0;
    for(int i = head[x]; i != -1; i = pre[i]) {
        int y = to[i];
        if(!vis[y]) {
            ch++;
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if(low[y] >= vis[x]) flag = 1;
        } else if(y != p) low[x] = min(low[x], vis[y]);
    }
    if((p == -1 && ch > 1) || (p != -1 && flag)) cnt++;
}

int n, T, A[maxn];

int main() {
    scanf("%d", &T);
    while(T--) {
        t = cnt = tot = 0;
        scanf("%d", &n);
        memset(vis, 0, 4 * n);
        memset(low, 0, 4 * n);
        memset(head, -1, 4 * n);
        for(int i = 0; i < n; i++) {
            scanf("%d", A + i);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(GCD(A[i], A[j]) > 1) {
                    add(i, j);
                    add(j, i);
                }
            }
        }
        for(int i = 0; i < n; i++)
            if(!vis[i]) dfs(i, -1);
        printf("%d\n", cnt);
    }
    return 0;
}
