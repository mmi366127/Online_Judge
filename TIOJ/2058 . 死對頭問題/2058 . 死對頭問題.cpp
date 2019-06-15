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
#define maxn 100007
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;


const loli INF = 0x3f3f3f3f3f3f3f3f;




void SP(vector<pll> G[], loli dis[], int s, int t) {
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
            int y = G[x][i].X;
            if(dis[y] > dis[x] + G[x][i].Y) {
                dis[y] = dis[x] + G[x][i].Y;
                pq.push({dis[y], y});
            }
        }
    }
}

loli dis[maxn], rvdis[maxn];
vector<pll> G[maxn], rvG[maxn];
int T, n, m, u, v, w, s, t;


int main() {
    YEE;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        cin >> s >> t;
        for(int i = 0; i < n; i++) {
            G[i].clear();
            rvG[i].clear();
        }
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            G[u].pb({v, w});
            rvG[v].pb({u, w});
        }
        MEM(dis, 0x3f);
        SP(G, dis, s, t);
        MEM(rvdis, 0x3f);
        SP(rvG, rvdis, t, s);
        loli MI = INF;
        for(int x = 0; x < n; x++) {
            for(int i = 0; i < G[x].size(); i++) {
                loli tmp = dis[x] + G[x][i].Y + rvdis[G[x][i].X];
                if(tmp > dis[t] && tmp < MI) MI = tmp;
            }
        }
        //cout << dis[t] << rvdis[s] << endl;
        //cout << MI << ' ' << dis[t] << endl;
        cout << MI - dis[t] << '\n';
    }
    return 0;
}
