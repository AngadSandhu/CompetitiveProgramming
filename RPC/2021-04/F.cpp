#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(A) int(A.size())
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(A) begin(A),end(A)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<int,int>> vii;
ll mulmod(ll a, ll b, ll p){
	ll x = 0, y = a%p;
	while(b>0){
		if(b%2==1) x = (x+y)%p;
		y = (1LL*y*2)%p;
		b = b/2;
	}
	return x%p;
}
ll fastexp(ll x, ll y, ll p){
	ll ans = 1;
	while(y > 0){
		if(y&1) ans = (1LL*ans*x)%p;
		y = y>>1;
		x = (1LL*x*x)%p;
	}
	return ans%p;
}
ll fastexpp(ll x, ll y, ll p){
	ll ans = 1;
	while(y > 0){
		if(y&1) ans = mulmod(ans,x,p);
		y = y>>1;
		x = mulmod(x,x,p);
	}
	return ans%p;
}
ll invmod(ll x, ll p){
	return fastexp(x,p-2,p)%p;
}
int n, p;
const int N = 1000001;
int lpf[N + 5];
void sieve() {
    lpf[1] = 1;
    for(int i = 2; i < N; i++) lpf[i] = i;
    for(int i = 2; i < N; i++) {
        if(lpf[i] != i) continue;
        for(ll j = 1LL*i*i; j < N; j += i) {
            lpf[j] = i;
        }
    }
}
int main(){
    sieve();
    cin >> n >> p;
    int nn = n;
    vl v;
    while(nn != 1) {
        int x = lpf[nn];
        v.pb(x);
        while(nn % x == 0) nn /= x;
    }
    ll res = 0;
    for(auto e : v) {
        ll cnt = n/e;
        ll e1 = ((e - 1) * (n - 2)) % p;
        ll e2 = (fastexp(2, cnt - 1, p) - 1 + p) % p;
        e1 = (e1 * e2) % p;
        res = (res + e1) % p;
    }
    cout << res << "\n";
    return 0; 
}