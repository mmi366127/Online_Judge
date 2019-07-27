#include <bits/stdc++.h>
using namespace std;


int a, b, c, A, B, C;

int main() {
    scanf("%d:%d:%d", &a, &b, &c);
    scanf("%d:%d:%d", &A, &B, &C);
    int ans = (A * 3600 + B * 60 + C) - (a * 3600 + b * 60 + c) + 86400 * 87;
    ans %= 86400;
    printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
    return 0;
}
