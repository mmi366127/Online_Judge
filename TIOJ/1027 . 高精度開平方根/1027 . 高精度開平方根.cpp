#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

void mul(const vector<int> &a, const vector<int> &b, vector<int> &c) {
    fill(c.begin(), c.end(), 0);
    for(int i = 0; i <= 87; i++) {
        for(int j = 0; j <= 87; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    for(int i = 199; i > 0; i--) {
        if(c[i] >= 10) {
            c[i - 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

bool cmp(const vector<int> &a, const vector<int> &b) {
    for(int i = 0; i < 200; i++) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

int main() {
    vector<int> ans(200, 0), tmp(200, 0), n(200, 0);
    scanf("%d", &n[0]);
    ans[0] = (int)sqrt(n[0]);
    for(int i = 1; i <= 60; i++) {
        for(int j = 0; j < 10; j++) {
            ans[i] = j;
            mul(ans, ans, tmp);
            if(cmp(n, tmp)) {
                ans[i] = j - 1;
                break;
            }
        }
    }
    if(ans[51] >= 5) ans[50]++;
    for(int i = 50; i > 0; i--) {
        if(ans[i] >= 10) {
            ans[i - 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    printf("%d.", ans[0]);
    for(int i = 1; i <= 50; i++) printf("%d", ans[i]);
    puts("");
    return 0;
}
