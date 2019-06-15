#include <stdio.h>
#include <string.h>
#define maxn 100007
#define ALPHA 26

int trie[maxn][ALPHA], tot = 0;
char s[1000];

int new_node() {
    memset(trie[tot], -1, sizeof(int)*ALPHA);
    return tot++;
}

int main() {
    new_node();
    while(~scanf("%s", s)) {
        for(int i = 0, p = 0; s[i]; i++) {
            int d = s[i] - 'A';
            if(trie[p][d] == -1) {
                trie[p][d] = new_node();
            }
            p = trie[p][d];
        }
    }
    printf("%d\n", tot);
    return 0;
}
