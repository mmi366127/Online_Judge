#include <bits/stdc++.h>
#define maxn (1 << 23)
using namespace std;

const double PI = acos(-1);

complex<double> A[maxn], B[maxn];

void FFT(complex<double> A[], int n, int rev) {
    // rev == -1 -----> IDFT
    // rer == 1  ----->  DFT
    complex<double> step, w, u, v;
    for(int i = 1, j = 0; i < n; i++) {
        for(int k = (n >> 1); k > (j ^= k); k >>= 1);
        if(i < j) swap(A[i], A[j]);
    }
    for(int len = 1; len << 1 <= n; len <<= 1) {
        step = {cos(PI*rev/len), sin(PI*rev/len)};
        for(int i = 0; i < n; i += (len << 1)) {
            w = {1.0, 0.0};
            for(int j = 0; j < len; j++) {
                u = A[i + j];
                v = A[i + len + j];
                A[i + j] = u + w * v;
                A[i + len + j] = u - w * v;
                w = w * step;
            }
        }
    }
}

int la, lb, tmp[maxn] = {};
char a[maxn], b[maxn];

int main() {
    //大數乘法
    scanf("%s %s", a, b);
    la = strlen(a), lb = strlen(b);
    int n = 1 << (__lg(la + lb - 1) + 1);
    for(int i = 0; i < n; i++)
        A[i] = B[i] = {0.00, 0.00};
    for(int i = la - 1, j = 0; i >= 0; i--) {
        A[j++] = {a[i] - '0', 0};
    }
    for(int i = lb - 1, j = 0; i >= 0; i--) {
        B[j++] = {b[i] - '0', 0};
    }
    FFT(A, n, 1);
    FFT(B, n, 1);
    for(int i = 0; i < n; i++) {
        A[i] = A[i] * B[i];
    }
    FFT(A, n, -1);
    for(int i = 0; i < n; i++) {
        tmp[i] = A[i].real() / n + 0.5;
    }
    for(int i = 0; i < n; i++) {
        if(tmp[i] >= 10) {
            tmp[i + 1] += tmp[i] / 10;
            tmp[i] %= 10;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(tmp[i]) {
            while(i >= 0) {
                printf("%01d", tmp[i]);
                i--;
            }
        }
    }
    puts("");
    return 0;
}

