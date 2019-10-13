#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define maxn 10005
using namespace std;


vector<int> G[maxn], GG[maxn];
int pre[maxn] = {}, nxt[maxn] = {};
int in[maxn] = {}, out[maxn] = {};
bitset<maxn> vis[maxn];
int n, m, u, v;



int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        GG[u].push_back(v);
        G[v].push_back(u);
        in[u]++; out[v]++;
    }
    // topo
    queue<int> Q;
    for(int i = 1; i <= n; i++) {
        vis[i].reset();
        vis[i][i] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) {
            Q.push(i);
        }
    }
    while(Q.size()) {
        int x = Q.front(); Q.pop();
        for(int y : G[x]) {
            in[y]--;
            vis[y] |= vis[x];
            if(in[y] == 0) Q.push(y);
        }
    }
    for(int i = 1; i <= n; i++) {
        pre[i] = vis[i].count();
        vis[i].reset();
        vis[i][i] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(out[i] == 0) {
            Q.push(i);
        }
    }
    while(Q.size()) {
        int x = Q.front(); Q.pop();
        for(int y : GG[x]) {
            out[y]--;
            vis[y] |= vis[x];
            if(out[y] == 0) Q.push(y);
        }
    }
    for(int i = 1; i <= n; i++) {
        nxt[i] = vis[i].count();
    }


    for(int i = 1; i <= n; i++) {
        printf("%d %d\n", pre[i], n - nxt[i] + 1);
    }
    return 0;
}

/*
10 5
1 10
2 10
3 10
10 5
10 6


4 10
4 10
4 10
1 10
1 6
1 6
1 10
1 10
1 10
3 7
*/
