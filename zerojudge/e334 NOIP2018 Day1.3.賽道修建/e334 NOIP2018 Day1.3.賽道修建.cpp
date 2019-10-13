#include <bits/stdc++.h>
#define maxn 50005
#define X first
#define Y second
using namespace std;

vector< pair<int, int> > G[maxn];
int n, m, cnt, val;
multiset<int> st;
int num[maxn];

void dfs(int x, int p) {
    for(auto y : G[x])
        if(y.X != p) dfs(y.X, x);
    for(auto y : G[x])
        if(y.X != p) st.insert(y.Y + num[y.X]);
    while(st.size()) {
        int ed = *st.rbegin();
        if(ed < val) break;
        st.erase(st.find(ed)); cnt++;
    }
    num[x] = 0;
    while(st.size()) {
        int tmp = *st.begin(); st.erase(st.begin());
        auto it = st.lower_bound(val - tmp);
        if(it == st.end()) num[x] = tmp;
        else st.erase(it), cnt++;
    }
    st.clear();
}

bool check(int x) {
    cnt = 0; val = x;
    dfs(1, -1);
    return cnt >= m;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    int l = 0, r = 1e9;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", l);
    return 0;
}
