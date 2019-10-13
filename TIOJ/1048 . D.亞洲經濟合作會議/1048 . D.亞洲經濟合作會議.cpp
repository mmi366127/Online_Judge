#include <bits/stdc++.h>
#define maxn 15
using namespace std;

char ans[maxn], tmp[maxn];
int pre[maxn];
int n, m;

int main() {
    pre[0] = 1;
    for(int i = 1; i < maxn; i++)
        pre[i] = pre[i - 1] * i;
    while(~scanf("%d%d", &n, &m) && n) {
        m = (m - 1) % pre[n];
        for(int i = 0; i < n; i++)
            tmp[i] = i + 'A';
        int sz = n;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < n; j++) {
                if(tmp[j] && m < pre[sz - 1]) {
                    ans[i] = tmp[j];
                    tmp[j] = '\0';
                    sz--;
                    break;
                }
                if(tmp[j]) {
                    m -= pre[sz - 1];
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            printf("%c%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}
