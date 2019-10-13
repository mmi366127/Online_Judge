#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 20
using namespace std;

int Time[maxn];
int n, t, a, b;

int main() {
    while(~scanf("%d%d", &n, &t)) {
        memset(Time, 0, sizeof(Time));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < t; j++) {
                scanf("%d:%d", &a, &b);
                Time[j] += a * 60 + b;
            }
        }
        sort(Time, Time + t);
        for(int i = 0; i < t; i++) {
            printf("%d\n", Time[i]);
        }
    }
    return 0;
}
