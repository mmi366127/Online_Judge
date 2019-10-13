#include <bits/stdc++.h>
#define maxn 100005
#define ALPHA 10
using namespace std;

struct Trie {
    vector<vector<int>> t;
    vector<int> cnt;
    Trie(){
        t.clear();
        cnt.clear();
        cnt.emplace_back(0);
        t.emplace_back(ALPHA, -1);
    }
    void insert(vector<int> &num) {
        int p = 0;
        for(int i = num.size() - 1; i >= 0; i--) {
            if(t[p][num[i]] == -1) {
                t[p][num[i]] = t.size();
                cnt.emplace_back(0);
                t.emplace_back(ALPHA, -1);
            }
            p = t[p][num[i]];
        }
        cnt[p]++;
    }
};

void mul(vector<int> &a, vector<int> &b) {
    a.resize(b.size());
    for(int i = 0; i < b.size(); i++) {
        a[i] = b[i] * 2;
    }
    for(int i = 0; i < a.size(); i++) {
        if(a[i] >= 10) {
            if(i + 1 >= a.size()) {
                a.emplace_back(0);
            }
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    }
}

void print(vector<int> &a) {
    for(int i = a.size() - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
    printf("\n");
}

vector<int> Two[801];
char s[maxn];
int n, q;

int main() {
    Trie cute;
    Two[0].emplace_back(1);
    for(int i = 1; i <= 800; i++) {
        mul(Two[i], Two[i - 1]);
        cute.insert(Two[i]);
    }
    cute.insert(Two[0]);
    scanf("%d", &q);
    while(q--) {
        scanf("%s", s);
        n = strlen(s);
        int ans = 0;
        for(int i = 0; i < n;  i++) {
            int p = 0, j = i;
            while(p != -1 && j < n) {
                ans += cute.cnt[p];
                p = cute.t[p][s[j++] - '0'];
            }
            if(p != -1) ans += cute.cnt[p];
        }
        printf("%d\n", ans);
    }
    return 0;
}
