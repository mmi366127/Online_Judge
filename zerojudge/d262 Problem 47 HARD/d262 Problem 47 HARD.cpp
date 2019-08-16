#include <bits/stdc++.h>
#define maxn 200000001
#define target 5
using namespace std;



vector<int> YEE, P;
bitset<maxn> bs;

int a[5] = {0, 1, 1, 2, 1};

int main() {
    bs.set();
    bs[0] = bs[1] = 0;
    for(int i = 2; i < maxn; i++) {
        if(bs[i]) {
            P.push_back(i);
            for(int j = i + i; j < maxn; j += i) {
                bs[j] = 0;
            }
        }
    }
    printf("build %d Primes\n", P.size());

    for(int i = 2; i < maxn; i++) {
        int tmp = i, j = 0, cnt = 0;
        while(P[j] * P[j] <= tmp) {
            if(tmp % P[j] == 0) {
                while(tmp % P[j] == 0) {
                    tmp /= P[j];
                }
                cnt++;
            }
            j++;
            if(cnt > target) break;
        }
        if(tmp > 1) {
            cnt++;
        }
        if(cnt == target) YEE.push_back(i);
    }

    printf("find %d YEE\n", YEE.size());

    for(int i = 0; i < YEE.size(); i++) {
        bool flag = true;
        for(int j = 0; j < target; j++) {
            if(YEE[i + j] != YEE[i] + j) {
                flag = false;
                break;
            }
        }
        if(flag) {
            for(int j = 0; j < target; j++) {
                printf("%d ", YEE[i + j]);
            }
            puts("");
            break;
        }
    }

    puts("done");

    while(1);
    return 0;
}
/*
4 134043 134044 134045 134046
5 129963314 129963315 129963316 129963317 129963318
*/
