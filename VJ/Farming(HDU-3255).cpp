#include <bits/stdc++.h>
#define maxn (1 << 21)
using namespace std;
typedef long long loli;

const int INF = 0x3f3f3f3f;

struct SGT {
    int val[maxn * 2], cnt[maxn * 2];
    #define ls(x) (x << 1)
    #define rs(x) (x << 1 | 1)
    void clear() {
        memset(val, 0, sizeof(val));
        memset(cnt, 0, sizeof(cnt));
    }
    void pull(int x, int l, int r) {
        if(cnt[x]) {
            val[x] = r - l + 1;
            return;
        }
        val[x] = (l == r) ? 0 : (val[ls(x)] + val[rs(x)]);
    }
    void add(int l, int r, int x = 1, int L = -1e6 - 5, int R = 1e6 + 5) {
        if(l <= L && R <= r) {
            cnt[x]++;
            pull(x, L, R);
            return;
        }
        int mid = (L + R) >> 1;
        if(l <= mid)
            add(l, r, ls(x), L, mid);
        if(r > mid)
            add(l, r, rs(x), mid + 1, R);

        pull(x, L, R);
    }
    void kill(int l, int r, int x = 1, int L = -1e6 - 5, int R = 1e6 + 5) {
        if(l <= L && R <= r) {
            cnt[x]--;
            pull(x, L, R);
            return;
        }
        int mid = (L + R) >> 1;
        if(l <= mid)
            kill(l, r, ls(x), L, mid);
        if(r > mid)
            kill(l, r, rs(x), mid + 1, R);
        pull(x, L, R);
    }
    long long query() {
        return val[1];
    }
}Tree;

struct seg {
    int x, l, r, p;
    bool operator < (const seg &a) const {
        return x < a.x;
    }
    seg(int a, int b, int c, int d) :
        x(a), l(b), r(c), p(d) {}
};

int value[5], p[5];
vector<seg> V;
int n, m, t, kase = 0;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++) {
            scanf("%d", value + i);
            p[i] = value[i];
        }
        value[0] = 0; V.clear();
        sort(value + 1, value + m + 1);
        for(int i = 0; i < n; i++) {
            int x1, x2, y1, y2, type;
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &type);
            V.emplace_back(x1, y1 + 1, y2,  p[type]);
            V.emplace_back(x2, y1 + 1, y2, -p[type]);
        }
        sort(V.begin(), V.end());
        long long ans = 0;
        for(int i = 1; i <= m; i++) {
            Tree.clear();
            long long pre = -INF, ans_ = 0;
            for(auto t : V) {
                if(abs(t.p) < value[i]) continue;
                ans_ = ans_ + ((long long)t.x - pre) * Tree.query();
                if(t.p > 0)
                    Tree.add(t.l, t.r);
                else
                    Tree.kill(t.l, t.r);
                pre = t.x;
            }
            ans  = ans + ans_ * (value[i] - value[i - 1]);
        }
        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}
