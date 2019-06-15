#includebitsstdc++.h
#define ls(x) (x1)
#define rs(x) ((x1)1)
#define maxn 200007
using namespace std;
struct seg{
    vectorint ST;
    seg(int _sz)  ST(_sz2) {}
    void build(int x,int L,int R,int a[]){
        if(L==R){
            ST[x] = a[L];
            return;
        }
        int mid = (L+R)1;
        build(ls(x),L,mid,a);
        build(rs(x),mid+1,R,a);
        ST[x] = max(ST[ls(x)],ST[rs(x)]);
    }
    int query(int x,int L,int R,int l,int r){
        if(rLRl)
            return 0;
        else if(l=L&&R=r)
            return ST[x];
        int mid = (L+R)1;
        return max(query(ls(x),L,mid,l,r),query(rs(x),mid+1,R,l,r));
    }
};
mapint,int cnt[2];
void add(int n){
    if(cnt[1].find(n)!=cnt[1].end()){
        cnt[0][n] = cnt[1][n]+1;
        cnt[1].erase(n);
    } else {
        if(cnt[0].find(n)==cnt[0].end()){
            cnt[1][n] = 1;
        } else {
            cnt[1][n] = cnt[0][n]+1;
            cnt[0].erase(n);
        }
    }
}
void kill(int n){
    if(cnt[0].find(n)!=cnt[0].end()){
        cnt[1][n] = cnt[0][n]-1;
        cnt[0].erase(n);
    } else {
        if(cnt[1][n]1){
            cnt[0][n] = cnt[1][n]-1;
        }
        cnt[1].erase(n);
    }
}
struct qu{
    int l,r,id,block;
};
bool cmp(qu a,qu b){
    return a.block==b.block  a.rb.r  a.blockb.block;
}
vectorqu Q;
int a[maxn];

int main(){
    int n,q,o,l,r,i;
    scanf(%d%d%d,&n,&q,&o);
    if(o){
        int ans = 0;
        seg SG(n);
        for(int i=1;i=n;i++){
            scanf(%d,a+i);
        }
        SG.build(1,1,n,a);
        for(int i=1;i=q;i++){
            scanf(%d%d,&l,&r);
            l = (l+ans)%n +1;
            r = (r+ans)%n +1;
            if(lr)
                swap(l,r);
            printf(%d %dn,l,r);
            ans = SG.query(1,1,n,l,r);
            printf(%dn,ans);
        }
    } else {
        int k = sqrt(n)+1;
        for(i=1;i=n;i++){
            scanf(%d,a+i);
        }
        for(i=1;i=q;i++){
            scanf(%d%d,&l,&r);
            Q.push_back({l,r,i,lk});
        }
        int ans[q+1];
        sort(Q.begin(),Q.end(),cmp);
        cnt[0].clear();
        cnt[1].clear();
        l = 1; r = 1;
        add(a[1]);
        for(int i=0;iQ.size();i++){
            while(lQ[i].l) kill(a[l++]);
            while(lQ[i].l) add(a[--l]);
            while(rQ[i].r) add(a[++r]);
            while(rQ[i].r) kill(a[r--]);
            if(cnt[1].size())
                ans[Q[i].id] = prev(cnt[1].end())-first;
            else
                ans[Q[i].id] = 0;
        }
        for(i=1;i=q;i++)
            printf(%dn,ans[i]);
    }
    return 0;
}
