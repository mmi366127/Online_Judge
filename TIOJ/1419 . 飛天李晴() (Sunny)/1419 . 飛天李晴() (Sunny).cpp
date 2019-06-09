#include <bits/stdc++.h>
#define maxn 100007
using namespace std;
typedef long long loli;
struct tree {
    loli x, y, h, dis2;
    bool operator < (const tree &a) const {
        loli A = (x*x) + (y*y);
        loli B = (a.x*a.x) + (a.y*a.y);
        return  A == B ? h > a.h : A < B;
    }
};



loli X, Y, H, n;
tree a[maxn];


int main() {
    ios_base::sync_with_stdio(false), cin.tie();
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].h;
        a[i].dis2 = a[i].x * a[i].x + a[i].y * a[i].y;
    }
    sort(a, a + n);
    loli ans = 0;
    vector<int> stk;
    for(int i = 0; i < n ;i++) {
        if(stk.size()) ans = max(ans, stk[0] - a[i].h);
        while(stk.size() && stk.back() <= a[i].h) stk.pop_back();
        stk.push_back(a[i].h);
    }
    cout << ans << endl;
    return 0;
}
