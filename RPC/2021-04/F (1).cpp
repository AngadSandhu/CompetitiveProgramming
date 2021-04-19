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
vector<int> phi(1000006);
void phi_1_to_n() {
    int n = 1000005;
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}



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
ll num(ll x) {
    if(x == 1) return 0;
    ll e = x;
    ll cnt = n/e;
    ll e1 = phi[e] * ((n - 2)) % p;
    ll e2 = (fastexp(2, cnt - 1, p) - 1 + p) % p;
    e1 = (e1 * e2) % p;
    return e1;
}
int main(){
    phi_1_to_n();
    sieve();
    cin >> n >> p;
    int nn = n;
    vl v;
    /*
    while(nn != 1) {
        int x = lpf[nn];
        v.pb(x);
        while(nn % x == 0) nn /= x;
    }
    */
   for(int i = 1; i <= n; i++) {
       if(n % i == 0) v.pb(i);
   }
    ll res = 0;
    for(auto e : v) {
        
        res = (res + num(e)) % p;
       // cout << e << " " << num(e) << "\n";
    }
    cout << res << "\n";
    return 0; 
}