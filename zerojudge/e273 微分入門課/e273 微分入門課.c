#include <stdio.h>
#include <string.h>
#define get() (p1_in == p2_in && (p2_in = (p1_in = buf_in) + fread(buf_in, 1, 1 << 22, stdin), p1_in == p2_in)) ? EOF : *p1_in++;
#define flush() fwrite(buf_out, 1, p2_out + 1, stdout), p2_out = -1
int n, tmp;
int K[1000][50];


char buf_in[1 << 22], *p1_in = buf_in, *p2_in = buf_in;
char buf_out[1 << 22], out[20];
int p_out, p2_out = -1;

int rd() {
    int ret = 0, f = 0; char ch = get();
    while (ch < '0') {
        if(ch == EOF) {
            printf("?\n");
            return -1;
        }
        if (ch == '-') f = 1;
        ch = get();
    }
    while (ch >= '0') {
        ret = ret * 10 + ch - 48;
        ch = get();
    }
    return f ? -ret : ret;
}
void print(int x, char e) {
    if (p2_out > (1<<20)) flush();
    if (x < 0) buf_out[++p2_out] = 45, x = -x;
    do {
        out[++p_out] = (x % 10) + 48;
    }while(x /= 10);
    do {
        buf_out[++p2_out] = out[p_out];
    }while(--p_out);
    buf_out[++p2_out] = e;
}



int main() {
    for(int i = 0; i < 1000; i++) {
        for(int j = 1; j < 50; j++)
            K[i][j] = j * i;
    }
    while((n = rd()) >= 0) {
        if(n <= 1) {
            print(0, '\n');
            if(n == 1) rd();
            continue;
        }
        for(int i = n - 1; i > 0; i--) {
            tmp = rd();
            print(K[i][tmp], i == 1 ? '\n' : ' ');
        }
    }
    return 0;
}
