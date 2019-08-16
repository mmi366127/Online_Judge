#include <bits/stdc++.h>
typedef long long int loli;
using namespace std;
struct item {
    loli val, M;
    item(loli m, loli v) : val(v), M(m) {}
    bool operator < (const item &a) const {
        return M == a.M ? val < a.val : M > a.M;
    }
};

priority_queue<item> pq;
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    while(pq.size()) pq.pop();
    for(int i = 0; i < n; i++) {
        loli a, b;
        scanf("%lld%lld", &a, &b);
        pq.push(item(a, b));
    }
    loli ans = 0;
    while(pq.size() > 1 && pq.top().M < m) {
        item a = pq.top(); pq.pop();
        item b = pq.top(); pq.pop();
        if(a.M != b.M) {
            if(a.M <= m) {
                ans = max(a.val, ans);
            }
            if(b.M <= m) {
                ans = max(b.val, ans);
            }
            a.M = b.M;
            pq.push(a);
            pq.push(b);
        } else {
            pq.push(item(a.M + 1, a.val + b.val));
        }
    }
    if(pq.top().M <= m) ans = pq.top().val;
    printf("%lld\n", ans);
    return 0;
}
