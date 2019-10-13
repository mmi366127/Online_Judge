#include <bits/stdc++.h>
#define all(X) (X).begin(), (X).end()
#define lowbit(X) (X&(-X))
#define maxn 1000005
using namespace std;

char s[maxn];
int n;

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    long long tmp = 0, ans = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == '>') {
            tmp++;
            ans += tmp;
        } else {
            tmp = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
