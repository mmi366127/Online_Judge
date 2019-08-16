#include <stdio.h>
#include <string.h>
#define swap(a, b) {int _ = a; a = b; b = _;}
#define maxn 100007
#define LOG 40
typedef struct Node {
    int s, p;
}Node;

#define getchar getchar_unlocked
#define putchar putchar_unlocked

Node ram[maxn * LOG];
int vision[maxn], tot = 0;
int n, m, op, x, y, cur = 0;

int rd() {
    static char c; int ret;
    for(c = getchar(); c < '0'; c = getchar())
        if(c == EOF) return 0;
    for(ret = 0; c >= '0'; c = getchar())
        ret = (ret << 3) + (ret << 1) + (c ^ '0');
    return ret;
}

int get_val(int x, int l, int r, int pos) {
    if(l == r) {
        return x;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) return get_val(ram[x].s, l, mid, pos);
    else return get_val(ram[x].p, mid+1, r, pos);
}

int build(int l, int r) {
    int x = tot++;
    if(l == r) {
        ram[x].s = 1;
        ram[x].p = l;
        return x;
    }
    int mid = (l + r) >> 1;
    ram[x].s = build(l, mid);
    ram[x].p = build(mid+1, r);
    return x;
}

int modify(int x, int l, int r, int pos, int p, int s) {
    int _x = tot++;
    if(l == r) {
        ram[_x].s = s;
        ram[_x].p = p;
        return _x;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) {
        ram[_x].s = modify(ram[x].s, l, mid, pos, p, s);
        ram[_x].p = ram[x].p;
    } else {
        ram[_x].s = ram[x].s;
        ram[_x].p = modify(ram[x].p, mid+1, r, pos, p, s);
    }
    return _x;
}

int find(int x) {
    int ptr = get_val(vision[cur - 1], 1, n, x);
    return (ram[ptr].p == x) ? ptr : find(ram[ptr].p);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(ram[x].p == ram[y].p) {
        vision[cur] = vision[cur - 1];
        return;
    }
    if(ram[x].s < ram[y].s)
        swap(x, y);
    vision[cur] = modify(vision[cur - 1], 1, n, ram[x].p, ram[x].p, ram[x].s + ram[y].s);
    vision[cur] = modify(vision[cur], 1, n, ram[y].p, ram[x].p, ram[y].s);
}


int main() {
    n = rd(); m = rd(); int pre = 0;
    vision[0] = build(1, n);
    for(cur = 1; cur <= m; cur++) {
        op = rd() ^ pre;
        if(op == 0) {
            vision[cur] = vision[rd() ^ pre];
        } else if(op == 1) {
            join(rd() ^ pre, rd() ^ pre);
        } else {
            if(ram[find(rd() ^ pre)].p == ram[find(rd() ^ pre)].p) {
                putchar('1');
                pre = 1;
            } else {
                putchar('0');
                pre = 0;
            }
            putchar('\n');
            vision[cur] = vision[cur - 1];
        }
    }
    return 0;
}
