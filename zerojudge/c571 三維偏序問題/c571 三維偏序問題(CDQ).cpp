#include <stdio.h>
#include <string.h>
#define lowbit(X) ((X)&-(X))
#define maxn 100007
typedef long long loli;
/*
#define getchar getchar_unlocked
#define putchar putchar_unlocked
*/
typedef struct Pt {
    int x, y, z;
}Pt;
typedef struct event {
    int pos, val, id;
}Et;

Pt A[maxn], Tmp[maxn];
Rt E[maxn], tmp[maxn];
int ans[maxn];

int cmp_Pt(Pt a, Pt b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

int cmp(Et a, Et b) {
    if(a.pos != b.pos) return a.pos < b.pos;
    return a.val < b.val;
}

int rd() {
    static char c;
    int ret;
    for(c = getchar(); c < '0'; c = getchar())
        if(c == EOF) return 0;
    for(ret = c ^ '0'; c >= '0'; c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ '0');
    return ret;
}

void prt(int x) {
    if(!x) return;
    if(x < 0) putchar('-'), x = -x;
    prt(x / 10);
    putchar(x % 10 + '0');
}

void sort(Pt a[], int l, int r) {
    if(l >= r) return;
    int idx1, idx2, idx, mid = (l + r) >> 1;
    sort(a, l, mid); idx1 = idx = l;
    sort(a, mid+1, r); idx2 = mid+1;
    while(idx1 <= mid && idx2 <= r) {
        if(cmp_Pt(a[idx1], a[idx2])) {
            Tmp[idx++] = a[idx1++];
        } else {
            Tmp[idx++] = a[idx2++];
        }
    }
    while(idx1 <= mid) Tmp[idx++] = a[idx1++];
    while(idx2 <= r) Tmp[idx++] = a[idx2++];
    for(idx = l; idx <= r; idx++) a[idx] = Tmp[idx];
}

int bit[maxn];
int n;

int qry(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int x, int v) {
    while(x <= n) {
        bit[x] += v;
        x += lowbit(x);
    }
}

void CDQ(int l, int  r) {
    if(l >= r) return;
    int mid = (l + r) >> 1;
    int idx1, idx2, idx;
    CDQ(l, mid); idx1 = idx = l;
    CDQ(mid+1, r); idx2 = mid+1;
    memset(bit, 0, 4 * n + 4);
    while(idx1 <= mid && idx2 <= r) {
        if(cmp(Et[a], Et[b])) {

        } else {

        }
    }
    while(idx1 <= mid) {

    }
    while(idx2 <= mid) {

    }
    for(idx = l; idx <= r; idx++) a[idx] = tmp[idx];
}

int main() {
    n = rd();
    for(int i = 0; i < n; i++) {
        A[i].x = rd();
        A[i].y = rd();
        A[i].z = rd();
    }
    sort(A, 0, n - 1);
    loli ans = 0;
    for(int i = 0; i < n; i++) {

    }

    prt(ans); putchar('\n');
    return 0;
}
