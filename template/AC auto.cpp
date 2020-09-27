#include <bits/stdc++.h>
#define maxn 350005
using namespace std;

const int ALPHA = 26;

int T[maxn][ALPHA], fail[maxn], val[maxn];
int cnt;

int node() {
    for(int i = 0; i < ALPHA; i++) {
        T[cnt][i] = 0;
    }
    val[cnt] = 0;
    return cnt++;
}

int insert(string &s)  {
    int p = 0;
    for(char c : s) {
        int nxt = c - 'a';
        if(!T[p][nxt]) {
            T[p][nxt] = node();
        }
        p = T[p][nxt];
    }
    return p;
}

void init() {
    cnt = 0; init();
}

void build() {
    queue<int> que;
    for(int i = 0; i < 26; i++) {
        if(T[0][i]) {
            fail[T[0][i]] = 0;
            que.push(T[0][i]);
        }
    }
    while(que.size()) {
        int x = que.front();
        que.pop();
        for(int i = 0; i < 26; i++) {
            if(T[x][i]) {
                que.push(T[x][i]);
                fail[T[x][i]] = T[fail[x]][i];
            }
            else {
                T[x][i] = T[fail[x]][i];
            }
        }
    }
}

void solve(string &s) {
    int p = 0;
    for(char c : s) {
        p = T[p][c - 'a'];
        for(int i = p; i > 0; i = fail[i]) {
            val[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); int T, Q;
    string s, t;
    cin >> T;
    while(T--) {
        init();
        cin >> s >> Q;
        vector<int> ans;
        while(Q--) {
            cin >> t;
            ans.push_back(insert(t));
        }
        build(); solve(s);
        for(auto it : ans) {
            cout << val[it] << '\n';
        }
    }
    return 0;
}