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
		ll n; cin >> n;
		ll res = 0;
		for(ll i = 2 ; i < 33 ; i++){
			if(n%((1<<i)-1)==0){
				res = n/((1<<i)-1);
				break;
			}
		}
		cout << res  << endl;
	}
	return 0;
}