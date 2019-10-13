#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#define maxn 50007
typedef long long int loli;
using namespace std;

int s[maxn], p[maxn];
map<int,int> mp[maxn];
loli ans;

void init(int n) {
    int tmp;
    for(int i = 1; i <= n; i++) {
        p[i] = -1;
        s[i] = 1;
        mp[i].clear();
        scanf("%d", &tmp);
        mp[i].insert({tmp, 1});
    }
}

int find(int x) {
    return p[x] < 0 ? x : (p[x] = find(p[x]));
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(s[x] < s[y])
        swap(x, y);
    p[y] = x;
    s[x] += s[y];
    for(auto t : mp[y]) {
        auto it = mp[x].find(t.first);
        if(it == mp[x].end()) {
            mp[x].insert(t);
        } else {
            ans -= (loli)t.second * (t.second - 1) / 2;
            ans -= (loli)it->second * (it->second - 1) / 2;
            it->second += t.second;
            ans += (loli)it->second * (it->second - 1) / 2;
        }
    }
}

int n, m, t, a, b;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        init(n);
        ans = 0;
        while(m--) {
            scanf("%d%d", &a, &b);
            merge(a, b);
            printf("%lld\n", ans);
        }
    }
    return 0;
}

