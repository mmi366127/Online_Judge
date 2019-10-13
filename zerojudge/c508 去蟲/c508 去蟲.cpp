#include <stdio.h>
#define maxn 100005


int arr[maxn], tmp[maxn];
int n;

void sort(int l, int r) {
    if(r - l == 1) return;
    int m = (l + r) >> 1;
    sort(l, m); sort(m, r);
    int i, j, idx = l;
    for(i = l, j = m; i < m; i++) {
        while(j < r && arr[j] < arr[i]) {
            tmp[idx++] = arr[j++];
        }
        tmp[idx++] = arr[i];
    }
    while(j < r) tmp[idx++] = arr[j++];
    for(idx = l; idx < r; idx++)
        arr[idx] = tmp[idx];
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    sort(0, n);
    for(int i = 0; i < n; i++) {
        printf("%d%c", arr[i], " \n"[i == n - 1]);
    }
    for(int i = n - 1; i >= 0; i--) {
        printf("%d%c", arr[i], " \n"[i == 0]);
        while(i > 0 && arr[i] == arr[i - 1]) i--;
    }
    return 0;
}
