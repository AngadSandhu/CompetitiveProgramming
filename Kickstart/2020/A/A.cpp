#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int main(){
	FIO;
	int t; cin >> t;
	int caso = 0;
	while(t--){
	    caso++;
	    ll n,b; cin >> n >> b;
	    vector<ll> a(n);
	    for(ll &i : a) cin >> i;
	    sort(a.begin(),a.end());
	    ll sum = 0, cnt = 0;
	    for(int i = 0 ; i < n ; i++){
	        sum += a[i];
	        if(sum > b) break;
	        cnt++;
	    }
	    cout << "Case #" << caso << ": " << cnt << endl;
	}
	return 0;
}