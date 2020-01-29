#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll>des;
		set<ll> st;
		ll cur = 1;
		for(ll i = 2 ; i*i <= n ; i++){
			while(n%i==0){
				des.push_back(i);
				cur *= i;
				if(st.find(cur)==st.end() && st.size() < 2){
					st.insert(cur);
					cur = 1;
				}
				n /= i;
			}
		}
		if(n>1){
			des.push_back(n);
			cur *= n;
			if(st.find(cur)==st.end()&& st.size() < 2){
				st.insert(cur);
			}
		}
		if(cur!=1) st.insert(cur);
		if(st.size()==3){
			cout << "YES" << endl;
			for(auto v : st) cout << v << " ";
			cout << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
