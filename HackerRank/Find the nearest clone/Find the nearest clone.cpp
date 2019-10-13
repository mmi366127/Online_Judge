#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

const int INF = 0x3f3f3f3f;

int color[maxn], dis[maxn], root[maxn] = {};
vector<int> G[maxn];
int n, m, tar;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", color + i);
    }
    scanf("%d", &tar);
    memset(dis, 0x3f, sizeof(dis));
    queue<int> Q;
    for(int i = 1; i <= n; i++) {
        if(color[i] == tar) {
            Q.push(i); dis[i] = 0;
            root[i] = i;
        }
    }
    if(Q.size() <= 1) {
        puts("-1");
        return 0;
    }
    while(Q.size()) {
        int x = Q.front(); Q.pop();
        for(int t : G[x]) {
            if(!root[t]) {
                dis[t] = dis[x] + 1;
                Q.push(t); root[t] = root[x];
            } else if(root[t] != root[x]){
                printf("%d\n", dis[t] + dis[x] + 1);
                return 0;
            }
        }
    }
    return 0;
}
