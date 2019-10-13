#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int arr[maxn], bit[maxn];
vector<int> V;
int n, kase = 0;

void add(int x, int v) {
    for(; x <= n; x += x & (-x)) {
        bit[x] += v;
    }
}

int query(int x) {
    int ret;
    for(ret = 0; x; x -= x & (-x)) {
        ret += bit[x];
    }
    return ret;
}

int main() {
    while(~scanf("%d", &n) && n) {
        V.clear();
        memset(bit, 0, sizeof(int) * (n + 1));
        for(int i = 0; i < n; i++) {
            scanf("%d", arr + i);
            V.push_back(arr[i]);
        }
        sort(V.begin(), V.end());
        V.erase(unique(V.begin(), V.end()), V.end());
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            arr[i] = V.size() - (lower_bound(V.begin(), V.end(), arr[i]) - V.begin());
            ans += query(arr[i] - 1);
            add(arr[i], 1);
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }
}
