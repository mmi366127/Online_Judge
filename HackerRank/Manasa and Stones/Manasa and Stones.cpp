#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

int t, n, a, b;
bitset<maxn> bs;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &a, &b);
        bs.reset(); bs[0] = 1;
        for(int i = 1; i < n; i++) {
            bs = (bs << a) | (bs << b);
        }
        for(int i = 0; i < maxn; i++)
            if(bs[i]) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
