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
    ll p,a,b,c; cin >> p >> a >> b >> c;
    ll ans = a*((p+a-1)/a)-p;
    ans = min(ans,b*((p+b-1)/b)-p);
    ans = min(ans,c*((p+c-1)/c)-p);
    cout << ans << endl;
  }
	return 0;
}