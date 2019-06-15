//It is made by Awson on 2018.1.2
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
const int N = 400;
const int MOD = 1e9+7;

int n;
int f[N+5];

int quick_pow(int x, int y) {
    int ans = 1;
    while (y) {
    if (y&1) ans = (LL)ans*x%MOD;
    x = (LL)x*x%MOD, y >>= 1;
    }
    return ans;
}
void work() {
    scanf("%d", &n);
    f[0] = 1;
    for (int k = 1; k <= n; k++)
    for (int i = 0; i <= k; i++)
        for (int j = i; j <= k; j++) {
        int p = k-1-i-j; if (p < j) break;
        if (i == p) (f[k] += (LL)f[i]*(f[i]+1)%MOD*(f[i]+2)%MOD*quick_pow(6, MOD-2)%MOD) %= MOD;
        else if (i == j) (f[k] += (LL)f[i]*(f[i]+1)%MOD*quick_pow(2, MOD-2)%MOD*f[p]%MOD) %= MOD;
        else if (j == p) (f[k] += (LL)f[p]*(f[p]+1)%MOD*quick_pow(2, MOD-2)%MOD*f[i]%MOD) %= MOD;
        else (f[k] += (LL)f[i]*f[j]%MOD*f[p]%MOD) %= MOD;
        }
    printf("%d\n", f[n]);
}
int main() {
    work();
    return 0;
}
