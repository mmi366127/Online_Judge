#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

struct DSU {
    vector<int> p, s;
    DSU(int n) : p(n + 1, -1), s(n + 1, 1) {}
    int find(int x) {
        return (p[x] < 0) ? x : (p[x] = find(p[x]));
    }
    int join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y)
            return s[x];
        if(s[x] < s[y])
            swap(x, y);
        p[y] = x;
        s[x] += s[y];
        return s[x];
    }
};

int Q[maxn][2];
vector<int> V;
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", Q[i], Q[i] + 1);
        V.emplace_back(Q[i][0]);
        V.emplace_back(Q[i][1]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    DSU cute(V.size()); int ans = 1;
    for(int i = 0; i < n; i++) {
        Q[i][0] = lower_bound(V.begin(), V.end(), Q[i][0]) - V.begin() + 1;
        Q[i][1] = lower_bound(V.begin(), V.end(), Q[i][1]) - V.begin() + 1;
        ans = max(ans, cute.join(Q[i][0], Q[i][1]));
        printf("%d\n", ans);
    }
    return 0;
}
