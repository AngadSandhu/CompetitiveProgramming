#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	ll n;
    while(cin >> n, n > 0){
        vector<ll> d;
        for(ll i = 1; i*i <= n ; i++){
            if(n%i==0){
                d.pb(i);
                if(i*i != n) d.pb(n/i);
            }
        }
        ll ans = 0;
        for(int i = 0 ; i < d.size() ; i++){
            for(int j = i+1 ; j < d.size() ; j++){
                ans += (d[i]*d[j] == n*__gcd(d[i],d[j]));
            }
        }
        cout << n << " " << ans+1 << endl;
    }
	return 0;
}