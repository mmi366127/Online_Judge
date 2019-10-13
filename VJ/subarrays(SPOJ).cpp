#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;


int arr[maxn];
int n, k;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    scanf("%d", &k);
    deque< pair<int, int> > dq;
    for(int i = 1; i <= n; i++) {
        while(dq.size() && dq.back().first <= arr[i]) dq.pop_back();
        dq.push_back({arr[i], i});
        while(dq.front().second <= i - k) dq.pop_front();
        if(i >= k) {
            printf("%d%c", dq.front().first, " \n"[i == n]);
        }
    }
    return 0;
}
