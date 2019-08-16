#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

int a[30];
map<int,int> mp;
int n, m;

void dfs(int dep, int num, int cnt) {
    if(dep >= n || cnt == 0) {
        if(!cnt) mp[num]++;
        return;
    }
    for(int i = dep; i < n; i++) {
        dfs(i + 1, num + a[i], cnt - 1);
    }
}

int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        mp.clear();
        for(int i = 0; i < n; i++) scanf("%d", a + i);
        dfs(0, 0, m);
        int tmp = 0, ans = 0;
        for(pair<int,int> t : mp) {
            if(t.second > tmp) {
                tmp = t.second;
                ans = t.first;
            }
        }
        printf("%d %d\n", ans, tmp);
    }
    return 0;
}
