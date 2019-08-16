#include <stdio.h>
#include <string.h>
#include <math.h>

double D, L;
double pi = acos(-1);

int main() {
    while(~scanf("%lf%lf", &D, &L)) {
        printf("%.3f\n", 0.25 * L * sqrt(L * L - D * D) * pi);
    }
    return 0;
}
