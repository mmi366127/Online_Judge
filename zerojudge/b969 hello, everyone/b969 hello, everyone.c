#include <stdio.h>
#include <string.h>

char data[100][100], greet[100], c;
int tot;

int main() {
    while(1) {
        scanf("%s%c", data[tot], &c);
        tot++;
        if(c != ' ') break;
    }
    fgets(greet, sizeof(greet), stdin);
    for(int i = 0; greet[i]; i++) {
        if(greet[i] == '\n') greet[i] = '\0';
    }
    for(int i = 0; i < tot; i++) {
        printf("%s, %s\n", greet, data[i]);
    }
    return 0;
}
