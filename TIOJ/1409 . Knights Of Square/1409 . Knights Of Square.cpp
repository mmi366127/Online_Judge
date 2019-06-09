#include <bits/stdc++.h>
#define YEE ios_base::sync_with_stdio(false), cin.tie();
#define maxn 1000007
typedef long long loli;
using namespace std;


loli n, tmp, mx, sum;


int main() {
    YEE
    while(cin >> n) {
        mx = sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> tmp; mx = max(tmp, mx), sum += tmp;
        }
        if(sum - mx <= mx) puts("NO");
        else puts("YES");
    }
    return 0;
}
