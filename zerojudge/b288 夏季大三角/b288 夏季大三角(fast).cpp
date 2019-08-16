#include<bits/stdc++.h>
#define x first
#define y second
#define all(_a) _a.begin(),_a.end()
const double eps = 1e-6;
using namespace std;
typedef pair<double,double> point;
typedef pair<double,double> vec;
typedef pair<point,vec> line;
vector<point> target;
vector<line> Line;
vec to_vec(point a,point b){
	return make_pair(b.x-a.x,b.y-a.y);
}
double ABS(double fuck){

}
double cross(vec a,vec b){
	return a.x*b.y - a.y*b.x;
}
void convex(vector<point> &x, vector<point> &target){
	static vector<point> stk;
	int i;
	stk.clear();
	target.clear();
	sort(all(x));
	for(i=0;i<x.size();i++){
		if(stk.size()<=1)
			stk.push_back(x[i]);
		else {
			while(stk.size()>1&&cross(to_vec(stk[stk.size()-2],stk[stk.size()-1]),to_vec(stk[stk.size()-1],x[i]))<=0.00){
				stk.pop_back();
			}
			stk.push_back(x[i]);
		}
	}
	for(i=0;i<stk.size()-1;i++){
		target.push_back(stk[i]);
	}
	stk.clear();
	for(i=x.size()-1;i>=0;i--){
		if(stk.size()<=1)
			stk.push_back(x[i]);
		else {
			while(stk.size()>1&&cross(to_vec(stk[stk.size()-2],stk[stk.size()-1]),to_vec(stk[stk.size()-1],x[i]))<=0.00){
				stk.pop_back();
			}
			stk.push_back(x[i]);
		}
	}
	for(i=0;i<stk.size()-1;i++){
		target.push_back(stk[i]);
	}
}
double tri(point a,point b,point c){
	vec _a = to_vec(a,b);
	vec _b = to_vec(a,c);
	return abs(cross(_a,_b))*0.5;
}
int main(){
	int n,i,k;
	scanf("%d",&n);
	vector<point> Points(n);
	for(i=0;i<n;i++){
		scanf("%lf %lf",&Points[i].x,&Points[i].y);
	}
	vector<point> hull;
	convex(Points,hull);
	/*for(point v : hull){
		printf("%lf %lf\n",v.x,v.y);
	}*/
	n = hull.size();
	int a, b, c;
	double ans = 0;
	if(n>=3){
	for(k=0;k<n-1;k++){
		c = 0;
		for(i=0;i+k+1<n;i++){
			a = i;
			b = i+k+1;
			while(1){
				//printf("fuck\n");
				int cl = (c-1);
				int cp = (c+1)%n;
				if(cl<0)
					cl = 0;
				if(tri(hull[a],hull[b],hull[cl])<=tri(hull[a],hull[b],hull[c]) && tri(hull[a],hull[b],hull[cp])<=tri(hull[a],hull[b],hull[c]))
					break;
				c = (c+1)%n;
			}
			ans = max(ans,tri(hull[a],hull[b],hull[c]));
		}
	}}
	printf("%.6lf\n",ans);
	return 0;
}
