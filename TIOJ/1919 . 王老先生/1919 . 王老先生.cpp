#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
struct Item {
    int l, r, val;
    bool operator < (const Item &a) const {
        return l < a.l;
    }
    void set(int L, int R, int v) {
        l = L; r = R; val = v;
    }
};

template<class T> void read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
}


struct BIT {
    int bit[maxn];
    #define lowbit(x) (x & (-x))
    void init() {
        memset(bit, 0, sizeof(bit));
    }
    void add(int x, int v) {
        for(; x < maxn; x += lowbit(x)) {
            bit[x] += v;
        }
    }
    int query(int x) {
        int ret = 0;
        for(; x; x -= lowbit(x)) {
            ret += bit[x];
        }
        return ret;
    }
} bit;

Item Query[maxn], tmp[maxn], cam[maxn];
vector<int> emp[maxn];
int Goal[maxn], nxt[maxn], ans[maxn], cnt[maxn];
int n, m, q;

void solve(int l, int r, vector<int>& Q) {
    if(l == r || Q.empty()) {
        for(int i : Q) {
            ans[i] = l;
        }
        return;
    }
    int i, j, mid = (l + r) >> 1;
    int idx1 = 0, idx2 = 0;
    for(i = max(l, 1LL); i <= mid; i++) {
        cam[idx1++] = Query[i];
    }
    for(int x : Q) {
        for(int y : emp[x]) {
            tmp[idx2++].set(y, nxt[y], x);
        }
        cnt[x] = 0;
    }
    sort(cam, cam + idx1);
    sort(tmp, tmp + idx2);
    for(i = 0, j = 0; i < idx2; i++) {
        while(j < idx1 && cam[j].l <= tmp[i].l) {
            bit.add(cam[j].r, cam[j].val); j++;
        }
        cnt[tmp[i].val] += bit.query(tmp[i].r - 1) - bit.query(tmp[i].l - 1);
    }
    for(j--; j >= 0; j--) {
        bit.add(cam[j].r, -cam[j].val);
    }
    vector<int> ql, qr;
    for(int x : Q) {
        //printf("%d %d %d %d\n", l, mid, x, cnt[x]);
        if(cnt[x] >= Goal[x])
            ql.push_back(x);
        else
            qr.push_back(x), Goal[x] -= cnt[x];
    }
    solve(l, mid, ql);
    solve(mid + 1, r, qr);
}

signed main() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        emp[x].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", Goal + i);
    }
    for(int i = 1; i <= q; i++) {
        int l, r, v;
        scanf("%d%d%d", &l, &r, &v);
        Query[i].set(l, r, v);
    }
    for(int i = 1; i <= n; i++) {
        if(emp[i].empty()) continue;
        for(int j = 0; j < emp[i].size() - 1; j++) {
            nxt[emp[i][j]] = emp[i][j + 1];
        }
        nxt[emp[i][emp[i].size() - 1]] = m + 1;
    }
    bit.init();
    vector<int> Q;
    for(int i = 1; i <= n; i++) Q.push_back(i);
    solve(0, q + 1, Q);
    for(int i = 1; i <= n; i++) {
        if(ans[i] == q + 1) puts("-1");
        else printf("%d\n", ans[i]);
    }
    return 0;
}

