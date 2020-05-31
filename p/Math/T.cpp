#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1000005
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
ll n, a[N];
ll cnt[N], maxn = -1;
int main(){
	FIO;
	sieve();
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i], cnt[a[i]]++, maxn = max(maxn,a[i]);
    ll ans = 0;
    for(ll i = 1 ; i <= maxn ; i++){
        ll cur = 0;
        for(ll j = 1 ; j <= maxn/i ; j++){
            cur += cnt[i*j];
        }
        ans += mobius[i]*cur*(cur-1)*(cur-2)/6;
    }
    cout << ans << endl;
	return 0;
}