#include <bits/stdc++.h>
#define all(X) X.begin(), X.end()
#define maxn 3007
typedef long long loli;
using namespace std;
struct Pt {
    int x, y;
    bool operator < (const Pt &a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
};

int n, l, w, ans;
vector<int> V;
Pt a[maxn];

int main() {
    scanf("%d%d%d", &n, &l, &w);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        V.push_back(a[i].y);
    }
    sort(a, a + n);
    sort(all(V));
    V.erase(unique(all(V)), V.end());
    ans = 0;
    for(int i = 0; i < V.size(); i++) {
        deque<Pt> dq;
        for(int j = 0; j < n; j++) {
            if(V[i] <= a[j].y && a[j].y <= V[i] + l) {
                while(dq.size() && dq.front().x < a[j].x - w) dq.pop_front();
                dq.push_back(a[j]);
                if(dq.size() > ans) ans = dq.size();
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
