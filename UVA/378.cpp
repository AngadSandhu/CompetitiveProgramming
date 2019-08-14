#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
#define vector point
#define eps 1e-8
typedef long long ll;
using namespace std;
struct point{
	double x,y;
	point(){}
	point(double a,double b){ x = a; y = b; }
	double mod(){ return sqrt(x*x+y*y); }
	double arg(){ return atan2(y,x); }
};
point operator -(const point &a,const point &b){return point(a.x-b.x,a.y-b.y);}
point operator +(const point &a, const point &b) { return point(a.x + b.x, a.y + b.y); }
point operator *(const point &a, double k) { return point(a.x*k, a.y*k); }
double dot(const vector &a, const vector &b){
	return a.x*b.x + a.y*b.y;
}
double cross(const vector &a, const vector &b){
	return a.x*b.y - a.y*b.x;
}
double area(const point &a,const point &b,const point &c){
	return cross(b-a,c-a);
}
point lineIntersection(const point &a, const point &b, const point &c, const point &d){
	return a + (b - a) * (cross(c - a, d - c) / cross(b - a, d - c));
}
bool online(const point &a,const point &b,const point &c){
	return abs(area(a,b,c)) < eps &&
	a.x >= min(b.x, c.x) && a.x <= max(b.x, c.x) &&
	a.y >= min(b.y, c.y) && a.y <= max(b.y, c.y);
}
int main(){
	double ax,ay,bx,by,cx,cy,dx,dy;
	int t; cin >> t;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	while(t--){
		cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
		point A(ax,ay);
		point B(bx,by);
		point C(cx,cy);
		point D(dx,dy);
		if(abs(area(A,C,D)) < eps && abs(area(B,C,D))<eps) cout << "LINE";
		else if(abs(cross(B-A,D-C))<eps) cout << "NONE";
		else printf("POINT %.2f %.2f",lineIntersection(A,B,C,D).x,lineIntersection(A,B,C,D).y);
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;	
}

