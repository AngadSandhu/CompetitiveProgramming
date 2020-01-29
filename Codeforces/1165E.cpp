#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n;
ll ar[200005],br[200005];
ll res = 0;
int main(){
	cin >> n; 
	for(ll i = 0 ; i < n ; i++) cin >> ar[i], ar[i] = (i+1)*(n-i)*ar[i];
	for(ll i = 0 ; i < n ; i++) cin >> br[i];
	sort(ar,ar+n);
	sort(br,br+n,greater<ll>());
	for(ll i = 0 ; i < n ; i++){
		res = (res+((ar[i]%mod)*br[i])%mod) % mod;
	}
	cout << (res)%mod << endl;
	return 0;
}
