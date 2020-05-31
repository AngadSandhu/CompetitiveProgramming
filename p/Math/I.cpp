#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1000005
ll ans[N];
int main(){
	FIO;
    ll cur = 0;
    for(ll i = 3 ; i < N ; i++){
        if(i%2==0) cur += (i-2)*(i-2)/4;
        else cur += ((i-3)/2)*((i-3)/2+1);
        ans[i] = cur;
    }
	ll n;
    while(cin >> n, n >= 3){
        cout << ans[n] << endl;
    }
	return 0;
}