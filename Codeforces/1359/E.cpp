#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 500005
const int mod = 998244353;
ll expmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a)% m;
        a = ( a * a )% m;
        b >>= 1;
    }
    return res;
}
ll F[N];
int main(){
	FIO;
	F[0] = 1;
    for(ll i = 1; i < N ; i++) F[i] = (F[i-1]*i)%mod;
    ll n,k; cin >> n >> k;
    ll ans = 0;
    for(ll i = 1 ; i <= n ; i++){
        ll d = n/i;
        if(k <= d) ans = (ans + ((F[d-1]*expmod(F[k-1],mod-2,mod))%mod)*expmod(F[d-k],mod-2,mod))%mod;
    }
    cout << ans << endl;
	return 0;
}