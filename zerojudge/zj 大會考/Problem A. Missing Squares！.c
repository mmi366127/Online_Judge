#include <stdio.h>

int x1, y1;
int x2, y2;
int x3, y3;
int x4, y4;


int main() {
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    scanf("%d%d", &x3, &y3);
    scanf("%d%d", &x4, &y4);
    if(y1 == y2 && x2 == x3 && y3 == y4 && x4 == x1 && y1 - y4 == x2 - x1 && x2 - x1 == y2 - y3 && y2 - y3 == x3 - x4)
        puts("Square!");
    else
        puts("No!");
    return 0;
}
