#include <bits/stdc++.h>
using namespace std;
#define maxn 10007
const int INF = 1 << 20;

char a[maxn], b[maxn];
int l, k, n, m, cur;
int dp[2][maxn];

struct MONO {
    struct data {
        int val, pos;
    };
    deque<data> dq;
    void add(int val, int pos) {
        while(dq.size() && dq.back().val >= val) dq.pop_back();
        dq.push_back((data){val, pos});
    }
    int get_val(int pos) {
        while(dq.size() && dq.front().pos < pos - l) dq.pop_front();
        return dq.size() ? dq.front().val : printf("shit\n");
    }
    void clear() {
        dq.clear();
    }
};

MONO D[maxn], A;

int main() {
    scanf("%s%s", a + 1, b + 1);
    scanf("%d%d", &l, &k);
    n = strlen(a+1);
    m = strlen(b+1);
    if(n < m) {
        swap(n, m);
        swap(a, b);
    }
    cur = 1;
    for(int i = 0; i <= m; i++) {
        dp[0][i] = i % l == 0 ? i / l : i / l + 1;
        D[i].add(dp[0][i], 0);
    }
    for(int i = 1; i <= n; i++) {
        dp[cur][0] = (i % l == 0) ? (i / l) : (i / l + 1);
        A.clear(); A.add(dp[cur][0], 0);
        for(int j = 1; j <= m; j++) {
            dp[cur][j] = INF;
            if(a[i] != b[j]) {
                dp[cur][j] = min(dp[cur][j], D[j].get_val(i) + 1);
                dp[cur][j] = min(dp[cur][j], A.get_val(j) + 1);
            } else {
                dp[cur][j] = dp[cur ^ 1][j - 1];
            }
            D[j].add(dp[cur][j], i);
            A.add(dp[cur][j], j);
        }
        cur ^= 1;
    }
    //printf("%d\n", dp[cur ^ 1][m]);
    if(dp[cur ^ 1][m] > k) puts("Impossible");
    else printf("%d\n", dp[cur ^ 1][m]);
    return 0;
}
