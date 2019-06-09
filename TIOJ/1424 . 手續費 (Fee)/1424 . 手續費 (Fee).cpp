#include <bits/stdc++.h>
using namespace std;


int x, y, n;

int main() {
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        pq.push(x);
    }
    int ans = 0;
    while(pq.size() > 1) {
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        ans += x + y;
        pq.push(x + y);
    }
    printf("%d\n", ans);
    return 0;
}
