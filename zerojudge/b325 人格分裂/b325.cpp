#include <bits/stdc++.h>
#define maxn 40000
using namespace std;

const double eps = 1e-12;

struct Pt {
    double x, y;
    Pt(double X = 0, double Y = 0) : x(X), y(Y) {}
    Pt operator + (const Pt &a) const {
        return Pt(a.x + x, a.y + y);
    }
    Pt operator - (const Pt &a) const {
        return Pt(x - a.x, y - a.y);
    }
    double operator ^ (const Pt &a) const {
        return x * a.x + y * a.y;
    }
    double operator | (const Pt &a) const {
        return x * a.y - y * a.x;
    }
    Pt operator * (const double &a) const {
        return Pt(x * a, y * a);
    }
};
struct SG {
    int id;
    Pt s, e;
    SG(Pt S, Pt E, int i) :
    s(S), e(E), id(i) {}
    SG(){}
};

Pt S, E;

int zero(const double &x) {
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

bool cmp(const Pt &a, const Pt &b) {
    if (a.y == 0 && b.y == 0 && a.x * b.x <= 0) return a.x > b.x;
    if (a.y == 0 && a.x >= 0 && b.y != 0) return true;
    if (b.y == 0 && b.x >= 0 && a.y != 0) return false;
    if (a.y * b.y < 0) return a.y > b.y;
    double c = a | b;
    return c > 0 || (c == 0 && fabs(a.x) < fabs(b.x));
}

bool cmp2(const pair<Pt, int> &a, const pair<Pt, int> &b) {
    return cmp(a.first, b.first);
}

bool hit(const Pt &as, const Pt &ae, const Pt &bs, const Pt &be) {
    if(zero((ae - as) | (bs - as)) * zero((ae - as) | (be - as)) < 0) {
        return zero((as - bs) | (as + ae - bs)) * zero((as - bs) | (be - as)) >= 0 && zero((as - be) | (as + ae - be)) * zero((as - be) | (bs - be)) >= 0;
    }
    return false;
}

Pt shoot(const Pt &as, const Pt &ae, const Pt &bs, const Pt &be) {
    Pt tmp = as - bs;
    double t = ((be - bs) | tmp)/((ae - as) | (be - bs));
    return as + ((ae - as) * t);
}



double dis2(Pt a, Pt b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}


struct CMP {
    bool operator()(const SG &a, const SG &b) {
        Pt Pa = shoot(S, E, a.s, a.e);
        Pt Pb = shoot(S, E, b.s, b.e);
        return zero(dis2(S, Pa) - dis2(S, Pb)) < 0;
    }
};


set<SG, CMP> st;
vector<pair<Pt, int>> V;
char ans[maxn];
SG SGs[maxn];
Pt s, e;
int n;

int main() {
    while(~scanf("%d", &n)) {
        memset(ans, 0, sizeof(ans));
        st.clear(); V.clear();
        for(int i = 1; i <= n; i++) {
            scanf("%lf%lf%lf%lf", &s.x, &s.y, &e.x, &e.y);
            V.push_back({s, i});
            V.push_back({e, -i});
            SGs[i] = SG(s, e, i);
        }
        sort(V.begin(), V.end(), cmp2);
        S = Pt(0, 0); E = V[0].first;
        for(int i = 1; i <= n; i++) {
            if(hit(S, E, SGs[i].s, SGs[i].e))
                st.insert(SGs[i]);
        }
        for(int i = 0; i < V.size();) {
            E = V[i].first;
            while(i < V.size() && zero((E - S) | (V[i].first - S)) == 0) {
                int flag, id = V[i].second;
                if(id > 0)
                    flag = zero((SGs[id].s - S) | (SGs[id].e - S));
                else
                    flag = -zero((SGs[-id].s - S) | (SGs[-id].e - S));
                if(flag) {
                    if(flag > 0)
                        st.insert(SGs[abs(id)]);
                    else
                        st.erase(SGs[abs(id)]);
                }
                i++;
            }
            if(st.size()) {
                ans[st.begin()->id] = 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}
