#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int arr[maxn], cnt[201] = {};
int n, k, ans = 0;

int get_mid() {
    if(k & 1) {
        int tmp = k / 2;
        for(int i = 0; i < 200; i++) {
            if(tmp < cnt[i]) return i + i;
            tmp -= cnt[i];
        }
    } else {
        int tmp = k / 2;
        for(int i = 0; i < 200; i++) {
            if(tmp == cnt[i]) {
                for(int j = i + 1; j <= 200; j++) {
                    if(cnt[j]) return i + j;
                }
            } else if(tmp < cnt[i]) {
                return i + i;
            }
            tmp -= cnt[i];
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++) {
        scanf("%d", arr + i); cnt[arr[i]]++;
    }
    for(int i = k + 1; i <= n; i++) {
        scanf("%d", arr + i);
        if(arr[i] >= get_mid()) ans++;
        cnt[arr[i]]++;
        cnt[arr[i - k]]--;
    }
    printf("%d\n", ans);
    return 0;
}
