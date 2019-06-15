#include <stdio.h>
#include <string.h>
#define maxn 50

int T, n, i;
int a[maxn+7], t[maxn+7];

void sort(int L, int R) {
    if(L == R) return;
    int mid = (L + R) >> 1;
    int idx1 = L;
    int idx2 = mid+1;
    int idx = L;
    sort(idx1, mid);
    sort(idx2, R);
    while(idx1 <= mid && idx2 <= R) {
        if(a[idx1] < a[idx2]) {
            t[idx++] = a[idx1++];
        } else {
            t[idx++] = a[idx2++];
        }
    }
    while(idx1 <= mid) {
        t[idx++] = a[idx1++];
    }
    while(idx2 <= R) {
        t[idx++] = a[idx2++];
    }
    for(idx = L; idx <= R; idx++) {
        a[idx] = t[idx];
    }
}

char s[1000007];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        if(n >= maxn) {
            fgets(s, sizeof(s), stdin);
            while(1) {
                s[1000006] = '@';
                fgets(s, sizeof(s), stdin);
                if(s[1000006] == '@') break;
            }
            puts("YES");
            continue;
        }
        for(int i = 1; i <= n; i++) {
            scanf("%d", a+i);
        }
        char flag = 0;
        sort(1, n);
        for(int i = 1; i <=n; i++) {
            for(int j = i + 1; j <= n; j++) {
                for(int k = j + 1; k <= n; k++) {
                    if(a[i] + a[j] > a[k]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
