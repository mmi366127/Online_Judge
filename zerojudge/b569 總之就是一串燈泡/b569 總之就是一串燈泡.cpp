#include <bits/stdc++.h>
using namespace std;

string s, t, tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    for(auto &c : s) c -= '0';
    for(auto &c : t) c -= '0';
    for(int i = 0; i < s.size(); i++) {
        if(s[i]) {
            t[i] = t[i] ^ 1;
        }
    }
    t[0]++;
    for(int i = 0; i < t.size(); i++) {
        if(t[i] > 1) {
            if(i + 1 != t.size()) t[i + 1] += t[i] / 2;
            t[i] %= 2;
        }
    }
    for(int i = 0; i < t.size(); i++) {
        if(s[i]) {
            t[i] ^= 1;
        }
    }
    for(auto &c : t) c += '0';
    cout << t << '\n';
    return 0;
}
