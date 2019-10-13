#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define int long long

bool is_leap(int x) {
    if(x % 400 == 0) return true;
    if(x % 100 == 0) return false;
    if(x % 4 == 0) return true;
    return false;
}

bool is_prime(int x) {
    if(x == 1) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int to_num(char s[]) {
    int ret = 0;
    for(int i = 0; s[i]; i++) {
        ret = (ret * 10) + (s[i] ^ '0');
    }
    return ret;
}

bool check(char s[]) {
    int len = strlen(s);
    for(int i = 0; i < len; i++)
        if(!is_prime(to_num(s + i))) return false;
    return true;
}

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char s[50];

signed main() {
    for(int Y = 2000000; Y < 3000000; Y++) {
        if(is_leap(Y)) month[2]++;
        for(int M = 1; M <= 12; M++) {
            for(int D = 1; D <= month[M]; D++) {
                sprintf(s, "%d%02d%02d", Y, M, D);
                if(check(s)) {
                    printf("%d/%02d/%02d\n", Y, M, D);
                }
            }
        }
        if(is_leap(Y)) month[2]--;
    }
    return 0;
}
