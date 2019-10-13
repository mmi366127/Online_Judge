#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
typedef long long loli;

const int INF = 0x3f3f3f3f;

struct Segment_Tree {
    pair<int, int> Tree[1 << 20];
    static const int n = maxn;
    #define ls(x) (x << 1)
    #define rs(x) (x << 1 | 1)
    void init(loli arr[], int _) {
        //n = _;
        build(arr);
    }
    void pull(int x) {
        Tree[x] = max(Tree[ls(x)], Tree[rs(x)]);
    }
    void build(loli arr[], int x = 1, int L = 1, int R = n) {
        if(L == R) {
            Tree[x].first = arr[L];
            Tree[x].second = L;
            return;
        }
        int m = (L + R) >> 1;
        build(arr, ls(x), L, m);
        build(arr, rs(x), m + 1, R);
        pull(x);
    }
    pair<int, int> query(int l, int r, int x = 1, int L = 1, int R = n) {
        if(l <= L && R <= r) {
            return Tree[x];
        }
        pair<int, int> ret = make_pair(0, 0);
        int mid = (L + R) >> 1;
        if(l <= mid)
            ret = max(ret, query(l, r, ls(x), L, mid));
        if(r > mid)
            ret = max(ret, query(l, r, rs(x), mid + 1, R));
        return ret;
    }
};

Segment_Tree cute;
loli arr[maxn], tmp[maxn];
loli ans = 0;
int n;

void merge(int l, int r, int L, int R) {
    int i, j, idx = l;
    for(i = l, j = L; i < r; i++) {
        while(j < R && arr[j] < arr[i]) {
            tmp[idx++] = arr[j++];
        }
        tmp[idx++] = arr[i];
    }
    while(j < R) {
        tmp[idx++] = arr[j++];
    }
    for(i = l; i < R; i++)
        arr[i] = tmp[i];
}

void solve(int l, int r) {
    if(l >= r) {
        return;
    }
    pair<int, int> pos = cute.query(l, r);
    for(int i = (l + r) / 2, j = (l + r) / 2 + 1; i >= l && j <= r; i--, j++) {
        if(arr[i] == pos.first) {
            pos.second = i;
            break;
        }
        if(arr[j] == pos.first) {
            pos.second = j;
            break;
        }
    }
    solve(l, pos.second - 1);
    solve(pos.second + 1, r);
    if(pos.second - l > r - pos.second) {
        for(int i = pos.second; i <= r; i++) {
            int p = upper_bound(arr + l, arr + pos.second, pos.first / arr[i]) - arr - l;
            ans = ans + p;
        }
        ans = ans + (upper_bound(arr + pos.second + 1, arr + r + 1, 1) - arr - pos.second - 1);
    } else {
        for(int i = l; i <= pos.second; i++) {
            int p = upper_bound(arr + pos.second + 1, arr + r + 1, pos.first / arr[i]) - arr - pos.second - 1;
            ans = ans + p;
        }
        ans = ans + (upper_bound(arr + l, arr + pos.second, 1) - arr - l);
    }
    merge(l, pos.second, pos.second, pos.second + 1);
    merge(l, pos.second + 1, pos.second + 1, r + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", arr + i);
    }
    cute.init(arr, n);
    solve(1, n);
    printf("%lld\n", ans);
    return 0;
}
