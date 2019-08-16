#include <bits/stdc++.h>
using namespace std;
struct Pt {
    long long v;
    char stat;
    Pt(long long a, char b) :
        v(a), stat(b) {}
    bool operator < (const Pt &a) const {
        return v == a.v ? stat > a.stat : v > a.v;
    }
};

vector<Pt> arr;
long long a, b;
int n;

int main() {
    while(~scanf("%d", &n) && n) {
        arr.clear();
        for(int i = 0; i < n;  i++) {
            scanf("%lld%lld", &a, &b);
            if(a < b) arr.emplace_back(a + b, '<');
            else if(a == b) arr.emplace_back(a + b, '=');
            else arr.emplace_back(a + b, '>');
        }
        sort(arr.begin(), arr.end());
        for(auto t : arr) {
            printf("%c%lld ", t.stat, t.v);
        }
        putchar('\n');
    }
}
