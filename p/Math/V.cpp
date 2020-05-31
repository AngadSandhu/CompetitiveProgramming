#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
ll N;
const int mod = 1e9 + 7;
ll f(ll d){
    ll x = N/d, ret = 1;
    ret = (x*(x+1))%mod;
    ret = (ret*(2*x+1))%mod;
    ret = (ret*166666668)%mod;
    ret = (ret*d)%mod;
    ret = (ret*d)%mod;
    return ret;
}
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n==1){
            cout << 0 << endl;
            continue;
        }
        N = n;
        vector<ll> v;
        for(ll i = 2 ; i*i <= n ;i++){
            if(n%i==0) v.pb(i);
            while(n%i==0) n /= i;
        }
        if(n > 1) v.pb(n);
        ll k = v.size();
        ll ans = 0;
        for(ll i = 0 ; i < (1ll<<k) ; i++){
            ll bt = __builtin_popcount(i);
            ll d = 1;
            for(ll j = 0 ; j < k ; j++) if(i&(1ll<<j)) d *= v[j];
            ans = (ans + 1ll*(bt%2?-1:1)*f(d))%mod;
        }
        cout << (ans%mod+mod)%mod << endl;
    }
	return 0;
}