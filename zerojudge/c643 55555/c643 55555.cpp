#include <stdio.h>
#define maxn 55555
#define digit 1000000000000000000LL
typedef long long loli;

loli tmp[100000] = {}, bin[100000] = {};
int tmp_sz, bin_sz, n;
char s[55556];

int mul(loli arr[], loli v, int sz) {
    for(int i = 0; i < sz; i++) {
        arr[i] *= v;
    }
    for(int i = 0; i < sz; i++) {
        if(arr[i] >= digit) {
            if(i < sz - 1) arr[i + 1] += arr[i] / digit;
            else arr[sz++] = arr[i] / digit;
            arr[i] %= digit;
        }
    }
    return sz;
}

int div(loli arr[], loli v, int sz) {
    for(int i = sz - 1; i >= 0; i--) {
        if(i) arr[i - 1] += (arr[i] % v) * digit;
        arr[i] /= v;
    }
    if(tmp[sz - 1] == 0) sz--;
    return sz;
}

int add(loli arr[], loli v[], int sz_a, int sz_v) {
    if(sz_a < sz_v) sz_a = sz_v;
    for(int i = 0; i < sz_v;  i++) {
        arr[i] += v[i];
    }
    for(int i = 0; i < sz_a; i++) {
        if(arr[i] >= digit) {
            if(i < sz_a - 1) arr[i + 1] += arr[i] / digit;
            else arr[sz_a++] = arr[i] / digit;
            arr[i] %= digit;
        }
    }
    return sz_a;
}


int main() {
    s[maxn - 1] = '5';
    tmp[0] = 1; tmp_sz = 1;
    bin[0] = 2; bin_sz = 1;
    for(int i = 2; i <= maxn; i++) {
        //printf("%d %d %d\n", i, tmp_sz, bin_sz);

        tmp_sz = add(tmp, bin, tmp_sz, bin_sz);
        bin_sz = mul(bin, 2, bin_sz);
        for(int k = 1; k < 10; k += 2) {
            // + 10^(i - 1) * k
            // --> + 2^(i - 1) * 5^(i - 1) * k;
            // if((k * 2 ^ (i - 1) + tmp) % 5 == 0)
            // tmp /= 5

            if(tmp[0] % 5 == 0) {
                s[maxn - i] = k ^ '0';
                tmp_sz = div(tmp, 5, tmp_sz);
                break;
            }

            tmp_sz = add(tmp, bin, tmp_sz, bin_sz);
        }
    }
    scanf("%d", &n);
    while(~scanf("%d", &n)) {
        puts(s + maxn - n);
    }

    for(int i = 0; i <= maxn; i++)
    return 0;
}


/*
5          1     5
75         3     25
375        3     125
9375       15    625
59375      19    3125
359375     23    15625
3359375    43    78125
*/
