#include <bits/stdc++.h>
#define maxn 1000007
using namespace std;
typedef long long loli;
struct breakfast {
    int v, w;
    bool operator < (const breakfast &a) const {
        return v < a.v;
    }
};

breakfast b[maxn];
int a[maxn];
int n, m;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &b[i].v, &b[i].w);
    }
    sort(a, a + n);
    sort(b, b + m);
    //for(int i = 0; i < n; i++) printf("%d\n", a[i]);
    //for(int i = 0; i < m; i++) printf("%d %d\n", b[i].v, b[i].w);
    bool flag = true;
    loli ans = 0;
    for(int i = 0, j = 0; i < n; i++) {
        while(j < m - 1 && b[j].v < a[i]) j++;
        if(j < m) ans += b[j++].w;
        else {
            flag = false;
            break;
        }
    }
    if(flag) printf("%lld\n", ans);
    else puts("Impossible.");
    return 0;
}
