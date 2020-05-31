#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1000005
ll p[N];
int main(){
	FIO;
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    for(ll x = a ; x <= b ; x++) p[x+b]++, p[x+c+1]--;
    ll cur = 0;
    for(ll i = 0 ; i <= b+c ; i++){
        cur += p[i];
        p[i] = cur;
    }
    ll ans = 0;
    cur = 0;
    for(ll z = b+c ; z >= c ; z--){
        if(z <= d) ans += cur;
        cur += p[z];
    }
    cout << ans << endl;
	return 0;
}