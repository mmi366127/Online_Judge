#include <stdio.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define maxm 200007
#define maxn 100007

typedef struct Edge {
    int to, pre, w;
}Edge;


Edge edge[maxm];
int head[maxn], tot;

void add(int u, int v, int w) {
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].pre = head[u];
    head[u] = tot++;
}

int dis[maxn], que[maxn];
char inq[maxn];


void spfa(int s, int t) {
    memset(dis, -0x3f, sizeof(dis));
    memset(inq, 0, sizeof(inq));
    int start = 0, rear = 0;
    que[rear++] = s;
    inq[s] = 1; dis[s] = 0;
    while(start != rear) {
        int x = que[start++];
        inq[x] = 0;
        if(start >= maxn) start = 0;
        for(int i = head[x]; i != -1; i = edge[i].pre) {
            int y = edge[i].to;
            if(dis[y] < dis[x] + edge[i].w) {
                dis[y] = dis[x] + edge[i].w;
                if(!inq[y]) {
                    que[rear++] = y;
                    if(rear >= maxn) rear = 0;
                    inq[y] = 1;
                }
            }
        }
    }
}

int n, s, t, u, v, w;

int main() {
    scanf("%d", &n);
    s = 0, t = 0;
    memset(head, -1, sizeof(head));
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u - 1, v, w);
        t = max(v, t);
    }
    for(int i = 0; i < t; i++) {
        add(i, i+1, 0);
        add(i+1, i, -1);
    }
    spfa(s, t);
    printf("%d\n", dis[t]);
    return 0;
}
