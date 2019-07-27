#include <stdio.h>
#include <algorithm>
using namespace std;

int n, ans, tmp;

int main() {
    scanf("%d%d", &n, &ans);
    for(int i = 1; i < n; i++) {
        scanf("%d", &tmp);
        ans = __gcd(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}
