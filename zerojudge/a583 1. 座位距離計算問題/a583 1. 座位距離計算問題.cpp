#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(a, b) a < b ? a : b
#define maxn 100


double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double x[maxn], y[maxn];
int n;

int main() {
    scanf("%d%d", &n, &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", x + i, y + i);
    }
    double ans = 1e9;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ans = min(ans, dis(x[i], y[i], x[j], y[j]));
        }
    }
    printf("%.4f\n", ans);
    return 0;
}
