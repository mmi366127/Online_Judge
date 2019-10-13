#include <stdio.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define maxn 10005

int stk_x[maxn], stk_y[maxn], top = 0;
int n, x, ans = 0;


int main() {
    scanf("%d", &n);
    stk_y[top] = 0;
    stk_x[top] = -1; top++;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        while(top && stk_y[top - 1] > x) {
            if(top > 1) ans = max(ans, ((i - 1 - stk_x[top - 2]) * stk_y[top - 1]));
            top--;
        }
        stk_x[top] = i;
        stk_y[top] = x;
        top++;
    }
    while(top) {
        if(top > 1) ans = max(ans, ((n - 1 - stk_x[top - 2]) * stk_y[top - 1]));
        top--;
    }
    printf("%d\n", ans);
    return 0;
}
