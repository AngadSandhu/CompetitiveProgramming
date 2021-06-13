#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 2000005
const int mod = 1e9 + 7;
ll p[N];
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
ll inv(ll n){ return expmod(n,mod-2,mod); }
int main(){
	FIO;
	int n; cin >> n;
  vector<int> a(n);
  for(int &i:a) cin >> i;
  ll curr = 1;
  for(int i = 0 ; i < n ;i ++){
    if(a[i] == 2) curr *= 2, curr %= mod;
    p[i] = curr;
  }
  ll cnt = 0, ans = 0; curr = 0;
  for(int i = n-1 ; i >= 0 ; -i--){
    if(a[i] == 1){ 
      ans += inv(p[i]) * curr - cnt;
      ans %= mod;
    }
    if(a[i] == 3) curr += p[i], curr %=mod, cnt++;
  }
  cout << ans%mod + mod % mod << endl;
	return 0;
}