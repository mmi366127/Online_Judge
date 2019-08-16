#include <stdio.h>
#include <string.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define maxn 107

int abs(int x) {
    return x < 0 ? -x : x;
}

int color(char c) {
    switch(c) {
        case 'R':
            return 1;
            break;
        case 'B':
            return 2;
            break;
        case 'Y':
            return 4;
            break;
        case 'P':
            return 3;
            break;
        case 'O':
            return 5;
            break;
        case 'G':
            return 6;
            break;
        case 'D':
            return 7;
            break;
    }
    return 0;
}

int x[3], y[3], c[3];
char M[maxn][maxn];
char s[10];
int n, T;

int draw(int t) {
    int ret = 0;
    memset(M, 0, sizeof(M));
    for(int k = 0; k < 3; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(abs(x[k] - i) <= t && abs(y[k] - j) <= t)
                    M[i][j] |= c[k];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(M[j][i] == T) ret++;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < 3; i++) {
        scanf("%s%d%d",s, x + i, y + i);
        c[i] = color(s[0]);
    }
    scanf("%s", s); T = color(s[0]);
    int tmp, ans = 0;
    for(int i = 0; i < 100; i++) {
        tmp = draw(i);
        ans = max(tmp, ans);
    }
    printf("%d\n", ans);
    return 0;
}
