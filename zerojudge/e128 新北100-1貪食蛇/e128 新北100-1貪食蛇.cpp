#include <stdio.h>
#include <math.h>

int n, x, y, tmp, temp;

int main() {
    while(~scanf("%d", &n) && n) {
        tmp = sqrt(n);
        temp = n - tmp * tmp;
        if(temp == 0) {
            x = 1, y = tmp;
        } else {
            if(temp <= tmp + 1)
                x = temp, y = tmp + 1;
            else
                x = tmp + 1, y = tmp + 1 - (temp - tmp - 1);
        }
        if(tmp & 1)
            printf("%d %d\n", x, y);
        else
            printf("%d %d\n", y, x);
    }
    return 0;
}
