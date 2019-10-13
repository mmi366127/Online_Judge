#include <bits/stdc++.h>
using namespace std;


map<int, int> mp;

int f(int x) {
    if(mp.find(x) != mp.end())
        return mp[x];
    if(x & 1)
        mp[x] = f(x - 1) + f(x + 1);
    else
        mp[x] = f(x / 2);
    return mp[x];
}

int x;

int main() {
    mp[1] = 1;
    while(~scanf("%d", &x))
        printf("%d\n", f(x));
    return 0;
}
