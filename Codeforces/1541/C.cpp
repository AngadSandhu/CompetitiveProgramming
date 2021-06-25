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
    vector<ll> d(n), p(n);
    for(int i = 0 ; i < n ; i++) cin >> d[i];
    sort(d.begin(),d.end());
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++){
      sum += d[i];
      p[i] = sum;
    }
    ll ans = 0;
    for(ll i = 2 ; i < n ; i++){
      ans += (i-1) * d[i] - p[i-2];
    }
    cout << -ans << endl;
  }
	return 0;
}