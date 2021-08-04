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
    if(n%6==0) ans = n/6*15;
    else if(n%8==0) ans = n/8*20;
    else if(n%10==0) ans = n/10*25;
    else ans = ((n+5)/6)*15;
    cout << ans << endl;
  }
	return 0;
}