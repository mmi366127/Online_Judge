#include <bits/stdc++.h>
using namespace std;


int n, m, l, r;
vector< pair<int, int> > V;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        V.emplace_back(l, r);
    }
    V.emplace_back(1e9, 1e9);
    sort(V.begin(), V.end());
    int ans = 0;
    l = V[0].first; r = V[0].second;
    for(auto t : V) {
        if(t.first <= r) {
            r = max(r, t.second);
        } else {
            ans += r - l + 1;
            l = t.first; r = t.second;
        }
    }
    printf("%d\n", n - ans + 1);
    return 0;
}
