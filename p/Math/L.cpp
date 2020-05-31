#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	ll n;
    int caso = 0;
    while(cin >> n, n > 0){
        ll ans = 0;
        for(ll k = 1 ; k <= n ; k++){
            ll i1 = max(n - 2*k+1,1ll), i2 = (n-k-1)/2;
            ans += max(0ll,i2-i1+1);
        }
        cout << "Case " << ++caso << ": " << ans << endl;
    }
	return 0;
}