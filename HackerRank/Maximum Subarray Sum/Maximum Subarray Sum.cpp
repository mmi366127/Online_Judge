#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long loli;

set<loli> st;


loli P[maxn];
loli n, m;
int t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &n, &m);
        P[0] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%lld", P + i);
            P[i] = (P[i] + P[i - 1]) % m;
        }
        st.clear(); st.insert(0);
        loli ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, P[i]);
            auto it = st.upper_bound(P[i]);
            if(it != st.end()) {
                ans = max(ans, P[i] - *it + m);
            }
            st.insert(P[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
