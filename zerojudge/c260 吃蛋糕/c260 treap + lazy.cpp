#include <cstdio>
#include <stdlib.h>
#include <utility>
#include <time.h>
#define maxn 100007
using namespace std;
typedef long long int loli;
struct Node {
    int sz, pri;
    loli val, tag;
    Node *l, *r;
    void pull() {
        sz = 1;
        if(l) sz += l->sz;
        if(r) sz += r->sz;
    }
    void push() {
        if(tag) {
            val += tag;
            if(l) l->tag += tag;
            if(r) r->tag += tag;
            tag = 0;
        }
    }
    Node(int v) {
        pri = rand();
        l = r = NULL;
        val = v;
        tag = 0;
        sz = 1;
    }
};


Node *merge(Node *a, Node *b) {
    if(!a) return b;
    if(!b) return a;
    if(a->pri > b->pri) {
        a->push();
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->push();
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

pair<Node*, Node*> split(Node *s, int k) {
    if(!s) return {NULL, NULL};
    pair<Node*, Node*> ret;
    s->push();
    if(s->val > k) {
        ret = split(s->l, k);
        s->l = ret.second;
        ret.second = s;
        ret.second->pull();
    } else {
        ret = split(s->r, k);
        s->r = ret.first;
        ret.first = s;
        ret.first->pull();
    }
    return ret;
}

Node *insert(Node *s, Node *x) {
    if(!x) return s;
    auto tmp = split(s, x->val);
    s = merge(tmp.first, x);
    s = merge(s, tmp.second);
    return s;
}

void out(Node *x) {
    if(!x) return;
    out(x->l);
    printf("%lld ", x->val);
    out(x->r);
}

loli upper[maxn], lower[maxn];
loli n, tmp, a, b, sum;

int main() {
    srand(time(NULL));
    scanf("%lld%lld%lld", &n, &a, &b);
    for(int i = 1; i <= n;  i++) {
        scanf("%lld", &tmp);
        lower[i] = tmp - a;
        upper[i] = b - tmp;
    }
    sum = 0;
    Node *root = NULL;
    for(int i = 1; i <= n; i++) {
        if(root) root->tag += lower[i];
        root = insert(root, new Node(lower[i]));
        auto temp = split(root, -1);
        sum += temp.second ? temp.second->sz : 0;
        root = merge(temp.first, temp.second);
    }
    root = NULL;
    for(int i = 1; i <= n; i++) {
        if(root) root->tag += upper[i];
        root = insert(root, new Node(upper[i]));
        auto temp = split(root, -1);
        sum += temp.second ? temp.second->sz : 0;
        root = merge(temp.first, temp.second);
    }
    printf("%lld\n", sum - (n*(n+1)/2));
    return 0;
}
