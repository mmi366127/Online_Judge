#include <bits/stdc++.h>
using namespace std;
struct item {
    int v, w;
    item(int a, int b) :
        v(a), w(b) {}
    bool operator < (const item &a) const {
        return w > a.w;
    }
};


int dp[205][1005] = {};
int n, t, L, v, w;
vector<item> V;


int main() {
    scanf("%d%d%d", &n, &t, &L);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &w, &v);
        V.emplace_back(v, w);
    }
    sort(V.begin(), V.end());
    for(auto tmp : V) {
        w = tmp.w; v = tmp.v;
        for(int i = L; i > 0; i--) {
            for(int k = t; k >= w * i; k--) {
                dp[i][k] = max(dp[i][k], dp[i - 1][k - w * i] + v);
            }
        }
        for(int i = 1; i <= L; i++) {
            for(int k = 1; k <= t; k++) {
                dp[i][k] = max(dp[i][k], dp[i - 1][k]);
            }
        }
    }
    printf("%d\n", dp[L][t]);
}
