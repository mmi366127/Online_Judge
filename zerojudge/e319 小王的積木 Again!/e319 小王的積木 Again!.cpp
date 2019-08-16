#include <stdio.h>
#include <string.h>

void read(int *x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar());
    for(*x = 0; c >= '0'; c = getchar())
        (*x) = ((*x) << 3) + ((*x) << 1) + (c ^ '0');
}

unsigned char tmp[4];
int cnt[4][256] = {};

int main() {
    int n, i; read(&n);
    for(; n--;) {
        read((int*)tmp);
        for(i = 0; i < 4; i++) {
            cnt[i][tmp[i]]++;
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 256; j++) {
            if(cnt[i][j] % 3 != 0) {
                tmp[i] = j;
                break;
            }
        }
    }
    printf("%d\n", *(int*)(tmp));
    return 0;
}
