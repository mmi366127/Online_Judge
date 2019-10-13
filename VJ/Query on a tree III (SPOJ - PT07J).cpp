#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define maxn 100005
using namespace std;
struct Node {
    int l, r, sum;
    Node() : l(0), r(0), sum(0) {}
};

Node ram[maxn * 20];
int tot = 0;


void modify(int l, int r, int pre, int &cur, int pos) { // a new tree ~~~
    cur = ++tot; ram[cur] = ram[pre]; ram[cur].sum++;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(pos <= mid)
        modify(l, mid, ram[pre].l, ram[cur].l, pos);
    else
        modify(mid + 1, r, ram[pre].r, ram[cur].r, pos);
}

int query(int l, int r, int a, int b, int k) {
    if(l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    int sum = ram[ram[b].l].sum - ram[ram[a].l].sum;
    if(sum >= k)
        return query(l, mid, ram[a].l, ram[b].l, k);
    else
        return query(mid + 1, r, ram[a].r, ram[b].r, k - sum);
}


int idx[2][maxn], Tree[maxn + maxn], label[maxn];
int n, m, u, v, ttt = 0;
vector<int> G[maxn];
vector<int> V;
map<int, int> rev;

int get_id(int x) {
    return (lower_bound(all(V), x) - V.begin()) + 1;
}

void dfs(int x, int p) {
    idx[0][x] = ++ttt;
    Tree[ttt] = Tree[ttt - 1];
    for(int y : G[x]) {
        if(y == p) continue;
        dfs(y, x);
    }
    idx[1][x] = ++ttt;
    modify(1, n, Tree[ttt - 1], Tree[ttt], get_id(label[x]));
}


int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", label + i);
        V.push_back(label[i]);
        rev[label[i]] = i;
    }
    sort(all(V));
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    Tree[0] = 0;
    dfs(1, -1);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        printf("%d\n", rev[V[query(1, n, Tree[idx[0][u]], Tree[idx[1][u]], v) - 1]]);
    }
    return 0;
}
