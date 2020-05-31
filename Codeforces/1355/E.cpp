#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
ll ar[N];
ll a,r,m;
int n;
ll f(ll h){
    ll cost = 0;
    ll hi = 0, low = 0;
    for(int i = 0 ; i < n ; i++){
        if(ar[i] > h) hi += ar[i]-h;
        else low += h-ar[i];
    }
    if(m < r+a){
        cost += min(hi,low)*m;
        cost += (hi-min(hi,low))*r;
        cost += (low-min(hi,low))*a;
    }else{
        cost += hi*r;
        cost += low*a;
    }
    return cost;
}
int main(){
	FIO;
    cin >> n >> a >> r >> m;
    for(int i = 0 ; i < n ; i++) cin >> ar[i];
    ll l = 0, r = 1e10, m1, m2;
    while((r-l)>=3){
        m1 = l + (r-l)/3;
        m2 = r - (r-l)/3;
        if(f(m1) < f(m2)) r = m2;
        else l = m1;
    }
    ll ans = 1e18;
    for(ll i = l-3 ; i <= l+3 ; i++){
        ans = min(ans,f(i));
    }
    cout << ans << endl;
	return 0;
}