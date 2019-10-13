#include <stdio.h>
#include <set>
using namespace std;

multiset< pair<int, int> >::iterator it;
multiset< pair<int, int> > st;
int k, p;

int main() {
    while(~scanf("%d", &k) && k) {
        if(k == 1) {
            scanf("%d%d", &k, &p);
            st.insert(make_pair(p, k));
        } else if(st.size()) {
            if(k == 2) {
                it = st.end(); it--;
                printf("%d\n", it->second);
                st.erase(it);
            } else {
                it = st.begin();
                printf("%d\n", it->second);
                st.erase(it);
            }
        } else puts("0");
    }
    return 0;
}
