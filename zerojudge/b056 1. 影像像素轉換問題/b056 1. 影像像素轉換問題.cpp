#include <stdio.h>
#include <string.h>

double R, G, B, X, Y, Z, ans;
int n;

int main() {
    while(~scanf("%d", &n)) {
        ans = 0.00;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%lf%lf%lf", &R, &G, &B);
                X = 0.5149 * R + 0.3244 * G + 0.1607 * B;
                Y = 0.2654 * R + 0.6704 * G + 0.0642 * B;
                Z = 0.0248 * R + 0.1248 * G + 0.8504 * B;
                printf("%.4f %.4f %0.4f\n", X, Y, Z);
                ans += Y;
            }
        }
        printf("The average of Y is %.4f\n", ans  / (double)(n * n));
    }
    return 0;
}
