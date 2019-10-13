#include <stdio.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

int t, sum, d, m, mx, mi, tot, n;
int arr[1000];
char s[20000];

int main() {
    scanf("%d", &t);
    fgets(s, sizeof(s), stdin);
    while(t--) {
        n = 0; fgets(s, sizeof(s), stdin);
        int i = 0;
        while(s[i]) {
            if(s[i] >= '0') {
                arr[n] = 0;
                while(s[i] >= '0') {
                    arr[n] = arr[n] * 10 + (s[i++] ^ '0');
                }
                n++;
            } else i++;
        }
        sort(arr, arr + n);
        sum = mx = 0; mi = 2147483647;
        for(int i = 0; i < n; i++) {
            if(i < n - 1 && arr[i] == arr[i + 1])
                d = arr[i];
            sum += arr[i];
            mi = min(mi, arr[i]);
            mx = max(mx, arr[i]);
        }
        tot = (mx + mi) * n / 2;
        printf("%d %d\n", tot - sum + d, d);
    }
    return 0;
}
