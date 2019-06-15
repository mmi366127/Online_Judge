#include<stdio.h>
#include<string.h>
#define maxn 87


int n,m,ans;
int cnt[maxn], vis[maxn];
char adj[maxn][maxn];

bool dfs(int pot[], int total, int dep){
    if(total == 0){
        if(dep > ans){
            ans = dep;
            return true;
        }
        return false;
    }
    int i,j,k, tmp[maxn];
    for(int i=0;i<total;i++){
        if(cnt[pot[i]]+dep <= ans) return false;
        if(dep + total - i <= ans) return false;
        k = 0;
        for(j=i+1;j<total;j++)
            if(adj[pot[j]][pot[i]]) tmp[k++] = pot[j];
        if(dfs(tmp, k, dep+1)) return true;
    }
    return false;
}
void solve(){
    ans = -1e9;
    int i,j,k;
    int pot[maxn];
    for(i=n-1;i>=0;i--){
        for(k=0,j=i+1;j<n;j++){
            if(adj[i][j]) pot[k++] = j;
        }
        dfs(pot, k, 1);
        cnt[i] = ans;
    }
}




int main(){
    int i,j,u,v;
    scanf("%d%d",&n,&m);
    memset(adj,-1,sizeof(adj));
    for(i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        adj[u][v] = adj[v][u] = 0;
    }
    solve();
    printf("%d\n",ans);
}
