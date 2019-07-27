#include <bits/stdc++.h>
using namespace std;

int n, t;
int A[10], cur[10];

bool decode(int x) {
    for(int i = 0; i < n; i++) {
        cur[i] = x % 64;
        x >>= 6;
        if(cur[i] == t) return true;
    }
    return false;
}

int encode() {
    int ret = 0;
    for(int i = n - 1; i >= 0; i--) {
        ret = (ret << 6) + cur[i];
    }
    return ret;
}

set<int> st;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", A + i);
    }
    scanf("%d", &t); int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] < t) cnt++;
    }
    if(cnt == n) {
        puts("-1");
        return 0;
    }
    int gcd = A[0];
    for(int i = 1; i < n; i++) gcd = __gcd(gcd, A[i]);
    if(t % gcd) {
        puts("-1");
        return 0;
    }
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    st.insert(0);
    while(Q.size()) {
        pair<int, int> x = Q.front(); Q.pop();
        if(decode(x.second)) {
            printf("%d\n", x.first);
            return 0;
        }
        for(int i = 0; i < n; i++) { // fill a cup
            if(cur[i] == A[i]) continue;
            int temp = cur[i]; cur[i] = A[i];
            int code = encode();
            if(st.find(code) == st.end()) {
                Q.push({x.first + 1, code});
                st.insert(code);
            }
            cur[i] = temp;
        }
        for(int i = 0; i < n; i++) { // empty a cup
            if(cur[i] == 0) continue;
            int temp = cur[i]; cur[i] = 0;
            int code = encode();
            if(st.find(code) == st.end()) {
                Q.push({x.first + 1, code});
                st.insert(code);
            }
            cur[i] = temp;
        }
        for(int i = 0; i < n; i++) { // fill another cup
            for(int j = 0; j < n; j++) {
                if(i != j && cur[j] < A[j] && cur[i] > 0) {
                    int temp = min(A[j] - cur[j], cur[i]);
                    cur[i] -= temp; cur[j] += temp;
                    int code = encode();
                    if(st.find(code) == st.end()) {
                        st.insert(code);
                        Q.push({x.first + 1, code});
                    }
                    cur[i] += temp; cur[j] -= temp;
                }
            }
        }
    }
    puts("-1");
    return 0;
}
