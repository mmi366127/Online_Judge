#include <stdio.h>
#include <string.h>
#include <map>
typedef long long int loli;
using namespace std;
#define maxp 5007


map<int,int> GCD, a, b, tmp;
int a0, a1, b0, b1, t;
loli prime[maxp];

void init() {
    loli i, flag, idx = 1, v = 3;
    prime[0] = 2;
    while(idx < maxp) {
        i = 0; flag = 1;
        while(prime[i] * prime[i] <= v) {
            if(v % prime[i] == 0) {
                flag = 0;
                break;
            }
            i++;
        }
        if(flag) {
            prime[idx++] = v;
        }
        v += 2;
    }
}

void decompose(int x, map<int,int> &n) {
    int cnt = 0; n.clear();
    for(int i = 0; prime[i] * prime[i] <= (loli)x; i++) {
        cnt = 0;
        while(x % prime[i] == 0) {
            cnt++;
            x /= prime[i];
        }
        if(cnt) n[prime[i]] = cnt;
    }
    if(x > 1) n[x]++;
}




int main() {
    init();
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
        int YEE = a0 / a1;
        if( b1 % a1 != 0) {
            puts("0");
            continue;
        }
        decompose(b0, b);
        decompose(a1, a);
        decompose(b1, GCD);
        tmp.clear();
        for(auto t : GCD) {
            auto it = b.find(t.first);
            if(it != b.end() && it->second >= t.second) {
                tmp.insert(t);
            }
        }
        for(auto t : a) {
            tmp[t.first] -= t.second;
        }
        loli ans = 1;
        for(auto T : tmp) {
            printf("%d %d\n", T.first, T.second);
            ans *= (T.second + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
41 = 41
1 = 1
96 = 2^5 * 3
288 = 2^5 * 3^2



95 = 19  * 5
1 = 1
37 = 37
1776 = 37 * 3 * 2^4
*/
