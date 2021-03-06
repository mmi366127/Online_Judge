#include<bits/stdc++.h>
using namespace std;
#define maxn 50007
#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
typedef long long int loli;
loli max(loli a,loli b){return a>b ? a:b;}
loli min(loli a,loli b){return a<b ? a:b;}
int read(){
    int tmp;
    static char c;
    while((c=getchar())<'0')
        if(c==EOF) return 0;
    tmp = c-'0';
    while((c=getchar())>='0')
        tmp = (tmp<<3) + (tmp<<1) + (c-'0');
    return tmp;
}
loli ST[maxn<<3];
int val[maxn], cost[maxn], in_val[maxn], in_cos[maxn];
int tree[2][maxn];
int idx;
int top[2][maxn];
loli dp[2][maxn];
vector<int> change;
void dfs(int x){
    if(x==0)
        return;
    dfs(tree[0][x]);
    in_val[idx] = val[x];
    in_cos[idx++] = cost[x];
    dfs(tree[1][x]);
}
void build(int x,int L,int R){
    ST[x] = 0;
    if(L==R){
        return;
    }
    int mid = (L+R)>>1;
    build(ls(x),L,mid);
    build(rs(x),mid+1,R);
}
void update(int x,int L,int R,int pos,loli val){
    if(L==R){
        ST[x] = max(val,ST[x]);
        return;
    }
    int mid = (L+R)>>1;
    if(pos<=mid)
        update(ls(x),L,mid,pos,val);
    else
        update(rs(x),mid+1,R,pos,val);
    ST[x] = max(ST[ls(x)],ST[rs(x)]);
}
loli query(int x,int L,int R,int l,int r){
    if(r<L||R<l)
        return 0;
    else if(l<=L&&R<=r)
        return ST[x];
    int mid = (L+R)>>1;
    return max(query(ls(x),L,mid,l,r),query(rs(x),mid+1,R,l,r));
}
int main(){
    int t,n,l,r,i,j;
    loli sum,ans;
    t = read();
    while(t--){
        change.clear();
        sum = 0;
        n = read();
        for(i=1;i<=n;i++){
            tree[0][i] = read();
            tree[1][i] = read();
        }
        for(i=1;i<=n;i++)
            val[i] = read();
        for(i=1;i<=n;i++)
            cost[i] = read(), sum = sum + cost[i];
        idx = 1; dfs(1);
        for(i=1;i<=n;i++){
            change.push_back(in_val[i]-i);
        }
        sort(change.begin(),change.end());
        change.erase(unique(change.begin(),change.end()),change.end());
        int tsz = change.size();
        build(1,0,tsz-1);
        for(i=1;i<=n;i++){
            ans = query(1,0,tsz-1,0,lower_bound(change.begin(),change.end(),in_val[i]-i)-change.begin()) + in_cos[i];
            update(1,0,tsz-1,lower_bound(change.begin(),change.end(),in_val[i]-i)-change.begin(),ans);
        }
        printf("%lld\n",sum-ST[1]);
    }
    return 0;
}
