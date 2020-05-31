#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        ll x,k; cin >> x >> k;
        ll j = (ll)log2(k);
        long double ans = 1.0* ((2.0*(k-(1ll<<j))+ 1)/(1ll<<(j+1)))*x;
        cout << fixed << setprecision(12) << ans << endl;
    }
	return 0;
}