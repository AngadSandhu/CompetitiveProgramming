#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define N 100005
#define FIFO ios::sync_with_stdio(false)
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl
#define cout2(x, y) cout << x << " " << y << endl
#define INF (1<<30)
#define MOD 1000000007
#define ones(x) __builtin_popcountll(x)



#define Vector Point
#define PI (atan2(0, -1))
#define EPS 1e-6

using namespace std;

struct Point{
	
	double x, y;
	
	Point(double _x, double _y){ x = _x; y = _y; }
	Point(){}
	
	double mod(){ return sqrt(x * x + y * y); }
	double mod2(){ return x * x + y * y; }
	double arg(){ return atan2(y, x); }
	Point ort(){ return Point(-y, x); }
	Point rev(){ return Point(y, x); }
	Point unit()  { double k = mod(); return Point(x/k, y/k); }
	
	void print(){ printf("%lf %lf\n", x, y); }
	void read(){ scanf("%lf%lf", &x, &y); }
};
	
//OPERADORES SOBRE PUNTOS
bool operator <(const Point &P1, const Point &P2){ return (P1.x != P2.x)? (P1.x < P2.x) : (P1.y < P2.y); }
bool operator ==(const Point &P1, const Point &P2){ return fabs(P1.x - P2.x) < EPS && fabs(P1.y - P2.y) < EPS; }
bool operator >(const Point &P1, const Point &P2){ return !(P1 == P2) && !(P1 < P2); }
bool operator !=(const Point &P1, const Point &P2){ return !(P1 == P2); }

Point operator -(const Point &p1, const Point &p2){ return Point(p1.x - p2.x, p1.y - p2.y); }
Point operator +(const Point &p1, const Point &p2){ return Point(p1.x + p2.x, p1.y + p2.y); }
Point operator *(const Point &p, double k){ return Point(p.x * k, p.y * k); }
Point operator /(const Point &p, double k) { return Point(p.x/k, p.y/k); }

//FUNCIONES BÁSICAS SOBRE PUNTOS Y VECTORES
double dot(const Vector &v1, const Vector &v2){ return v1.x * v2.x + v1.y * v2.y; }
double cross(const Vector &v1, const Vector &v2){ return v1.x * v2.y - v1.y * v2.x; }
double dis(const Point &P1, const Point &P2){ return (P1 - P2).mod(); }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

double areaHeron(double a, double b, double c){
    double s = (a + b + c) / 2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}
double areaHeron(double a, double b, double c, double d){
	
    double s = (a + b + c + d) / 2;
    return sqrt((s-a) * (s-b) * (s-c) * (s-d));
}

double circumradius(double a, double b, double c) { return a * b * c / (4 * areaHeron(a, b, c)); }

Point rotate(Point A, Point C, double teta){ 
		
	Point T = Point(A.x - C.x, A.y - C.y);
	return C + Point( T.x * cos(teta) - T.y * sin(teta), T.y * cos(teta) + T.x * sin(teta));	
}

int main(){

	long double r;
	cin >> r;
	
	
	int n;
	cin >> n;
	
	vector<Point>P(n);
	for(int i = 0; i < n; i++)P[i].read();
	
	Point center, v, center1, center2;
	int ans = 1, cnt;
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
		
			double dis = (P[i] - P[j]).mod2(), h;
			if(dis > 4 * r * r)continue;
			
			else if(dis == 4 * r * r){
				
				center = (P[i] + P[j])/2.0;
				cnt = 0;
				
				for(int k = 0; k < n; k++)
					if((center - P[k]).mod2() < r * r + EPS)cnt++;
				
				ans = max(ans, cnt);
			}
			else{
				
				dis = sqrt(dis)/2.0;
				h = sqrt(r * r - dis * dis);
				
				v = (P[i] - P[j]).ort().unit();
				center = (P[i] + P[j])/2.0;
				
				center1 = center + v * h;
				center2 = center - v * h;
				cnt = 0;
				
				for(int k = 0; k < n; k++)
					if((center1 - P[k]).mod2() < r * r + EPS)cnt++;
				
				ans = max(ans, cnt);
				cnt = 0;
				
				for(int k = 0; k < n; k++)
					if((center2 - P[k]).mod2() < r * r + EPS)cnt++;
				
				ans = max(ans, cnt);
			}
		}
	}
	
	cout << ans << endl;
}

