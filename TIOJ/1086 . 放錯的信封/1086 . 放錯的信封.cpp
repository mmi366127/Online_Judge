#include <bits/stdc++.h>
using namespace std;

long long ans[20];
int n;

int main() {
    for(int i = 1; i <= 3; i++)
        ans[i] = i - 1;
    for(int i = 4; i < 20; i++) {
        ans[i] = (ans[i - 1] + ans[i - 2]) * (i - 1);
    }
    while(~scanf("%d", &n) && n)
        printf("%lld\n", ans[n]);
    return 0;
}
