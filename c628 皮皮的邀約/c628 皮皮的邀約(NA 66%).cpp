#include<bits/stdc++.h>
#define maxn 200007
#define LOG 60
using namespace std;
struct Node{
    int l,r;
    int val;
};
int read(){
    int tmp;
    static char c;
    while((c=getchar())<'0')
        if(c==EOF) return 0;
    tmp = c - '0';
    while((c=getchar())>='0')
        tmp = (tmp<<3) + (tmp<<1) + (c-'0');
    return tmp;
}
vector<int> change;
Node mem[maxn*LOG];
int history[maxn], ram;

void pull(int x){
    mem[x].val = mem[mem[x].l].val + mem[mem[x].r].val;
}
int build(int L,int R){
    int x = ram++;
    if(L==R){
        return x;
    }
    int mid = (L+R)>>1;
    mem[x].l = build(L,mid);
    mem[x].r = build(mid+1,R);
    return x;
}

int update(int x,int L,int R,int pos){
    int _x = ram++;
    if(L==R){
        mem[_x].val = mem[x].val+1;
        return _x;
    }
    int mid = (L+R)>>1;
    if(pos<=mid){
        mem[_x].l = update(mem[x].l,L,mid,pos);
        mem[_x].r = mem[x].r;
    } else {
        mem[_x].l = mem[x].l;
        mem[_x].r = update(mem[x].r,mid+1,R,pos);
    }
    pull(_x);
    return _x;
}

int query(int xl,int xr,int L,int R){
    if(L==R){
        if((mem[xr].val - mem[xl].val)&1)
            return L;
        return 0;
    }
    int tmp,mid = (L+R)>>1;
    if(mem[mem[xr].r].val-mem[mem[xl].r].val){
        tmp = query(mem[xl].r,mem[xr].r,mid+1,R);
        if(tmp)
            return tmp;

    }
    if(mem[mem[xr].l].val-mem[mem[xl].l].val){
        tmp = query(mem[xl].l,mem[xr].l,L,mid);
        if(tmp)
            return tmp;
    }
    return 0;
}
int a[maxn];


int main(){
    int n,q,o,i,tsz,l,r,ans;
    ram = 0;
    n = read(); q = read(); o = read();
    change.push_back(0);
    for(i=1;i<=n;i++){
        a[i] = read();
        change.push_back(a[i]);
    }
    sort(change.begin(),change.end());
    change.erase(unique(change.begin(),change.end()),change.end());
    tsz = change.size();
    history[0] = build(0,tsz-1);
    for(i=1;i<=n;i++){
        //printf("update %d\n",lower_bound(change.begin(),change.end(),a[i])-change.begin());
        history[i] = update(history[i-1],0,tsz-1,lower_bound(change.begin(),change.end(),a[i])-change.begin());
    }
    ans = 0;
    for(i=1;i<=q;i++){
        scanf("%d%d",&l,&r);
        if(o){
            l = (l+ans)%n +1;
            r = (r+ans)%n +1;
        }
        if(l>r)
            swap(l,r);
        ans = change[query(history[l-1],history[r],0,tsz-1)];
        printf("%d\n",ans);
    }
    return 0;
}
