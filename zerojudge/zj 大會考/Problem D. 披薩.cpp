#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;


int a, b, n, len;
int ans[20], tmp[20];
vector<int> P;

void dfs(int dep, int num, int idx) {
    //printf("%d %d\n", dep, num);
    if(dep >= len) return;
    if(num == 0) {
        len = dep;
        for(int i = 0; i < dep; i++) {
            ans[i] = tmp[i];
        }
        return;
    }
    for(int i = idx; i < P.size(); i++) {
        if(num >= P[i]) {
            tmp[dep] = b/P[i];
            dfs(dep + 1, num - P[i], i);
        }
    }
}


int main() {
    scanf("%d%d", &a, &b);
    for(int i = 1; i <= 30; i++) {
        if(b % i == 0) {
            P.push_back(b/i);
        }
    }
    sort(P.rbegin(), P.rend());
    //for(int i = 0; i < P.size(); i++) printf("%d\n", P[i]);
    memset(ans, 0, sizeof(ans));
    memset(tmp, 0, sizeof(tmp));
    len = 11;
    dfs(0, a, 0);
    printf("%d\n", len);
    for(int i = 0; i < len; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}


/*
115 = 84 + 24 + 7
168 = 2 * 2 * 2  * 3 * 7
*/
