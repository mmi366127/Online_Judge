#include <stdio.h>
#include <string.h>

int GCD(int a, int b) {
    if(!a || !b) return a + b;
    while((a %= b) && (b %= a));
    return a + b;
}

int G[505];
int n;

int main() {
    for(n = 2; n <= 500; n++) {
        G[n] = G[n - 1];
        for(int i = n - 1; i > 0; i--) {
            G[n] += GCD(n, i);
        }
    }
    while(~scanf("%d", &n) && n)
        printf("%d\n", G[n]);
    return 0;
}
