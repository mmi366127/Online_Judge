#include <bits/stdc++.h>
using namespace std;

int arr[10];

bool check() {
    int a, b, c;
    // FORTYENSIX
    // 0123456789
    a = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4];
    c = arr[7] * 10000 + arr[8] * 1000 + arr[9] * 100 + arr[3] * 10 + arr[4];
    b = arr[3] * 100 + arr[5] * 10 + arr[6];
    return a + 2 * b == c;
}

int main() {
    for(int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    do {
        if(check()) {
            printf("%d%d%d%d%d + %d%d%d + %d%d%d = %d%d%d%d%d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[3], arr[5], arr[6], arr[3], arr[5], arr[6], arr[7], arr[8], arr[9], arr[3], arr[4]);
            //break;
        }
    } while(next_permutation(arr, arr + 10));
    return 0;
}
