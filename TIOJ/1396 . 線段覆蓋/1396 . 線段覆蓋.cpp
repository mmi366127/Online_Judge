#include <bits/stdc++.h>
#define all(X) X.begin(), X.end()
#define maxn 100007
typedef long long loli;
using namespace std;
struct SG {
    int l, r;
    bool operator < (const SG &a) const {
        return a.l == l ? r > a.r : l < a.l;
    }
};


SG SGA[maxn], SGB[maxn];
int n, m, l, r;

int solve(SG a[], int n, int l, int r) {
    if(l == r) {
        for(int i = 0; i < n; i++) {
            if(a[i].l <= l && l <= a[i].r) return 1;
        }
        return -1;
    }
    sort(a, a + n);
    int ret = 0, i = 0;
    while(l < r) {
        int tmp = -2147483648;
        while(i < n && a[i].l <= l) {
            tmp = max(tmp, a[i].r);
            i++;
        }
        if(tmp <= l) return -1;
        ret++;
        l = tmp;
    }
    return ret;
}


int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &SGA[i].l, &SGA[i].r);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &SGB[i].l, &SGB[i].r);
        }
        scanf("%d%d", &l, &r);
        int a = solve(SGA, n, l, r);
        int b = solve(SGB, m, l, r);
        if(a == -1 && b == -1) puts("TIE");
        else if((a <= b && a != -1) || b == -1) puts("A WIN");
        else puts("B WIN");
    }
    return 0;
}

