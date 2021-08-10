#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
const int mod = 1e9 + 7;
ll expmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a)% m;
        a = ( a * a )% m;
        b >>= 1;
    }
    return res;
}
ll F[N];
int main(){
	FIO;
  F[0] = 1;
  for(ll i = 1 ; i < N ; i++) F[i] = (F[i-1]*2)% mod;
	int t; cin >> t;
  while(t--){
    ll n,k; cin >> n >> k;
    if(n%2){
      cout << expmod(F[n-1]+1,k,mod) << endl;
    }else{
      ll ans = ( ((expmod(F[n],k,mod) - expmod(F[n-1]-1,k,mod) )% mod + mod )% mod) * expmod(F[n-1]+1,mod-2,mod) % mod;
      ans = (ans + expmod(F[n-1]-1,k,mod))%mod;
      cout << ans << endl;
    }
  }
	return 0;
}