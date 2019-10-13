#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int arr[maxn];
int t, n, c;

bool check(int x) {
    int cnt = 0, pre = -1e9;
    for(int i = 0; i < n; i++) {
        if(arr[i] - pre >= x) {
            cnt++;
            pre = arr[i];
        }
    }
    return cnt >= c;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &c);
        for(int i = 0; i < n; i++)
            scanf("%d", arr + i);
        sort(arr, arr + n);
        int l = 0, r = 1e9 + 1;
        while(r - l > 1) {
            int mid = (l + r) >> 1;
            if(check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}
