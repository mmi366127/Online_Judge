#include <bits/stdc++.h>
const double eps = 1e-9;
using namespace std;
int zero(double x) {
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
struct Pt {
    double x, y;
    Pt(double X, double Y) : x(X), y(Y){}

    bool operator < (const Pt &a) const {
        return zero(x - a.x) ? zero(a.y - y) > 0 : zero(a.x - x) > 0;
    }
    double operator | (const Pt &a) const {
        return x * a.y - y * a.x;
    }
    Pt operator - (const Pt &a) const {
        return Pt(x - a.x, y - a.y);
    }
};

double tri(Pt a, Pt b, Pt c) {
    return 0.5 * fabs((a - b) | (c - b));
}

vector<Pt> P, Hull;


void convex(vector<Pt> &a, vector<Pt> &Hull) {
    static vector<Pt> stk;
    Hull.clear();
    stk.clear();
    for(int i = 0; i < a.size(); i++) {
        while(stk.size() > 1 && ((stk[stk.size()-1] - stk[stk.size()-2]) | (a[i] - stk[stk.size()-1])) <= 0) stk.pop_back();
        stk.push_back(a[i]);
    }
    Hull = stk;
    stk.clear(); Hull.pop_back();
    for(int i = a.size() - 1; i >= 0; i--) {
        while(stk.size() > 1 && ((stk[stk.size()-1] - stk[stk.size()-2]) | (a[i] - stk[stk.size()-1])) <= 0) stk.pop_back();
        stk.push_back(a[i]);
    }
    for(Pt t : stk) Hull.push_back(t);
    Hull.pop_back();
}


double x, y, ans;
int n;


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &x, &y);
        P.push_back({x, y});
    }
    sort(P.begin(), P.end());
    vector<Pt> Hull;
    convex(P, Hull);
    ans = 0;
    /*for(int i = 0; i < Hull.size(); i++) {
        printf("%f %f\n", Hull[i].x, Hull[i].y);
    }*/
    int a, b, c; n = Hull.size();
    for(i = 1; i < n; i++) {

    }
    printf("%.6f\n", ans);
    return 0;
}
