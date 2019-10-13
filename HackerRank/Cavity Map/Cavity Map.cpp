#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int mx[] = {0,  0, 1, -1, -1, -1, 1, 1};
int my[] = {1, -1, 0,  0, -1,  1,-1, 1};

char M[maxn][maxn];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n ; i++) {
        scanf("%s", M[i]);
    }
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - 1; j++) {
            bool flag = true;
            for(int k = 0; k < 4; k++) {
                if(M[i + mx[k]][j + my[k]] >= M[i][j]) flag = false;
            }
            if(flag) M[i][j] = 'X';
        }
    }
    for(int i = 0; i < n; i++) {
        puts(M[i]);
    }
    return 0;
}



