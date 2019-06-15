#include <bits/stdc++.h>
#define X first
#define Y second
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define lowbit(X) ((X)&-(X))
#define MEM(X, val) memset((X), (val), sizeof(X));
#define pb push_back
#define ins insert
#define mp make_pair
#define YEE ios_base::sync_with_stdio(0); cin.tie()
#define maxn 1000007
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;


const loli INF = 0x3f3f3f3f3f3f3f3f;

vector<vector<pll>> G, revG;
loli dis[maxn], revdis[maxn];

void SP(vector<vector<pll>> &G, loli dis[], int s) {
    static priority_queue<pll,vector<pll>,greater<pll>> pq;
    while(pq.size()) pq.pop();
    dis[s] = 0;
    pq.push({0, s});
    while(pq.size()) {
        int x = pq.top().Y;
        loli d = pq.top().X;
        pq.pop();
        if(dis[x] != d) continue;
        for(int i = 0; i < G[x].size(); i++) {
            int y  = G[x][i].X;
            if(dis[y] > dis[x] + G[x][i].Y) {
                dis[y] = dis[x] + G[x][i].Y;
                pq.push({dis[y], y});
            }
        }
    }
}


int n, m, u, v, w;

int main() {
    YEE;
    cin >> n >> m;
    G.resize(n+1); revG.resize(n+1);
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        G[u].pb({v, w});
        revG[v].pb({u, w});
    }
    MEM(dis, 0x3f);
    MEM(revdis, 0x3f);
    SP(G, dis, 1);
    SP(revG, revdis, 1);
    loli ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dis[i] + revdis[i];
    }
    cout << ans << '\n';
    return 0;
}
