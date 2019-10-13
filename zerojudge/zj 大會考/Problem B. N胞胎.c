#include <stdio.h>
#include <string.h>
#define maxn 1007



int id[maxn], check[maxn], num[maxn];
int n, m, a, b, q;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        id[i] = i;
        check[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        int tmp = id[a];
        id[a] = id[b];
        id[b] = tmp;
    }
    for(int i = 1; i <= n; i++) {
        num[id[i]] = i;
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &a);
        check[num[a]] = 0;
    }
    char flag = 1;
    for(int i = 1; i <= n; i++) {
        if(check[i]) printf("%d ", i), flag = 0;
    }
    if(flag) puts("-1");
    else puts("");
    return 0;
}
