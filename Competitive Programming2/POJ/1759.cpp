#include <iostream>
#include <cstdio>
using namespace std;
int n;
double a,m;
double f(int i){
	double d = (i-1)*m + (double)(i-1)*(i-2) - (i-2)*a;
	return d;
}
double minimo(double b){
	m = (b + (n-2)*a - (n-1)*(n-2))/(n-1);
	int l = 1, r = n,m1,m2;
	while( (r-l) >= 3){
		m1 = l + (r-l)/3;
		m2 = r - (r-l)/3;
		if( f(m1) > f(m2) ) l = m1;
		else r = m2;
	}
	double mini = 9999999;
	for(int i = l ; i <= r ; i++){
		if( f(i) < mini ) mini = f(i);
	} 
	return mini;
} 
int main(){
	cin >> n >> a;
	double l = 0, r = 1e7, med;
	while( (r-l) > 1e-3 ){
		med = (l+r)/2;
		if(minimo(med) >= 0) r = med;
		else l = med;
	}
	printf("%.2f\n",med);
	return 0;
}
