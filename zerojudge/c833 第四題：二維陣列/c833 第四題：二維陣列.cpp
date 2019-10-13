#include <stdio.h>
#define maxn 3005

char MAP[maxn][maxn] = {};
char is_[2][maxn] = {};
int n, m, c;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            c = getchar();
            while(c != '.' && c != '#')
                c = getchar();
            MAP[j][i] = c;
            if(c == '#') {
                is_[0][j] = c;
                is_[1][i] = c;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if(is_[0][i]) {
            for(int j = 0; j < n; j++) {
                MAP[i][j] = '#';
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(is_[1][i]) {
            for(int j = 0; j < m; j++) {
                MAP[j][i] = '#';
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(MAP[j][i] == '#') putchar(MAP[j][i]);
            else putchar('X');
        }
        putchar('\n');
    }
    return 0;
}
