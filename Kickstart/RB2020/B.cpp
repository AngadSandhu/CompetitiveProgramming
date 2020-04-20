#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
int main(){
	FIO;
	int t,caso = 0; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vector<ll> a(n);
        for(ll &i : a) cin >> i;
        a.pb(k); n++;
        reverse(a.begin(),a.end());
        for(int i = 1 ; i < n ; i++){
            a[i] = (a[i-1]/a[i])*a[i];
         }
        cout << "Case #" << ++caso << ": " << a[n-1] << endl;
    }
	return 0;
}