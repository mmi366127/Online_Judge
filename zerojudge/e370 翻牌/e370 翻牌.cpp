#include <stdio.h>
#define maxn 1000005
#define maxm 2000005

int a[maxn], b[maxn], arr[maxm], tmp[maxm];
int p[maxm], s[maxm], mi[maxm];
long long sum[maxm];
int n, m, tot = 0;

#define getchar getchar_unlocked

int read() {
    static char c;
    static int ret;
    for(c = getchar(); c < '0'; c = getchar());
    for(ret = 0; c >= '0'; c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ '0');
    return ret;
}

void sort(int l, int r) {
    if(r - l == 1) return;
    int m = (l + r) >> 1;
    sort(l, m); sort(m, r);
    int i, j, idx = l;
    for(i = l, j = m; i < m; i++) {
        while(j < r && arr[j] < arr[i]) {
            tmp[idx++] = arr[j++];
        }
        tmp[idx++] = arr[i];
    }
    while(j < r) tmp[idx++] = arr[j++];
    for(idx = l; idx < r; idx++)
        arr[idx] = tmp[idx];
}

int discrete(int sz) {
    int i, j;
    for(i = 0, j = 0; i < sz; i++) {
        arr[j++] = arr[i];
        while(i < sz - 1 && arr[i] == arr[i + 1]) i++;
    }
    return j;
}

int lower_bound(int l, int r, int v) {
    if(arr[l] >= v) return l;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if(arr[mid] < v)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int find(int x) {
    return (p[x] == -1) ? x : (p[x] = find(p[x]));
}

void init(int x) {
    for(int i = 0; i < x; i++) {
        p[i] = -1; s[i] = 1;
        sum[i] = mi[i] = arr[i];
    }
}

void join(int x, int y) {
    x = lower_bound(0, m, x);
    y = lower_bound(0, m, y);
    x = find(x); y = find(y);
    if(x == y) {
        mi[x] = 0;
        return;
    }
    if(s[x] < s[y]) {
        int __ = x;
        x = y;
        y = __;
    }
    p[y] = x;
    s[x] += s[y];
    sum[x] += sum[y];
    mi[x] = mi[x] < mi[y] ? mi[x] : mi[y];
}

int main() {
    n = read();
    for(int i = 0; i < n; i++) {
        a[i] = read(); b[i] = read();
        arr[tot++] = a[i];
        arr[tot++] = b[i];
    }
    sort(0, tot);
    m = discrete(tot); init(m);
    for(int i = 0; i < n; i++) {
        join(a[i], b[i]);
    }
    long long ans = 0;
    for(int i = 0; i < m; i++) {
        if(p[i] == -1) {
            ans = ans + sum[i] - mi[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
