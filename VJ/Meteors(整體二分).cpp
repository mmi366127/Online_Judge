#include <bits/stdc++.h>
#define lowbit(X) ((X)&(-(X)))
#define maxn 300007
using namespace std;
struct Pt {
    int l, r;
    long long w;
    Pt(int a, int b, long long c) :
        l(a), r(b), w(c) {}
};

namespace BIT {
    long long bit[maxn] = {};
    void add(int x, long long v) {
        while(x < maxn) {
            bit[x] += v;
            x += lowbit(x);
        }
    }
    void ADD(int l, int r, long long v) {
        add(l, v); add(r + 1, -v);
    }
    long long qry(int x) {
        static long long ret;
        for(ret = 0; x; x -= lowbit(x)) {
            ret += bit[x];
        }
        return ret;
    }
}

const long long INF = 1000000000000000LL;

long long Goal[maxn], ans[maxn];
vector<int> country[maxn];
vector<Pt> V;
int n, m, k;

void solve(int l, int r, vector<int> &Q) {
    if(l == r || Q.empty()) {
        for(int t : Q) {
            ans[t] = l;
        }
        return;
    }
    int mid = (l + r) >> 1;
    for(int i = l; i <= mid; i++) {
        if(V[i].l <= V[i].r) {
            BIT::ADD(V[i].l, V[i].r, V[i].w);
        } else {
            BIT::ADD(1, V[i].r, V[i].w);
            BIT::ADD(V[i].l, n, V[i].w);
        }
    }
    vector<int> ql, qr;
    for(int t : Q) {
        long long sum = 0;
        for(int x : country[t]) {
            sum += BIT::qry(x);
            if(sum >= INF) break;
        }
        if(sum >= Goal[t]) {
            ql.push_back(t);
        } else {
            Goal[t] -= sum;
            qr.push_back(t);
        }
    }
    for(int i = l; i <= mid; i++) {
        if(V[i].l <= V[i].r) {
            BIT::ADD(V[i].l, V[i].r, -V[i].w);
        } else {
            BIT::ADD(1, V[i].r, -V[i].w);
            BIT::ADD(V[i].l, n, -V[i].w);
        }
    }
    solve(l, mid, ql);
    solve(mid + 1, r, qr);
}

signed main() {
    scanf("%lld%lld", &m, &n);
    for(int i = 1; i <= n; i++) {
        int x; scanf("%lld", &x);
        country[x].emplace_back(i);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%lld", Goal + i);
    }
    scanf("%lld", &k);
    V.emplace_back(0, 0, 0);
    for(int i = 0; i < k; i++) {
        int l, r, w;
        scanf("%lld%lld%lld", &l, &r, &w);
        V.emplace_back(l, r, w);
    }
    V.emplace_back(1, n, INF);
    vector<int> Q;
    for(int i = 1; i <= m; i++) {
        Q.push_back(i);
    }
    solve(1, k + 1, Q);
    for(int i = 1; i <= m; i++) {
        if(ans[i] == k + 1) puts("NIE");
        else printf("%lld\n", ans[i]);
    }
    return 0;
}
/*
#include<cstdio>
#include<iostream>
using namespace std;
#define inf 100000000000ll
#define ll long long
#define N 300005

int n,m,x,fi[N],kk,ne[N],ans[N];
ll c[N];

struct node{
	int l,r;
	ll v;
}k[N];

struct node1{
	int x,id;
	ll now;
}q[N],b[N];

int read()
{
    int ret; scanf("%d", &ret); return ret;
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

void add(int u,ll v)
{
	for(;u<=m;u+=u&(-u)) c[u]+=v;
}

ll cal(int u)
{
	ll now=0;
	for(;u;u-=u&(-u)) now+=c[u];
	return now;
}

void chan(int l,int r,ll v)
{
	add(r+1,-v);add(l,v);
}

void solve(int l,int r,int u,int v)
{
	if(u>v) return;
	if(l==r)
	{
		for(int i=u;i<=v;i++) ans[q[i].id]=l;
		return;
	}
	int mid=l+r>>1,l1=u-1,r2=v+1;
	for(int i=l;i<=mid;i++)
	  if(k[i].l<=k[i].r) chan(k[i].l,k[i].r,k[i].v);
	  else chan(1,k[i].r,k[i].v),chan(k[i].l,m,k[i].v);
	for(int i=u;i<=v;i++)
	{
		ll now=0;
		for(int j=fi[q[i].id];j && now<=inf;j=ne[j]) now+=cal(j);
		if(q[i].now+now>=q[i].x) b[++l1]=q[i];
		else q[i].now+=now,b[--r2]=q[i];
	}
	for(int i=u;i<=v;i++) q[i]=b[i];
	for(int i=l;i<=mid;i++)
	  if(k[i].l<=k[i].r) chan(k[i].l,k[i].r,-k[i].v);
	  else chan(1,k[i].r,-k[i].v),chan(k[i].l,m,-k[i].v);
	solve(l,mid,u,l1);solve(mid+1,r,l1+1,v);
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++) x=read(),ne[i]=fi[x],fi[x]=i;
	for(int i=1;i<=n;i++) q[i].x=read(),q[i].id=i;
	kk=read();
	for(int i=1;i<=kk;i++) k[i].l=read(),k[i].r=read(),k[i].v=read();
	k[++kk].l=1,k[kk].r=m,k[kk].v=1000000000;
	solve(1,kk,1,n);
	for(int i=1;i<=n;i++)
	  if(ans[i]==kk) puts("NIE");
	  else printf("%d\n",ans[i]);
	return 0;
}
*/
