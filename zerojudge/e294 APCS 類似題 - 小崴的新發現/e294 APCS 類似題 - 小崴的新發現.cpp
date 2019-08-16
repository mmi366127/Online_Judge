#include <stdio.h>
#include <string.h>
#define min(a, b) (a) < (b) ? (a) : (b)
typedef long long loli;

loli to_num(char s[]) {
    loli ret = 0;
    for(int i = 0; s[i]; i++) {
        ret = (ret * 10) + (s[i] ^ '0');
    }
    return ret;
}

loli lower(char s[]) {
    int i; char t[20];
    strcpy(t, s);
    for(i = 0; t[i]; i++) {
        if(!((t[i] - '0') & 1)) {
            if(t[i] == '0') {
                t[i] = '9';
                for(int j = i - 1; j >= 0; j--) {
                    if(t[j] == '1') {
                        if(j == 0) t[j] = '0';
                        else t[j] = '9';
                    } else {
                        t[j] -= 2;
                        break;
                    }
                }
                for(i++; t[i]; i++) {
                    t[i] = '9';
                }
            } else {
                t[i]--;
                for(i++; t[i]; i++) t[i] = '9';
            }
            break;
        }
    }
    for(i = 0; ; i++) {
        if(t[i] != '0') break;
    }
    return to_num(t + i);
}

loli higher(char s[]) {
    int i = 0; char t[20];
    strcpy(t + 1, s);
    t[0] = '0';
    for(int i = 1; t[i]; i++) {
        if(!((t[i] - '0') & 1)) {
            t[i]++;
            for(i++; t[i]; i++) t[i] = '1';
            break;
        }
    }
    for(i = 0; ; i++) {
        if(t[i] != '0') break;
    }
    return to_num(t + i);
}

char s[20];

int main() {
    while(~scanf("%s", s)) {
        loli l = lower(s);
        loli r = higher(s);
        loli m = to_num(s);
        printf("%lld\n", min((m - l), (r - m)));
    }
    return 0;
}
