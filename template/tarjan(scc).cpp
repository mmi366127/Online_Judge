#include<vector>
#include<cstdio>
#include<stack>
#define output
using namespace std;


struct tarjan {
    vector<vector<int>> G;
    vector<int> low, vis;
    vector<bool> instk;
    stack<int> stk;
    int t,ans,n;
    tarjan(int _n) : n(_n), G(_n+1), low(_n+1,0), vis(_n+1,0), instk(_n+1,false){}
    void add(int u,int v){
        G[u].push_back(v);
    }
    void dfs(int x){
        vis[x] = low[x] = ++t;
        stk.push(x); instk[x] = true;
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i];
            if(!vis[y]){
                dfs(y);
                low[x] = min(low[x],low[y]);
            } else if(instk[y]){
                low[x] = min(low[x],vis[y]);
            }
        }
        if(vis[x] == low[x]){
            int p = -1, cnt = 0;
            while(!stk.empty() && p!=x){
                p = stk.top();
#ifdef output
                printf("%d ",p);
#endif // output
                instk[p] = false;
                stk.pop(); cnt++;
            }
#ifdef output
            puts("");
#endif // output
            ans = max(ans,cnt);
        }
    }
    int solve(){
        t = 0; ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i);
        }
        return ans;
    }
};
/*
6
8
1 3
1 2
2 4
3 4
3 5
4 1
4 6
5 6
*/

int main(){
    int n,m,i,u,v;
    scanf("%d%d",&n,&m);
    tarjan loli(n);
    for(i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        loli.add(u,v);
    }
    printf("%d\n",loli.solve());
    return 0;
}
