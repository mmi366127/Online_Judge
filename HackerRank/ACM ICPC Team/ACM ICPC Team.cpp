#include <bits/stdc++.h>
#define maxn 505
using namespace std;

bitset<maxn> bs[maxn];
int cnt[maxn] = {};
string s;
int n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        bs[i] = bitset<maxn>(s);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            bitset<maxn> tmp = bs[i] | bs[j];
            cnt[tmp.count()]++;
        }
    }
    for(int i = maxn - 1; i >= 0; i--) {
        if(cnt[i]) {
            printf("%d\n%d\n", i, cnt[i]);
            break;
        }
    }
    return 0;
}
