#include <stdio.h>
#include <string.h>
#define maxn 15

char a[maxn], b[maxn];

void solve(int la, int ra, int lb, int rb) {
    if(la > ra || lb > rb) return;
    if(la == ra) {
        putchar(a[la]);
        return;
    }
    int i;
    for(i = la; i <= ra; i++) {
        if(a[i] == b[rb]) {
            break;
        }
    }
    putchar(a[i]);
    solve(la, i - 1, lb, lb + i - la - 1);
    solve(i + 1, ra, lb + i - la, rb - 1);
}

int main() {
    scanf("%s%s", a, b);
    solve(0, strlen(a) - 1, 0, strlen(b) - 1);
    putchar('\n');
    return 0;
}
