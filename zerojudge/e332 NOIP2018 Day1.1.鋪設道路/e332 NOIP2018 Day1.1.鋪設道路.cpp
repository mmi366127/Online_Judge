#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int arr[maxn];
int x, n, ans = 0;

int main() {
    scanf("%d", &n);
    stack<pair<int, int>> stk;
    stk.push(make_pair(0, 0));
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if(stk.top().first >= x) {
            ans += stk.top().first - x;
            while(stk.size() && stk.top().first >= x) {
                stk.pop();
            }
        }
        stk.push(make_pair(x, i));
    }
    ans += stk.top().first;
    printf("%d\n", ans);
    return 0;
}
