#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
typedef long long ll;
 
using namespace std;
int main(){
	int t;cin >> t;
	while(t--){
		ll n,m; cin >> n >> m;
		ll s = 0;
		ll res = 0;
		for(int i = 1 ; i <= 10 ;i ++){
			s += (m*i)%10;
		}
		res += s*(n/(10*m));
		n -= 10*m*(n/(10*m));
		int i = 1;
		while(m*i<=n){
			res += (m*i)%10;
			i++;
		}
		cout << res <<endl;
	}
	return 0;
}
