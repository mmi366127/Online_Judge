#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
struct Edge {
    int to, w, pre;
};

#define getchar getchar_unlocked
#define putchar putchar_unlocked

bool read(int &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
    return (x > 0);
}

Edge edge[maxn << 1];
int head[maxn], tot;

void add(int u, int v, int w) {
    edge[tot].w = w;
    edge[tot].to = v;
    edge[tot].pre = head[u];
    head[u] = tot++;
}

int n, u, v, w, ans;

int dfs(int x, int p) {
    int tmp, fst = 0, snd = 0;
    for(int i = head[x]; i != -1; i = edge[i].pre) {
        if(edge[i].to == p) continue;
        tmp = dfs(edge[i].to, x) + edge[i].w;
        if(tmp > fst) {
            snd = fst;
            fst = tmp;
        } else if(tmp > snd) {
            snd = tmp;
        }
    }
    ans = max(ans, fst + snd);
    return fst;
}


int main() {
    while(read(n)) {
        tot = 0; memset(head, -1, sizeof(int) * (n + 1));
        for(int i = 1; i < n; i++) {
            read(u), read(v), read(w);
            add(u, v, w); add(v, u, w);
        }
        ans = 0;
        dfs(1, -1);
        printf("%d\n", ans);
    }
    return 0;
}
