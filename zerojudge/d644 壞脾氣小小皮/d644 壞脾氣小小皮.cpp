#include <stdio.h>
#include <string.h>
#include <windows.h>
#define sz 5
const int mod = 100019;

void mul(int a[sz][sz], int b[sz][sz], int c[sz][sz]) {
    long long ret[sz][sz] = {};
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            for(int k = 0; k < sz; k++) {
                ret[i][j] += (long long)b[i][k] * a[k][j];
            }
        }
    }
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            c[i][j] = ret[i][j] % mod;
        }
    }
}

int M[31][sz][sz];
int n;

int cal_A(int n) {
    static int cal[sz][sz];
    if(n <= 2) return 1;
    n -= 2;
    memset(cal, 0, sizeof(cal));
    for(int i = 0; i < sz;i++)
            cal[i][i] = 1;
    for(int i = 0; i < 31; i++) {
        if(n & (1 << i)) {
            mul(cal, M[i], cal);
        }
    }
    return cal[3][3] + cal[4][3];
}

int cal_B(int n) {
    static int cal[sz][sz];
    static int m[sz] = {2, 1, 1, 2, 1};
    if(n <= 0) return 0;
    if(n <= 2) return 1;
    if(n <= 3) return 2;
    n -= 3;
    memset(cal, 0, sizeof(cal));
    for(int i = 0; i < sz;i++)
            cal[i][i] = 1;
    for(int i = 0; i < 31; i++) {
        if(n & (1 << i)) {
            mul(cal, M[i], cal);
        }
    }
    long long ret = 0;
    for(int i = 0; i < 5; i++) {
        ret = (ret + cal[i][0] * m[i]) % mod;
    }
    return ret;
}

int main() {
    M[0][0][0] = 0; M[0][1][0] = 0; M[0][2][0] = 1; M[0][3][0] = 1; M[0][4][0] = 1;
    M[0][0][1] = 1; M[0][1][1] = 0; M[0][2][1] = 0; M[0][3][1] = 0; M[0][4][1] = 0;
    M[0][0][2] = 0; M[0][1][2] = 1; M[0][2][2] = 0; M[0][3][2] = 0; M[0][4][2] = 0;
    M[0][0][3] = 0; M[0][1][3] = 0; M[0][2][3] = 0; M[0][3][3] = 1; M[0][4][3] = 1;
    M[0][0][4] = 0; M[0][1][4] = 0; M[0][2][4] = 0; M[0][3][4] = 1; M[0][4][4] = 0;
    for(int i = 1; i < 31; i++) {
        mul(M[i - 1], M[i - 1], M[i]);
    }
    while(~scanf("%d", &n)) {
        printf("%d\n", (cal_A(n) - cal_B(n - 3) + mod) % mod);
    }
    return 0;
}
