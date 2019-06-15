#include <stdio.h>
#include <string.h>
typedef long long int loli;

int T, a0, a1, b0, b1, ans;


int gcd(int a, int b) {
    if(!a || !b) return a + b;
    while((a %= b) && (b %= a));
    return a + b;
}

int lcm(loli a, loli b) {
    loli GCD = gcd(a, b);
    return a * b / GCD;
}


int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
        ans = 0;
        for(loli x = 1; x * x <= (loli)b1; x++) {
            if(b1 % x == 0) {
                if(gcd(x, a0) == a1 && lcm(x, b0) == b1) ans++;
                if(x * x == (loli)b1);
                else {
                    if(gcd(b1 / x, a0) == a1 && lcm(b1 / x, b0) == b1) ans++;
                }

            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
 gcd(a, b) * lcm(a, b) = a * b

 lcm(x, b0) * gcd(x, b0) = x * b0

-->  gcd(x, b0) = x * b0 / b1
-->  gcd(b1 / b0, b1 / x) = 1
-->  b1 mod x = 0 & x mod a1 == 0

 gcd(x, a0) = a1
 lcm(x, b0) = b1
*/
