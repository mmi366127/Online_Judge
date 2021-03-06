#include <bits/stdc++.h>
using namespace std;
#define eps 1e-12
struct Pt {
    double x, y;
    Pt(double a = 0, double b = 0):
    x(a), y(b) {}
    Pt operator-(const Pt &a) const {
        return Pt(x - a.x, y - a.y);
    }
    Pt operator+(const Pt &a) const {
        return Pt(x + a.x, y + a.y);
    }
    Pt operator*(const double a) const {
        return Pt(x * a, y * a);
    }
    bool operator<(const Pt &a) const {
        if (fabs(x - a.x) > eps)
            return x < a.x;
        if (fabs(y - a.y) > eps)
            return y < a.y;
        return false;
    }
    double dist2(Pt a) {
    	return (x - a.x)*(x - a.x)+(y - a.y)*(y - a.y);
    }
};
double dot(Pt a, Pt b) {
    return a.x * b.x + a.y * b.y;
}
double cross(Pt o, Pt a, Pt b) {
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double cross2(Pt a, Pt b) {
    return a.x * b.y - a.y * b.x;
}
int between(Pt a, Pt b, Pt c) {
    return dot(c - a, b - a) >= -eps && dot(c - b, a - b) >= -eps;
}
int onSeg(Pt a, Pt b, Pt c) {
    return between(a, b, c) && fabs(cross(a, b, c)) < eps;
}
Pt getIntersect(Pt as, Pt ae, Pt bs, Pt be) {
    Pt u = as - bs;
    double t = cross2(be - bs, u)/cross2(ae - as, be - bs);
    return as + (ae - as) * t;
}
struct Seg {
	Pt s, e;
	int id;
	Seg(Pt a = Pt(), Pt b = Pt(), int c = 0):
		s(a), e(b), id(c) {}
};
bool polar_cmp(const Pt& p1, const Pt& p2) {
    if (p1.y == 0 && p2.y == 0 && p1.x * p2.x <= 0) return p1.x > p2.x;
    if (p1.y == 0 && p1.x >= 0 && p2.y != 0) return true;
    if (p2.y == 0 && p2.x >= 0 && p1.y != 0) return false;
    if (p1.y * p2.y < 0) return p1.y > p2.y;
    double c = cross2(p1, p2);
    return c > 0 || (c == 0 && fabs(p1.x) < fabs(p2.x));
}
bool polar_cmp2(pair<Pt, int> x, pair<Pt, int> y) {
	return polar_cmp(x.first, y.first);
}
int cmpZero(double x) {
	if (fabs(x) < eps)	return 0;
	return x < 0 ? -1 : 1;
}
struct CMP {
	static Pt ray_s, ray_e;

	bool operator()(const Seg &x, const Seg &y) {
		Pt v1 = getIntersect(ray_s, ray_e, x.s, x.e);
		Pt v2 = getIntersect(ray_s, ray_e, y.s, y.e);
		return cmpZero(ray_s.dist2(v1) - ray_s.dist2(v2)) < 0;
	}
	static bool ray2seg(Seg x) {
		if (cmpZero(cross(ray_s, ray_e, x.s))*cmpZero(cross(ray_s, ray_e, x.e)) < 0) {
			return cmpZero(cross(x.s, ray_s, ray_s+ray_e))*cmpZero(cross(x.s, ray_s, x.e)) >= 0 &&
					cmpZero(cross(x.e, ray_s, ray_s+ray_e))*cmpZero(cross(x.e, ray_s, x.s)) >= 0;
		}
		return false;
	}
};
Pt CMP::ray_s, CMP::ray_e;
const int MAXN = 32768;
int visual[MAXN];
Seg segs[MAXN];
int main() {
	int N, sx, sy, ex, ey;
	while (scanf("%d", &N) == 1) {
		vector< pair<Pt, int> > A;
		set<Seg, CMP> S;
		for (int i = 1; i <= N; i++) {
			scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
			A.push_back(make_pair(Pt(sx, sy), i));
			A.push_back(make_pair(Pt(ex, ey), -i));
			segs[i] = Seg(Pt(sx, sy), Pt(ex, ey), i);
			visual[i] = 0;
		}
		sort(A.begin(), A.end(), polar_cmp2);
		CMP::ray_s = Pt(0, 0), CMP::ray_e = A[0].first;

		for (int i = 1; i <= N; i++) {
			if (CMP::ray2seg(segs[i]))
				S.insert(segs[i]);
		}

		for (int i = 0; i < A.size(); ) {
			CMP::ray_e = A[i].first;
			while (i < A.size() && cmpZero(cross(CMP::ray_s, CMP::ray_e, A[i].first)) == 0) {
				int clockwise, id = abs(A[i].second);
				if (A[i].second > 0)
					clockwise = cmpZero(cross(CMP::ray_s, segs[id].s, segs[id].e));
				else
					clockwise = cmpZero(cross(CMP::ray_s, segs[id].e, segs[id].s));
				if (clockwise) {
					if (clockwise > 0)
						S.insert(segs[id]);
					else
						S.erase(segs[id]);
				}
				i++;
			}
			if (S.size() > 0)
				visual[S.begin()->id] = 1, printf("%f %f %d\n", CMP::ray_e.x, CMP::ray_e.y, S.begin()->id);
		}
		for (int i = 1; i <= N; i++)
			printf("%d%c", visual[i], i == N ? '\n' : ' ');
	}
	return 0;
}
