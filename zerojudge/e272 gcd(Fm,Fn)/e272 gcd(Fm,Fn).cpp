#include <stdio.h>
#define maxn 10007
#define abs(X) (X) < 0 ? -(X) : (X);
typedef unsigned long long loli;

int n, m;
loli tmp;
loli F[maxn];

loli GCD(int a, int b) {
    if(a == 0 || b == 0) return  a + b;
    while((a %= b) && (b %= a));
    return a + b;
}


int main() {
    F[1] = F[2] = 1;
    for(int i = 3; i < maxn; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    while(~scanf("%llu%llu", &n, &m)) {
        if(n > m) {
            tmp = m;
            m = n;
            n = tmp;
        }
        printf("%llu\n", F[GCD(n, m)]);
    }
    return 0;
}
