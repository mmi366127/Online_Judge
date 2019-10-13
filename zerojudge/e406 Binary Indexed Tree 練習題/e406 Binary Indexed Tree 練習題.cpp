#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

#define maxn 1000005
#define maxQ 100005

int A[maxn], X[maxQ], Y[maxQ];
int bit[maxn] = {};
char C[maxQ];
int k,m,n,Q;


void ADD(int *a, int *b) {
    *a = *a + *b;
    if(*a >= m) {
        *a -= m;
    }
}

void add(int x, int v) {
    for(; x < maxn; x += x &(-x)) {
        ADD(bit + x, &v);
    }
}

int query(int x) {
    static int ret;
    for(ret = 0; x; x -= x & (-x)) {
        ADD(&ret, bit + x);
    }
    return ret;
}



void gen_dat() {
   int i,j;
   for(i = k + 1; i <= max(Q, n); i++)
        A[i] = (A[i - 2] * 97 + A[i - 1] * 3) % m + 1;
   for(i = 1, j = max(Q, n); i <= Q; i++, j--) {
        C[i] = A[i] & 1;
        X[i] = (A[i] + A[j]) % n + 1;
        if(C[i]) Y[i] = X[i] + ((A[i] << 3) + (A[j] << 5) + m) % (n - X[i] + 1);
        else Y[i] = ((A[i] << 3) + (A[j] << 5)) % m + 1;
   }
}



int main() {
    scanf("%d%d", &k, &m);
    for(int i = 1; i <= k; i++) {
        scanf("%d", A + i);
    }
    scanf("%d%d", &n, &Q);
    gen_dat();
    for(int i = 1; i <= n; i++) {
        add(i, A[i]);
    }
    for(int i = 1; i <= Q; i++) {
        if(C[i]) {
            printf("%d\n", (query(Y[i]) - query(X[i] - 1) + 1000 * m) % m);
        } else {
            add(X[i], Y[i] - A[X[i]]);
            A[X[i]] = Y[i];
        }
    }
    return 0;
}
