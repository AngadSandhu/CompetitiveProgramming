#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
const int mod = 1e9 + 7;
ll F[N];
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
int binomial(int n, int k){
    return F[n]*expmod(F[n-k], mod-2, mod) %mod * expmod(F[k],mod-2,mod) %mod;
}
int main(){
	FIO;
    F[0] = 1;
	for(int i = 1 ; i < N ; i++) F[i] = (F[i-1]*i)%mod;
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int inside= 0, total= 0;
        for(int i = 0 ; i < n ; i++){
            if(a[i]==a[n-k]){
                if(i >= n-k) inside++;
                total++;
            } 
        }
        cout << binomial(total,inside) << endl;
    }
	return 0;
}