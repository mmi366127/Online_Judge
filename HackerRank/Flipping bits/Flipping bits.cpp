#include <bits/stdc++.h>
using namespace std;

unsigned int n, x;

int main() {
    scanf("%u", &n);
    for(int i = 0; i < n; i++) {
        scanf("%u", &x);
        printf("%u\n", ~x);
    }
    return 0;
}
