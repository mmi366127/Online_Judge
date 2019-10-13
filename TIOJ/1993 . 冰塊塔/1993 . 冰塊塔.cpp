#include <bits/stdc++.h>
#define maxh 100005
#define maxn 1005
using namespace std;

bitset<maxh> dp;
int n, t, h;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &h);
        dp.reset(); dp[0] = 1;
        for(int i = 0; i < n; i++) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            dp = (dp << x) | (dp << y) | (dp << z);
        }
        int ans;
        for(ans = h; ans > 0;  ans--)
            if(dp[ans]) break;
        if(ans == 0) puts("no solution");
        else printf("%d\n", ans);
    }
    return 0;
}
