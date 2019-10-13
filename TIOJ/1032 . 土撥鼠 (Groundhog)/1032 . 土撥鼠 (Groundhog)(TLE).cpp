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

#define getchar getchar_unlocked

bool read(int &x) {
    static char c;
    for(c = getchar(); c < '0'; c = getchar())
        if(c == EOF) return false;
    for(x = 0; c >= '0'; c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
    return true;
}

const loli INF = 0x3f3f3f3f3f3f3f3f;

map<int,int> G[maxn];

int n, m, op, x, y, k;
set<int> st;

int main() {
    read(n), read(m);
    while(read(op)) {
        if(op == 0) {
            read(x), read(y);
            G[x][y]++;
            G[y][x]++;
        } else if(op == 1) {
            read(x), read(y);
            if(G[x][y] == 1) {
                G[x].erase(y);
                G[y].erase(x);
            } else {
                G[x][y]--;
                G[y][x]--;
            }
        } else if(op == 2) {
            read(k);
            st.clear();
            for(int i = 0; i < k; i++) {
                read(x);
                st.insert(x);
            }
            bool flag = true;
            for(auto a : st) {
                for(auto t : G[a]) {
                    if(st.find(t.X) == st.end()) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) {
                putchar('1');
                putchar('\n');
            } else {
                putchar('0');
                putchar('\n');
            }
        }
    }

    return 0;
}
