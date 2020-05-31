#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
    int caso = 0;
    while(t--){
        if(caso++) cout << "\n";
        ll n; cin >> n;
        n = abs(n);
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        for(ll i = 1; ;i++){
            ll x = i*(i+1)/2;
            if(x%2!=n%2) continue;
            if(x<n) continue;
            if(i%2){
                if(x-n+2 <= 3*(i+1)){
                    cout << i << endl;
                    break;
                }
            }else{
                if(x-n+2 <= 2*i){
                    cout << i << endl;
                    break;
                }
            }
        }
    }
	return 0;
}