#include<bits/stdc++.h>
using namespace std;
int n, h[10005], c[10005];
long long f(int alt){
	long long cost = 0;
	for(int i = 0; i < n ; i++){
		cost += (long long)abs(alt-h[i])*c[i];
	}
	return cost;
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&h[i]);
		}
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&c[i]);
		}
		int l = 0, r = (1e4)+5, m1,m2;
		while( (r-l)>3 ){
			m1 = l + (r-l)/3;
			m2 = r - (r-l)/3;
			if( f(m1) > f(m2) ) l = m1;
			else r = m2;
		}
		long long mini = 1e18;
		for(int i = l; i <= r ; i++){
			mini = min(mini,f(i));
		}
		printf("%lld\n",mini);
	}
	return 0;
}
