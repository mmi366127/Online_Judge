#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define maxn 50
using namespace std;
typedef long long int loli;
const loli INF = 0x3f3f3f3f3f3f3f3f;

loli n, W, a, b;
loli va[maxn], wa[maxn];
loli vb[maxn], wb[maxn];
pair<loli, loli> V[(1<<21)];


int main() {
    scanf("%lld%lld", &n, &W);
    a = n >> 1;
    b = n - a;
    for(int i = 0; i < a; i++) {
        scanf("%lld%lld", va+i, wa+i);
    }
    for(int i = 0; i < b; i++) {
        scanf("%lld%lld", vb+i, wb+i);
    }
    for(int i = 0; i < (1 << a); i++) {
        loli vv = 0, ww = 0;
        for(int j = 0; j < a; j++) {
            if((i >> j) & 1) {
                vv += va[j];
                ww += wa[j];
            }
        }
        V[i] = {ww, vv};
    }
    sort(V, V + (1 << a));
    int m = 1;
    for(int i = 1; i < (1 << a); i++) {
        if(V[m-1].second < V[i].second)
            V[m++] = V[i];
    }
    loli ans = 0;
    for(int i = 0; i < (1 << b); i++) {
        loli vv = 0, ww = 0;
        for(int j = 0; j < b; j++) {
            if((i >> j) & 1) {
                vv += vb[j];
                ww += wb[j];
            }
        }
        if(ww <= W) {
            loli tmp = (lower_bound(V, V + m, (pair<loli,loli>){W - ww, INF}) - 1) -> second;
            ans = max(ans, vv + tmp);
        }
    }
    printf("%lld\n", ans);
    return 0;
}

