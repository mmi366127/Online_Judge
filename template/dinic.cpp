#include<vector>
#include<cstdio>
#include<queue>
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


int main(){
    //test
    Dinic loli(10);
    loli.add(0,1,1);
    loli.add(0,2,1);
    loli.add(0,3,1);
    loli.add(3,10,1);
    loli.add(2,10,1);
    loli.add(1,10,1);
    printf("%d\n",loli.max_flow(0,10));
    return 0;
}
