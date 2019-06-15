#include <stdio.h>
#include <string.h>
#define maxn 100007

int a[maxn], pos[maxn];
int n, k, flag = 0;

int main() {
    scanf("%d%d", &n, &k);
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        a[i] = (a[i-1] + a[i]) % k;
    }
    memset(pos, -1, sizeof(pos));
    pos[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(pos[a[i]] == -1) {
            pos[a[i]] = i;
        } else {
            printf("%d\n", i - pos[a[i]]);
            for(int k = pos[a[i]]+1; k <= i; k++)
                printf("%d ", k);
            flag = 1;
            break;
        }
    }
    if(!flag) puts("0");
}
