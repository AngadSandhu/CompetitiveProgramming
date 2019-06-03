#include<bits/stdc++.h>
using namespace std;
int n, m;
long long k;
bool f(long long x){
	long long c = 0;
	for(int i = 1 ; i <= n && x/i>0; i++){
		c += min(x/i,(long long)m);
	}
	return c >= k; 

}
int main(){

	cin >> n >> m >> k;
	long long l = 0, r = 1e13, med;
	while(l<r){
		med = l + (r-l)/2;
		if(f(med)) r = med;
		else l = med+1;
	}
	cout << l << endl;
	return 0;
}
