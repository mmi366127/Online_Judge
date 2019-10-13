#include <bits/stdc++.h>
using namespace std;

double r;
int m;

int main() {
    while(cin >> r >> m) {
        if(r == 0.00) {
            cout << 0 << '\n';
            continue;
        }
        cout << 1250 % m << '\n';
    }
    return 0;
}
