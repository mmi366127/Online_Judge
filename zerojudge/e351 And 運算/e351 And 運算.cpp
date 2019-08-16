#include <stdio.h>
#include <string.h>
typedef unsigned long long loli;

loli a, b, ans, mask;

int main() {
    while(~scanf("%llu%llu", &a, &b)) {
        if(a > b) {
            loli _ = a;
            a = b;
            b = _;
        }
        ans = 0LL; mask = 0xffffffffffffffff;
        for(int i = 0; i < 64; i++) {
            if((a & (1LL << i)) && b <= ((a & mask) + (1LL << i) - 1)) {
                ans |= (1LL << i);
            }
            mask ^= (1LL << i);
        }
        printf("%llu\n", ans);
    }
    return 0;
}
