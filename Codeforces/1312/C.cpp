#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vector<ll> a(n), freq(100);
        for(ll &i : a) cin >> i;
        sort(a.begin(),a.end());
        bool ans = 1;
        for(int i = 0 ; i < n ; i++){
            vector<ll> rep;
            ll x = a[i], cnt = 0;
            while(x > 0){
                rep.pb(x%k);
                if(x%k > 1) ans = 0;
                x /= k;
            }
            for(int j = 0 ; j < rep.size() ;j ++){
                freq[j] += rep[j];
            }
        }
        for(auto v : freq){
            if(v > 1) ans = 0;
        }
        cout << (ans?"YES":"NO") << endl;
    }
	return 0;
}