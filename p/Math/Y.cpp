#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10000005
const int mod = 1e9 + 7;
vector<int> prime;
bool notprime[N];
int mobius[N];
void sieve() {
	memset(notprime,0,sizeof notprime);
    mobius[1] = 1;
	for(int i = 2; i < N ; i++){
		if(!notprime[i]) {
			prime.push_back(i);
            mobius[i] = -1;
		}
		for(int j = 0; j < prime.size () && i * prime[j] < N ; ++j){
			notprime[i*prime[j]] = true;
			if(i % prime[j] == 0){
                mobius[i*prime[j]] = 0;
				break;
			}else {
                mobius[i*prime[j]] = mobius[i]*mobius[prime[j]];
			}
		}
	}
}
ll expmod(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a)% mod;
        a = ( a * a )% mod;
        b >>= 1;
    }
    return res;
}

ll g[N];
int main(){
	FIO;
    sieve();
    int t; cin >> t;
    while(t--){
        ll n,m,l,r; cin >> n >> m >> l >> r;
        vector<pair<int,int>> ter;
        for(int i = 1 ; i <= m ; i++) g[i] = expmod(i,n);
        for(int i = l ; i <= r ; i++){
            if(ter.empty() || ter.back().first != m/i) ter.pb({m/i,1});
            else if(ter.back().first == m/i) ter.back().second++;
        }
        ll ans = 0;
        for(int i = 0 ; i < ter.size() ; i++){
            int k = ter[i].first;
            ll cur = 0;
            for(int d = 1 ; d <= k ; d++){
                cur = (cur + 1ll*mobius[d]*g[k/d])%mod;
            }
            ans = (ans + 1ll*cur*ter[i].second)%mod;
        }
        ans = (ans%mod+mod)%mod;
        cout << ans << endl;
    }
	return 0;
}