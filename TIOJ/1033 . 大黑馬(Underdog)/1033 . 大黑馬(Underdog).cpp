#include <bits/stdc++.h>
using namespace std;
struct Player {
    int low, mid, hi;
};

vector< vector<Player> > V;
int n, k;

struct Match {
    #define maxn 15
    char G[maxn][maxn], vx[maxn], vy[maxn];
    int mx[maxn], my[maxn];
    int n;
    void init(int _) {
        n = _;
        memset(G, 0, sizeof(G));
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
    }
    bool dfs(int x) {
        if(vx[x]) return false;
        vx[x] = 1;
        for(int y = 0; y < n; y++) {
            if(G[x][y] == 0 || vy[y] == 1) continue;
            vy[y] = 1;
            if(my[y] == -1 || dfs(my[y])) {
                mx[x] = y;
                my[y] = x;
                return true;
            }
        }
        return false;
    }
    int match() {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if(dfs(i)) ans++;
        }
        return ans;
    }
    void add(int x, int y) {
        G[x][y] = 1;
    }
}M;

int solve_A() {
    for(int i = n - 1; i >= 0; i--) {
        bool flag = true;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            M.init(2 * k + 1);
            for(int _ = 0; _ < 2 * k + 1; _++) {
                for(int __ = 0; __ < 2 * k + 1; __++) {
                    if(j < i && V[i][_].mid > V[j][__].mid) {
                        M.add(_, __);
                    }
                    else if(j > i && V[i][_].mid >= V[j][__].mid) {
                        M.add(_, __);
                    }
                }
            }
            if(M.match() <= k) {
                flag = false;
                break;
            }
        }
        if(flag) return  i + 1;
    }
    return 0;
}

int solve_B() {
     for(int i = n - 1; i >= 0; i--) {
        bool flag = true;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            M.init(2 * k + 1);
            for(int _ = 0; _ < 2 * k + 1; _++) {
                for(int __ = 0; __ < 2 * k + 1; __++) {
                    if(j < i && V[i][_].hi > V[j][__].low) {
                        M.add(_, __);
                    }
                    else if(j > i && V[i][_].hi >= V[j][__].low) {
                        M.add(_, __);
                    }
                }
            }
            if(M.match() <= k) {
                flag = false;
                break;
            }
        }
        if(flag) return  i + 1;
    }
    return 0;
}

int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n; V.resize(n);
    for(int i = 0; i < n; i++) {
        int S; cin >> S;
        V[S - 1].resize(2 * k + 1);
        for(int j = 0; j < 2 * k + 1; j++)
            cin >> V[S - 1][j].mid;
        for(int j = 0; j < 2 * k + 1; j++)
            cin >> V[S - 1][j].hi;
        for(int j = 0; j < 2 * k + 1; j++)
            cin >> V[S - 1][j].low;
    }
    cout << solve_A() << ' ' << solve_B() << '\n';
    return 0;
}
