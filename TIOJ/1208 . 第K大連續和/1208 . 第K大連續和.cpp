#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define maxn 20005
using namespace std;
using namespace __gnu_pbds;
using loli = tree< pair<int, int>, null_type, less< pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 0x3f3f3f3f;

int n, k;
int A[maxn], P[maxn];

bool check(int v) {
    static loli Tree;
    Tree.clear();
    int cnt = 0, tot = 0;
    for(int i = 0; i <= n; i++) {
        cnt += Tree.order_of_key({P[i] - v, INF});
        Tree.insert({P[i], ++tot});
    }
    //printf("%d %d\n", cnt, v);
    return cnt < k;
}

int main() {
    while(~scanf("%d%d", &n, &k)) {
        if(n == 0) break;
        P[0] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", A + i);
            P[i] = P[i - 1] + A[i];
        }
        int L = -5e8, R = 5e8;
        while(R - L > 1) {
            int mid = (L + R) >> 1;
            if(check(mid))
                R = mid;
            else
                L = mid;
        }
        printf("%d\n", L);
    }
    return 0;
}
