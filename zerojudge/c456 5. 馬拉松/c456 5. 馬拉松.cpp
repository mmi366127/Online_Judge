#include <stdio.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)
#define true 1
#define false 0
#define maxn 5007
#define maxm 25000007

const int INF = (1 << 25);

// input

#define getchar getchar_unlocked

int rd() {
	static char c; int ret;
	for(c = getchar(); c < '0'; c = getchar());
	for(ret = 0; c >= '0'; c = getchar()) {
		ret = (ret << 3) + (ret << 1) + (c ^ '0');
	}
	return ret;
}


// Graph

int head[maxn], to[maxm], pre[maxm], tot = 0;

void add(int u, int v) {
    to[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}

// disjoint set

int s[maxn], p[maxn];

int find(int x) {
    return (p[x] < 0) ? x : (p[x] = find(p[x]));
}

int join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return s[x];
    if(s[x] < s[y]) {
        int _ = x;
        x = y;
        y = _;
    }
    s[x] += s[y];
    p[y] = x;
    return s[x];
}

// queue

int l = 0, r = 0;
int que[maxn + maxn];


// solving

int nd[maxn + maxn], deg[maxn + maxn], sz = 0;
int d[maxn] = {};
int n, m, u, v;


int main() {
	n = rd(); m = rd();
    memset(head, -1, sizeof(head));
    for(int i = 0; i < m; i++) {
    	u = rd(); v = rd();
        add(u, v); add(v, u);
        d[u]++; d[v]++;
    }
    while(true) {
        int k = INF;
        for(int i = 1; i <= n; i++) {
            if(d[i] > 0) {
                k = min(k, d[i]);
            }
        }
        if(k >= INF) break;
        l = r = 0;
        for(int i = 1; i <= n; i++) {
            if(d[i] == k) {
                que[r++] = i; d[i] = -1;
            }
        }
        while(l != r) {
            int x = que[l++];
            nd[sz] = x;
            deg[sz] = k;
            sz++;
            for(int i = head[x]; i != -1; i = pre[i]) {
                if(d[to[i]] > 0 && --d[to[i]] <= k) {
                	que[r++] = to[i]; d[to[i]] = -1;
				}
            }
        }
    }
    for(int i = 1; i <= n; i++)
    p[i] = -1, s[i] = 1; // reset disjoint set
    int ans = 0;
    for(int i = sz - 1; i >= 0; i--) {
        int x = nd[i]; d[x] = 1; // add nodes back
        for(int j = head[x]; j != -1; j = pre[j]) {
            if(d[to[j]] > 0) ans = max(ans, deg[i] * join(to[j], x));
        }
    }
    printf("%d\n", ans);
    return 0;
}
