#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 100007
typedef struct Node {
    int val, l, r;
}Node;

int tot, n, m, i, j, sz;
Node ram[maxn*20];
int s[maxn], a[maxn], t[maxn], history[maxn];

void sort(int a[],int L,int R) {
    if(L == R) return;
    int mid = (L+R)>>1;
    int idx1 = L;
    int idx2 = mid+1;
    int idx = L;
    sort(a,idx1,mid);
    sort(a,idx2,R);

    while(idx1<=mid && idx2 <= R) {
        if(a[idx1] < a[idx2]) {
            t[idx++] = a[idx1++];
        } else {
            t[idx++] = a[idx2++];
        }
    }
    while(idx1<=mid) {
        t[idx++] = a[idx1++];
    }
    while(idx2<=R) {
        t[idx++] = a[idx2++];
    }
    for(idx=L;idx<=R;idx++)
        a[idx] = t[idx];
}

int get_id(int x) {
    int L = 1, R = sz;
    while(L<=R) {
        int mid = (L+R)>>1;
        if(a[mid] == x) return mid;
        else if(a[mid] > x) {
            R = mid-1;
        } else {
            L = mid+1;
        }
    }
    return -1;
}

void pull(int x) {
    ram[x].val = ram[ram[x].l].val + ram[ram[x].r].val;
}

int build(int L,int R) {
    int x = tot++;
    if(L==R) {
        ram[x].val = 0;
        return x;
    }
    int mid = (L+R)>>1;
    ram[x].l = build(L,mid);
    ram[x].r = build(mid+1,R);
    ram[x].val = 0;
    return x;
}

int modify(int x,int L,int R,int pos) {
    int _x = tot++;
    if(L == R) {
        ram[_x].val = ram[x].val+1;
        return _x;
    }
    int mid = (L+R)>>1;
    if(pos <= mid) {
        ram[_x].l = modify(ram[x].l,L,mid,pos);
        ram[_x].r = ram[x].r;
    } else {
        ram[_x].l = ram[x].l;
        ram[_x].r = modify(ram[x].r,mid+1,R,pos);
    }
    pull(_x);
    return _x;
}

int query(int a,int b,int L,int R,int k) {
    if(L == R) {
        return L;
    }
    int mid = (L+R)>>1;
    if(ram[ram[b].l].val - ram[ram[a].l].val > k) {
        return query(ram[a].l,ram[b].l,L,mid,k);
    } else {
        return query(ram[a].r,ram[b].r,mid+1,R,k-ram[ram[b].l].val+ram[ram[a].l].val);
    }
}



int main() {
    while(~scanf("%d%d",&n,&m)) {
        tot = 0;
        for(i=1;i<=n;i++) {
            scanf("%d",s+i);
        }
        memcpy(a,s,sizeof(int)*(n+7));
        sort(a,1,n);
        for(i=1,j=1;i<=n;i++) {
            a[j++] = a[i];
            while(i<n && a[i] == a[i+1]) i++;
        }
        sz = j-1;
        history[0] = build(1,sz);
        for(i=1;i<=n;i++) {
            int id = get_id(s[i]);
            history[i] = modify(history[i-1],1,sz,id);
        }
        while(m--) {
            int l, r, k;
            scanf("%d%d%d",&l,&r,&k); k--;
            printf("%d\n",a[query(history[l-1],history[r],1,sz,k)]);
        }

    }
    return 0;
}
