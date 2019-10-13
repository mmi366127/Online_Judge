#include <stdio.h>
#include <string.h>
#include <math.h>

double aver, s, sc_sum, sq_sum, S;
int T, n, sum;


int main() {
    scanf("%d", &T);
    sum = 0;
    sc_sum = sq_sum = 0.00;
    while(T--) {
        scanf("%d%lf%lf", &n, &aver, &s);
        sc_sum += aver * n;
        sq_sum += (s * s) * n + (n * aver *  aver);
        sum += n;
    }
    aver = sc_sum / sum;
    S = sq_sum - sum * aver * aver;
    S /= sum;
    S = sqrt(S);
    printf("%d %.2f %.2f", sum, aver, S);
    return 0;
}
