#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int>> trie(1, vector<int>(26, -1));

char s[1000];


int main() {
    while(~scanf("%s", s)) {
        int p = 0;
        for(int i = 0; s[i]; i++) {
            int d = s[i] - 'A';
            if(trie[p][d] == -1) {
                trie[p][d] = trie.size();
                trie.push_back(vector<int>(26, -1));
            }
            p = trie[p][d];
        }
    }
    printf("%d\n", trie.size());
    return 0;
}
