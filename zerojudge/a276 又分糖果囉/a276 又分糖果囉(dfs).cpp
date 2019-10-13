#include <stdio.h>
#include <string.h>
#define maxn 30
#define min(a, b) (a) < (b) ? (a) : (b)
#define abs(X) (X) < 0 ? -(X) : (X)

int a[maxn];
int n, ans;

void dfs(int dep, int val) {
    if(dep == n) {
        ans = min(ans, abs(val));
        return;
    }
    dfs(dep+1, val + a[dep]);
    dfs(dep+1, val - a[dep]);
}


int main() {
    while(~scanf("%d", &n)) {
        ans = (int)1e9;
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
