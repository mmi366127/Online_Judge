#include <stdio.h>

double a, b, c, d, det;

int main() {
    while(scanf("%lf%lf%lf%lf", &a, &b, &c, &d) == 4) {
        if(a == 0 && b == 0 && c == 0 && d == 0)
            break;
        det = a * d - b * c;
        if(det == 0) puts("cheat!");
        else printf("%.5f %.5f\n %.5f %.5f\n", d / det, -b / det, -c / det, a / det);
    }
    return 0;
}
