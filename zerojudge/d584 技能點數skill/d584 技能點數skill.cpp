#include <stdio.h>

int a, lv;

int main() {
    while(~scanf("%d%d", &a, &lv)) {
        int ans = 0;
        if(a == 2) {

            if(lv >= 8)
                ans++;
            if(lv >= 30)
                ans++;
            if(lv >= 70)
                ans++;
            if(lv >= 120)
                ans += 3;

            ans += (lv - 8) * 3;

        } else {

            if(lv >= 10)
                ans++;
            if(lv >= 30)
                ans++;
            if(lv >= 70)
                ans++;
            if(lv >= 120)
                ans += 3;

            ans += (lv - 10) * 3;

        }
        printf("%d\n", a == 0 ? a : ans);
    }
    return 0;
}

