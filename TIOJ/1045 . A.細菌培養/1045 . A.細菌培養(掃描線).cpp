#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long loli;
struct Pt {
    int x, b, t, v;
    Pt(int a, int B, int c, int d) :
        x(a), b(B), t(c), v(d) {}
    bool operator < (const Pt &a) const {
        return x < a.x;
    }
};

struct Segment_Tree {
    loli tag[1 << 15], val[1 << 15];
    const static int maxn = 10000;

    #define ls(X) (X << 1)
    #define rs(X) ((X << 1) | 1)

    void pull(int x) {
        val[x] = val[ls(x)] + val[rs(x)];
    }
    void push(int x) {
        if(tag[x]) {
            tag[ls(x)] += tag[x];
            tag[rs(x)] += tag[x];
            if(tag[x] > 0) {
                val[ls(x)] <<= tag[x];
                val[rs(x)] <<= tag[x];
            } else {
                val[ls(x)] >>= -tag[x];
                val[rs(x)] >>= -tag[x];
            }
            tag[x] = 0;
        }
    }
    void build(int x = 1, int L = 1, int R = maxn) {
        tag[x] = 0;
        if(L == R) {
            val[x] = 1;
            return;
        }
        int M = (L + R) >> 1;
        build(ls(x), L, M);
        build(rs(x), M + 1, R);
        pull(x);
    }
    void modify(int l, int r, int v, int L = 1, int R = maxn, int x = 1) {
        if(l <= L && R <= r) {
            if(v < 0) {
                val[x] >>= -v;
            } else {
                val[x] <<= v;
            }
            tag[x] += v;
            return;
        }
        push(x);
        int M = (L + R) >> 1;
        if(l <= M)
            modify(l, r, v, L, M, ls(x));
        if(M < r)
            modify(l, r, v, M + 1, R, rs(x));
        pull(x);
    }
    loli query() {
        return val[1];
    }
} cute;


vector<Pt> V;
int n;


int main() {
    while(~scanf("%d", &n) && n) {
        cute.build(); V.clear();
        for(int i = 0; i < n; i++) {
            int l, r, b, t;
            scanf("%d%d%d%d", &l, &b, &r, &t);
            V.emplace_back(l + 1, b + 1, t, 1);
            V.emplace_back(r + 1, b + 1, t, -1);
        }
        V.emplace_back(10001, 1, 10000, 0);
        sort(V.begin(), V.end());
        int pre = 1;
        loli ans = 0;
        for(Pt t : V) {
            ans += cute.query() * (t.x - pre);
            cute.modify(t.b, t.t, t.v);
            pre = t.x;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
