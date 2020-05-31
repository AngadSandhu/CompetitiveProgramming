#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10005
ll n;
ll a[N], sum[N], pre[N];
int main(){
	FIO;
	cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a,a+n);
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            sum[a[j]-a[i]]++;
        }
    }
    for(int i = 0 ; i < N/2 ; i++){
        for(int j = 0 ; j < N/2 ; j++){
            pre[i+j] += sum[i]*sum[j];
        }
    }
    for(int i = 1 ; i < N ; i++) pre[i] += pre[i-1];
    ll ans = 0;
    for(int i = 1 ; i < N ; i++){
        ans += sum[i]*pre[i-1];
    }
    ll x = n*(n-1)/2;
    cout << fixed << setprecision(6) << (long double)ans/(x*x*x) << endl;
	return 0;
}