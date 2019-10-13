#include <bits/stdc++.h>
using namespace std;
struct INT {
    #define digit 10000
    vector<long long> arr;
    INT(int v) {
        arr.push_back(v % digit);
        if(v >= digit) {
            arr.push_back(v / digit);
        }
    }
    INT(){}
    INT operator*(const INT &a) const {
        INT ret;
        ret.arr.resize(arr.size() + a.arr.size() - 1);
        fill(ret.arr.begin(), ret.arr.end(), 0);
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < a.arr.size(); j++) {
                ret.arr[i + j] += arr[i] * a.arr[j];
            }
        }
        for(int i = 0; i < ret.arr.size() - 1; i++) {
            if(ret.arr[i] >= digit) {
                ret.arr[i + 1] += ret.arr[i] / digit;
                ret.arr[i] %= digit;
            }
        }
        if(*ret.arr.rbegin() >= digit) {
            ret.arr.push_back(*ret.arr.rbegin() / digit);
            ret.arr[ret.arr.size() - 2] %= digit;
        }
        return ret;
    }
    void output() {
        while(*arr.rbegin() == 0) arr.pop_back();
        printf("%d", arr[arr.size() - 1]);
        for(int i = arr.size() - 2; i >= 0; i--) {
            printf("%04d", arr[i]);
        }
        putchar('\n');
    }
};

INT power(INT a, int n) {
    if(n == 0) {
        return INT(1);
    }
    if(n == 1)
        return a;
    INT ret = power(a, n / 2);
    ret = ret * ret;
    if(n & 1)
        ret = ret * a;
    return ret;
}

int n, m;

int main() {
    while(~scanf("%d%d", &n, &m) && ()) {
        power(INT(n), m).output();
    }
}
