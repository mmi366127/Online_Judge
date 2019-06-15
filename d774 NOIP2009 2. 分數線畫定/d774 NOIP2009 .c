#include <stdio.h>
#include <string.h>
#define maxn 5007
typedef struct YEE {
    int idx, score;
}YEE;
YEE arr[maxn], tmp[maxn];

char cmp(YEE a, YEE b) {
    return a.score != b.score ? a.score > b.score : a.idx < b.idx;
}

void sort(int L, int R) {
    if(L == R) return;
    int mid = (L + R) >> 1;
    int idx1 = L;
    int idx2 = mid+1;
    int idx = L;
    sort(idx1, mid);
    sort(idx2, R);
    while(idx1 <= mid && idx2 <= R) {
        if(cmp(arr[idx1], arr[idx2])) {
            tmp[idx++] = arr[idx1++];
        } else {
            tmp[idx++] = arr[idx2++];
        }
    }
    while(idx1 <= mid) {
        tmp[idx++] = arr[idx1++];
    }
    while(idx2 <= R) {
        tmp[idx++] = arr[idx2++];
    }
    for(idx = L; idx <= R; idx++)
        arr[idx] = tmp[idx];
}



int main() {
    int n, m, s;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &arr[i].idx, &arr[i].score);
    }
    sort(1, n); arr[n+1].score = -1e9;
    m = (m * 3) >> 1;
    s = arr[m].score;
    int idx;
    for(idx = 1; arr[idx].score >= s; idx++);
    printf("%d %d\n", s, idx - 1);
    for(int i = 1; i < idx; i++) {
        printf("%d %d\n", arr[i].idx, arr[i].score);
    }
    return 0;
}
