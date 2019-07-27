#include <bits/stdc++.h>
using namespace std;

int A[105];
int n;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d", A + i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(A[j] > A[i]) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
