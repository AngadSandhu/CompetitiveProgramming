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
    ll n; cin >> n;
    vector<ll> c(n);
    for(ll &i : c) cin >> i;
    ll ans = LLONG_MAX;
    vector<ll> mini(2,LLONG_MAX),sum(2,0),sz(2,0);
    for(int i = 0 ; i < n ; i++){
      mini[i%2] = min(mini[i%2],c[i]);
      sum[i%2] += c[i];
      sz[i%2]++;
      if(i < 1) continue;
      ans = min(ans,sum[0] + mini[0]*(n-sz[0]) + sum[1] + mini[1]*(n-sz[1]));
    }
    cout << ans << endl;
  }
	return 0;
}