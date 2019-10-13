#include <bits/stdc++.h>
#define sq(x) ((x) * (x))
using namespace std;

long long arr[3], a, b;

int main() {
    for(int i = 0; i < 3; i++)
        scanf("%lld", arr + i);
    sort(arr, arr + 3);
    a = sq(arr[0]) + sq(arr[1]);
    b = sq(arr[2]);
    if(a > b) puts("acute triangle");
    else if(a == b) puts("right triangle");
    else puts("obtuse triangle");
    return 0;
}
