#include <bits/stdc++.h>
#define maxn 100005
#define maxb 400005
using namespace std;


char bit[maxb] = {};

void add(int x) {
    for(int i = x; i < maxb; i += i & (-i)) {
        bit[i] ^= 1;
    }
}

int query(int x) {
    int ret = 0;
    while(x) {
        ret ^= bit[x];
        x -= x & (-x);
    }
    return ret;
}

int L[maxn], R[maxn];
vector<int> V;
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    V.push_back(0);
    V.push_back(n + 1);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", L + i, R + i);
        V.push_back(L[i]);
        V.push_back(L[i] - 1);
        V.push_back(R[i]);
        V.push_back(R[i] + 1);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    for(int i = 0; i < m; i++) {
        L[i] = lower_bound(V.begin(), V.end(), L[i]) - V.begin() + 1;
        R[i] = lower_bound(V.begin(), V.end(), R[i]) - V.begin() + 1;
        add(L[i]);
        add(R[i] + 1);
    }
    int ans = 0;
    for(int i = 0; i < V.size() - 1; i++) {
        if(query(i + 1)) {
            ans += V[i + 1] - V[i];
        }
    }
    printf("%d\n", n - ans);
    return 0;
}
