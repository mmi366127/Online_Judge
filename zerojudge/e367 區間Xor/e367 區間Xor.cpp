#include <stdio.h>
#include <string.h>
#define maxn 100005


int arr[maxn];
int a, b;

int main() {
    arr[0] = 0;
    for(int i = 1; i < maxn; i++) {
        arr[i] = arr[i - 1] ^ i;
    }
    for(int i = 1; i < maxn; i++) {
        arr[i] ^= arr[i - 1];
    }
    while(~scanf("%d%d", &a, &b))
        printf("%d\n", arr[a - 1] ^ arr[b]);
    return 0;
}
