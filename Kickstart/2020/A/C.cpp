#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int n,k;
bool f(ll x, vector<ll> &a){
  ll cnt = 0;
  for(int i = 1 ; i < n ; i++){
    cnt += (a[i]-a[i-1] + x - 1)/x - 1;
  }
  return cnt <= k;
}
int main(){
	FIO;
  int t, caso = 0;
  cin >> t;
  while(t--){
    caso++;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    ll l = 1, r = 2e9, med;
    while(l < r){
      med = (l+r)/2;
      if(f(med,a)) r = med;
      else l = med+1;
    }
    cout << "Case #" << caso << ": " << l << endl;
  }	
	return 0;
}