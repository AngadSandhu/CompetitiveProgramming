#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(ww) ww.begin(),ww.end()
#define N 

int main(){
	int t; cin>>t;
	while(t--){
		ll x, k; cin >> x >> k;
		int c = 0;
		for(ll i = 2 ; i*i  <= x ; i++){
			while(x%i==0){
				x/=i;
				c++;
			}
		}
		if(x>1) c++;
		cout << (k<=c) << endl;
	}
	return 0;
}