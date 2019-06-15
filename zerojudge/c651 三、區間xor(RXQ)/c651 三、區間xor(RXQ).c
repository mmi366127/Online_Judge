#include <stdio.h>
#include <string.h>
#define lowbit(X) (X&(-X))
#define maxn 1000007

int a[maxn], bit[maxn], pre[maxn];
int n, q, op, l, r;

int read() {
    int tmp;
    static char c;
    while((c = getchar()) < '0');
    tmp = (c - '0');
    while((c = getchar()) >= '0')
        tmp = (tmp<<3) + (tmp<<1) + (c - '0');
    return tmp;
}

int query(int l, int r) {
    int ret = 0;
    for(int k = l - 1; k > 0; k -= lowbit(k)) {
        ret ^= bit[k];
    }
    for(int k = r; k > 0; k -= lowbit(k)) {
        ret ^= bit[k];
    }
    return ret;
}

void build() {
    for(int i = 1; i <= n; i++) {
        bit[i] = pre[i - lowbit(i)] ^ pre[i];
    }
}

void modify(int pos, int val) {
    int mod = val ^ a[pos];
    a[pos] = val;
    for(; pos <= n; pos += lowbit(pos)) {
        bit[pos] ^= mod;
    }
}


int main() {
    scanf("%d%d", &n, &q);
    pre[0] = 0;
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        pre[i] = pre[i-1] ^ a[i];
    }
    build();
    for(int i = 1; i <= q; i++) {
        op = read(); l = read(); r = read();
        if(op == 0) {
            printf("%d\n", query(l, r));
        } else {
            modify(l, r);
        }
    }
    return 0;
}
