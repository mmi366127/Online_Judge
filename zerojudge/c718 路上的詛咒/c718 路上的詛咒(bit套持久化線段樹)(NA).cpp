#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long loli;
struct Road {
    int to, h, v, id;
    Road(int a, int b, int c, int d) :
        to(a), h(b), v(c), id(d) {}
};
struct Node {
    int l, r;
    loli val;
    Node(int a = 0, int b = 0, loli v = 0) :
        l(a), r(b), val(v) {}
};

int n, m;

template<class T> void read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = x * 10 + (c ^ '0');
}

template<class T> void put(T x) {
    static char buf[20], idx;
    for(idx = 0; x; idx++) {
        buf[idx] = (x % 10) + '0';
        x /= 10;
    }
    if(idx == 0) putchar('0');
    else {
        for(idx--; idx >= 0; idx--) {
            putchar(buf[idx]);
        }
    }
    putchar('\n');
}

Node ram[maxn * 200];
int bit[maxn] = {}, tot;

void update(int l, int r, int pre, int &cur, int pos, loli val) {
    cur = ++tot; ram[cur] = ram[pre];
    ram[cur].val += val;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(l, mid, ram[pre].l, ram[cur].l, pos, val);
    else
        update(mid + 1, r, ram[pre].r, ram[cur].r, pos, val);
}

loli query(int x, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return ram[x].val;
    }
    int mid = (L + R) >> 1;
    loli ret = 0;
    if(l <= mid)
        ret += query(ram[x].l, L, mid, l, r);
    if(r > mid)
        ret += query(ram[x].r, mid + 1, R, l, r);
    return ret;
}

void add(int x, int h, int v) {
    for(; x <= n; x += x & (-x)) {
        update(1, n, bit[x], bit[x], h, v);
    }
}

loli query(int x, int d) {
    loli ret = 0;
    for(; x; x -= x & (-x)) {
        ret += query(bit[x], 1, n, d + 1, n);
    }
    return ret;
}

loli query(int l, int r, int d) {
    return query(r, d) - query(l - 1, d);
}


int heavy[maxn], top[maxn], dep[maxn], par[maxn], sz[maxn];
int H[maxn], V[maxn], pos[maxn], id[maxn], road_id[maxn];
vector<Road> G[maxn], R;


void dfs(int x, int p, int d, int h, int v, int idx) {
    H[x] = h, V[x] = v; heavy[x] = -1;
    par[x] = p; dep[x] = d; sz[x] = 1;
    road_id[idx] = x;
    for(auto y : G[x]) {
        if(y.to == p) continue;
        dfs(y.to, x, d + 1, y.h, y.v, y.id);
        sz[x] += sz[y.to];
        if(heavy[x] == -1 || sz[heavy[x]] < sz[y.to])
            heavy[x] = y.to;
    }
}

void build() {
    dfs(1, -1, 1, 0, 0, 0); int idx = 0;
    for(int i = 1; i <= n; i++) {
        if(par[i] == -1 || heavy[par[i]] != i) {
            for(int p = i; p != -1; p = heavy[p]) {
                top[p] = i; pos[++idx] = p; id[p] = idx;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        add(i, H[pos[i]], V[pos[i]]);
    }
}

loli solve(int a, int b, int d) {
    loli ret = 0;
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]])
            swap(a, b); // move a
        ret += query(id[top[a]], id[a], d);
        a = par[top[a]];
    }
    if(a == b) return ret;
    if(dep[a] < dep[b])
        swap(a, b);
    ret += query(id[b] + 1, id[a], d);
    return ret;
}

int main() {
    read(n), read(m);
    for(int i = 1; i < n; i++) {
        int a, b, h, v;
        read(a), read(b), read(h), read(v);
        G[a].emplace_back(b, h, v, i);
        G[b].emplace_back(a, h, v, i);
        R.emplace_back(0, h, v, i);
    }
    build();
    while(m--) {
        int s, t, d, op;
        read(op), read(s), read(t), read(d);
        if(op == 0)
            put(solve(s, t, d));
        else {
            add(id[road_id[s]], R[s - 1].h, -R[s - 1].v);
            R[s - 1].h = t;
            R[s - 1].v = d;
            add(id[road_id[s]], t, d);
        }
    }
    return 0;
}
