#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define maxn 2019

int arr[maxn], LIS[maxn], LDS[maxn];
int n, t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = n - 1; i >= 0; i--) {
            scanf("%d", arr + i);
            LIS[i] = LDS[i] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(arr[j] < arr[i]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
                if(arr[j] > arr[i]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, LIS[i] + LDS[i] - 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
