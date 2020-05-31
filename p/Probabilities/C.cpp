#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
long double xp(long double a,int b){
    long double res = 1;
    while(b > 0){
        if(b & 1) res = res * a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main(){
	FIO;
	ll n,m; cin >> m >> n;
    long double ans = 0;
    for(int i = 1; i <= m ; i++){
        ans += i*(xp(1.0*i/m,n)-xp(1.0*(i-1)/m,n));
    }
    cout << fixed << setprecision(7) << ans << endl;
	return 0;
}