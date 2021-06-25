#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;	int t; cin >> t;
  while(t--){
    ll n; cin >> n;
    vector<pair<ll,ll>> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i].first, a[i].second = i+1;
    sort(a.begin(),a.end());
    ll ans = 0;
    for(int j = 0 ; j < n ; j++){
      for(int i = 0 ; i < j ; i++){
        if(a[i].first * a[j].first > 2*n) break;
        if(a[i].first * a[j].first == a[i].second + a[j].second) ans++;
      }
    }
    cout << ans << endl;
  }
	return 0;
}