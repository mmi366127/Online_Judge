#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> s, p;
    DSU(int n) : s(n + 1, 1), p(n + 1, -1) {}
    int find(int x) {
        return (p[x] < 0) ? x : (p[x] = find(p[x]));
    }
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y)
            return false;
        if(s[x] < s[y])
            swap(x, y);
        p[y] = x;
        s[x] += s[y];
        return true;
    }
};

int t, n, m, cost_road, cost_lib, x, y;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &m, &cost_lib, &cost_road);
        long long ans, num = (long long)n * cost_lib;
        ans = num; DSU cute(n);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            if(cute.join(x, y)) {
                num = num - cost_lib;
                num = num + cost_road;
            }
            ans = min(ans, num);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
