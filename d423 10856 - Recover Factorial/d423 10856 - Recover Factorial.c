#include <stdio.h>
#include <string.h>
#define maxp 5000
#define maxn 3000007


int p[maxp], sum[maxn];
int n, kase = 0;

void init() {
    int v, i, j, flag;
    p[0] = 2;
    i = 1, v = 3;
    while(i < maxp) {
        j = 0, flag = 1;
        while(p[j] * p[j] <= v) {
            j++;
            if(v % p[j] == 0) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            p[i++] = v;
        }
        v += 2;
    }
    sum[0] = 0;
    for(i = 1; i <= maxn; i++) {
        int tmp = i;
        for(j = 0; p[j] * p[j] <= tmp; j++) {
            while(tmp % p[j] == 0) {
                sum[i]++;
                tmp /= p[j];
            }
        }
        if(tmp > 1) sum[i]++;
        sum[i] += sum[i - 1];
    }
}

char ans[100];

char *solve(int x) {
    if(x == 0) {
        sprintf(ans, "Case %d: %d!", ++kase, 0);
        return ans;
    }
    int l = 0, r = maxn - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(sum[mid] == x) {
            sprintf(ans, "Case %d: %d!", ++kase, mid);
            return ans;
        }
        else if(sum[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    sprintf(ans, "Case %d: Not possible.", ++kase);
    return ans;
}


int main() {
    init();
    while(~scanf("%d", &n) && n != -1) {
        puts(solve(n));
    }
    return 0;
}
