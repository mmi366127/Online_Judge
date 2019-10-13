#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

char YEE[maxn];
int A[maxn];
int t, n;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", A + i), YEE[i] = 0;
        int mx = A[1];
        for(int i = 2; i <= n; i++) {
            if(mx < A[i]) {
                YEE[i]++;
            }
            if(A[i] > mx) mx = A[i];
        }
        int mi = A[n];
        for(int i = n - 1; i > 0; i--) {
            if(mi > A[i]) {
                YEE[i]++;
            }
            if(A[i] < mi) mi = A[i];
        }
        int ans = 0;
        for(int i = 2; i < n; i++)
            if(YEE[i] == 2) ans++;

        printf("%d\n", ans);
    }
    return 0;
}
