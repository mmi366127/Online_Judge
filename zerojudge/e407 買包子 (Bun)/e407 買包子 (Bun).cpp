#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define maxn 300005
using namespace std;
typedef long long loli;
struct Treap {
    struct Node {
        Node *l, *r;
        int pri, sz; loli val;
        Node(loli v) :
        l(NULL), r(NULL), val(v), pri(rand()), sz(1){}
    };
    Node *root = NULL;
    int Node_size(Node *x) {
        return x ? x -> sz : 0;
    }
    void pull(Node *x) {
        x -> sz = Node_size(x -> l) + Node_size(x -> r) + 1;
    }
    Node *merge(Node *a, Node *b) {
        if(!a) return b;
        if(!b) return a;
        if(a -> pri > b -> pri) {
            a -> r = merge(a -> r, b);
            pull(a);
            return a;
        } else {
            b -> l = merge(a, b -> l);
            pull(b);
            return b;
        }
    }
    pair<Node*, Node*> split(Node *s, loli val) {
        if(!s) return {NULL, NULL};
        pair<Node*, Node*> ret;
        if(s -> val <= val) {
            ret = split(s -> r, val);
            s -> r = ret.first;
            pull(s);
            ret.first = s;
        } else {
            ret = split(s -> l, val);
            s -> l = ret.second;
            pull(s);
            ret.second = s;
        }
        return ret;
    }
    int query(loli x) {
        static pair<Node*, Node*> tmp;
        static int ret;
        tmp = split(root, x);
        ret = Node_size(tmp.first);
        root = merge(tmp.first, tmp.second);
        return ret;
    }
    void insert(loli x) {
        static Node* tmp;
        static pair<Node*, Node*> two;
        tmp = new Node(x);
        two = split(root, x);
        root = merge(two.first, tmp);
        root = merge(root, two.second);
    }
    void erase(loli x) {
        static Node* tmp;
        static pair<Node*, Node*> a, b;
        a = split(root, x);
        b = split(a.first, x - 1);
        tmp = b.second;
        if(!tmp) return;
        b.second = merge(tmp -> l, tmp -> r);
        delete tmp;
        root = merge(b.first, b.second);
        root = merge(root, a.second);
    }
    int size() {
        return Node_size(root);
    }
    void dfs(Node *x) {
        if(!x) return;
        dfs(x -> l);
        printf("%lld ", x -> val);
        dfs(x -> r);
    }
    void print() {
        dfs(root);
        putchar('\n');
    }
};



loli k ,acc = 0;
queue<loli> Q;
int n, op;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Treap T;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> op >> k;
        if(op == 1) {
            Q.push(k + acc);
            T.insert(k + acc);
        } else {
            acc += k;
            while(Q.size() && Q.front() <= acc) {
                T.erase(Q.front());
                Q.pop();
            }
            cout << T.query(acc) << '\n';
        }
    }
    return 0;
}
