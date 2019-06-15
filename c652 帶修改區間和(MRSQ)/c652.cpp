#include<stdio.h>
#include<math.h>
#define maxn 300007
#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
typedef long long int loli;
typedef struct Node {
    char flag;
    loli val;
}Node;

Node SGT[maxn<<2];

void pull(int x) {
    SGT[x].flag = SGT[ls(x)].flag & SGT[rs(x)].flag;
    SGT[x].val = SGT[ls(x)].val + SGT[rs(x)].val;
}

void build(int x,int L,int R,loli a[]) {
    if(L == R) {
        SGT[x].val = a[L];
        SGT[x].flag = a[L] <= 1 ? 1 : 0;
        return;
    }
    int mid = (L+R)>>1;
    build(ls(x),L,mid,a);
    build(rs(x),mid+1,R,a);
    pull(x);
}

void modify(int x,int L,int R,int l,int r) {
    if(r<L||R<l) return;
    else if(L == R) {
        SGT[x].val = (int)sqrt(SGT[x].val);
        SGT[x].flag = SGT[x].val <= 1 ? 1 : 0;
        return;
    }
    int mid = (L+R)>>1;
    if(!SGT[ls(x)].flag) {
        modify(ls(x),L,mid,l,r);
    }
    if(!SGT[rs(x)].flag) {
        modify(rs(x),mid+1,R,l,r);
    }
    pull(x);
}

loli query(int x,int L,int R,int l,int r) {
    if(r<L||R<l) return 0;
    else if(l<=L&&R<=r) return SGT[x].val;
    int mid = (L+R)>>1;
    return query(ls(x),L,mid,l,r) + query(rs(x),mid+1,R,l,r);
}

loli a[maxn], n, q, op, l, r;

int main() {
    scanf("%d%d", &n, &q);
    for(int i=1;i<=n;i++) {
        scanf("%lld",a+i);
    }
    build(1,1,n,a);
    while(q--) {
        scanf("%d%d%d",&op,&l,&r);
        if(op == 0) {
            printf("%lld\n",query(1,1,n,l,r));
        } else {
            modify(1,1,n,l,r);
        }
    }
    return 0;
}
