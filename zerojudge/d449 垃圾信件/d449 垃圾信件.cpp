#include <stdio.h>
#define maxn 1000007


#define getchar getchar_unlocked

int rd() {
    static char c; static int ret;
    for(c = getchar(); c < '0'; c = getchar())
        if(c == EOF) return 0;
    for(ret = 0; c >= '0'; c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ '0');
    return ret;
}

int p[maxn], s[maxn];

int find(int x) {
    return (p[x] < 0) ? x : (p[x] = find(p[x]));
}

int join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(s[x] < s[y]) {
        int _ = x;
        x = y;
        y = _;
    }
    p[y] = x;
    s[x] += s[y];
    return 1;
}

int n, m, x, y, k, tot, ans;
int nd[10007];

int main() {
    while((n = rd())) {
        m = rd(); tot = 0;
        for(int i = 0; i < maxn; i++) {
            p[i] = -1; s[i] = 1;
        }
        for(int i = 1; i <= n; i++) {
            nd[i] = tot++;
        }
        ans = n;
        while(m--) {
            k = rd();
            if(k == 1) {
                x = rd(); y = rd();
                if(join(nd[x], nd[y])) ans--;
            } else {
                x = rd();
                y = find(nd[x]);
                if(s[y] > 1) {
                    ans++; s[y]--;
                    nd[x] = tot++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
