#include <bits/stdc++.h>
#define X first
#define Y second
#define YEE ios_base::sync_with_stdio(false), cin.tie();
#define maxn 1000007
typedef long long loli;
using namespace std;

loli n, m, tmp, id, cnt;
bitset<maxn> used;
loli ans;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minpq;
priority_queue<pair<int,int>> maxpq;

inline int get_max() {
    static pair<int,int> tmp;
    while(!maxpq.empty()) {
        tmp = maxpq.top();
        maxpq.pop();
        if(!used[tmp.Y]) {
            used[tmp.Y] = 1;
            cnt--;
            return tmp.X;
        }
    }
    return 0;
}

inline int get_min() {
    static pair<int,int> tmp;
    while(!minpq.empty()) {
        tmp = minpq.top();
        minpq.pop();
        if(!used[tmp.Y]) {
            used[tmp.Y] = 1;
            cnt--;
            return tmp.X;
        }
    }
    return 0;
}

int main() {
    YEE
    while(cin >> n) {
        id = ans = cnt = 0;
        used.reset();
        while(minpq.size()) minpq.pop();
        while(maxpq.size()) maxpq.pop();
        for(int i = 0; i < n; i++) {
            cin >> m;
            for(int j = 0; j < m; j++) {
                cin >> tmp;
                minpq.push({tmp, id});
                maxpq.push({tmp, id});
                id++; cnt++;
            }
            if(cnt >= 2) ans += get_max() - get_min();
        }
        cout << ans << '\n';
    }
    return 0;
}
