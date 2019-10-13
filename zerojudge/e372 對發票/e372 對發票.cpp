#include <stdio.h>
#include <string.h>
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define maxn 10



char a[maxn], b[maxn], x[3][maxn], s[maxn], t[maxn];
int n, arr[] = {2e5, 4e4, 1e4, 4e3, 1e3, 2e2};
long long mi = 0, mx = 0;
char str[maxn];

int Try(char str[]) {
    int add = (strcmp(str + 5, s) == 0 || strcmp(str + 5, t) == 0);
    if(strcmp(str, a) == 0) return 1e7;
    if(strcmp(str, b) == 0) return 2e6;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 3; j++) {
            if(strcmp(x[j] + i, str + i) == 0) return arr[i];
        }
    }
    if(strcmp(str + 5, s) == 0 || strcmp(str + 5, t) == 0) return 200;
    return 0;
}

int main() {
    scanf("%s%s%s%s%s%s%s", a, b, x[0], x[1], x[2], s, t);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        int tmp = -1, mx_ = 0, mi_ = 1e9;
        for(int j = 0; j < 8; j++) {
            if(str[j] == '*') {
                for(char c = '0'; c <= '9'; c++) {
                    str[j] = c;
                    tmp = Try(str);
                    mx_ = max(mx_, tmp);
                    mi_ = min(mi_, tmp);
                }
            }
        }
        if(tmp == -1)
            mx_ = mi_ = Try(str);
        mx = mx + mx_;
        mi = mi + mi_;
    }
    printf("%lld %lld\n", mx, mi);
    return 0;
}
