#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
  ll n,k,x; cin >> n >> k >> x;
  vector<ll> a(n);
  for(auto &i : a) cin >> i;
  sort(a.begin(),a.end());
  vector<ll> need;
  for(int i = 1 ; i < n ; i++){
    if(a[i] - a[i-1] > x){
      need.pb((a[i] - a[i-1] + x - 1)/x - 1);
    }
  }
  sort(need.begin(),need.end());
  ll ans = need.size() + 1;
  for(int i = 0 ; i < need.size() && k > 0; i++){
    if(k - need[i] >= 0) k -= need[i], ans--;
  }
  cout << ans << endl;
	return 0;
}