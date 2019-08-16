#include <bits/stdc++.h>
#define lowbit(X) (X)&(-(X))
#define maxn 100007
using namespace std;
struct Pt {
    int y, z, id;
    Pt(int a, int b, int c) :
         y(a), z(b), id(c) {}
    bool operator < (const Pt &a) const {
        return y == a.y ? z < a.z : y < a.y;
    }
};

vector< vector<Pt> > arr;
int ans[maxn], bit[maxn];
int n;

void add(int x, int v) {
    if(x <= 0) return;
    while(x <= n) {
        bit[x] += v;
        x += lowbit(x);
    }
}

int qry(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

void CDQ(int l, int r) {
    if(r - l <= 1) {
        return;
    }
    int mid = (l + r) >> 1;
    CDQ(l, mid);
    CDQ(mid, r);

    vector<Pt> l_data, r_data;
    for(int i = l; i < mid; i++) {
        for(auto t : arr[i]) l_data.push_back(t);
    }
    for(int i = mid; i < r; i++) {
        for(auto t : arr[i]) r_data.push_back(t);
    }
    if(l_data.empty() || r_data.empty()) return;
    sort(l_data.begin(), l_data.end());
    sort(r_data.begin(), r_data.end());
    int idx = 0;
    for(auto t : r_data) {
        while(idx < l_data.size() && l_data[idx].y < t.y) {
            add(l_data[idx++].z, 1);
        }
        ans[t.id] += qry(t.z - 1);
    }
    for(int i = 0; i < idx; i++)
        add(l_data[i].z, -1);
}

int main() {
    scanf("%d", &n);
    arr.resize(n);
    memset(bit, 0, 4 * (n + 1));
    memset(ans, 0, 4 * (n + 1));
    for(int i = 0; i < n; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        arr[n - x].emplace_back(n - y + 1, n - z + 1, i);
    }
    CDQ(0, n);
    for(int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
