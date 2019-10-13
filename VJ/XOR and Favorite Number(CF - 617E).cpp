#include <bits/stdc++.h>
#define maxc 2000005
#define maxn 100005
using namespace std;
struct Pt {
    int l, r, k, id;
    Pt(int a, int b, int c, int d) :
        l(a), r(b), k(c), id(d) {}
    bool operator < (const Pt & a) const {
        return (k == a.k) ? (r < a.r) : (k < a.k);
    }
};


int arr[maxn], cnt[maxc] = {};
long long ans[maxn], val = 0;
int n, m, k, l, r;
vector<Pt> V;

void add(int x) {
    val = val + cnt[x ^ k];
    cnt[x]++;
}

void kill(int x) {
    cnt[x]--;
    val = val - cnt[x ^ k];
}


int main() {
    scanf("%d%d%d", &n, &m, &k);
    arr[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
        arr[i] ^= arr[i - 1];
    }
    int K = sqrt(n);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        V.emplace_back(l - 1, r, l / K, i);
    }
    sort(V.begin(), V.end());
    int L = 0, R = 0; add(arr[0]);
    for(auto t : V) {
        while(L > t.l) add(arr[--L]);
        while(R < t.r) add(arr[++R]);
        while(L < t.l) kill(arr[L++]);
        while(R > t.r) kill(arr[R--]);
        ans[t.id] = val;
    }
    for(int i = 0; i < m; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
