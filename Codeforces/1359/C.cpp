#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
char a[N][N];
int main(){
	FIO;
    int t; cin >> t;
    while(t--){
        ll c,h,t; cin >> h >> c >> t;
        if(h + c >= 2*t){
            cout << 2 << endl;
            continue;
        }
        ll k = (c-t)/(h+c-2*t);
        ll ans = 0;
        ld mini = 1e18;
        for(ll i = max(1ll,k-2) ; i <= k+2; i++){
            if(abs((ld)(h*i + c*(i-1))/(2*i-1) - t) < mini) mini = abs((ld)(h*i + c*(i-1))/(2*i-1) -t), ans = 2*i-1;
        }
        cout << ans << endl;
    }
	return 0;
}