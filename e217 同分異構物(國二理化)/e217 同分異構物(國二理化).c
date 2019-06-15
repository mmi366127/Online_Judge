#include <stdio.h>
#include <string.h>
#define maxn 57
typedef unsigned long long int loli;


loli base[maxn], dp[maxn];
int n;

loli pow(loli a, int n) {
    loli ret = 1, tmp = a;
    while(n) {
        if(n & 1) {
            ret *= tmp;
        }
        n <<= 1;
        tmp *= tmp;
    }
    return ret;
}

loli cal_3(int n) {
    loli ret = 0;
    int mx = (n + 1) >> 1;
    // 3 different
    for(int i = 1; i < mx; i++) {
        for(int j = i + 1; j < mx; j++) {
            int k = n - i - j;
            if(k < mx && k > j)
                ret += base[i] * base[j] * base[k];
        }
    }
    // 2 different
    for(int i = 1; i < mx; i++) {
        int j = n - i - i;
        if(j > 0 && j < mx && i != j)
            ret += base[i] * (base[i] + 1) / 2 * base[j];
    }
    // All same
    if(n % 3 == 0) {
        ret += base[n/3] * (base[n/3] + 1) * (base[n/3] + 2) / 6;
    }
    return ret;
}

loli cal_4(int n) {
    loli ret = 0;
    int mx = (n + 1) >> 1;
    // 4 different
    for(int i = 1; i < mx; i++) {
        for(int j = i + 1; j < mx; j++) {
            for(int k = j + 1; k < mx; k++) {
                int l = n - i - j - k;
                if(l > k && l < mx) {
                    ret += base[i] * base[j] * base[k] * base[l];
                }
            }
        }
    }
    // 3 different
    for(int i = 1; i < mx; i++) {
        for(int j = 1; j < mx; j++) {
            int k = n - i - i - j;
            if(k > j && k < mx && i != j && i != k) {
                ret += base[i] * (base[i] + 1) / 2 * base[j] * base[k];
            }
        }
    }
    // 2 different
    if(n % 2 == 0) {
        int half = n >> 1;
        for(int i = 1; i+i < half; i++) {
            int j = half - i;
            ret += base[i] * (base[i] + 1) / 2 * base[j] * (base[j] + 1) / 2;
        }
    }
    for(int i = 1; i <= n && n > 3 * i; i++) {
        int j = n - i - i - i;
        if(i != j && j < mx) {
            ret += base[i] * (base[i] + 1) * (base[i] + 2) / 6 * base[j];
        }
    }
    // All same
    if(n % 4 == 0) {
        ret += base[n/4] * (base[n/4] + 1) * (base[n/4] + 2) * (base[n/4] + 3) / 24;
    }

    return ret;
}




int main() {
    base[0] = 1;
    for(int i = 1; i < maxn; i++) {
        for(int j = 0; j <= i; j++)  {
            for(int k = j; k <= i; k++) {
                int l = i - j - k - 1;
                if(l < k) break;
                if(j == l)
                    base[i] += base[j]*(base[j]+1)*(base[j]+2) / 6;
                else if(j == k)
                    base[i] += (base[k] * (base[k]+1) / 2 ) * base[l];
                else if(k == l)
                    base[i] += (base[k] * (base[k]+1) / 2 ) * base[j];
                else
                    base[i] += base[j] * base[k] * base[l];
            }
        }
    }
    dp[0] = dp[1] = 1;
    for(int sz = 2; sz < maxn; sz++) {
        if(sz & 1) {
            dp[sz] = base[sz >> 1] * (base[sz >> 1] + 1) / 2 + base[sz >> 1] * (base[(sz >> 1) + 1] - base[sz >> 1]);
        } else {
            dp[sz] = base[sz >> 1] * (base[sz >> 1] + 1) / 2;
        }
        //printf("%d %llu %llu %llu\n", sz, dp[sz], cal_3(sz - 1), cal_4(sz - 1));
        dp[sz] += cal_3(sz - 1);
        dp[sz] += cal_4(sz - 1);
    }
    while(~scanf("%d", &n) && n) {
        printf("%llu\n", dp[n]);
    }
    return 0;
}
