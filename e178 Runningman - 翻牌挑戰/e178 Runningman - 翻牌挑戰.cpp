#include <bits/stdc++.h>
#define maxn 10007
using namespace std;


int a[maxn];
int n, k;

int main() {
    while(~scanf("%d%d", &n, &k)) {
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        sort(a, a + n);
        for(int i = 0; i < n; i++) {
            if(k == 0 || a[i] >= 0) break;
            a[i] = -a[i], k--;
        }
        k %= 2;
        if(k) {
            sort(a, a + n);
            a[0] = -a[0];
        }
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
        }
        printf("%lld\n", sum);
    }
    return 0;
}
