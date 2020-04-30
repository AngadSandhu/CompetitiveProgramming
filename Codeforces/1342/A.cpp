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
        ll x,y,a,b; cin >> x >> y >> a >> b;
        ll ans = LLONG_MAX; 
        ans = min(ans,min(x,y)*b + (max(x,y)-min(x,y))*a);
        ans = min(ans,x*a + y*a);
        cout << ans << endl;
    }
	return 0;
}