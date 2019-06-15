#include <bits/stdc++.h>
#define X first
#define Y second
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define lowbit(X) ((X)&-(X))
#define MEM(X, val) memset((X), (val), sizeof(X));
#define pb push_back
#define ins insert
#define mp make_pair
#define YEE ios_base::sync_with_stdio(0); cin.tie()
#define maxn 1000007
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;


const loli INF = 0x3f3f3f3f3f3f3f3f;

loli a[maxn];
int num[maxn];
vector<loli> V;
int n, tmp;

inline int zero(int x) {
    if(x == 0) return 0;
    return x < 0 ? -1 : 1;
}


int main() {
    YEE;
    while(cin >> n) {
        a[0] = 0; V.clear();
        V.pb(0);
        for(int i = 1; i <= n; i++) {
            cin >> tmp;
            a[i] = a[i - 1] + zero(tmp);
            V.pb(a[i]);
        }
        int ans = 0;
        sort(all(V));
        V.erase(unique(all(V)), V.end());
        memset(num, -1, sizeof(int) * (V.size()));
        num[lower_bound(all(V), 0) - V.begin()] = 0;
        for(int i = 1; i <= n; i++) {
            int p = lower_bound(all(V), a[i]) - V.begin();
            if(num[p] != -1) {
                //cout << i << ' ' << i - num[p] << '\n';
                ans = max(i - num[p], ans);
            } else {
                num[p] = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
