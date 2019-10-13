#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define X first
#define Y second
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define lowbit(X) ((X)&-(X))
#define MEM(X, val) memset((X), (val), sizeof(X));
#define eb emplace_back
#define pb push_back
#define ins insert
#define mp make_pair
#define YEE ios_base::sync_with_stdio(0); cin.tie()
#define maxn 100007
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;

//#define getchar getchar_unlocked

bool read(int &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar())
        if(c == EOF) return false;
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
    return true;
}

int n, m, op, x, y, k;

loli WTF[maxn] = {};

loli my_hash(loli x, loli y) {
    return x * 948787LL + y;
}

int main() {
    read(n), read(m);
    while(read(op)) {
        if(op == 0) {
            read(x), read(y);
            WTF[x] += my_hash(x, y);
            WTF[y] -= my_hash(x, y);
        } else if(op == 1){
            read(x), read(y);
            WTF[x] -= my_hash(x, y);
            WTF[y] += my_hash(x, y);
        } else {
            read(k); loli sum = 0;
            for(int i = 0; i < k; i++) {
                read(x);
                sum += WTF[x];
            }
            printf("%d\n", sum == 0);
        }
    }
}
