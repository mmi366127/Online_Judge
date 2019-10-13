#include<cstdio>
#include<algorithm>
using namespace std;
struct Node {
    Node *l, *r;
    int val, pri, sz;
    Node(int v) : sz(1), val(v), l(NULL), r(NULL), pri(rand()){}
    void pull() {
        sz = 1;
        sz += l ? l->sz : 0;
        sz += r ? r->sz : 0;
    }

};


int size(Node *x) {
    return x ? x->sz : 0;
}

Node *merge(Node *a,Node *b) {
    if(!a) return b;
    if(!b) return a;
    if(a->pri > b->pri) {
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

pair<Node*,Node*> splt(Node *s,int k) {
    if(!s) return {NULL,NULL};
    pair<Node*,Node*> ret;
    if(size(s->l) >= k) {
        ret = splt(s->l, k);
        s->l = ret.second;
        s->pull();
        ret.second = s;
        return ret;
    } else {
        ret = splt(s->r, k-size(s->l)-1);
        s->r = ret.first;
        s->pull();
        ret.first = s;
        return ret;
    }
}

void out(Node *x) {
    if(!x) return;
    out(x->l);
    printf("%d ",x->val);
    out(x->r);
}


int main() {
    //
    Node *root = NULL;
    for(int i=0;i<10;i++) {
        root = merge(root,new Node(i));
    }
    out(root); puts("");
    pair<Node*,Node*> tmp = splt(root,5);
    out(tmp.first); puts("");
    out(tmp.second); puts("");
    return 0;
}
