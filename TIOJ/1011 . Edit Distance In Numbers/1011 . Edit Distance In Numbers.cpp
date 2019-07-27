#pragma GCC optimize("O3", "Ofast")
#include <bits/stdc++.h>
#define X first
#define Y second
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define lowbit(X) ((X)&(-(X)))
#define MEM(X, val) memset((X), (val), sizeof(X));
#define pb push_back
#define ins insert
#define mp make_pair
#define eb emplace_back
#define YEE ios_base::sync_with_stdio(0); cin.tie(nulltpr)
#define maxn 1000007
using namespace std;

int main() {
    int a, b, ans = 0;
    scanf("%d%d", &a, &b);
    while(a != b) {
        if(a > b) a >>= 1;
        else b >>= 1;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

