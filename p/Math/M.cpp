#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define eps 1e-6
int main(){
	FIO;
    ll a,b;
    while(cin >> a >> b, a > 0){
        if(a==1 && b==1){
            cout << "0 1"<< endl;
            continue;
        }
        ll n,s;
        for(ll i = 1 ; i <= 100 ; i++){
            if(pow(a+eps,1.0/i)-pow(b+eps,1.0/i) < eps + 1){
                s = i, n = pow(b+eps,1.0/i);
                break;
            }
        }
        ll ans1 = 0, cur1 = 1;
        for(ll i = 0 ; i < s ; i++){
            ans1 += cur1;
            cur1 *= n;
        }
        ll ans2 = 0, cur2 = a, aux = 1;
        for(ll i = 0 ; i <= s; i++){
            ans2 += aux*cur2;
            aux *= n;
            cur2 /= (n+1);
        }
        cout << ans1 << " " << ans2 << endl;
    }
	return 0;
}