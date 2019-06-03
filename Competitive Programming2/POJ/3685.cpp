#include<iostream>
using namespace std;
long long n,m;
bool f(long long x){
	long long c = 0;
	for(long long i = 1 ; i <= n ; i++){
		if((1*1 +(1e5)*1 + i*i -(1e5)*i + 1*i) > x) continue;
		if((n*n +(1e5)*n + i*i -(1e5)*i + n*i) <= x){
			c += n;
			continue;
		}
		long long l = 1, r = n, med;
		while(l<r){
			med = l + (r-l+1)/2;
			if( (med*med +(1e5)*med + i*i -(1e5)*i + med*i) <= x) l = med;
			else r = med-1;
		}
		c += r;
	}
	return c >= m;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		long long l = -1e11, r = 1e11,med;
		while(l<r){
			med = l + (r-l)/2;
			if(f(med)) r = med;
			else l = med+1;
		}
		cout << l << endl;
	}
	return 0;
}
