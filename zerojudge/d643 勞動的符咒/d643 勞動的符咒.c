#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 100005


char *V[100], *arr[100005], *tmp[100005];
char s[100005];
int len, n, tot = 0;

int cmp(char *a, char *b) {
    for(int i = 0; i < len; i++) {
        if(*(a + i) != *(b + i))
            return *(a + i) < *(b + i);
    }
    return 0;
}

int equal(char *a, char *b) {
    for(int i = 0; i < len; i++)
        if(*(a + i) != *(b + i))
            return 0;
    return 1;
}

void sort(int l, int r) {
    if(r - l <= 1) return;
    int m = (l + r) >> 1;
    sort(l, m), sort(m, r);
    int i, j, idx = l;
    for(i = l, j = m; i < m; i++) {
        while(j < r && cmp(arr[j], arr[i])) {
            tmp[idx++] = arr[j++];
        }
        tmp[idx++] = arr[i];
    }
    while(j < r) tmp[idx++] = arr[j++];
    for(idx = l; idx < r; idx++)
        arr[idx] = tmp[idx];
}

void add(int x) {
    len = n / x; int cnt = 0;
    for(int i = 0; i < n; i += len) {
        arr[cnt++] = s + i;
    }
    sort(0, cnt);
    V[tot] = malloc(sizeof(char) * (n));
    for(int i = 0; i < cnt; i ++) {
        for(int j = 0; j < len; j++) {
            V[tot][i * len + j] = *(arr[i] + j);
        }
    }
    V[tot][n] = '\0';
    tot++;
}

int main() {
    scanf("%s", s); n = strlen(s);
    for(int i = n; i >= 1; i--) {
        if(n % i == 0) {
            add(i);
        }
    }
    int flag = 0;
    for(int i = 0; i < tot; i++) {
        if(!equal(V[i], s))
            puts(V[i]), flag = 1;
    }
    if(flag) return 0;
    puts("bomb!");
    return 0;
}
