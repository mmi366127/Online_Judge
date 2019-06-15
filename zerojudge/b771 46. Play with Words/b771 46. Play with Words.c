#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    struct Node *l, *r;
    int pri, sz;
    char val;
}Node;
typedef struct loli {
    Node *a, *b;
}loli;

int to_num(char *s) {
    int i = 0, ret = 0;
    while(s[i] < '0') i++;
    while(s[i] >= '0')
        ret = (ret<<3) + (ret<<1) + (s[i] - '0'), i++;
    return ret;
}

Node *new_Node(char c) {
    Node* ret =  malloc(sizeof(Node));
    ret->l = ret->r = NULL;
    ret->pri = rand();
    ret->val = c;
    ret->sz = 1;
    return ret;
}

int size(Node *x) {
    return x ? x->sz : 0;
}

void pull(Node *x) {
    x->sz = 1 + size(x->l) + size(x->r);
}

Node *merge(Node *a, Node *b) {
    if(!a) return b;
    if(!b) return a;
    if(a->pri > b->pri) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

loli split(Node *s, int k) {
    loli ret;
    ret.a = ret.b = NULL;
    if(!s) return ret;
    if(size(s->l) >= k) {
        ret = split(s->l, k);
        s->l = ret.b;
        pull(s);
        ret.b = s;
    } else {
        ret = split(s->r, k - size(s->l) - 1);
        s->r = ret.a;
        pull(s);
        ret.a = s;
    }
    return ret;
}

int tot = 0;
char s[1000007];

void out(Node *x) {
    if(!x) return;
    out(x->l);
    s[tot++] = x->val;
    out(x->r);
}

void _free(Node *x) {
    if(!x) return;
    free(x);
}

void solve() {
    int i, cnt, mx = 0;
    for(i = 0; s[i]; i++) {
        cnt = 1;
        while(s[i] && s[i] == s[i+1]) i++, cnt++;
        if(cnt > mx) mx = cnt;
    }
    for(i = 0; s[i]; i++) {
        cnt = 1;
        while(s[i] && s[i] == s[i+1]) i++, cnt++;
        if(cnt == mx) {
            printf("%c ", s[i]);
        }
    }
    printf("%d\n", mx);
}



int main() {
    srand(0x94878787);
    int k; loli temp;
    Node *tmp, *root = NULL;
    while(~scanf("%s", s)) {
        if(s[0] == 'i') {
            scanf("%s", s);
            if(s[0] == 'l') {
                scanf("%s", s);
                tmp = new_Node(s[0]);
                root = merge(tmp, root);
            } else if(s[0] == 'r') {
                scanf("%s", s);
                tmp = new_Node(s[0]);
                root = merge(root, tmp);
            } else {
                k = to_num(s);
                scanf("%s", s);
                tmp = new_Node(s[0]);
                temp = split(root, k-1);
                root = merge(temp.a, tmp);
                root = merge(root, temp.b);
            }
        } else {
            scanf("%s", s);
            if(s[0] == 'l') {
                temp = split(root, 1);
                _free(temp.a);
                root = temp.b;
            } else if(s[0] == 'r') {
                temp = split(root, size(root)-1);
                _free(temp.b);
                root = temp.a;
            } else {
                k = to_num(s);
                temp = split(root, k-1);
                loli tt = split(temp.b, 1);
                _free(tt.a);
                root =  merge(temp.a, tt.b);
            }
        }
    }
    tot = 0;
    out(root);
    s[tot++] = '\0';
    solve();
    return 0;
}
