#include <bits/stdc++.h>
#define maxn 3005
using namespace std;


char A[maxn][maxn], B[maxn][maxn], C[maxn][maxn];
int n;

bool get_val(int x, int y) {
    bool ret = false;
    for(int i = 0; i < n; i++) {
        ret ^= A[i][y] & B[x][i];
    }
    return ret;
}

bool Try() {
    for(int i = 0; i < 10000; i++) {
        int x = rand() % n;
        int y = rand() % n;
        if(get_val(x, y) != C[x][y])
            return false;
    }
    return true;
}


int main() {
    srand(time(NULL));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[j][i]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &B[j][i]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &C[j][i]);
        }
    }
    puts(Try() ? "YES" : "NO");
    return 0;
}
