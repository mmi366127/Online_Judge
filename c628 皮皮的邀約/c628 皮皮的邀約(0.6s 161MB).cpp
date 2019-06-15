#include<bits/stdc++.h>
#define maxn 200007
#define LOG 60
typedef unsigned long long int loli;
using namespace std;
struct Node{
    unsigned int l,r;
    // if you erase base-2, it would also AC(0.5s 129.9MB)
    loli b2, b3, b5, b7;// 2 base, 3 base, 5 base , 7 base
};
inline unsigned int read(){
    unsigned int tmp;
    static char c;
    while((c=getchar())<'0')
        if(c==EOF) return 0;
    tmp = c - '0';
    while((c=getchar())>='0')
        tmp = (tmp<<3) + (tmp<<1) + (c-'0');
    return tmp;
}
vector<unsigned int> change;
Node mem[maxn*LOG];
unsigned int history[maxn], ram;

inline void pull(unsigned int x){
    mem[x].b2 = mem[mem[x].l].b2 ^ mem[mem[x].r].b2;
    mem[x].b3 = mem[mem[x].l].b3 ^ mem[mem[x].r].b3;
    mem[x].b5 = mem[mem[x].l].b5 ^ mem[mem[x].r].b5;
    mem[x].b7 = mem[mem[x].l].b7 ^ mem[mem[x].r].b7;
}
unsigned int build(unsigned int L,unsigned int R){
    unsigned int x = ram++;
    mem[x].b2 = mem[x].b3 = mem[x].b5 = 0;
    if(L==R){
        return x;
    }
    unsigned int mid = (L+R)>>1;
    mem[x].l = build(L,mid);
    mem[x].r = build(mid+1,R);
    return x;
}
inline loli trans2(unsigned int pos){
    loli ret = 0;
    for(unsigned int i=0;i<20;i++){
        if(pos & (1<<i)){
            ret |= (1<<(2*i));
        } else {
            ret |= (1<<(2*i+1));
        }
    }
    return ret;
}
inline loli trans3(unsigned int pos){
    loli ret = 0;
    for(unsigned int t, i=0;i<12;i++){
        t = pos%3;
        if(t == 1){
            ret |= (1<<(i*3+1));
        } else if(t == 2){
            ret |= (1<<(i*3+2));
        } else {
            ret |= (1<<(i*3));
        }
        pos /= 3;
    }
    return ret;
}
inline loli trans5(unsigned int pos){
    loli ret = 0;
    for(unsigned int t, i=0;i<10;i++){
        t = pos%5;
        if(t == 1){
            ret |= (1<<(i*5+1));
        } else if(t == 2){
            ret |= (1<<(i*5+2));
        } else if(t == 3){
            ret |= (1<<(i*5+3));
        } else if(t == 4){
            ret |= (1<<(i*5+4));
        } else {
            ret |= (1<<(i*5));
        }
        pos /= 5;
    }
    return ret;
}
inline loli trans7(unsigned int pos){
    loli ret = 0;
    for(unsigned int t, i=0;i<8;i++){
        t = pos%7;
        if(t == 1){
            ret |= (1<<(i*7+1));
        } else if(t == 2){
            ret |= (1<<(i*7+2));
        } else if(t == 3){
            ret |= (1<<(i*7+3));
        } else if(t == 4){
            ret |= (1<<(i*7+4));
        } else if(t == 5){
            ret |= (1<<(i*7+5));
        } else if(t == 6){
            ret |= (1<<(i*7+6));
        } else {
            ret |= (1<<(i*7));
        }
        pos /= 7;
    }
    return ret;
}
unsigned int update(unsigned int x,unsigned int L,unsigned int R,unsigned int pos){
    int _x = ram++;
    if(L==R){
        mem[_x].b2 = mem[x].b2 ^ trans2(pos);
        mem[_x].b3 = mem[x].b3 ^ trans3(pos);
        mem[_x].b5 = mem[x].b5 ^ trans5(pos);
        mem[_x].b7 = mem[x].b7 ^ trans7(pos);
        //printf("%llu\n",mem[_x].val);
        return _x;
    }
    unsigned int mid = (L+R)>>1;
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
inline bool cute(int xl,int xr){
    return mem[xl].b2 ^ mem[xr].b2 || mem[xl].b3 ^ mem[xr].b3 || mem[xl].b5 ^ mem[xr].b5 || mem[xl].b7 ^ mem[xr].b7;
}
unsigned int query(unsigned int xl,unsigned int xr,unsigned int L,unsigned int R){
    if(L==R){
        return L;
    }
    unsigned int tmp,mid = (L+R)>>1;
    if(cute(mem[xl].r,mem[xr].r)){
        return query(mem[xl].r,mem[xr].r,mid+1,R);
    }
    if(cute(xl,xr)){
        return query(mem[xl].l,mem[xr].l,L,mid);
    }
    return 0;
}
unsigned int a[maxn];


int main(){
    unsigned int n,q,o,i,tsz,l,r,ans;
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
        //scanf("%d%d",&l,&r);
        l = read(); r = read();
        if(o){
            l = (l+ans)%n +1;
            r = (r+ans)%n +1;
        }
        if(l>r)
            swap(l,r);
        //printf("%d %d\n",l,r);
        ans = change[query(history[l-1],history[r],0,tsz-1)];
        printf("%u\n",ans);
    }
    return 0;
}
