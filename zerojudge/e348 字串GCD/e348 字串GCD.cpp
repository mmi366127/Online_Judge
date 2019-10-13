#include <stdio.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)


int GCD(int a, int b) {
    if(!a || !b) return a + b;
    while((a %= b) && (b %= a));
    return a + b;
}

char a[10000], b[10000];
int n, m;

int check(int len) {
    for(int i = 1; i <= n; i += len) {
        for(int j = 0; j < len; j++) {
            if(a[j + 1] != a[j + i]) {
                return 0;
            }
        }
    }
    for(int i = 1; i <= m; i += len) {
        for(int j = 0; j < len; j++) {
            if(b[j + 1] != b[j + i]) {
                return 0;
            }
        }
    }
    for(int i = 1; i <= len; i++) {
        if(a[i] != b[i]) return 0;
    }
    for(int i = 1; i <= len; i++) {
        putchar(a[i]);
    }
    putchar('\n');
    return 9487;
}


int main() {
    while(~scanf("%s%s", a + 1, b + 1)) {
        n = strlen(a + 1), m = strlen(b + 1);
        int flag = 9487;
        for(int i = min(n, m); i >= 1; i--) {
            if(n % i == 0 && m % i == 0) {
                if(check(i)) {
                    flag = 0; break;
                }
            }
        }
        if(flag) puts("= =");
    }
    return 0;
}
