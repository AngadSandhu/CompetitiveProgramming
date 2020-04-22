#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
ll n,l,r;
vector<ll> construct(ll x){
	ll p = x+1, cur = x;
	vector<ll> res;
	if(x==n){
		res.pb(1);
		return res;
	}
	for(int i = 0 ; i < 2*(n-x); i++){
		if(i%2==0) cur = x;
		else cur = p++;
		res.pb(cur);
	}
	return res;
}
int main(){
	FIO;
	int t; cin >>t;
	while(t--){
		cin >> n >> l >> r;
		ll sum = 0, nod, need;
		for(int i = 1 ; i <= n ; i++){
			sum += 2*(n-i) + (i==n);
			if(sum >= l){
				nod = i;
				sum -= 2*(n-i) + (i==n);
				need = l-sum-1;
				break;
			}
		}
		vector<ll> v;
		while(v.size() < need + r-l+1){
			vector<ll> aux = construct(nod++);
			for(auto x : aux) v.pb(x);
		}
		for(int i = 0 ; i < v.size() && sum < r ; i++){
			if(++sum >= l) cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}