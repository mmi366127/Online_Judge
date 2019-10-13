#include <bits/stdc++.h>
using namespace std;

vector<pair<string, string>> V;
set<string> Try, AC;
int n, k = 0;
string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> t;
        V.emplace_back(s, t);
    }
    for(int i = n  - 1; i >= 0; i--) {
        s = V[i].first; t = V[i].second;
        if(Try.find(s) == Try.end()) {
            if(t == "AC") {
                k++;
                AC.insert(s);
            }
        } else {
            if(t == "AC") {
                AC.insert(s);
            }
        }
        Try.insert(s);
    }
    cout << k * 100 / AC.size() << "%\n";
    return 0;
}
