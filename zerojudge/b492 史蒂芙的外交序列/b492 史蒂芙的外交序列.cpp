#include <bits/stdc++.h>
#define maxn 50007
using namespace std;
typedef long long loli;
struct Node {
    loli val;
    int l, r, cnt;
};


const loli mod = 1000000007;

Node ram[maxn * 20];
int tot;

loli power(loli a, int n) {
    loli ret = 1;
    while(n) {
        if(n & 1) {
            ret = (ret * a) % mod;
        }
        n >>= 1;
        a = (a * a) % mod;;
    }
    return ret;
}


int a[maxn], root[maxn];

void pull(int x) {
    ram[x].val = (ram[ram[x].l].val * ram[ram[x].r].val) % mod;
    ram[x].cnt = (ram[ram[x].l].cnt + ram[ram[x].r].cnt);
}

int build(int l, int r) {
    int x = tot++;
    if(l == r) {
        ram[x].val = 1;
        ram[x].cnt = 0;
        return x;
    }
    int mid = (l + r) >> 1;
    ram[x].l = build(l , mid);
    ram[x].r = build(mid +1, r);
    pull(x);
    return x;
}

int update(int x, int l, int r, loli pos) {
    int _x = tot++;
    if(l == r) {
        ram[_x].val = ram[x].val * pos % mod;
        ram[_x].cnt = ram[x].cnt + 1;
        return _x;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) {
        ram[_x].l = update(ram[x].l, l, mid, pos);
        ram[_x].r = ram[x].r;
    } else {
        ram[_x].l = ram[x].l;
        ram[_x].r = update(ram[x].r, mid + 1, r, pos);
    }
    pull(_x);
    return _x;
}

pair<loli,loli> query(int x, int L, int R, int l, int r) {
    if(r < L || R < l) return {1, 0};
    else if(l <= L && R <= r) return {ram[x].val, ram[x].cnt};
    int mid = (L + R) >> 1;
    pair<loli,loli> a, b;
    a = query(ram[x].l, L, mid, l, r);
    b = query(ram[x].r, mid+1, R, l, r);
    return {a.first * b.first % mod, a.second + b.second};
}

int n, m, l, r, k;

int main() {
    while(~scanf("%d%d", &n, &m)) {
        tot = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        root[0] = build(1, n);
        for(int i = 1; i <= n; i++) {
            root[i] = update(root[i - 1], 1, n, a[i]);
        }
        pair<loli,loli> a, b;
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &l, &r, &k);
            a = query(root[r], 1, n, 1, k);
            b = query(root[l - 1], 1, n, 1, k);
            if(a.second - b.second == 0) puts("0 0");
            else printf("%lld %lld\n", a.second - b.second, a.first * power(b.first, mod - 2) % mod);
        }
    }
    return 0;
}
