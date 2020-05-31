#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1000005
const int mod = 998244353;
int f[N];
int n;
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
vector<vector<int>> v;
int main(){
	FIO;
	cin >> n;
    ll ans = 0;
    v.resize(n);
    for(int i = 0 ; i < n ; i++){
        int k; cin >> k;
        v[i].resize(k);
        for(int j = 0 ; j < k ; j++) cin >> v[i][j], f[v[i][j]]++;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            ans = (ans + expmod(1ll*v[i].size()*n,mod-2,mod)*f[v[i][j]])%mod;
        }
    }
    ans = (ans * expmod(n,mod-2,mod))%mod;
    cout << ans << endl;
	return 0;
}