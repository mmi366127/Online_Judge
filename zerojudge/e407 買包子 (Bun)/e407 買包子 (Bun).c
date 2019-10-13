#include <stdio.h>
#include <string.h>
#define maxn 300005

long long tmp[maxn], V[maxn], JK[maxn], Q[maxn];
int n, m, l, r, tot = 0;
int bit[maxn] = {};
long long acc = 0;
char op[maxn];

void add(int x, int v) {
    for(; x < maxn; x += x & (-x)) bit[x] += v;
}

int query(int x) {
    int ret;
    for(ret = 0; x; x -= x & (-x)) ret += bit[x];
    return ret;
}

void sort(int l, int r) {
    if(r - l == 1) return;
    int m = (l + r) >> 1;
    sort(l, m); sort(m, r);
    int i, j, idx = l;
    for(i = l, j = m; i < m; i++) {
        while(j < r && V[j] < V[i]) {
            tmp[idx++] = V[j++];
        }
        tmp[idx++] = V[i];
    }
    while(j < r) tmp[idx++] = V[j++];
    for(idx = l; idx < r; idx++)
        V[idx] = tmp[idx];
}


int discrete(int sz) {
    int i, j;
    for(i = 0, j = 0; i < sz; i++) {
        V[j++] = V[i];
        while(i < sz - 1 && V[i] == V[i + 1]) i++;
    }
    return j;
}

int upper_bound(int l, int r, long long v) {
    if(V[l] > v) return l;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if(V[mid] <= v)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%lld", op + i, JK + i);
        if(op[i] == 1) {
            V[tot++] = acc + JK[i];
        } else {
            acc += JK[i];
        }
    }
    sort(0, tot); m = discrete(tot);
    l = r = 0; acc = 0;
    for(int i = 0; i < n; i++) {
        if(op[i] == 1) {
            add(upper_bound(0, m, acc + JK[i]), 1);
            Q[r++] = acc + JK[i];
        } else {
            acc += JK[i];
            while(l != r && Q[l] <= acc) {
                add(upper_bound(0, m, Q[l++]), -1);
            }
            printf("%d\n", query(upper_bound(0, m, acc)));
        }
    }
    return 0;
}
