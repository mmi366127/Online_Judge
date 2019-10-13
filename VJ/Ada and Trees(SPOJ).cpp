#include <bits/stdc++.h>
#define all(X) (X).begin(), (X).end()
#define maxn 300005
using namespace std;
struct Node {
    int l, r, val;
    Node(int v = 0) : val(v) {}
};


vector<Node> ram;


int build(int L = 0, int R = 1e6) {
    int x = ram.size();
    ram.emplace_back();
    if(L == R) {
        return x;
    }
    int mid = (L + R) >> 1;
    ram[x].l = build(L, mid);
    ram[x].r = build(mid + 1, R);
    return x;
}

int modify(int x, int L, int R, int pos) {
    int _x = ram.size();
    ram.emplace_back(ram[x].val + 1);
    if(L == R) {
        return _x;
    }
    int mid = (L + R) >> 1;
    if(pos <= mid) {
        ram[_x].l = modify(ram[x].l, L, mid, pos);
        ram[_x].r = ram[x].r;
    } else {
        ram[_x].l = ram[x].l;
        ram[_x].r = modify(ram[x].r, mid + 1, R, pos);
    }
    return _x;
}

int query(int a, int b, int L, int R, int h) {
    if(L == R) {
        return L;
    }
    int mid = (L + R) >> 1;
    int ret = 0;
    if(h > mid && ram[ram[b].r].val - ram[ram[a].r].val > 0) {
        ret = query(ram[a].r, ram[b].r, mid + 1, R, h);
        if(ret) return ret;
    }
    if(ram[ram[b].l].val - ram[ram[a].l].val == 0) return 0;
    return query(ram[a].l, ram[b].l, L, mid, h);
}

int tree[maxn];
int n, m;

int main() {
    ram.reserve(10000000);
    scanf("%d%d", &n, &m);
    tree[0] = build();
    for(int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        tree[i] = modify(tree[i - 1], 0, 1e6, x);
    }
    for(int i = 0; i < m; i++) {
        int l, r, h;
        scanf("%d%d%d", &l, &r, &h); l++, r++;
        printf("%d\n", query(tree[l - 1], tree[r], 0, 1e6, h));
    }
    return 0;
}
