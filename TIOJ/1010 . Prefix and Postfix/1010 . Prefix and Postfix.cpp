#include <bits/stdc++.h>
#define X first
#define Y second
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define lowbit(X) ((X)&-(X))
#define MEM(X, val) memset((X), (val), sizeof(X));
#define pb push_back
#define ins insert
#define mp make_pair
#define YEE ios_base::sync_with_stdio(0); cin.tie()
#define maxn 1007
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;


const loli INF = 0x3f3f3f3f3f3f3f3f;

char a[maxn], b[maxn];
int ans = 0;

int main() {
    scanf("%s%s", a + 1, b + 1);
    int la = strlen(a + 1);
    int lb = strlen(b + 1);
    for(int len = 1; len <= la; len++) {
        bool flag = true;
        for(int j = 1; j <= len; j++) {
            if(a[j] != b[lb - len  + j]) {
                flag = false;
                break;
            }
        }
        if(flag) ans = max(ans, len);
    }
    cout << ans << '\n';
    return 0;
}
