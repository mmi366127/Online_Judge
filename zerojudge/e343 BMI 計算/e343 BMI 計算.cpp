#include <stdio.h>

int w, h;

int main() {
    scanf("%d%d", &w, &h);
    printf("%.1f\n", (double)w / ((double)h / 100) / ((double)h / 100));
}
