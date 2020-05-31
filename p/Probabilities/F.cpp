#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
ll f(ll x,ll n){return x/n;}
int n,p;
pair<ll,ll> v[N];
int main(){
	FIO;
	cin >> n >> p;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i].first >> v[i].second;
    }
    v[n] = v[0];
    long double ans = 0;
    for(int i = 0 ; i < n ; i++){
        ll r1 = v[i].second-v[i].first+1, r2 = v[i+1].second-v[i+1].first+1;
        ll f1 = f(v[i].second,p) - f(v[i].first-1,p), f2 = f(v[i+1].second,p) - f(v[i+1].first-1,p);
        ans += (long double)(f1*r2 + f2*r1 - f1*f2)/(r1*r2);
    }
    cout << fixed << setprecision(7) << 2000*ans << endl;
	return 0;
}