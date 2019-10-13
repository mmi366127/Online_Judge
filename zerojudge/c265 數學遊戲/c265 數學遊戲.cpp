#include <string.h>
#include <stdio.h>
#include <math.h>
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define maxn 100005
typedef __int128_t loli;
typedef struct Node {
    loli val, len;
    loli VAL, LEN;
}Node;

Node SGT[maxn * 4];
loli mod, MOD;

loli GCD(loli a, loli b) {
    if(!a || !b) return a + b;
    while((a %= b) && (b %= a));
    return a + b;
}

loli LCM(loli a, loli b) {
    return a * b / GCD(a, b);
}

void put(loli x) {
    static char buf[50];
    static int idx;
    if(x < 0) {
        puts("WTF");
        return;
    }
    for(idx = 0; x; idx++) {
        buf[idx] = (x % 10LL) ^ '0';
        x /= 10LL;
    }
    if(idx) {
        for(idx--; idx >= 0; idx--) {
            putchar(buf[idx]);
        }
    } else putchar('0');
    putchar('\n');
}

void pull(int x) {
    SGT[x].val = (SGT[ls(x)].val * SGT[rs(x)].len + SGT[rs(x)].val) % mod;
    SGT[x].len = SGT[ls(x)].len * SGT[rs(x)].len % mod;
    SGT[x].VAL = (SGT[ls(x)].VAL * SGT[rs(x)].LEN + SGT[rs(x)].VAL) % MOD;
    SGT[x].LEN = SGT[ls(x)].LEN * SGT[rs(x)].LEN % MOD;
}

loli num[10];

loli GO(int x) {
    static char s[20];
    static int len;
    sprintf(s, "%d", x);
    len = strlen(s);
    return num[len];
}

void build(int x, int L, int R, int arr[]) {
    if(L == R) {
        SGT[x].val = arr[L];
        SGT[x].len = GO(arr[L]);
        SGT[x].VAL = arr[L];
        SGT[x].LEN = GO(arr[L]);
        //printf("%d --> ", arr[L]);
        //put(SGT[x].len);
        return;
    }
    int mid = (L + R) >> 1;
    build(ls(x), L, mid, arr);
    build(rs(x), mid + 1, R, arr);
    pull(x);
}

void modify(int x, int L, int R, int pos, int val) {
    if(L == R) {
        SGT[x].val = val;
        SGT[x].len = GO(val);
        SGT[x].VAL = val;
        SGT[x].LEN = GO(val);
        //printf("%d --> ", val);
        //put(SGT[x].len);
        return;
    }
    int mid = (L + R) >> 1;
    if(pos <= mid)
        modify(ls(x), L, mid, pos, val);
    else
        modify(rs(x), mid + 1, R, pos, val);
    pull(x);
}

Node merge(Node a, Node b) {
    Node ret;
    ret.val = (a.val * b.len + b.val) % mod;
    ret.len = a.len * b.len % mod;
    ret.VAL = (a.VAL * b.LEN + b.VAL) % MOD;
    ret.LEN = a.LEN * b.LEN % MOD;
    return ret;
}

Node query(int x, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return SGT[x];
    }
    int mid = (L + R) >> 1;
    if(l <= mid && r > mid) {
        return merge(query(ls(x), L, mid, l, r), query(rs(x), mid + 1, R, l, r));
    }
    if(l <= mid)
        return query(ls(x), L, mid, l, r);
    return query(rs(x), mid + 1, R, l, r);
}


int n, m, o, x, v, l, r, k;
int arr[maxn];

int main() {
    num[0] = 1;
    for(int i = 1; i < 10; i++) {
        num[i] = num[i - 1] * 10LL;
        //put(num[i]);
    }
    mod = 1LL;
    for(loli i = 1LL; i <= 40LL; i++) {
        mod = LCM(mod, i);
    }
    MOD = 1LL;
    for(loli i = 41LL; i <= 50LL; i++) {
        MOD = LCM(MOD, i);
    }
    //put(mod);
    //put(MOD);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build(1, 1, n, arr);
    for(int i = 0; i < m; i++) {
        scanf("%d", &o);
        if(o == 1) {
            scanf("%d%d", &x, &v);
            modify(1, 1, n, x, v);
        } else {
            scanf("%d%d%d", &l, &r, &v);
            Node tmp = query(1, 1, n, l, r);
            //put(tmp.val);
            if(v <= 40) puts(tmp.val % v == 0 ? "YES" : "NO");
            else puts(tmp.VAL % v == 0 ? "YES" : "NO");
        }
    }
    return 0;
}
