#include <stdio.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define maxn 27


int n, W, ans = 0;
int v[maxn], w[maxn];


int main() {
    scanf("%d%d", &n, &W);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", v+i, w+i);
    }
    for(int i = 0; i < (1<<n); i++) {
        int cnt = 0, val = 0;
        for(int j = 0; j < n; j++) {
            if((1<<j) & i) {
                val += w[j];
                cnt += v[j];
            }
        }
        if(val <= W) ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}
