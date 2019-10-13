#include <stdio.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define maxn 10000005

int next[maxn], prev[maxn], P[maxn];

const int INF = 0x3f3f3f3f;

void reisei(int *p, int n, unsigned int a, unsigned int c, unsigned int m){
    for(int i=1; i<=n; i++) p[i] = i;
    unsigned int x = 0;
    for(int i=1; i<=n-1; i++){
        x = ((unsigned long long)a*x+c)%m;
        int j = i + x%(n-i+1);
        int t = p[i]; p[i] = p[j]; p[j] = t;
    }
}

unsigned int n, a, c, m;

int main() {
    while(~scanf("%u%u%u%u", &n, &a, &c, &m)) {
        reisei(P, n, a, c, m);
        for(int i = 2; i < n; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        prev[1] = -INF;
        next[1] = 2;
        next[n] = INF;
        prev[n] = n - 1;
        int ans = 0;
        /*for(int i = 1; i <= n; i++)
            printf("%d%c", P[i], " \n"[i == n]);*/
        for(int i = n; i > 1; i--) {
            ans ^= (min(P[i] - prev[P[i]], next[P[i]] - P[i]) + i);
            //printf("%d %d\n", P[i] - prev[P[i]], next[P[i]] - P[i]);
            if(next[P[i]] != INF)
                prev[next[P[i]]] = prev[P[i]];
            if(prev[P[i]] != -INF)
                next[prev[P[i]]] = next[P[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}
