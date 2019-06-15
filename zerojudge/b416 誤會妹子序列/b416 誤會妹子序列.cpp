#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 1000007
#define lowbit(X) ((X)&(-(X)))
using namespace std;
struct qry {
    int x, y, id;
    bool operator < (const qry &a) const {
        return x < a.x;
    }
};


int arr[maxn], bit[maxn], ans[maxn];
int n, m, l, r, a, b;
qry Q[maxn << 2];


void add(int x, int val) {
    while(x <= n && x) {
        bit[x]++;
        x += lowbit(x);
    }
}

int query(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}


int main() {
    scanf("%d%d", &n, &m);
    memset(bit, 0, sizeof(int) * (n + 1));
    memset(ans, 0, sizeof(int) * (n + 1));
    for(int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    int idx = 0;
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &l, &r, &a, &b);
        l--, a--;
        Q[idx].id = i;
        Q[idx].x = r;
        Q[idx++].y = b;
        Q[idx].id = i;
        Q[idx].x = l;
        Q[idx++].y = a;
        Q[idx].id = -i;
        Q[idx].x = l;
        Q[idx++].y = b;
        Q[idx].id = -i;
        Q[idx].x = r;
        Q[idx++].y = a;
    }
    sort(Q, Q + idx);
    for(int i = 0, j = 0; i <= n; i++) {
        add(arr[i], 1);
        while(Q[j].x == i) {
            if(Q[j].id < 0) {
                ans[-Q[j].id] -= query(Q[j].y);
            } else {
                ans[Q[j].id] += query(Q[j].y);
            }
            j++;
        }
    }
    for(int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
