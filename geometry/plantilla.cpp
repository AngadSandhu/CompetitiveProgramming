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
double dot(const vector &a, const vector &b){ return a.x*b.x + a.y*b.y;}
double cross(const vector &a, const vector &b){ return a.x*b.y - a.y*b.x;}
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
	if( ((A1 > eps && A2 < eps) || (A1 < eps && A2 > eps)) && ((A3 > eps && A4 < eps) || (A3 < eps && A4 > eps))) return true;
	else if(A1 <eps && onSegment(P3, P4, P1)) return true;
	else if(A2 <eps && onSegment(P3, P4, P2)) return true;
	else if(A3 <eps && onSegment(P1, P2, P3)) return true;
	else if(A4 <eps && onSegment(P1, P2, P4)) return true;
	else return false;

}

/*********************************
*********GEOMETRY FUNCTIONS*******
***********************************/

int main(){

	
	return 0;	
}
