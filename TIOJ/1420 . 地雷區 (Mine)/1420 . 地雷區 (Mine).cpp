#include <bits/stdc++.h>
#define maxn 50007
using namespace std;
typedef long long loli;
struct pnt {
    int x, y;
    bool operator < (const pnt &a) const {
        return a.x == x ? y < a.y : x < a.x;
    }
};

char vis[maxn];
pnt a[maxn];
int t, n;

void dfs(int u) {
    vis[u] = 1;
    int x = a[u].x;
    int y = a[u].y;
    int l, r;
    l = lower_bound(a, a + n, (pnt){x - 2, y - 2}) - a;
    r = upper_bound(a, a + n, (pnt){x + 2, y + 2}) - a;
    if(r - l > 1) {
        for(; l < r; l++) {
            if(!vis[l] && a[l].y >= y - 2 && a[l].y <= y + 2) {
                dfs(l);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &t, &t, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    memset(vis, 0, sizeof(vis));
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
