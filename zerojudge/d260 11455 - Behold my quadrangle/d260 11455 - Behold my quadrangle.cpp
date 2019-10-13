#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int arr[4];
int t;

int main() {
    scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 4; i++)
            scanf("%d", arr + i);
        sort(arr, arr + 4);
        if(arr[0] == arr[3])
            puts("square");
        else if(arr[0] == arr[1] && arr[2] == arr[3] && arr[1] != arr[2])
            puts("rectangle");
        else if(arr[3] < arr[0] + arr[1] + arr[2])
            puts("quadrangle");
        else
            puts("banana");
    }
    return 0;
}
