#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


char *s[] = {"0", "1 1", "1 2", "2 1", "2 2", "3 1 2", "3 2 1"};
vector<int> ans;
int x, y, k;

/*
1 1 --->   1
1 2 --->   2
2 1 --->   3
2 2 --->   4
3 1 2 ---> 5
3 2 1 ---> 6
*/

int main() {
    scanf("%d%d%d", &x, &y, &k);
    if(k == 0 || k > max(x, y) || k % __gcd(x, y) != 0) {
        printf("0\n");
        return 0;
    }
    if(x < y) {
        swap(x, y);
        swap(s[1], s[2]);
        swap(s[3], s[4]);
        swap(s[5], s[6]);
    }


    int a = 0, b = 0;
    while(1) {
        if(a == 0) {
            a = x;
            ans.push_back(1);
        }
        else {
            if(a > y - b) {
                a = a + b - y;
                b = y;
                ans.push_back(5);
                if(a == k)
                    break;
                ans.push_back(4);
                b = 0;
            } else {
                b += a;
                a = 0;
                ans.push_back(5);
                if(b == k)
                    break;
            }
        }
    }
    ans.push_back(0);
    for(auto t : ans)
        puts(s[t]);

    return 0;
}

