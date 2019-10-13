#include <bits/stdc++.h>
#define maxn 45
using namespace std;

string S[maxn];
int ans[] = {0,1,2,2,4,6,6,8,10,14,20,26,34,46,62,78,102,134,176,226,302,408,528,678,904,1182,1540,2012,2606,3410,4462,5808,7586,9898,12884,16774,21890,28528,37158,48410,63138,82350,107312,139984,182376};
int n;

int main() {
    /*S[1] = "1";
    for(int i = 2; i < maxn; i++) {
        for(int j = 0, k = 0; j < S[i - 1].size(); j++) {
            k = j;
            while(k < S[i - 1].size() - 1 && S[i - 1][k] == S[i - 1][k + 1]) {
                k++;
            }
            S[i] += to_string(k - j + 1);
            S[i] += S[i - 1][j];
            j = k;
        }
    }

    for(int i = 1; i < maxn; i++) {
        cout << S[i].size() << ',';
    }*/
    while(~scanf("%d", &n) && n) {
        printf("%d %.6f\n", ans[n], (double)ans[n - 1] / (double)ans[n]);
    }
    return 0;
}
