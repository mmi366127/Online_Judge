#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define maxn 500005
#define maxm 100005
using namespace std;

const int INF = (1 << 20);

#define getchar getchar_unlocked

void read(int &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
}

int n, k, p, x, cnt, ans = 0;
int dish[maxn], nxt[maxn], head[maxm] = {};

struct cmp {
    bool operator()(const int &a, const int &b) {
        return nxt[a] < nxt[b];
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main() {
    read(n), read(k), read(p);
    for(int i = 1; i <= p; i++) {
        read(dish[i]);
    }
    for(int i = p; i > 0; i--) {
        if(!head[dish[i]]) {
            nxt[i] = INF;
            head[dish[i]] = i;
        } else {
            nxt[i] = head[dish[i]];
            head[dish[i]] = i;
        }
    }
    cnt = 0;
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= p; i++) {
        if(head[dish[i]] >  0) {
            pq.push(i);
            continue;
        }
        ans++;
        if(cnt < k) {
            head[dish[i]] = ++cnt;
            pq.push(i);
        } else {
            x = dish[pq.top()]; pq.pop();
            //printf("%d YEE%d\n", i, x);
            head[dish[i]] = head[x];
            head[x] = -1;
            pq.push(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
