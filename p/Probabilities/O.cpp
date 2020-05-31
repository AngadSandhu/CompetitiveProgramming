#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1000005
ll n, a[N], f[N], last[N];
int main(){
	FIO;
	cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= n ; i++){
        f[i] = last[a[i]];
        last[a[i]] = i;
    }
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++) ans += 2ll*(n-i+1) * (i-f[i]) - 1;
    cout << fixed << setprecision(6) << (ld)ans/(n*n)<< endl;
	return 0;
}