#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 100005
long double f[N];
int s[N];
int main(){
	FIO;
	f[0] = log(1);
    for(int i = 1 ; i < N ; i++) f[i] = f[i-1] + log(i);
    int n,m,h; cin >> n >> m >> h;
    ll sum = 0;
    for(int i = 0 ; i < m ; i++) cin >> s[i], sum += s[i];
    h--;
    if(sum < n){
        cout << -1 << endl;
        return 0;
    }
    long double ans = 0;
    for(int k = 1 ; k < s[h] ; k++){
        if(k < n && sum-s[h]-n+k+1 >= 0) ans += exp(f[s[h]-1] + f[n-1] + f[sum-n] + f[sum-s[h]]- f[k] - f[s[h]-1-k] - f[sum-1] -f[n-k-1]-f[sum-s[h]-n+k+1]);
    }
    cout << fixed << setprecision(7) << ans << endl;
	return 0;
}