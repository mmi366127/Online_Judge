#include <stdio.h>
#include <string.h>
#define maxn 1000007

int dq[maxn], a[maxn];
int l, r, n, k;

int main() {
    while(~scanf("%d%d", &n, &k)) {
        if(k > n) {
            k = n;
        }
        for(int i = 0; i < n; i++) scanf("%d", a + i);
        l = r = 0;
        for(int i = 0; i < k - 1; i++) {
            while(l < r && a[dq[r - 1]] >= a[i]) r--;
            dq[r++] = i;
        }
        for(int i = k - 1; i < n; i++) {
            while(l != r && a[dq[r - 1]] >= a[i]) r--;
            dq[r++] = i;
            while(l < r && dq[l] <= i - k) l++;
            if(i == n - 1) printf("%d\n", a[dq[l]]);
            else printf("%d ", a[dq[l]]);
        }
        l = r = 0;
        for(int i = 0; i < k - 1; i++) {
            while(l < r && a[dq[r - 1]] <= a[i]) r--;
            dq[r++] = i;
        }
        for(int i = k - 1; i < n; i++) {
            while(l < r && a[dq[r - 1]] <= a[i]) r--;
            dq[r++] = i;
            while(l < r && dq[l] <= i - k) l++;
            if(i == n - 1) printf("%d\n", a[dq[l]]);
            else printf("%d ", a[dq[l]]);
        }
    }
    return 0;
}
