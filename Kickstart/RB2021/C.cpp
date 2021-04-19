#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}
int main(){
	FIO;
	int t; cin >> t;
  int caso = 0;
  while(t--){
    ll n; cin >> n;
    cout << "Case #" << ++caso << ": ";
    ll sq = (ll)ceil(sqrt(n));
    ll ans = 0, i = sq, j = sq;
    while(isPrime(i)==0) i--;
    while(isPrime(j)==0) j++;
    ans = i*j;
    cout << ans << endl;
  }
	return 0;
}