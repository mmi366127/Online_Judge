#include <stdio.h>
#include <string.h>
#define min(a, b) (a) < (b) ? (a) : (b)
#define swap(a, b) {int _ = a; a = b; b = _;}
#define maxn 305

const int INF = (1 << 20);

int to[maxn+maxn], pre[maxn+maxn], head[maxn], tot = 0;

void add(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}

int par[maxn], lay[maxn][maxn];
int n, m, u, v, ans;

void build(int x, int p) {
    par[x] = p;
    for(int i = head[x]; i != -1; i = pre[i]) {
        if(to[i] != p) {
            build(to[i], x);
        }
    }
}

void dfs(int P[], int cnt, int sum) {
    if(sum + cnt >= ans) return;
    sum += cnt;
    int NEXT[maxn], CNT = 0;
    for(int i = 0; i < cnt; i++) {
        int x = P[i];
        for(int k = head[x]; k != -1; k = pre[k]) {
            if(to[k] != par[x]) NEXT[CNT++] = to[k];
        }
    }
    if(CNT < 2) {
        ans = min(sum, ans);
        return;
    }
    for(int i = 0; i < CNT; i++) {
        swap(NEXT[i], NEXT[CNT-1]);
        dfs(NEXT, CNT-1, sum);
        swap(NEXT[i], NEXT[CNT-1]);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    build(1, -1);
    ans = INF;
    int P[maxn];
    P[0] = 1;
    dfs(P, 1, 0);
    printf("%d\n", ans);
    return 0;
}
