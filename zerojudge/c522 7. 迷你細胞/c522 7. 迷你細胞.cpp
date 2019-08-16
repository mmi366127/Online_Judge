#pragma gcc optimize("unroll-loop")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int s, p;
    Node(int a = 1, int b = -1) :
        s(a), p(b) {}
};

//#define getchar getchar_unlocked
//#define putchar putchar_unlocked

template <class T>
void read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0LL; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
}

template <class T>
void put(T x) {
    static char buf[50], idx;
    if(x == 0LL) {
        putchar('0');
        putchar('\n');
        return;
    }
    for(idx = 0; x > 0; x /= 10) {
        buf[idx++] = (x % 10) ^ '0';
    }
    for(idx--; idx >= 0; idx--) {
        putchar(buf[idx]);
    }
    putchar('\n');
}

void Mukyu() {
    putchar('M');
    putchar('u');
    putchar('k');
    putchar('y');
    putchar('u');
    putchar('\n');
}

vector<Node> ram;
vector<int> history;
int N;

int build(int L, int R) {
    int x = ram.size();
    ram.emplace_back(1, -1);
    if(L == R) {
        return x;
    }
    int M = (L + R) >> 1;
    ram[x].s = build(L, M);
    ram[x].p = build(M + 1, R);
    return x;
}

void init(int n) {
    N = n;
    history[0] = build(1, n);
}

Node get_(int pos, int x, int L = 1, int R = N) {
    if(L == R) {
        return ram[x];
    }
    int M = (L + R) >> 1;
    if(pos <= M)
        return get_(pos, ram[x].s, L, M);
    else
        return get_(pos, ram[x].p, M + 1, R);
}

Node get(int ver, int pos) {
    return get_(pos, history[ver]);
}

int modify(int x, int pos, int s, int p, int L = 1, int R = N) {
    int _x = ram.size();
    ram.emplace_back(s, p);
    if(L == R) {
        return _x;
    }
    int M = (L + R) >> 1;
    if(pos <= M) {
        ram[_x].s = modify(ram[x].s, pos, s, p, L, M);
        ram[_x].p = ram[x].p;
    } else {
        ram[_x].s = ram[x].s;
        ram[_x].p = modify(ram[x].p, pos, s, p, M + 1, R);
    }
    return _x;
}

/* ------------- YEE ------------ */

int find(int ver, int x) {
    Node tmp = get(ver, x);
    return (tmp.p == -1) ? x : find(ver, tmp.p);
}

int n, m, x, y, tx, ty;
Node X, Y;

int main() {
    ram.reserve(25000000);
    read(n), read(m);
    history.resize(m + 1);
    init(n);
    for(int i = 1; i <= m; i++) {
        read(x); read(y);
        if((tx = find(i - 1, x)) == (ty = find(i - 1, y))) {
            history[i] = history[i - 1];
            int L = 0, R = i - 1;
            while(R - L > 1) {
                int M = (L + R) >> 1;
                if(find(M, x) == find(M, y))
                    R = M;
                else
                    L = M;
            }
            put(R);

        } else {

            Mukyu();

            X = get(i - 1, tx);
            Y = get(i - 1, ty);
            if(X.s < Y.s)
                swap(X, Y), swap(tx, ty);



            // s[x] += s[y]
            // p[y] = x;
            history[i] = modify(history[i - 1], tx, X.s + Y.s, X.p);
            history[i] = modify(history[i],     ty,       Y.s,  tx);


        }
    }
    return 0;
}
