#include <bits/stdc++.h>
#define maxn 500005
#define maxc 1000005
using namespace std;
typedef long long loli;


pair<int, int> Circle[maxn];
loli bit[maxc] = {};
vector<int> V;
loli n;


void add(int x) {
    for(; x < maxc; x += x & (-x)) {
        bit[x]++;
    }
}

loli query(int x) {
    loli ret = 0;
    for(; x; x -= x & (-x)) {
        ret += bit[x];
    }
    return ret;
}

int get_id(int x) {
    return lower_bound(V.begin(), V.end(), x) - V.begin() + 1;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, r; scanf("%d%d", &x, &r);
        Circle[i].first = x - r;
        Circle[i].second = x + r;
        V.push_back(x - r);
        V.push_back(x + r);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    sort(Circle, Circle + n);
    loli cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += query(get_id(Circle[i].second)) - query(get_id(Circle[i].first) - 1);
        add(get_id(Circle[i].second));
    }
    printf("%lld\n", (n * (n - 1) / 2) - cnt);
    return 0;
}
