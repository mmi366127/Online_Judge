#include <bits/stdc++.h>
using namespace std;

void solve(int p, int q) {
    printf("%d", p / q);
    if(p % q == 0) return;
    putchar('+');
    putchar('1');
    putchar('/');
    if(q % (p % q) != 0) putchar('{');
    solve(q, p % q);
    if(q % (p % q) != 0) putchar('}');
}


int t, p, q;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &p, &q);
        printf("%d/%d = ", p, q);
        solve(p, q);
        puts("");
    }
    return 0;
}
