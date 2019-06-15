#include <stdio.h>
#include <string.h>
#define maxn 21

int n, m, l, r;
int SG[maxn];

int get_SG(int x) {
    if(SG[x] != -1) return SG[x];
    char mex[maxn];
    memset(mex, 0, sizeof(mex));
    for(int i = 1; x >= i && i <= m; i++) {
        mex[get_SG(x - i)] = 1;
    }
    for(int i = 0; ; i++) {
        if(!mex[i]) return SG[x] = i;
    }
}


int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(SG, -1, sizeof(SG));
        int ans = 0; SG[0] = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &l, &r);
            ans ^= get_SG(r - l - 1);
        }
        puts(ans ? "OpenChan" : "Kitty");
    }
    return 0;
}
