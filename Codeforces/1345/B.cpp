#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
ll n;
ll f(ll x){
    return x*(x+1) + (x*(x+1)-2*x)/2;
}
int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        cin >> n;
        ll res = 0;
        while(n >= 2){
            ll l = 0, r = n, med;
            while( l < r ){
                med = l + (r-l+1)/2;
                if(f(med) <= n) l = med;
                else r = med-1;
            }
            n -= f(l);
            res++;
        }
        cout << res << endl;
    }
	return 0;
}