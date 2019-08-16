#include <bits/stdc++.h>
using namespace std;
struct Node {
    int dep;
    string s;
};

string rules[10][2];
string s, t;
int idx = 0;
set<string> st;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    while(cin >> rules[idx][0] >> rules[idx][1]) idx++;
    queue<Node> que;
    que.push({0, s});
    while(que.size()) {
        Node x = que.front();
        que.pop();
        //cout << x.s << endl;
        if(x.dep > 10 || st.find(x.s) != st.end()) continue;
        st.insert(x.s);
        if(x.s == t) {
            cout << x.dep << '\n';
            return 0;
        }
        for(int i = 0; i < idx; i++) {
            for(int j = 0; j + rules[i][0].size() - 1 < x.s.size(); j++) {
                if(x.s[j] == rules[i][0][0]) {
                    int p1 = j, p2 = 0;
                    while(p2 < rules[i][0].size() && x.s[p1] == rules[i][0][p2]) {
                        p1++; p2++;
                    }
                    if(p2 == rules[i][0].size()) {
                        string next;
                        next = x.s.substr(0, j) + rules[i][1] + x.s.substr(p1, x.s.size() - p1);
                        if(x.dep < 10)
                        que.push({x.dep + 1, next});
                    }
                }
            }
        }
    }
    cout << "no answer!\n";
    return 0;
}
