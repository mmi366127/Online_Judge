#include <bits/stdc++.h>
using namespace std;
typedef long long loli;

const loli INF = 0x3f3f3f3f3f3f3f3f;

vector< vector< pair<int, int> > > GA, GB;
vector<loli> CA, CB, dis;
vector<int> TA, TB;

int n1, t1, m1, n2, t2, m2, u, v, w;

loli SP(vector<loli> &dis, vector< vector< pair<int, int> > > &G, int s) {
    static priority_queue< pair<loli, int>, vector< pair<loli, int> >, greater< pair<loli, int> > > pq;
    while(pq.size()) pq.pop();
    fill(dis.begin(), dis.end(), INF);
    dis[s] = 0; pq.push({0, s});
    while(pq.size()) {
        int x = pq.top().second;
        loli d = pq.top().first;
        pq.pop();
        if(d != dis[x]) continue;
        for(int i = 0; i < G[x].size(); i++) {
            int y = G[x][i].first, w = G[x][i].second;
            if(dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                pq.push({dis[y], y});
            }
        }
    }
    loli ret = 0;
    for(int i = 1; i < dis.size(); i++) ret = max(ret, dis[i]);
    return ret;
}


int main() {
    scanf("%d%d%d", &n1, &t1, &m1);
    GA.resize(n1 + 1); TA.resize(t1);
    for(int i = 0; i < t1; i++) {
        scanf("%d", &TA[i]);
    }
    for(int i = 0; i < m1; i++) {
        scanf("%d%d%d", &u, &v, &w);
        GA[u].push_back({v, w});
        GA[v].push_back({u, w});
    }
    CA.resize(t1); dis.resize(n1 + 1);
    for(int i = 0; i < t1; i++) {
        CA[i] = SP(dis, GA, TA[i]);
    }

    scanf("%d%d%d", &n2, &t2, &m2);
    GB.resize(n2 + 1); TB.resize(t2);
    for(int i = 0; i < t2; i++) {
        scanf("%d", &TB[i]);
    }
    for(int i = 0; i < m2; i++) {
        scanf("%d%d%d", &u, &v, &w);
        GB[u].push_back({v, w});
        GB[v].push_back({u, w});
    }
    CB.resize(t2); dis.resize(n2 + 1);
    for(int i = 0; i < t2; i++) {
        CB[i] = SP(dis, GB, TB[i]);
    }
    loli ans = INF;
    for(int i = 0; i < t1; i++) {
        for(int j = 0; j < t2; j++) {
            ans = min(ans, CA[i] + CB[j] + 1000);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
