#include<iostream>
#include<vector>
#include<queue>
#define maxn 107
using namespace std;

struct HK{
    struct Edge{
        int to, pre;
    };
    vector<Edge> edge;
    vector<int> mx, my, dx, dy, head;
    int n,m;
    HK(int n,int m): n(n), m(m), mx(n+1,-1), my(m+1,-1), dx(n+1), dy(m+1), head(n+1,-1){}
    void add(int u,int v){
        edge.push_back({v,head[u]});
        head[u] = edge.size()-1;
    }
    bool bfs(){
        bool flag = false;
        queue<int> Q;
        fill(dy.begin(),dy.end(),0);
        fill(dx.begin(),dx.end(),0);
        for(int i=1;i<=n;i++){
            if(mx[i] == -1)
                Q.push(i), dx[i] = 1;
        }
        while(!Q.empty()){
            int x = Q.front();
            Q.pop();
            for(int i=head[x];i!=-1;i=edge[i].pre){
                int y = edge[i].to;
                if(!dy[y]){
                    dy[y] = dx[x]+1;
                    if(my[y] == -1) flag = true;
                    else {
                        dx[my[y]] = dy[y]+1;
                        Q.push(my[y]);
                    }
                }
            }
        }
        return flag;
    }
    bool dfs(int x){
        for(int i=head[x];i!=-1;i=edge[i].pre){
            int y = edge[i].to;
            if(dy[y] == dx[x]+1){
                dy[y] = 0;
                if(my[y] == -1 || dfs(my[y])){
                    mx[x] = y;
                    my[y] = x;
                    return true;
                }
            }
        }
        return false;
    }
    int cal(){
        int ans = 0;
        while(bfs()){
            for(int i=1;i<=n;i++)
                if(mx[i] == -1 && dfs(i)) ans++;
        }
        return ans;
    }
};

char s[maxn], M[maxn][maxn];
int id[maxn][maxn], idx;
int n, m, r, c, cnt;

bool in(int x, int y) {
    return (0 <= x && x < m) && (0 <= y && y < n);
}

int main(){
    scanf("%d%d%d%d", &n, &m, &r, &c);
    fgets(s, sizeof(s), stdin);
    for(int i = 0, idx = 0; i < n; i++) {
        fgets(s, sizeof(s), stdin);
        for(int j = 0; j < m; j++) {
            M[j][i] = s[j];
            id[j][i] = ++idx;
        }
    }
    HK cute(n * m, n * m); cnt = 0;
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(M[x][y] == 'x') {
                cnt++;
                continue;
            }
            if(in(x + r, y + c) && M[x+r][y+c] == '.') {
                //printf("%d %d --> %d %d\n", x, y, x + r, y + c);
                cute.add(id[x][y], id[x+r][y+c]);
            }
            if(in(x - r, y + c) && M[x-r][y+c] == '.') {
                //printf("%d %d --> %d %d\n", x, y, x - r, y + c);
                cute.add(id[x][y], id[x-r][y+c]);
            }
            if(in(x + c, y + r) && M[x+c][y+r] == '.') {
                //printf("%d %d --> %d %d\n", x, y, x + c, y + r);
                cute.add(id[x][y], id[x+c][y+r]);
            }
            if(in(x - c, y + r) && M[x-c][y+r] == '.') {
                //printf("%d %d --> %d %d\n", x, y, x - c, y + r);
                cute.add(id[x][y], id[x-c][y+r]);
            }
        }
    }
    printf("%d\n", n * m - cute.cal() - cnt);
    return 0;
}

