#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)

const double eps = 1e-5;

double H, S, V, L, K;
int n;

int main() {
    scanf("%lf %lf %lf %lf %lf %d", &H, &S, &V, &L, &K, &n);
    int ans = 0;
    double l, r;
    r = S - V * sqrt((H - K) / 5.0) + L;
    l = S - V * sqrt(H / 5.0);
    for(int i = 0; i < n; i++)
        if(l - eps <= (double)i && (double)i <= r + eps) ans++;
    printf("%d\n", ans);
    return 0;
}
