#include <stdio.h>

int x, y, a, n;

int exgcd(int a, int b) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

int main() {
    while(~scanf("%d%d", &a, &n)) {
        int tmp = exgcd(a, n);
        if(0 == tmp || tmp != 1 || (x % n + n)%n == 0) {
            puts("No Inverse");
            continue;
        }
        printf("%d\n", (x%n + n)%n);
    }
    return 0;
}

/*
x*a - y*n = 1
*/


/*
#include <iostream>
using namespace std;
#define int long long

int extgcd(int a, int b, int &x, int &y)
{
	if (b==0)  {
		x=1; y=0;
		return a;
	}
	else  {
		int d=extgcd(b, a%b, y, x);
		y-=(a/b)*x;
		return d;
	}
}

main()
{
	int a, b, x, y;
	while (cin >> a >> b)  {
		cout << extgcd(a, b, x, y) << endl;
	}
}
*/
