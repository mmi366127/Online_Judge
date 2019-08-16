#include <stdio.h>
#include <string.h>

int ram[8], reg[4];
int n, a, b, c;
char s[10];

int main() {
    for(int i = 0; i < 8; i++) scanf("%d", ram + i);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        switch(s[0]) {
            case 'L':
                scanf("%d%d", &a, &b);
                reg[a] = ram[b];
                break;
            case 'S':
                scanf("%d%d", &a, &b);
                ram[a] = reg[b];
                break;
            case 'A':
                scanf("%d%d%d", &a, &b, &c);
                reg[a] = reg[b] + reg[c];
                break;
            case 'M':
                scanf("%d%d", &a, &b);
                reg[a] = reg[b];
                break;
        }
    }
    printf("%d\n%d\n", reg[0], ram[0]);
    return 0;
}
