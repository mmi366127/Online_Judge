#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int N[20], V[(1 << 19)];
int n;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++)
            scanf("%d", N + i);
        for(int i = 1; i < (1 << n); i++) {
            V[i] = 0;
            for(int j = 0, k = i; j < n; j++) {
                if(k & 1) {
                    V[i] += N[j];
                }
                k >>= 1;
            }
        }
        sort(V + 1, V + (1 << n));
        int ans = 0;
        for(int j, i = 1; i < (1 << n); i++) {
            j = i; ans++;
            while(j < (1 << n) - 1 && V[j] == V[j + 1]) j++;
            i = j;
        }
        printf("%d\n", ans);
    }
    return 0;
}
