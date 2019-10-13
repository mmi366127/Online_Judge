#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long loli;
struct Node {
    long long dis;
    int pre, cur;
    Node(){}
    Node(long long d, int p, int c) :
        dis(d), pre(p), cur(c){}
};


vector<pair<long long, int>> G[maxn];
loli tot[maxn * 100];
int n, N, TOT = 0;

struct Queue {
    Node arr[maxn];
    int l, r;
    Queue() {
        l = r = 0;
    }
    void clear() {
        l = r = 0;
    }
    void pop() {
        l++;
        if(l >= maxn) l = 0;
    }
    void push(Node a) {
        arr[r++] = a;
        if(r >= maxn) r = 0;
    }
    Node front() {
        return arr[l];
    }
    bool empty() {
        return l == r;
    }
}Q;


bool check(loli X) {
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        Q.clear();
        Q.push(Node(0, -1, i));
        while(!Q.empty()) {
            Node x = Q.front(); Q.pop();
            for(auto y : G[x.cur]) {
                if(y.second == x.pre) continue;
                if(x.dis + y.first <= X) {
                    Q.push(Node(x.dis + y.first, x.cur, y.second));
                    if(y.second > i) {
                        cnt++;
                        if(cnt >= N)
                            return false;
                    }
                } else break;
            }
        }
    }
    return cnt < N;
}

void bfs(loli X) {
    for(int i = 1; i < n; i++) {
        Q.clear();
        Q.push(Node(0, -1, i));
        while(!Q.empty()) {
            Node x = Q.front(); Q.pop();
            for(auto y : G[x.cur]) {
                if(y.second == x.pre) continue;
                if(x.dis + y.first <= X) {
                    Q.push(Node(x.dis + y.first, x.cur, y.second));
                    if(y.second > i) {
                        tot[TOT++] = x.dis + y.first;
                        //tot.emplace_back(x.dis + y.first);
                    }
                } else break;
            }
        }
    }
}

int main() {
    scanf("%d", &n); N = n * 5;
    for(int i = 1; i < n; i++) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        G[u].emplace_back(d, v);
        G[v].emplace_back(d, u);
    }
    for(int i = 1; i <= n; i++)
        sort(G[i].begin(), G[i].end());
    int i; loli ans = 0;
    for(i = 0; i < 51; i++) {
        if(!check(1LL << i)) break;
    }
    ans = 1LL << (i - 1);
    for(i--; i >= 0; i--) {
        if(check(ans + (1LL << i))) {
            ans += (1LL << i);
        }
    }
    if(n < 12) {
        bfs(ans + 1);
        sort(tot, tot + TOT);
        //for(auto x : tot) printf("%lld ", x); puts("");
        for(int i = 4; i < 5 * n; i += 5) {
            if(i < TOT)
                printf("%lld ", tot[i]);
            else
                printf("-1 ");
        }
    } else {
        bfs(ans++);
        sort(tot, tot + TOT);
        for(int i = 4; i < 5 * n; i += 5) {
            if(i < TOT)
                printf("%lld ", tot[i]);
            else
                printf("%lld ", ans);
        }
    }
    printf("\n");
    return 0;
}

