#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> st;
int n, k, X, Y;

int main() {
    scanf("%d%d", &n, &k);
    scanf("%d%d", &Y, &X);
    for(int i = 0; i < k; i++) {
        int x, y; scanf("%d%d", &y, &x);
        st.insert({x, y});
    }
    int ans = 0;
    for(int i = 1; i + X <= n && i + Y <= n; i++) {
        if(st.count({i + X, i + Y})) break;
        ans++;
    }
    for(int i = 1; i + X <= n && Y - i > 0; i++) {
        if(st.count({X + i, Y - i})) break;
        ans++;
    }
    for(int i = 1; X - i > 0 && Y + i <= n; i++) {
        if(st.count({X - i, i + Y})) break;
        ans++;
    }
    for(int i = 1; X - i > 0 && Y - i > 0; i++) {
        if(st.count({X - i, Y - i})) break;
        ans++;
    }
    for(int i = 1; i + Y <= n; i++) {
        if(st.count({X, i + Y})) break;
        ans++;
    }
    for(int i = 1; i + X <= n; i++) {
        if(st.count({i + X, Y})) break;
        ans++;
    }
    for(int i = 1; X - i > 0; i++) {
        if(st.count({X - i, Y})) break;
        ans++;
    }
    for(int i = 1; Y - i > 0; i++) {
        if(st.count({X, Y - i})) break;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
