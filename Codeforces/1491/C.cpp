#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 500005

int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<ll> a(n), c(n,0);
    for(ll &i : a) cin >> i;
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
      ll add = max(0ll,a[i]-c[i]-1);
      ans += add;
      // cout << add << " " << a[i] << " " << c[i] << endl;
      if(i+a[i] >= n) a[i] = n-i;
      while(a[i] > !(a[i] <= c[i])){
        if(i+a[i] < n) c[i+a[i]]++;
        a[i]--;
      }
    }
    cout << ans << endl;
  }
	return 0;
}