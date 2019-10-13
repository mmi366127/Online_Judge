#include <set>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 1000005
using namespace std;

char used[maxn];
int arr[maxn];
set<int> st;
int t, n, m;


int main() {
    scanf("%d", &t);
    while(t--) {
        st.clear();
        scanf("%d%d", &n, &m);
        memset(used, 0, (m + 1));
        for(int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        int idx;
        for(int i = 0; i < n; i++) {
            if(used[arr[i]] || i == n - 1) {
                idx = i;
                break;
            }
            used[arr[i]] = 1;
        }
        for(int i = 1; i <= m; i++) {
            if(!used[i]) st.insert(i);
        }
        while(1) {
            auto it = st.upper_bound(arr[idx]);
            if(it == st.end()) {
                st.insert(arr[--idx]);
                used[arr[idx]] = 0;
            } else {
                arr[idx++] = *it;
                used[*it] = 1;
                break;
            }
        }
        for(int i = 1; i <= m && idx < n; i++)
            if(!used[i]) arr[idx++] = i;
        for(int i = 0; i < n; i++)
            printf("%d%c", arr[i], " \n"[i == n - 1]);
    }
    return 0;
}
/*
3
5 5
1 2 3 4 5
5 5
2 1 5 4 3
5 5
3 3 3 3 2

1 2 3 5 4
2 3 1 4 5
3 4 1 2 5

*/
