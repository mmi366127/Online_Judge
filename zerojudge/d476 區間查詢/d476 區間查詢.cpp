#include <stdio.h>
#include <string.h>
#include <vector>
#define lowbit(X) ((X)&-(X))
#define maxn 100007
using namespace std;
struct Pt {
    int l, r, v;
    char type;
    Pt(int a, int b, char c, int d) :
        l(a), r(b), type(c), v(d) {}
};
/*
#define putchar putchar_unlocked
#define getchar getchar_unlocked
*/
int bit[maxn] = {};

int rd() {
    static char c; static int ret;
    for(c = getchar(); c < '0'; c = getchar());
    for(ret = 0; c >= '0'; c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ '0');
    return ret;
}

void prt(int x) {
    if(x < 10) {
        putchar(x + '0');
        return;
    }
    prt(x / 10);
    putchar(x % 10 + '0');
}

void add(int x, int v) {
    while(x < 40000) {
        bit[x] += v;
        x += lowbit(x);
    }
}

int qry(int x) {
    static int ret;
    for(ret = 0; x; x -= lowbit(x)) {
        ret += bit[x];
    }
    return ret;
}


int A[maxn], ans[maxn];
vector<int> qs;
vector<Pt> V;
int n, m;


void solve(int l, int r, vector<int> &Q) {
    if(l == r || Q.empty()) {
        for(int t : Q) {
            ans[t] = l;
        }
        return;
    }
    vector<int> ql, qr;
    int mid = (l + r) >> 1;
    for(int t : Q) {
        if(V[t].type == 0) { // query
            int cnt = qry(V[t].r) - qry(V[t].l - 1);
            if(cnt >= V[t].v) {
                ql.push_back(t);
            } else {
                V[t].v -= cnt;
                qr.push_back(t);
            }
        } else { // modify
            if(V[t].v <= mid) {
                add(V[t].l, V[t].type);
                ql.push_back(t);
            } else {
                qr.push_back(t);
            }
        }
    }
    for(int t : ql) {
        if(V[t].type) {
            add(V[t].l, -V[t].type);
        }
    }

    solve(l, mid, ql);
    solve(mid + 1, r, qr);
}


int main() {
    n = rd(); m = rd();
    for(int i = 1; i <= n; i++) {
        A[i] = rd();
        V.emplace_back(i, i, 1, A[i]);
    }
    char s[5]; int l, r, k;
    for(int i = 0; i < m; i++) {
        scanf("%s", s);
        if(s[0] == 'Q') {
            l = rd(); r = rd(); k = rd();
            V.emplace_back(l, r, 0, k);
        } else {
            l = rd(); k = rd();
            V.emplace_back(l, l, -1, A[l]);
            A[l] = k;
            V.emplace_back(l, l, 1, A[l]);
        }
    }
    for(int i = 0; i < V.size(); i++) qs.push_back(i);
    solve(1, 1e9, qs);
    for(int t : qs) {
        if(V[t].type == 0) {
            printf("%d\n", ans[t]);
        }
    }
    return 0;
}
