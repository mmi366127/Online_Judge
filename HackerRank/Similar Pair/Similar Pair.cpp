#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long loli;
struct Node {
    Node *l, *r;
    int val, pri, sz;
    Node(int v) :
        sz(1), val(v), pri(rand()), l(NULL), r(NULL) {}
};

int size(Node *x) {
    return x ? x->sz : 0;
}

void pull(Node *x) {
    if(!x) return;
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

pair<Node*, Node*> split(Node *s, int val) {
    if(!s) return {NULL, NULL};
    pair<Node*, Node*> ret;
    if(s->val <= val) {
        ret = split(s->r, val);
        s->r = ret.first;
        ret.first = s;
        pull(ret.first);
    } else {
        ret = split(s->l, val);
        s->l = ret.second;
        ret.second = s;
        pull(ret.second);
    }
    return ret;
}

void prt(Node *x) {
    if(!x) return;
    prt(x->l);
    printf("%d ", x->val);
    prt(x->r);
}

int query(Node *x, int l, int r) {
    static pair<Node*, Node*> a, b;
    static int ret;
    a = split(x, l - 1);
    b = split(a.second, r);
    ret = size(b.first);
    x = merge(b.first, b.second);
    x = merge(a.first, x);
    return ret;
}

void insert(Node *&x, Node *v) {
    static pair<Node*, Node*> tmp;
    v->sz = 1; v->l = v->r = NULL;
    tmp = split(x, v->val);
    x = merge(tmp.first, v);
    x = merge(x, tmp.second);
}

void DFS_merge(Node *&x, Node *cur) {
    if(!cur) return;
    DFS_merge(x, cur->l);
    DFS_merge(x, cur->r);
    insert(x, cur);
}

Node* YEE(Node *a, Node *b) {
    if(size(a) > size(b)) {
        DFS_merge(a, b);
        return a;
    } else {
        DFS_merge(b, a);
        return b;
    }
}

vector<int> G[maxn];
int P[maxn] = {};
int n, k;
loli ans = 0;

Node* dfs(int x) {
    Node* ret = NULL;
    for(int t : G[x]) {
        ret = YEE(ret, dfs(t));
    }
    ans += query(ret, x - k, x + k);
    insert(ret, new Node(x));
    return ret;
}



int main() {
    srand(0x94879487);
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i++) {
        int p, c;
        scanf("%d%d", &p, &c);
        G[p].push_back(c);
        P[c] = p;
    }
    for(int i = 1; i <= n; i++) {
        if(!P[i]) {
            dfs(i);
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
