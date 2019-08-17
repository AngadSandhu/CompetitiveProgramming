#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> res;
int main(){
	cin >> n;
	for(ll k = 1 ; k*k <= n && res.size()<100000; k++){
		if(n%k!=0) continue;
		ll x = n/k;
		res.push_back(x+x*(x-1)*k/2);
	}
	sort(res.begin(),res.end());
	for(auto v : res) cout << v << " ";
	cout << endl;
	return 0;
}
