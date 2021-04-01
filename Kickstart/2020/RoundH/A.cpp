#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
	int t; cin >> t;
	int caso = 1;
	while(t--){
	    ll n,k,s; cin >> n >> k >> s;
	    cout << "Case #" << caso++ << ": " << min(2*(k-s)+n,n+k) << endl;
	}
	return 0;
}