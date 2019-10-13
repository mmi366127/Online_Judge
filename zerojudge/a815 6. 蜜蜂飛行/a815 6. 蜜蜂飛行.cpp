#include <bits/stdc++.h>
#define maxn 305
#define X first
#define Y second
using namespace std;

const long long int INF = (1<<30);

struct Dinic{
    struct Edge{
        int to, pre;
        long long flow;
    };
    int s, t;
    vector<Edge> edge;
    vector<int> dis, head;
    Dinic(int n) : dis(n+1), head(n+1,-1){}
    void add(int u,int v,long long flow){
        edge.push_back({v,head[u],flow});
        head[u] = edge.size()-1;
        edge.push_back({u,head[v],0});
        head[v] = edge.size()-1;
    }
    void set_st(int _s,int _t){
        s = _s, t = _t;
    }
    void init(int sz) {
        edge.clear();
        dis.resize(sz + 1);
        head.resize(sz + 1);
        fill(dis.begin(), dis.end(), 0);
        fill(head.begin(), head.end(), 0);
    }
    bool bfs(){
        queue<int> Q;
        fill(dis.begin(),dis.end(),0);
        Q.push(s); dis[s] = 1;
        while(!Q.empty()){
            int x = Q.front();
            Q.pop();
            if(x == t) return true;
            for(int i=head[x];i!=-1;i=edge[i].pre){
                int y = edge[i].to;
                if(edge[i].flow > 0 && !dis[y]){
                    dis[y] = dis[x]+1;
                    Q.push(y);
                }
            }
        }
        return false;
    }
    long long dfs(int x,long long f){
        long long a,flow = 0;
        if(x == t || f == 0)
            return f;
        for(int i=head[x];i!=-1;i=edge[i].pre){
            int y = edge[i].to;
            if(dis[y] == dis[x]+1 && edge[i].flow > 0){
                a = dfs(y,min(f,edge[i].flow));
                f -= a; flow += a;
                edge[i].flow -= a;
                edge[i^1].flow += a;
                if(f == 0){
                    return flow;
                }
            }
        }
        return flow;
    }
    long long max_flow(int _s,int _t){
        set_st(_s,_t);
        long long flow = 0;
        while(bfs()){
            flow += dfs(s,INF);
        }
        return flow;
    }
};


template<class T> void read(T &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 1) + (x << 3) + (c ^ '0');
}

int mx[] = {0, -1, 1, 0, 1, -1};
int my[] = {1, 0, 0, -1, -1, 1};

int pre_x[maxn][maxn], pre_y[maxn][maxn];
char MAP[maxn][maxn];
int n, m, T;

void print() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            putchar(MAP[j][i]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int idx(int x, int y) {
    x--; y--;
    return x * m + y;
}

int main() {
    read(T);
    while(T--) {
        read(n); read(m);
        Dinic cute (n * m * 2 + 5);
        memset(MAP, 0, sizeof(MAP));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                char c = getchar();
                while(c != '.' && c != 'O') {
                    c = getchar();
                }
                MAP[j][i] = c;
                if(c == '.') {
                    if(i == j && i == 0)
                    cute.add(idx(j, i), n * m + idx(j, i), );
                }
            }
        }
        queue< pair<int, int> > Q;
        Q.push({1, 1}); MAP[1][1] = '?';
        pre_x[1][1] = pre_y[1][1] = -1;
        while(Q.size()) {
            auto cur = Q.front(); Q.pop();
            for(int i = 0; i < 6; i++) {
                int x = cur.X + mx[i];
                int y = cur.Y + my[i];
                if(MAP[x][y] == '.') {
                    MAP[x][y] = '?';
                    Q.push({x, y});
                    pre_x[x][y] = cur.X;
                    pre_y[x][y] = cur.Y;
                }
            }
        }
        print();
        if(MAP[m][n] == '.') {
            puts("0"); continue;
        }
        int _x = pre_x[m][n], _y = pre_y[m][n], x, y;
        while(_x > 0) {
            x = _x;
            y = _y;
            MAP[x][y] = 'O';
            _x = pre_x[x][y];
            _y = pre_y[x][y];
        }
        print();
        Q.push({1, 1}); MAP[x][y] = '!';
        while(Q.size()) {
            auto cur = Q.front(); Q.pop();
            for(int i = 0; i < 6; i++) {
                int x = cur.X + mx[i];
                int y = cur.Y + my[i];
                if(MAP[x][y] == '?') {
                    MAP[x][y] = '!';
                    Q.push({x, y});
                }
            }
        }
        //print();
        if(MAP[m][n] != '!') {
            puts("1"); continue;
        }
        puts("2");
    }
    return 0;
}
