#include<iostream>
#include<vector>
using namespace std;

struct hungary{
    vector<vector<int>> e;
    vector<int> mx, my;
    vector<bool> vis;
    int _x, _y;
    hungary(int x,int y) : e(x+1), mx(x+1,-1), my(x+1,-1), vis(y+1){_x = x, _y = y;}
    void add(int x,int y){
        e[x].push_back(y);
    }
    bool dfs(int x){
        for(int y : e[x]){
            if(!vis[y]){
                vis[y] = true;
                if(my[y]==-1 || dfs(my[y])){
                    mx[x] = y;
                    my[y] = x;
                    return true;
                }
            }

        }
    }
    int cal(){
        int i,ans = 0;
        for(i=1;i<=_x;i++){
            if(mx[i] == -1){
                vis.assign(_y+1,false);
                if(dfs(i))
                    ans++;
            }
        }
        return ans;
    }
};

int t,n,x,y,m;

int main(){
    // test
    cin>>t;
    while(t--){
        cin>>x>>y>>m;
        hungary loli(x,y);
        while(m--){
            cin>>x>>y;
            loli.add(x,y);
        }
        cout<<loli.cal()<<endl;
    }
    return 0;
}
