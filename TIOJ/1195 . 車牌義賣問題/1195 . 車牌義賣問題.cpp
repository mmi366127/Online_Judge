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
#define maxn 100007
using namespace std;
typedef long long loli;
typedef pair<int,int> pii;
typedef pair<loli,loli> pll;


const loli INF = 0x3f3f3f3f3f3f3f3f;

int cal(char s[]) {
    if(s[2] == s[3] && s[3] == s[4] && s[4] == s[5]) return 2000;
    if(s[2] == s[3] && s[4] == s[5] && s[3] != s[4]) return 1500;
    if(s[2] == s[3] && s[3] == s[4]) return 1000;
    if(s[3] == s[4] && s[4] == s[5]) return 1000;
    return 0;
}

char s[maxn];
int n, ans = 0;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        ans += cal(s);
    }
    printf("%d\n", ans);
    return 0;
}
