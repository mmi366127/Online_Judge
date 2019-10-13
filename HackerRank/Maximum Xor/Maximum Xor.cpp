#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

struct Trie {
    vector<vector<int>> t;
    #define ALPHA 2
    Trie() {
        t.emplace_back(ALPHA, -1);
    }
    void insert(int x) {
        int p = 0;
        for(int i = 31; i >= 0; i--) {
            int v = (int)((x & (1 << i)) > 0);
            if(t[p][v] == -1) {
                t[p][v] = t.size();
                t.emplace_back(ALPHA, -1);
            }
            p = t[p][v];
        }
    }
    int query(int x) {
        int p = 0, ret = 0;
        for(int i = 31; i >= 0; i--) {
            int v = ((int)((x & (1 << i)) > 0)) ^ 1;
            if(t[p][v] != -1)
                ret += (1 << i);
            else
                v = v ^ 1;
            p = t[p][v];
        }
        return ret;
    }
};

Trie cute;
int n, x;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        cute.insert(x);
    }
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        printf("%d\n", cute.query(x));
    }
    return 0;
}

