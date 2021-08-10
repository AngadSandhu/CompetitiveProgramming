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
    ll ans = 0;
    if(n <= 10){
      if(n>8) ans += 25;
      else if(n>6) ans += 20;
      else ans += 15;
    }else{
      ans += 15*((n-5)/6);
      n -= 6*((n-5)/6);
      if(n>8) ans += 25;
      else if(n>6) ans += 20;
      else ans += 15;
    }
    cout << ans << endl;
  }
	return 0;
}