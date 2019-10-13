#include <stdio.h>
#include <string.h>
#define maxn 100005


int arr[maxn], tmp[maxn];
int n, k;

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

int get_val(int l, int r, int v) {
    if(arr[l] > v) return l;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if(arr[mid] <= v)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int check(int num) {
    long long cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += get_val(0, i, arr[i] - num);
    }
    return cnt >= k;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    sort(0, n);
    int l = 0, r = 1e9 + 1;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", l);
    return 0;
}
