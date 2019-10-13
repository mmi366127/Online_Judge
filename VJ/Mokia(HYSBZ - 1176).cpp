#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define maxn 2000005
using namespace std;
typedef long long loli;
struct Pt {
    int x, l, r, idx, val;
    void push(int a, int b, int c, int d, int e) {
        x = a; l = b; r = c; idx = d; val = e;
    }
};


Pt arr[200005], tmp[200005];
loli bit[maxn] = {};
loli ans[maxn];
loli S, W;


void add(int x, int v) {
    for(int i = x; i <= W; i += i & (-i)) {
        bit[i] += v;
    }
}

loli query(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}


void CDQ(int l, int r) {
    if(r - l <= 1) return;
    int m = (l + r) >> 1;
    CDQ(l, m); CDQ(m, r);

    int i, j, idx = l;
    for(i = m, j = l; i < r; i++) {
        while(j < m && arr[j].x <= arr[i].x) {
            if(!arr[j].idx) {
                add(arr[j].l, arr[j].val);
            }
            j++;
        }
        if(arr[i].idx) {
            loli tmp = query(arr[i].r) - query(arr[i].l - 1);
            if(arr[i].idx < 0)
                ans[-arr[i].idx] -= tmp;
            else
                ans[arr[i].idx] += tmp;
        }
    }

    j--;
    while(j >= l) {
        if(!arr[j].idx) add(arr[j].l, -arr[j].val);
        j--;
    }
    for(i = m, j = l; i < r; i++) {
        while(j < m && arr[j].x <= arr[i].x) {
            tmp[idx++] = arr[j++];
        }
        tmp[idx++] = arr[i];
    }
    while(j < m) tmp[idx++] = arr[j++];
    for(idx = l; idx < r; idx++)
        arr[idx] = tmp[idx];
}


int main() {
    scanf("%lld%lld", &S, &W);
    int op, l, r, b, t, x, y, v, tot = 0, Q = 1;
    while(~scanf("%d", &op) && op != 3) {
        if(op == 1) {
            scanf("%d%d%d", &x, &y, &v);
            arr[tot++].push(x, y, y, 0, v);
        } else {
            scanf("%d%d%d%d", &l, &b, &r, &t);
            arr[tot++].push(l - 1, b, t, -Q, 0);
            arr[tot++].push(r, b, t, Q, 0);
            ans[Q++] = S * (r - l + 1) * (t - b + 1);
        }
    }
    CDQ(0, tot);
    for(int i = 1; i < Q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
