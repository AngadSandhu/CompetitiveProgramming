#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int n;
ld p, f[N];
int main(){
	FIO;
    f[0] = 0;
    for(int i = 1 ; i < N ; i++) f[i] = f[i-1] + log(i);
    int caso = 1;
    cout << fixed << setprecision(6);
	while(cin >> n >> p){
        ld ans = 0, cur = 1;
        for(int i = 0 ; i <= n ; i++){
            ans += exp((n+1)*log(p) + i*log(1-p) + log(n-i) + f[n+i] - f[i] - f[n]);
            ans += exp((n+1)*log(1-p) + i*log(p) + log(n-i) + f[n+i] - f[i] - f[n]);
        }
        cout << "Case " << caso++ << ": " << ans << "\n";
    }
	return 0;
}