#include <stdio.h>
#include <string.h>
#define get() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)) ? EOF : *p1++

int n, tmp;

char buf[1 << 22], *p1 = buf, *p2 = buf;

int rd() {
    int ret = 0, f = 0; char ch = get();
    while (ch < '0') {
        if(ch == EOF) {
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
void wrtn(int x){
    if(x<0) {putchar('-');x=-x;}
    int y=10,len=1;
    while(y<=x)    {y*=10;len++;}
    while(len--){y/=10;putchar(x/y+48);x%=y;}
}


char *solve() {
    static char ans[10000];
    static int tmp;
    char *p = ans;
    for(int i = n - 1; i >= 0; i--) {
        tmp = rd();
        if(i) {
            //sprintf(p, "%d ", i * tmp);
            wrtn(i * tmp); putchar(' ');
            while(*p) p++;
        }
    }
    putchar('\n');
    return ans;
}


int main() {
    while((n = rd()) >= 0) {
        if(n <= 1) {
            puts("0");
            if(n == 1) rd();
            continue;
        }
        solve();
    }
    return 0;
}
