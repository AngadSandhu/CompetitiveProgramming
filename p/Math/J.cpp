#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 0

int main(){
	FIO;
	ll n;
    int caso = 0;
    while(cin >> n, n > 0){
        ll ans = n/2;
        cout << "Case " << ++caso << ": " << ans << endl;
    }
	return 0;
}