#pragma GCC optmize("Ofast")
#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;


int arr[maxn];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    if(n == 1) {
        printf("%d\n", arr[0]);
        return 0;
    }
    sort(arr, arr + n);
    long long ans = arr[n - 1] - arr[0];
    for(int i = n - 2; i > 0; i--) {
        ans = ans + abs(arr[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
