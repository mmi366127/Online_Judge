#include <stdio.h>
#include <string.h>
#define maxn 27
#define maxp 1500

int num[maxn], prime[maxp];
char used[maxn];
int n, k, ans = 0;

void build() {
    int i, flag, v = 3, tot = 1;
    prime[0] = 2;
    while(tot < maxp) {
        for(i = 0, flag = 1; prime[i] * prime[i] <= v; i++) {
            if(v % prime[i] == 0) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            prime[tot++] = v;
        }
        v += 2;
    }
}
char isprime(int x) {
    for(int i = 0; prime[i] * prime[i] <= x; i++) {
        if(x % prime[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void dfs(int pos, int len, int cur) {
    if(len == k) {
        ans += isprime(cur);
        return;
    }
    for(int i = pos; i < n; i++) {
        if(!used[i]) {
            used[i] = 1;
            dfs(i+1, len+1, cur+num[i]);
            used[i] = 0;
        }
    }
}


int main() {
    memset(used, 0, sizeof(used));
    build();
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", num + i);
    }
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return  0;
}
