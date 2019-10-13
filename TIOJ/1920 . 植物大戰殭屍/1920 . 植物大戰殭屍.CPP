#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
struct Node {
    Node *s[2];
    int idx;
    Node(int x) : idx(x) {
        memset(s, 0, sizeof(s));
    }
};

Node *Tree[maxn];
int A[maxn];
int n, q;

Node *build(int val, int digit, int idx) {
    if(digit < 0) return new Node(idx);
    Node *ret = new Node(idx);
    if(val & (1 << digit)) {
        ret->s[1] = build(val, digit - 1, idx);
    } else {
        ret->s[0] = build(val, digit - 1, idx);
    }
    return ret;
}

Node *modify(Node *x, int val, int digit, int idx) {
    if(digit < 0) return new Node(idx);
    Node *ret = new Node(idx);
    if(x) {
        if(val & (1 << digit)) {
            ret->s[0] = x->s[0];
            ret->s[1] = modify(x->s[1], val, digit - 1, idx);
        } else {
            ret->s[0] = modify(x->s[0], val, digit - 1, idx);
            ret->s[1] = x->s[1];
        }
    } else {
        if(val & (1 << digit)) {
            ret->s[1] = modify(NULL, val, digit - 1, idx);
        } else {
            ret->s[0] = modify(NULL, val, digit - 1, idx);
        }
    }
    return ret;
}

int query(int l, int r, int v) {
    int ans = v ^ A[r], tmp = 0;
    Node *ptr = Tree[l];
    for(int i = 29; i >= 0; i--) {
        if(ans & (1 << i)) {
            if(ptr->s[0] && ptr->s[0]->idx < r) {
                ptr = ptr->s[0];
            } else {
                ptr = ptr->s[1];
                ans ^= (1 << i);
                tmp ^= (1 << i);
            }
        } else {
            if(ptr->s[1] && ptr->s[1]->idx < r) {
                ptr = ptr->s[1];
                ans ^= (1 << i);
                tmp ^= (1 << i);
            } else {
                ptr = ptr->s[0];
            }
        }
    }
    //printf("YEE %d %d\n", tmp, v ^ A[r]);
    return ans;
}

int main() {
    scanf("%d%d", &n, &q); A[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", A + i);
        A[i] ^= A[i - 1];
    }
    Tree[n] = build(A[n], 29, n);
    for(int i = n - 1; i >= 0; i--) {
        Tree[i] = modify(Tree[i + 1], A[i], 29, i);
    }
    int l, r, v;
    while(q--) {
        scanf("%d%d%d", &l, &r, &v);
        printf("%d\n", query(l, r, v));
    }
    return 0;
}
