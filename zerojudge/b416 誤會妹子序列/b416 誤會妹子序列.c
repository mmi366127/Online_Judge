#include <stdio.h>
#include <string.h>
#define maxn 1000007
#define lowbit(X) ((X)&(-(X)))
struct qry {
    int x, y, id;
};


int arr[maxn], bit[maxn], ans[maxn];
struct qry tmp[maxn << 2];
struct qry Q[maxn << 2];
int n, m, l, r, a, b;


void sort(int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    int idx1 = l;
    int idx2 = mid + 1;
    int idx = l;
    sort(l, mid);
    sort(mid + 1, r);
    while(idx1 <= mid && idx2 <= r) {
        if(Q[idx1].x < Q[idx2].x) {
            tmp[idx++] = Q[idx1++];
        } else {
            tmp[idx++] = Q[idx2++];
        }
    }
    while(idx1 <= mid) {
        tmp[idx++] = Q[idx1++];
    }
    while(idx2 <= r) {
        tmp[idx++] = Q[idx2++];
    }
    for(idx = l; idx <= r; idx++)
        Q[idx] = tmp[idx];
}


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
    sort(0, idx - 1);
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
