#include <stdio.h>
#include <string.h>

int a, b, n, z;
char s[107];

int main() {
    while(~scanf("%s", s)) {
        n = strlen(s);
        z = a = b = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                z++;
                if(s[(i + 1) % n] == '0')
                    a++;
                else
                    b++;
            }
        }
        if(z * z == a * n) puts("EQUAL");
        else if(z * z < a * n) puts("SHOOT");
        else puts("ROTATE");
    }
    return 0;
}
