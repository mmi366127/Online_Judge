#include <bits/stdc++.h>
#define all(X) X.begin(), X.end()
#define pb push_back
#define maxn
typedef long long loli;
using namespace std;

vector<int> d;
vector<pair<int, int>> ll, rr;

int n, l, r, w;


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &l, &r, &w);
        ll.pb({l, 0});
        rr.pb({r, 0});
        d.pb(l);
        d.pb(r);
        d.pb(l-1);
        d.pb(r+1);
    }
    sort(all(d));
    d.erase(unique(all(d)), d.end());
    int ans = 0;

    printf("%d\n", ans);
    return 0;
}
