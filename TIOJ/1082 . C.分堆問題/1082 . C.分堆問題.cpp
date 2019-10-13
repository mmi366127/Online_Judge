#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

int B[maxn], W[maxn];
int n;

int main() {
    while(~scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            scanf("%d%d", B + i, W + i);
        }
        if(n == 1) {
            puts((!W[0] || !B[0]) ? "0" : "-1" ); continue;
        }
        int ans = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(W[i] < B[i]) {
                ans += W[i];
            } else if(W[i] > B[i]){
                ans += B[i];
                cnt += 1;
            } else {
                ans += B[i];
                cnt = maxn;
            }
        }
        if(cnt == n || cnt == 0) {
            if(cnt == n) { // all black
                int tmp = 2e9;
                for(int i = 0; i < n; i++) {
                    tmp = min(tmp, W[i] - B[i]);
                }
                ans += tmp;
            } else { // all white
                int tmp = 2e9;
                for(int i = 0; i < n; i++) {
                    tmp = min(tmp, B[i] - W[i]);
                }
                ans += tmp;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
