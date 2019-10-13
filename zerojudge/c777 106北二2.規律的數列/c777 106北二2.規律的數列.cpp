#include <stdio.h>
#define maxn 70

long long arr[maxn];

int upper(long long x) {
    for(int i = 0; i < maxn; i++)
        if(arr[i] > x) return i;
}

int lower(long long x) {
    for(int i = 0; i < maxn; i++)
        if(arr[i] >= x) return i;
}

long long n, m;

int main() {
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    for(int i = 3; i < maxn; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    scanf("%lld%lld", &n, &m);
    printf("%d\n", upper(m) - lower(n));
    return 0;
}
