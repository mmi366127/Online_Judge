#include <vector>
#include <queue>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
#define maxn 500007
using namespace std;
typedef long long int loli;
const loli INF = 0x3f3f3f3f3f3f3f3f;
struct cute {
    int L, R, l, r;
    loli val;
    bool operator<(const cute &a)const {
        return a.val > val;
    }
};

priority_queue<cute> pq;
loli prefix[maxn];
int SGT[1<<21];

int YEE(int a, int b) {
    return prefix[a] > prefix[b] ? a : b;
}

void build(int x, int L, int R) {
    if(L == R) {
        SGT[x] = L;
        return;
    }
    int mid = (L + R) >> 1;
    build(ls(x), L, mid);
    build(rs(x), mid+1, R);
    SGT[x] = YEE(SGT[ls(x)], SGT[rs(x)]);
}

int query(int x, int L, int R, int l, int r) {
    if(r < L || R < l) return maxn - 1;
    else if(l <= L && R <= r) return SGT[x];
    int mid = (L + R) >> 1;
    return YEE(query(ls(x), L, mid, l, r), query(rs(x), mid+1, R, l, r));
}


int n, k, L, R, t, l, r;


int main() {
    scanf("%d%d%d%d", &n, &k, &L, &R);
    prefix[0] = 0; prefix[maxn - 1] = -INF;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", prefix + i);
        prefix[i] += prefix[i-1];
    }
    while(!pq.empty()) pq.pop();
    build(1, 1, n);
    for(int i = 0; i + L <= n; i++) {
        l = i + L;
        r = min(i + R, n);
        t = query(1, 1, n, l, r);
        pq.push({i+1 ,t, l, r, prefix[t] - prefix[i]});
        //printf("push %d %d : %lld\n", i, t, prefix[t] - prefix[i]);
    }
    loli ans = 0;
    for(int i = 1; i <= k; i++) {
        cute tmp = pq.top();
        pq.pop();
        ans += tmp.val;
        //printf("add %d\n", tmp.val);
        if(tmp.l < tmp.R) {
            t = query(1, 1, n, tmp.l, tmp.R - 1);
            pq.push({tmp.L, t, tmp.l, tmp.R - 1, prefix[t] - prefix[tmp.L - 1]});
            //printf("push %d %d : %lld\n", tmp.L, t, prefix[t] - prefix[tmp.L - 1]);
        }
        if(tmp.R < tmp.r) {
            t = query(1, 1, n, tmp.R+1, tmp.r);
            pq.push({tmp.L, t, tmp.R+1, tmp.r, prefix[t] - prefix[tmp.L - 1]});
            //printf("push %d %d : %lld\n", tmp.L, t, prefix[t] - prefix[tmp.L - 1]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
