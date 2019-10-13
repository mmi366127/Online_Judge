#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define all(x) (x).begin(), x.end()
#define rs(x) ((x << 1) | 1)
#define ls(x) (x << 1)
#define maxn 100005
using namespace std;
struct Seg {
    int x, l, r, val;
    Seg(int a, int b, int c, int d) :
        x(a), l(b), r(c), val(d) {}
    bool operator < (const Seg &a) const {
        return (x == a.x) ? val < a.val : x < a.x;
    }
};
struct Node {
    int val, tag;
    Node() :
    val(0), tag(0){}
};

const int INF = 0x3f3f3f3f;


Node SGT[1 << 20];
vector<int> V;
vector<Seg> S;

void pull(int x) {
    SGT[x].val = max(SGT[ls(x)].val, SGT[rs(x)].val);
}

void push(int x) {
    if(SGT[x].tag) {
        SGT[ls(x)].val += SGT[x].tag;
        SGT[rs(x)].val += SGT[x].tag;
        SGT[ls(x)].tag += SGT[x].tag;
        SGT[rs(x)].tag += SGT[x].tag;
        SGT[x].tag = 0;
    }
}

void modify(int x, int L, int R, int l, int r, int val) {
    if(l <= L && R <= r) {
        SGT[x].tag += val;
        SGT[x].val += val;
        return;
    }
    push(x);
    int mid = (L + R) >> 1;
    if(l <= mid)
        modify(ls(x), L, mid, l, r, val);
    if(r > mid)
        modify(rs(x), mid + 1, R, l, r, val);
    pull(x);
}

int query() {
    return SGT[1].val;
}

int get_id(int x) {
    return lower_bound(all(V), x) - V.begin() + 1;
}

int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x1, x2, y1, y2, w;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &w);
        V.emplace_back(y1 - 1); V.emplace_back(y2);
        V.emplace_back(y1); V.emplace_back(y2 + 1);
        S.emplace_back(x1, y1, y2, w);
        S.emplace_back(x2 + 1, y1, y2, -w);
    }
    sort(all(V)); V.erase(unique(all(V)), V.end());
    sort(all(S)); int mx = V.size();
    for(auto t : S) {
        if(t.val > 0) {
            modify(1, 1, mx, get_id(t.l), get_id(t.r), t.val);
        }
    }
    //printf("--->%d\n", query());
    int ans = query(), tmp = 0;
    for(int i = 0; i < S.size(); i++) {
        modify(1, 1, mx, get_id(S[i].l), get_id(S[i].r), -S[i].val);
        tmp += S[i].val;
        ans = max(ans, query() + tmp);
        //printf("-->%d %d %d\n",S[i].x, query(), tmp);
    }
    printf("%d\n", ans);
    return 0;
}
