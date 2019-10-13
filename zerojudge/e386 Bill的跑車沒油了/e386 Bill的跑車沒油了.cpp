#include <bits/stdc++.h>
#define X first
#define Y second
#define maxn 1000005
using namespace std;
typedef long long loli;
typedef pair<loli, loli> pii;

const loli INF = 0x3f3f3f3f3f3f3f3f;

pii arr[maxn * 2];

int n, p, c, d;
loli sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> p >> n;
    for(int i = 0; i < n; i++) {
        cin >> c >> d;
        arr[i].X = sum;
        arr[i].Y = c;
        sum = sum + d;
    }
    arr[n].X = sum; int tot = n + 1;
    for(int i = 0; i < n; i++) {
        if(arr[i].X + p > sum) break;
        arr[tot].X = arr[i].X + p;
        arr[tot].Y = -1;
        tot++;
    }
    sort(arr, arr + tot);
    /*for(int i = 0; i < tot; i++)
        cout << arr[i].X << "  " << arr[i].Y << "\n";*/
    loli ans = 0; deque<pii> dq;
    dq.push_back({p, arr[0].Y});
    for(int i = 1; i < tot; i++) {
        while(dq.size() && dq.front().X < arr[i].X) dq.pop_front();
        ans += (arr[i].X - arr[i - 1].X) * dq.front().Y;
        if(arr[i].Y > 0) {
            while(dq.size() && dq.back().Y >= arr[i].Y) dq.pop_back();
            dq.push_back({arr[i].X + p, arr[i].Y});
        }
    }
    cout << ans << '\n';
    return 0;
}
