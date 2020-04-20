#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int const mod = 998244353;
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
ll fac[N], po[N];
int main(){
	FIO;
    fac[0] = 1; po[0] = 1;
    for(int i = 1 ; i < N ; i++) fac[i] = i*fac[i-1]%mod, po[i] = 2*po[i-1]%mod;
        ll n,k;
        cin >> n >> k;
        ll res = 1;
        res = (res * fac[k])%mod;
        res = (res * expmod(fac[n-1],mod-2,mod))%mod;
        res = (res * expmod(fac[k-n+1],mod-2,mod))%mod;
        res = (res * po[n-3])%mod;
        res = (res * (n-2))%mod;
        cout << res << endl;
	return 0;
}