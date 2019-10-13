#include "lib1044.h"


int main() {
    int L = 0, R = Initialize() + 1;
    while(R - L > 1) {
        int mid = (L + R) >> 1;
        if(Guess(mid))
            R = mid;
        else
            L = mid;
    }
    Report(R);
    return 0;
}
