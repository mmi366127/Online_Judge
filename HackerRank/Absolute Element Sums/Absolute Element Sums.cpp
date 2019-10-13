#include <bits/stdc++.h>
#define maxn 5000
using namespace std;

long long sum[maxn + 1] = {}, cnt[maxn + 1] = {};
long long n, m, x, num;

long long query_sum(int l, int r) {
    if(l > r) return 0;
    if(r <= -2500 || l > 2500) return 0;
    l = max(l, -2499);
    r = min(r, 2500);
    l += 2500;
    r += 2500;
    return sum[r] - sum[l - 1];
}

long long query_cnt(int l, int r) {
    if(l > r) return 0;
    if(r <= -2500 || l > 2500) return 0;
    l = max(l, -2499);
    r = min(r, 2500);
    l += 2500;
    r += 2500;
    return cnt[r] - cnt[l - 1];
}

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &x);
        cnt[x + 2500]++;
        sum[x + 2500] += x;
    }
    for(int i = 1; i <= maxn; i++) {
        sum[i] += sum[i - 1];
        cnt[i] += cnt[i - 1];
    }
    num = 0;
    scanf("%lld", &m);
    while(m--) {
        scanf("%lld", &x);
        num += x;
        long long ans = 0;
        ans = query_sum(-num, 2500) + num * query_cnt(-num, 2500);
        ans += -query_sum(-2500, -num - 1) - query_cnt(-2500, -num - 1) * num;
        printf("%lld\n", ans);
    }
    return 0;
}
