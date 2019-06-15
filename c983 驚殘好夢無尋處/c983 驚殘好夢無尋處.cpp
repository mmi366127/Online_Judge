#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 1007
#define INF 0x3f3f3f3f
typedef struct Edge {
    int to, pre, cap, w;
}Edge;
typedef struct clock {
    int t, p;
}clock;

int tot, front, end, n, m, k, t;
clock tmp[maxn], time[maxn];
Edge edge[maxn<<2];
char inq[maxn];
int Q[maxn], head[maxn], dis[maxn], pre[maxn], pe[maxn];

int min(int a, int b) {
    return a < b ? a : b;
}

void add(int u, int v, int f, int w) {
    edge[tot].to = v;
    edge[tot].pre = head[u];
    edge[tot].cap = f;
    edge[tot].w = w;
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].pre = head[v];
    edge[tot].cap = 0;
    edge[tot].w = -w;
    head[v] = tot++;
}

int lower_bound(int L, int R, int k) {
    R++;
    while(R - L > 1) {
        int mid = (L + R)>>1;
        if(time[mid].t < k) {
            L = mid;
        } else {
            R = mid;
        }
    }
    return R;
}

void sort(clock a[], int L, int R) {
    if(L >= R) return;
    int mid = (L + R)>>1;
    int idx1 = L;
    int idx2 = mid + 1;
    int idx = L;
    sort(a, idx1, mid);
    sort(a, idx2, R);
    while(idx1 <= mid && idx2 <= R) {
        if(a[idx1].t < a[idx2].t) {
            tmp[idx++] = a[idx1++];
        } else {
            tmp[idx++] = a[idx2++];
        }
    }
    while(idx1 <= mid) {
        tmp[idx++] = a[idx1++];
    }
    while(idx2 <= R) {
        tmp[idx++] = a[idx2++];
    }
    for(idx = L; idx <= R; idx++) {
        a[idx] = tmp[idx];
    }
}

char spfa(int s, int t) {
    memset(inq, 0, sizeof(inq));
    memset(dis, 0x3f, sizeof(dis));
    memset(pre, -1, sizeof(pre));
    memset(pe, -1, sizeof(pe));
    dis[s] = front = end = 0;
    Q[end++] = s; inq[s] = 1;
    while(front != end) {
        int x = Q[front++]; inq[x] = 0;
        if(front >= maxn) front = 0;
        for(int i = head[x]; i != -1; i = edge[i].pre) {
            int y = edge[i].to;
            if(edge[i].cap > 0 && dis[y] > dis[x] + edge[i].w) {
                pre[y] = x;
                pe[y] = i;
                dis[y] = dis[x] + edge[i].w;
                if(!inq[y]) {
                    Q[end++] = y;
                    inq[y] = 1;
                    if(end >= maxn) end = 0;
                }
            }
        }
    }
    return dis[t] != INF;
}

int solve(int s, int t) {
    int f, ans = 0, flow = 0;
    while(spfa(s, t)) {
        int p = t;
        f = INF;
        ans += dis[t];
        while(p != s) {
            f = min(f, edge[pe[p]].cap);
            p = pre[p];
        }
        flow += f;
        p = t;
        while(p != s) {
            edge[pe[p]].cap -= f;
            edge[pe[p]^1].cap += f;
            p = pre[p];
        }
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        tot = 0; int sum = 0;
        memset(head, -1, sizeof(head));
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &time[i].t);
        }
        for(int i = 1; i <= n; i++) {
            scanf("%d", &time[i].p);
            sum += time[i].p;
        }
        sort(time, 1, n);
        for(int i = 1; i < n; i++) {
            add(i, i+1, INF, 0);
        }
        add(0, 1, k - 1, 0);
        add(n, n+1, k - 1, 0);
        for(int i = 1; i <= n; i++) {
            int k = lower_bound(1, n, time[i].t + m);
            add(i, k, 1, -time[i].p);
        }
        printf("%d\n", sum + solve(0, n+1));
    }
    return 0;
}
