#include <bits/stdc++.h>
using namespace std;
int n, k,s[100005],d[100005];
double f(double t){
	double min = 1e13, max = -1;
	for(int i = 0 ; i < n ; i++){
		double pos = (double)s[i]*t + (double)d[i];
		if(pos > max) max = pos;
		if(pos < min) min = pos;
	}
	return max - min;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n ; i++){
		scanf("%d %d",&s[i],&d[i]);
	}
	double l = 0 , r = k , m1,m2;
	while( (r-l) > 1e-10){
		m1 = l + (r-l)/3;
		m2 = r - (r-l)/3;
		if( f(m1) > f(m2) ) l = m1;
		else r = m2;
		}
		printf("%.6f\n",f(l));
 	return 0;
	
}
