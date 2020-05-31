#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> a(n);
		for(ll &i:a) cin >> i;
		ll mx = LLONG_MIN, res = 0;
		a.pb(0);
		for(int i = 0 ; i < n ; i++){
			mx = max(mx,a[i]);
			if(a[i]*a[i+1] <= 0){
				res += mx;
				mx = LLONG_MIN;
			}
		}
		cout << res << endl;
	}
	return 0;
}