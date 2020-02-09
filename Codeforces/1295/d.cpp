#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
int main(){
    int t; cin >> t;
    while(t--){
        ll a,m;
        cin >> a >> m;
        ll g = __gcd(a,m);
        m /= g;
        cout << phi(m) << endl;
    }
    return 0;
}