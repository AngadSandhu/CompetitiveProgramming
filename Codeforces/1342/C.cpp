#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 40005
ll f[N], mcm;
ll g(ll x){
    return (x/mcm)*f[mcm] + f[x%mcm];
}
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        ll a,b,q; cin >> a >> b >> q;
        mcm = a*b/__gcd(a,b);
        f[0] = 0;
        for(int i = 1 ; i <= mcm ; i++) f[i] = f[i-1] + (((i%a)%b)!=((i%b)%a));
        while(q--){
            ll l, r; cin >> l >> r;
            cout << g(r) - g(l-1) << " ";
        }
        cout << endl;
    }
	return 0;
}