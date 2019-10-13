#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define maxn 500000
#define digit 1000
using namespace std;
typedef long long loli;

const double PI = acos(-1);

vector<loli> num[25];
int n, t1, t2;


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

void fast_mul(vector<loli> &ans, vector<loli> &a, vector<loli> &b) {
    int n = 1 << (__lg(a.size() + b.size() - 1) + 1);
    static complex<double> A[maxn], B[maxn];
    ans.resize(n);
    fill(ans.begin(), ans.end(), 0);
    for(int i = 0; i < n; i++) {
        A[i] = B[i] = {0.00, 0.00};
        if(i < a.size()) {
            A[i] = {a[i], 0.00};
        }
        if(i < b.size()) {
            B[i] = {b[i], 0.00};
        }
    }
    //printf("%d\n", n);
    //puts("FFT");
    FFT(A, n, 1);
    FFT(B, n, 1);
    for(int i = 0; i < n; i++) {
        A[i] = A[i] * B[i];
    }
    //puts("IDFT");
    FFT(A, n, -1);
    for(int i = 0; i < n; i++) {
        ans[i] = A[i].real() / n + 0.5;
    }
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] >= digit) {
            ans[i + 1] += ans[i] / digit;
            ans[i] %= digit;
        }
    }
}

void mul(vector<loli> &ans, vector<loli> &a, vector<loli> &b) {
    ans.resize(a.size() + b.size());
    fill(ans.begin(), ans.end(), 0);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            ans[i + j] += a[i] * b[j];
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] >= digit) {
            if(i + 1 >= ans.size()) {
                ans.push_back(0);
            }
            ans[i + 1] += ans[i] / digit;
            ans[i] %= digit;
        }
    }
}

void add(vector<loli> &a, vector<loli> &b) {
    for(int i = 0; i < min(a.size(), b.size()); i++) {
        a[i] += b[i];
    }
    for(int i = 0; i < a.size(); i++) {
        if(a[i] >= digit) {
            if(i + 1 >= a.size()) {
                a.push_back(0);
            }
            a[i + 1] += a[i] / digit;
            a[i] %= digit;
        }
    }
}

void print(vector<loli> &a) {
    for(int i = a.size() - 1; i >= 0; i--) {
        if(a[i] || i == 0) {
           // printf("len :%d\n", i + 1);
            printf("%d", a[i--]);
            while(i >= 0) {
                printf("%03d", a[i]);
                i--;
            }
        }
    }
    putchar('\n');
}


int main() {
    memset(num, 0, sizeof(num));
    scanf("%d%d%d", &t1, &t2, &n);
    num[1].push_back(t1);
    num[2].push_back(t2);
    for(int i = 3; i <= n; i++) {
        fast_mul(num[i], num[i - 1], num[i - 1]);
        add(num[i], num[i - 2]);
        //printf("%d\n", i);
        //print(num[i]);
    }
    print(num[n]);
    return 0;
}
