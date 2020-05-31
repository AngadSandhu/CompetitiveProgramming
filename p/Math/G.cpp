#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
ll phi(ll n) {
    ll ret = n;
    for(ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ret -= ret / i;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;
}
int main(){
	FIO;
	ll n;
	while(cin >> n, n > 0) cout << phi(n) << endl;
	return 0;
}