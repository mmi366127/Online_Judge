#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define swap(a, b) {int _ = a; a = b; b = _;}
#define maxn 130007
typedef struct Node {
    int v, l, r, pri, sz;
    char tag;
}Node;
typedef struct Pair {
    int a, b;
}Pr;

Node ram[maxn];
int tot;

int new_Node(int v) {
    int ret = tot++;
    ram[ret].l = ram[ret].r = -1;
    ram[ret].pri = rand();
    ram[ret].tag = 0;
    ram[ret].sz = 1;
    ram[ret].v = v;
    return ret;
}

int size(int x) {
    if(!(~x)) return 0;
    return ram[x].sz;
}

void pull(int x) {
    if(!(~x)) return;
    ram[x].sz = 1;
    ram[x].sz += size(ram[x].l);
    ram[x].sz += size(ram[x].r);
}

void push(int x) {
    if(!(~x)) return;
    if(ram[x].tag) {
        ram[x].tag ^= 1;
        if(ram[x].l != -1) ram[ram[x].l].tag ^= 1;
        if(ram[x].r != -1) ram[ram[x].r].tag ^= 1;
        swap(ram[x].l, ram[x].r);
    }
}

void out(int x) {
    if(x == -1) return;
    push(x);
    out(ram[x].l);
    printf("%d ", ram[x].v);
    out(ram[x].r);
}

int merge(int a, int b) {
    if(a == -1) return b;
    if(b == -1) return a;
    if(ram[a].pri > ram[b].pri) {
        push(a);
        ram[a].r = merge(ram[a].r, b);
        pull(a);
        return a;
    } else {
        push(b);
        ram[b].l = merge(a, ram[b].l);
        pull(b);
        return b;
    }
}

Pr split(int s, int k) {
    Pr ret; ret.a = ret.b = -1;
    if(!(~s)) return ret;
    push(s);
    if(size(ram[s].l) >= k) {
        ret = split(ram[s].l, k);
        ram[s].l = ret.b;
        ret.b = s;
        pull(s);
    } else {
        ret = split(ram[s].r, k - size(ram[s].l) - 1);
        ram[s].r = ret.a;
        ret.a = s;
        pull(s);
    }
    return ret;
}

int n, m, root, a, b;

void rev(int a, int b) {
    static Pr P1, P2;
    P1 = split(root, b);
    P2 = split(P1.a, a - 1);
    if(P2.b != -1) ram[P2.b].tag ^= 1;
    root = merge(P2.a, P2.b);
    root = merge(root, P1.b);
}

int main() {
    srand(0x94878787);
    while(~scanf("%d%d", &n, &m)) {
        int tmp; root = -1; tot = 0;
        for(int i =  1; i <= n; i++) {
            tmp = new_Node(i);
            root = merge(root, tmp);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            rev(a, b);
        }
        out(root); putchar('\n');
    }

    return 0;
}
