#include <stdio.h>


int t, n, k, kase = 0;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        int ans = 0;
        for(int i = 2; i <= n; i++)
            ans = (ans + k) % i;
        printf("Case %d: %d\n", ++kase, ans + 1);
    }
}
