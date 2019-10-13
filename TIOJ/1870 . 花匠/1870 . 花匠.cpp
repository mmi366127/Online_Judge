#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ls(X) (X << 1)
#define rs(X) (X << 1 | 1)
#define maxn 100007
using namespace std;
typedef long long loli;
struct Node {
    int cnt[20][2];
    int tag;
};

Node SGT[300000];

void pull(int x) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 20; j++) {
            SGT[x].cnt[j][i] = SGT[ls(x)].cnt[j][i] + SGT[rs(x)].cnt[j][i];
        }
    }
}

void push(int x) {
    if(SGT[x].tag) {
        int LS = ls(x), RS = rs(x);
        for(int i = 0; i < 20; i++) {
            if(SGT[x].tag & (1 << i)) swap(SGT[LS].cnt[i][0], SGT[LS].cnt[i][1]);
        }
        for(int i = 0; i < 20; i++) {
            if(SGT[x].tag & (1 << i)) swap(SGT[RS].cnt[i][0], SGT[RS].cnt[i][1]);
        }
        SGT[LS].tag ^= SGT[x].tag;
        SGT[RS].tag ^= SGT[x].tag;
        SGT[x].tag = 0;
    }
}

loli sum(int x) {
    loli ret = 0;
    for(int i = 0; i < 20; i++) {
        ret += (1LL << i) * SGT[x].cnt[i][1];
    }
    return ret;
}

void build(int x, int L, int R, int A[]) {
    SGT[x].tag = 0;
    if(L == R) {
        for(int i = 0; i < 20; i++) {
            if(A[L] & (1 << i)) {
                SGT[x].cnt[i][1] = 1;
                SGT[x].cnt[i][0] = 0;
            } else {
                SGT[x].cnt[i][1] = 0;
                SGT[x].cnt[i][0] = 1;
            }
        }
        return;
    }
    int mid = (L + R) >> 1;
    build(ls(x), L, mid, A);
    build(rs(x), mid + 1, R, A);
    pull(x);
}

void modify(int x, int L, int R, int l, int r, int val) {
    if(l <= L && R <= r) {
        SGT[x].tag ^= val;
        for(int i = 0; i < 20; i++) {
            if(val & 1) swap(SGT[x].cnt[i][0], SGT[x].cnt[i][1]);
            val >>= 1;
        }
        return;
    }
    int mid = (L + R) >> 1;
    push(x);
    if(l <= mid) modify(ls(x), L, mid, l, r, val);
    if(r > mid) modify(rs(x), mid + 1, R, l, r, val);
    pull(x);
}

loli query(int x, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return sum(x);
    }
    int mid = (L + R) >> 1;
    push(x); loli ret = 0;
    if(l <= mid) ret += query(ls(x), L, mid, l, r);
    if(r > mid) ret += query(rs(x), mid + 1, R, l, r);
    return ret;
}

int A[maxn];
int n, q;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", A + i);
    }
    scanf("%d", &q);
    build(1, 1, n, A);
    int op, l, r, x;
    while(q--) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, 1, n, l, r));
        } else {
            scanf("%d%d%d", &l, &r, &x);
            modify(1, 1, n, l, r, x);
        }
    }
    return 0;
}
