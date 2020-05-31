#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
const int mod = 1000000007;
int main(){
	FIO;
    int t; cin >> t;
    int caso = 0;
    while(t--){
        int c; cin >> c;
        ll ans = 1 , n = 1;
        for(int i = 0 ; i < c ; i++){
            ll p,k; cin >> p >> k;
            ll cur = 1;
            ll f = 0;
            for(int j = 0 ; j < k ; j++){
                f = (f + cur)%mod;
                cur = (cur*p)%mod;
            }
            n = (n*cur)%mod;
            f = (f + cur*(k+1))%mod;
            ans = (ans*f)%mod;
        }
        cout << "Case " << ++caso << ": " << (ans+n)%mod << endl;
    }	
	return 0;
}