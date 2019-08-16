#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    struct Node *next, *prev;
    char str[1000];
};

#define getchar_unlocked getchar
#define putchar_unlocked putchar

struct Node *tmp, *head, *rear;
char s[1000];
char c, pre;
int idx;

int valid(char c) {
    if('a' <= c && c <= 'z') return 1;
    if('A' <= c && c <= 'Z') return 1;
    return 0;
}


int main() {
    pre = 0; rear = head = NULL;
    while((c = getchar_unlocked()) != '0') {
        if(!valid(c)) {
            if(valid(pre)) {
                s[idx++] = '\0';
                tmp = head;
                int cnt = 1;
                while(tmp) {
                    if(strcmp(tmp->str, s) == 0) {
                        printf("%d", cnt);
                        if(tmp != head) {
                            if(tmp == rear) {
                                rear = rear->prev;
                            }
                            tmp->prev->next = tmp->next;
                            if(tmp->next) tmp->next->prev = tmp->prev;
                            tmp->next = head;
                            head->prev = tmp;
                            tmp->prev = NULL;
                            head = tmp;
                        }
                        break;
                    }
                    cnt++;
                    tmp = tmp->next;
                }
                if(!tmp) {
                    printf("%s", s);
                    tmp = malloc(sizeof(Node));
                    strcpy(tmp->str, s);
                    if(!head) {
                        head = rear = tmp;
                        tmp->next = tmp->prev = NULL;
                    } else {
                        tmp->next = head;
                        head->prev = tmp;
                        head = tmp;
                    }
                }
                idx = 0;
            }
            putchar_unlocked(c);
        } else {
            s[idx++] = c;
        }
        pre = c;
    }
    return 0;
}
