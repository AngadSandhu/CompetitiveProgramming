#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
    while(t--){
        ll a,k; cin >> a >> k;
        k--;
        while(k--){
            ll mx = 0, mn = 10;
            ll x = a;
            while(x > 0){
                mx = max(mx,x%10);
                mn = min(mn,x%10);
                x /= 10;
            }
            if(mx*mn == 0) break;
            else a += mx*mn;
        }
        cout << a << endl;
    }
	return 0;
}