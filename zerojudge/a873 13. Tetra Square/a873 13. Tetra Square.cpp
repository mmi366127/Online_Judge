#include <stdio.h>
#include <string.h>
#define MEM(X, a, b, c) X[0] = a; X[1] = b; X[2] = c;

#define putchar_unlocked putchar

char M[10][10] ,s[5], T[100][3][3];
int n, cnt;

void brick(char B[3][3], char s[]) {
    memset(B, 0, sizeof(B));
    if(s[0] == 'J') {
        if(s[1] == '1') {
            MEM(B[0], 0, 1, 0);
            MEM(B[1], 0, 1, 0);
            MEM(B[2], 1, 1, 0);
        } else if(s[1] == '2') {
            MEM(B[0], 1, 0, 0);
            MEM(B[1], 1, 1, 1);
            MEM(B[2], 0, 0, 0);
        } else if(s[1] == '3') {
            MEM(B[0], 1, 1, 0);
            MEM(B[1], 1, 0, 0);
            MEM(B[2], 1, 0, 0);
        } else if(s[1] == '4') {
            MEM(B[0], 1, 1, 1);
            MEM(B[1], 0, 0, 1);
            MEM(B[2], 0, 0, 0);
        }
    } else if(s[0] == 'L') {
        if(s[1] == '1') {
            MEM(B[0], 1, 0, 0);
            MEM(B[1], 1, 0, 0);
            MEM(B[2], 1, 1, 0);
        } else if(s[1] == '2') {
            MEM(B[0], 1, 1, 1);
            MEM(B[1], 1, 0, 0);
            MEM(B[2], 0, 0, 0);
        } else if(s[1] == '3') {
            MEM(B[0], 1, 1, 0);
            MEM(B[1], 0, 1, 0);
            MEM(B[2], 0, 1, 0);
        } else if(s[1] == '4') {
            MEM(B[0], 0, 0, 1);
            MEM(B[1], 1, 1, 1);
            MEM(B[2], 0, 0, 0);
        }
    } else if(s[0] == 'T') {
        if(s[1] == '1') {
            MEM(B[0], 1, 1, 1);
            MEM(B[1], 0, 1, 0);
            MEM(B[2], 0, 0, 0);
        } else if(s[1] == '2') {
            MEM(B[0], 0, 1, 0);
            MEM(B[1], 1, 1, 0);
            MEM(B[2], 0, 1, 0);
        } else if(s[1] == '3') {
            MEM(B[0], 0, 1, 0);
            MEM(B[1], 1, 1, 1);
            MEM(B[2], 0, 0, 0);
        } else if(s[1] == '4') {
            MEM(B[0], 1, 0, 0);
            MEM(B[1], 1, 1, 0);
            MEM(B[2], 1, 0, 0);
        }
    } else if(s[0] == 'I') {
        if(s[1] == '1') {
            MEM(B[0], 1, 0, 0);
            MEM(B[1], 1, 0, 0);
            MEM(B[2], 0, 0, 0);
        } else {
            MEM(B[0], 1, 1, 0);
            MEM(B[1], 0, 0, 0);
            MEM(B[2], 0, 0, 0);
        }
    } else if(s[0] == 'Z') {
        if(s[1] == '1') {
            MEM(B[0], 1, 1, 0);
            MEM(B[1], 0, 1, 1);
            MEM(B[2], 0, 0, 0);
        } else {
            MEM(B[0], 0, 1, 0);
            MEM(B[1], 1, 1, 0);
            MEM(B[2], 1, 0, 0);
        }
    } else if(s[0] == 'S') {
        if(s[1] == '1') {
            MEM(B[0], 0, 1, 1);
            MEM(B[1], 1, 1, 0);
            MEM(B[2], 0, 0, 0);
        } else {
            MEM(B[0], 1, 0, 0);
            MEM(B[1], 1, 1, 0);
            MEM(B[2], 0, 1, 0);
        }
    }
}

int check(int x, int y, int n) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(M[x + i][y + j] && T[n][j][i]) return 0;
            if((x + i > 4 || y + j > 4) && T[n][j][i]) return 0;
        }
    }
    return 1;
}

void put(int x, int y, int n, char st) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(T[n][j][i]) {
                M[x + i][y + j] = st;
                cnt = cnt + (st > 0 ? +1 : -1);
            }
        }
    }
}

void dfs(int x) {
    if(x >= n) {
        if(cnt == 16)
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 4; j++) {
                putchar_unlocked(M[j][i] ? M[j][i] : '@');
            }
            putchar_unlocked('\n');
        }
        return;
    }
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            if(check(i, j, x)) {
                put(i, j, x, x + 'A');
                dfs(x + 1);
                put(i, j, x, 0);
            }
        }
    }
    dfs(x + 1);
}

int main() {
    while(~scanf("%d", &n)) {
        memset(M, 0, sizeof(M));
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            brick(T[i], s);
        }
        cnt = 0; dfs(0);
    }
    return 0;
}
