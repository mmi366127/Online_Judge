#include <bits/stdc++.h>
#define maxn 107
using namespace std;

char s[maxn] = {};
int cnt[27];
int n, t;


int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%s", &n, s + 1);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) {
            if(s[i] == '_')
                cnt[0]++;
            else
                cnt[s[i] - 'A' + 1]++;
        }
        bool flag = true;
        if(cnt[0] == 0) {
            for(int i = 1; i <= n; i++) {
                if(s[i - 1] != s[i] && s[i + 1] != s[i]) {
                    flag = false;
                    break;
                }
            }
        }
        for(int i = 1; i <= 26; i++) {
            if(cnt[i] == 1) {
                flag = false;
                break;
            }
        }

        puts(flag ? "YES" : "NO");
    }
    return 0;
}
