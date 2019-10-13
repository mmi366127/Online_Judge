#include <bits/stdc++.h>
using namespace std;

map<string, int> idx;
int tot = 0;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return idx[a.first] < idx[b.first];
}

struct ENV {
    vector< pair<string, int> > V;
    map<string, int> mp;
    string Name;
    ENV(string s) : Name(s) {}
    void insert(string name, int cnt) {
        if(mp.find(name) == mp.end()) {
            mp[name] = V.size();
            V.push_back(make_pair(name, cnt));
            return;
        }
        V[mp[name]].second += cnt;
    }
    void output() {
        sort(V.begin(), V.end(), cmp);
        cout << Name << " :";
        for(auto t : V) {
            cout << " " << t.first << ' ' << t.second;
            if(t != *V.rbegin()) cout << ",";
        }
        cout << '\n';
    }
};


map<string, int> mp;
vector<ENV> V;
int n;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> n;
    while(n--) {
        string animal, place; int num;
        cin >> animal >> num >> place;
        if(idx.find(animal) == idx.end()) {
            idx[animal] = tot++;
        }
        if(mp.find(place) == mp.end()) {
            mp[place] = V.size();
            V.emplace_back(place);
        }
        V[mp[place]].insert(animal, num);
    }
    for(auto t : V) {
        t.output();
    }
}
