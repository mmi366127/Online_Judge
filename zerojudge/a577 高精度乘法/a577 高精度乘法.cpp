#include <bits/stdc++.h>
#define maxn (1 << 18)
using namespace std;

const double PI = acos(-1);

void FFT(complex<double> A[], int n, int rev) {
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

complex<double> A[maxn], B[maxn];
char a[maxn], b[maxn];
int ans[maxn + 5];

int main() {
    while(~scanf("%s%s", a, b)) {
        int len_a = strlen(a);
        int len_b = strlen(b);
        int n = (1 << (__lg(len_a + len_b - 1) + 1));
        for(int i = 0; i < n; i++) {
            A[i] = B[i] = {0.00, 0.00};
        }
        for(int i = len_a - 1, j = 0; i >= 0; i--) {
            A[j++] = {a[i] ^ '0', 0.00};
        }
        for(int i = len_b - 1, j = 0; i >= 0; i--) {
            B[j++] = {b[i] ^ '0', 0.00};
        }
        FFT(A, n, 1);
        FFT(B, n, 1);
        for(int i = 0; i < n; i++) {
            A[i] = A[i] * B[i];
        }
        FFT(A, n, -1);
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i++) {
            ans[i] = A[i].real() / n + 0.5;
        }
        for(int i = 0; i < n + 5; i++) {
            if(ans[i] >= 10) {
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }
        for(int i = n + 4; i >= 0; i--) {
            if(ans[i] > 0 ||  i == 0) {
                while(i >= 0) {
                    putchar(ans[i--] ^ '0');
                }
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}
