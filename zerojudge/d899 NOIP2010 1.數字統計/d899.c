#include <stdio.h>

int l, r, ans = 0;

int cal(int x) {
    int ret = 0;
    while(x) {
        ret += x % 10 == 2;
        x /= 10;
    }
    return ret;
}

int main() {
    scanf("%d%d", &l, &r);
    for(int i = l; i <= r; i++)
        ans += cal(i);
    printf("%d\n", ans);
    return 0;
}
