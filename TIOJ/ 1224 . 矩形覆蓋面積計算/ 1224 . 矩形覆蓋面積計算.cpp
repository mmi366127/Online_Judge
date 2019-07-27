#include <bits/stdc++.h>
#define ls(X) (X << 1)
#define rs(X) ((X << 1) | 1)
using namespace std;
struct Edge {
    int x, a, b;
    char val;
    Edge(int X, int A, int B, int V) {
        x = X; a = A; b = B; val = V;
    }
    bool operator < (const Edge &a) const {
        return x < a.x;
    }
};
struct SGT {
    struct Node {
        int len, tag;
    };
    vector<Node> ST;
    SGT() {
        ST.resize(1 << 21);
    }
    void modify(int l, int r, int val, int x = 1, int L = 0, int R = (int)1e6) {
        if(l <= L && R <= r) {
            ST[x].tag += val;
        } else {
            int mid = (L + R) >> 1;
            if(l <= mid) {
                modify(l, r, val, (x << 1), L, mid);
            }
            if(mid < r) {
                modify(l, r, val, (x << 1) | 1, mid + 1, R);
            }
        }
        if(ST[x].tag) {
            ST[x].len = R - L + 1;
        } else {
            if(L == R) ST[x].len = 0;
            else ST[x].len = ST[ls(x)].len + ST[rs(x)].len;
        }
        return;
    }
    int query() {
        return ST[1].len;
    }
};

int n, L, R, D, U;
vector<Edge> v;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &L, &R, &D, &U);
        v.push_back(Edge(L, D, U - 1, 1));
        v.push_back(Edge(R, D, U - 1, -1));
    }
    sort(v.begin(), v.end());
    long long ans = 0, pre = 0;
    SGT cute;
    for(int i = 0; i < v.size(); i++) {
        ans = ans + (v[i].x - pre) * cute.query();
        cute.modify(v[i].a, v[i].b, v[i].val);
        pre = v[i].x;
    }
    printf("%lld\n", ans);
    return 0;
}
