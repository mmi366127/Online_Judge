#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define maxn 60


char *D[] = {"E", "SE", "S", "SW", "W", "NW", "N", "NE"};
int mx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int my[] = {0, 1, 1, 1, 0, -1, -1, -1};


int get_dir(char s[]) {
    for(int i = 0; i < 8; i++)
        if(strcmp(s, D[i]) == 0)
            return i;
    return 9487;
}


char fail[8][maxn][maxn] = {};
char MAP[maxn][maxn] = {};
char s[maxn], P[500];
int n, m, x, y, dir;


int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        for(int j = 1; j <= m; j++) {
            MAP[j][i] = s[j - 1];
        }
    }
    bool flag = false;
    while(~scanf("%d%d%s%s", &x, &y, s, P)) {
        if(flag) {
            puts("I think I don't need to move anymore.");
            continue;
        }
        dir = get_dir(s); bool is_fail = false;
        for(int i = 0; P[i]; i++) {
            if(P[i] == 'M') {
                x += mx[dir];
                y += my[dir];
            } else if(P[i] == 'L') {
                int tmp = 0;
                while(P[i + 1] >= '0' && P[i + 1] <= '9') {
                    tmp = tmp * 10 + (P[++i] ^ '0');
                }
                tmp /= 45;
                dir = (dir - tmp + 88) % 8;
            } else if(P[i] == 'R') {
                int tmp = 0;
                while(P[i + 1] >= '0' && P[i + 1] <= '9') {
                    tmp = tmp * 10 + (P[++i] ^ '0');
                }
                tmp /= 45;
                dir = (dir + tmp) % 8;
            }
            if(MAP[x][y] == 'T') {
                printf("%d %d FINISHED!\n", x, y);
                flag = true;
                break;
            }
            if(MAP[x][y] == 'H' || MAP[x][y] == 0) {
                x -= mx[dir];
                y -= my[dir];
                if(fail[dir][x][y]) {
                    continue;
                }
                printf("%d %d %s BAD PLAN!\n", x, y, D[dir]);
                fail[dir][x][y] = 1;
                is_fail = true;
                break;
            }
        }
        if(is_fail == false && flag == false) printf("%d %d %s\n", x, y, D[dir]);
    }
    return 0;
}
