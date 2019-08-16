#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define N 0
#define Vector point
#define eps 1e-8
const double PI = acos(-1);
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
point operator /(const point &a, double k){ return point(a.x/k,a.y/k); }
bool operator <(const point &a, const point &b){ if(a.x!=b.x) return a.x+eps<b.x; else return a.y+eps<b.y; }
bool operator ==(const point &a, const point &b){ return (abs(a.x-b.x)<eps && abs(a.y-b.y)<eps); }
bool operator !=(const point &a, const point &b){ return !(a==b); }
double dot(const Vector &a, const Vector &b){ return a.x*b.x + a.y*b.y;}
double cross(const Vector &a, const Vector &b){ return a.x*b.y - a.y*b.x;}
double area(const point &a,const point &b,const point &c){ return cross(b-a,c-a);}
point lineIntersection(const point &a, const point &b, const point &c, const point &d){
	return a + (b - a) * (cross(c - a, d - c) / cross(b - a, d - c));
}
bool online(const point &a,const point &b,const point &c){
	return abs(area(a,b,c)) < eps &&
	a.x >= min(b.x, c.x) && a.x <= max(b.x, c.x) &&
	a.y >= min(b.y, c.y) && a.y <= max(b.y, c.y);
}
bool onSegment(const point &A, const point &B, const point &P){
	return abs(area(A, B, P)) < eps &&
	P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
	P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y);
}
bool intersects(const point &P1, const point &P2, const point &P3, const point &P4){
	double A1 = area(P3, P4, P1);
	double A2 = area(P3, P4, P2);
	double A3 = area(P1, P2, P3);
	double A4 = area(P1, P2, P4);
	if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) && ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))) return true;
	else if(A1 <eps && onSegment(P3, P4, P1)) return true;
	else if(A2 <eps && onSegment(P3, P4, P2)) return true;
	else if(A3 <eps && onSegment(P1, P2, P3)) return true;
	else if(A4 <eps && onSegment(P1, P2, P4)) return true;
	else return false;

}
bool left(const point &a,const point &b,const point &p){
	if(abs(area(a,b,p))<eps) return false;
	return area(a,b,p)>0; 
}
bool right(const point &a,const point &b,const point &p){
	if(abs(area(a,b,p))<eps) return false;
	return area(a,b,p)<0; 
}
/*********************************
*********GEOMETRY FUNCTIONS*******
***********************************/

int n;
double T;
point a[200005];
double r[55],t[55];
double xx,yy;
int c1 = 0,c2 = 0;
void sol(){
	c1 = 0, c2 = 0;
	for(int i = 0 ; i < n ;i++){
		if(a[i].x>xx+eps && a[i].y>yy+eps) c1++;
		if(a[i].x+eps<xx && a[i].y+eps<yy) c1++;
		if(a[i].x>eps+xx && a[i].y+eps<yy) c2++;
		if(a[i].x+eps<xx && a[i].y>eps+yy) c2++;
	}
}
int main(){
	while(cin >> n, n > 0){
		for(int i = 0 ; i < n ;i++){
			double x,y;
			cin >> x >>y;
			a[i] = point(x,y);
		}
		xx = a[n/2].x, yy = a[n/2].y;
		sol();
		cout << c1 << " " << c2 << endl;
	}
	return 0;	
}
