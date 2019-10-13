#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define maxn 1005
using namespace std;
typedef long long loli;
struct Item {
    loli w, s, l;
    Item(loli a, loli b, loli c) :
        w(a), s(b), l(c) {}
    bool operator < (const Item &a) const {
         return l == a.l ? s < a.s : l < a.l;
    }
};

const int INF = 0x3f3f3f3f3f3f3f3f;

vector<Item> V;
loli dp[maxn];
int n, t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n); V.clear();
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < n; i++) {
            loli w, s, l;
            scanf("%lld%lld%lld", &w, &s, &l);
            if(s >= w) {
                V.emplace_back(w, s, l);
            }
        }
        sort(begin(V), end(V)); dp[0] = 0;
        for(int i = 0; i < V.size(); i++) {
            for(int j = V.size(); j > 0; j--) {
                if(dp[j - 1] + V[i].w <= V[i].s) {
                    dp[j] = min(dp[j], dp[j - 1] + V[i].w);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= V.size(); i++) {
            if(dp[i] < INF)
                ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
