#include <stdio.h>
#include <math.h>

int n, a, b, c;

double sqare(double x) {
    return x * x;
}



int main() {
    while(~scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            double aa = sqrt((sqare(b) + sqare(c) - 0.5 * sqare(a)) * 0.5) / 3.0  * 2.0;
            double bb = sqrt((sqare(c) + sqare(a) - 0.5 * sqare(b)) * 0.5) / 3.0  * 2.0;
            double cc = sqrt((sqare(a) + sqare(b) - 0.5 * sqare(c)) * 0.5) / 3.0  * 2.0;
            printf("%.1f\n", aa * aa + bb * bb + cc * cc);
        }
    }
    return 0;
}
