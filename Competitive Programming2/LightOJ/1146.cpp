#include<bits/stdc++.h>
using namespace std;
pair<double,double>p[4],u1,u2;
double ep = 1e-8,d1,d2,k;
double f(double m){
	pair<double,double> pos1,pos2;
	pos1.first = (p[0].first*(d1-m) + p[1].first*m)/d1;
	pos1.second = (p[0].second*(d1-m) + p[1].second*m)/d1;
	pos2.first = (p[2].first*(d2-m*k) + p[3].first*m*k)/d2;
	pos2.second = (p[2].second*(d2-m*k) + p[3].second*m*k)/d2;
	double dis = sqrt( pow(pos2.second-pos1.second,2) + pow(pos2.first-pos1.first,2) );
	return dis;
}
int main(){
	int t,d=0; cin >> t;
	while(t--){
		d++;
		for(int i = 0,a,b ; i < 4 ; i++){
			cin >> a >> b;
			p[i] = make_pair(a,b);
		}
		d1 = sqrt( pow(p[1].second-p[0].second,2) + pow(p[1].first-p[0].first,2) );
		d2 = sqrt( pow(p[3].second-p[2].second,2) + pow(p[3].first-p[2].first,2) );
		k = d2/d1;
		double l = 0, r = d1,m1,m2;
		while( (r-l) > ep ){
			m1 = l + (r-l)/3;
			m2 = r - (r-l)/3;
			if(f(m1) > f(m2)) l = m1;
			else r = m2;
		}
		printf("Case %d: %.7f\n",d,f(l));
	}
	return 0;
}
