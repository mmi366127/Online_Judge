#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int arr[maxn], num[maxn *  maxn * maxn];
int n, tmp, idx = 0;

int get(int x) {
    static int l, r;
    l = lower_bound(num, num + idx, x) - num;
    r = upper_bound(num, num + idx, x) - num;
    return r - l;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(arr[k] == 0) continue;
                num[idx++] = (arr[i] + arr[j]) * arr[k];
            }
        }
    }
    sort(num, num  + idx);
    long long ans = 0;
    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            for(int c = 0; c < n; c++) {
                ans = ans + get(arr[a] * arr[b] + arr[c]);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
