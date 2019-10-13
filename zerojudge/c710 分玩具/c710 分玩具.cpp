#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define maxn 300005
#define zerojudge
#ifdef zerojudge

#define getchar getchar_unlocked
#define putchar putchar_unlocked

#endif // zerojudge
using namespace std;
struct Pt {
    int x, k, id;
    Pt(int a, int b, int c) :
        x(a), k(b), id(c) {}
    bool operator < (const Pt &a) const {
        return x < a.x;
    }
};

template <class T> void read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 1) + (x << 3) + (c ^ '0');
}

template <class T> void put(T x) {
    static char buf[20], idx;
    if(x == 0) {
        putchar('0');
        putchar('\n');
        return;
    }
    for(idx = 0; x; idx++) {
        buf[idx] = (x % 10) ^ '0';
        x = x / 10;
    }
    for(idx--; ~idx; idx--) {
        putchar(buf[idx]);
    }
    putchar('\n');
}

int arr[maxn], cnt[maxn] = {}, ans[maxn] = {};
vector<Pt> V;
int n, m;

void add(int x) {
    static int i;
    for(i = 1; i * i < x; i++) {
        if(x % i == 0) {
            cnt[i]++;
            cnt[x / i]++;
        }
    }
    if(i * i == x) cnt[i]++;
}

int main() {
    read(n); read(m);
    for(int i = 1; i <= n; i++) {
        read(arr[i]);
    }
    for(int i = 1; i <= m; i++) {
        int l, r, k;
        read(l); read(r); read(k);
        V.emplace_back(l - 1, k, -i);
        V.emplace_back(r, k, i);
    }
    sort(V.begin(), V.end());
    for(int i = 0, j = 1; i < V.size(); i++) {
        while(j <= n && j <= V[i].x) {
            add(arr[j++]);
        }
        if(V[i].id < 0) ans[-V[i].id] -= cnt[V[i].k];
        else ans[V[i].id] += cnt[V[i].k];
    }
    for(int i = 1; i <= m; i++) {
        put(ans[i]);
    }
    return 0;
}
