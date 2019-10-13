#include <bits/stdc++.h>
#define lowbit(X) (X&(-X))
#define maxn 800005
using namespace std;

int bit[maxn] = {};
int n;

void add(int x, int val) {
    while(x <= n) {
        bit[x] += val;
        x += lowbit(x);
    }
}

void add(int l, int r, int val) {
    add(l, val); add(r + 1, -val);
}

int query(int x) {
    int ret = 0;
    for(; x; x -= lowbit(x)) {
        ret += bit[x];
    }
    return ret;
}

set<int> st;

int main() {
    scanf("%d", &n);
    st.insert(n);
    int l, r, cur, pre, val, tmp;
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &l, &r); ++l, ++r;
        st.insert(l - 1);
        auto it = st.lower_bound(r);
        add(l, *it, 1);
        val = query(*it);
        for(; it != prev(st.end());) {
            tmp = query(*it + 1);
            if(tmp > val) break;
            add(*it + 1, *next(it), val - tmp);
            it++; st.erase(prev(it));
        }
    }
    printf("%d\n", query(n));
    return 0;
}
