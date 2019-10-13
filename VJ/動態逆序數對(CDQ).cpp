#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

struct bit {
    vector<int> arr;
    bit(int n) : arr(n + 1, 0) {}
    #define lowbit(X) ((X) & -(X))
    void clear() {
        fill(arr.begin(), arr.end(), 0);
    }
    void add(int x, int v) {
        for(; x < arr.size(); x += lowbit(x)) {
            arr[x] += v;
        }
    }
    int query(int x) {
        int ret = 0;
        while(x) {
            ret += arr[x];
            x -= lowbit(x);
        }
        return ret;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

struct Pt {
    int pos, val, idx;
    Pt(int a = 0, int b = 0, int c = 0) :
        pos(a), val(b), idx(c) {}
};


int ans_L[maxn] = {}, ans_R[maxn] = {};
vector<Pt> qry_L, qry_R, tmp;
int A[maxn], pos[maxn];
int n, m, x;

bit cute(maxn);

void solve_L(int l, int r) {
    if(r - l == 1) {
        return;
    }
    int mid = (l + r) >> 1;
    int i, j, idx = l;
    solve_L(l, mid);
    solve_L(mid, r);

    // cal
    for(i = mid, j = l; i < r; i++) {
        while(j < mid && qry_L[j].pos < qry_L[i].pos) {
            if(qry_L[j].idx)
                cute.add(qry_L[j].val, -1);
            else
                cute.add(qry_L[j].val,  1);
            j++;
        }
        if(qry_L[i].idx) ans_L[qry_L[i].idx] += cute.query(qry_L[i].val + 1, n);
    }

    // reset bit
    while(j > l) {
        j--;
        if(qry_L[j].idx)
            cute.add(qry_L[j].val,  1);
        else
            cute.add(qry_L[j].val, -1);
    }

    // sort
    for(i = mid, j = l; i < r; i++) {
        while(j < mid && qry_L[j].pos < qry_L[i].pos) {
            tmp[idx++] = qry_L[j++];
        }
        tmp[idx++] = qry_L[i];
    }
    while(j < mid) {
        tmp[idx++] = qry_L[j++];
    }
    for(i = l; i < r; i++) {
        qry_L[i] = tmp[i];
    }
}

void solve_R(int l, int r) {
    if(r - l == 1) {
        return;
    }
    int mid = (l + r) >> 1;
    int i, j, idx = l;
    solve_R(l, mid);
    solve_R(mid, r);

    // cal
    for(i = mid, j = l; i < r; i++) {
        while(j < mid && qry_R[j].pos > qry_R[i].pos) {
            if(qry_R[j].idx)
                cute.add(qry_R[j].val, -1);
            else
                cute.add(qry_R[j].val, 1);
            j++;
        }
        if(qry_R[i].idx) ans_R[qry_R[i].idx] += cute.query(qry_R[i].val - 1);
    }

    // reset bit
    while(j > l) {
        j--;
        if(qry_R[j].idx)
            cute.add(qry_R[j].val,  1);
        else
            cute.add(qry_R[j].val, -1);
    }

    // sort
    for(i = mid, j = l; i < r; i++) {
        while(j < mid && qry_R[j].pos > qry_R[i].pos) {
            tmp[idx++] = qry_R[j++];
        }
        tmp[idx++] = qry_R[i];
    }
    while(j < mid) {
        tmp[idx++] = qry_R[j++];
    }

    for(i = l; i < r; i++) {
        qry_R[i] = tmp[i];
    }

}


int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", A + i);
        //qry_L.emplace_back(i, A[i], 0);
        //qry_R.emplace_back(i, A[i], 0);
        qry_L.push_back({i, A[i], 0});
        qry_R.push_back({i, A[i], 0});
        pos[A[i]] = i;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        //qry_L.emplace_back(pos[x], x, i);
        //qry_R.emplace_back(pos[x], x, i);
        qry_L.push_back({pos[x], x, i});
        qry_R.push_back({pos[x], x, i});
    }
    tmp.resize(qry_L.size());

    long long total = 0;
    for(int i = 1; i <= n; i++) {
        total = total + cute.query(A[i] + 1, n);
        cute.add(A[i], 1);
    }
    //printf("%d\n", total);


    cute.clear();

    solve_L(0, n + m);
    solve_R(0, n + m);

    /*for(int i = 1; i <= m; i++) {
        printf("%d %d\n", ans_L[i], ans_R[i]);
    }*/

    for(int i = 1; i <= m; i++) {
        printf("%lld\n", total);
        total = total - ans_L[i] - ans_R[i];
    }
    return 0;
}
