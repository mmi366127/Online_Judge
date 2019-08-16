#include <bits/stdc++.h>
using namespace std;
struct Pt {
    long long x, y;
    Pt(long long a = 0.00, long long b = 0.00) :
        x(a), y(b){}
    Pt operator - (const Pt &a) const {
        return Pt(x - a.x, y - a.y);
    }
    long long operator * (const Pt &a) const {
        return x * a.x + y * a.y;
    }
    long long operator ^ (const Pt &a) const {
        return x * a.y - a.x * y;
    }
};

char *S[] = {"Gold", "Diamond", "Emerald"};
Pt arr[100];
int n, t;

long long area(int i, int j, int k) {
    return abs((arr[i] - arr[k]) ^ (arr[j] - arr[k]));
}

int type(int i, int j, int k) {
    static long long a, b, c;
    a = (arr[j] - arr[i]) * (arr[k] - arr[i]);
    b = (arr[i] - arr[j]) * (arr[k] - arr[j]);
    c = (arr[i] - arr[k]) * (arr[j] - arr[k]);
    if(a < 0 || b < 0 || c < 0) return 0;
    else if(a == 0 || b == 0 || c == 0) return 1;
    else return 2;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%lld%lld", &arr[i].x, &arr[i].y);
        }
        long long ans = 0x3f3f3f3f3f3f3f3f; int t = 100;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    long long Area = area(i, j, k);
                    if(Area == 0) continue;
                    if(Area < ans) {
                        ans = Area;
                        t = type(i, j, k);
                    } else if(Area == ans) {
                        t = min(t, type(i, j, k));
                    }
                }
            }
        }
        printf("Block of %s %lld", S[t], ans >> 1);
        if(ans & 1) puts(".5");
        else puts("");
    }
}
