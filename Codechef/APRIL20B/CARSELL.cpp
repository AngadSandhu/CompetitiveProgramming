#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(ww) ww.begin(),ww.end()
#define N 

int main(){
	int t; cin>>t;
	while(t--){
		int n ; cin >> n;
		vector<int>a(n);
		for(int &i : a) cin >> i;
		sort(a.begin(),a.end(),greater<int>());
		ll ans =0;
		for(int i = 0 ; i < n ; i++){
			ans += max(a[i]-i,0);
		}
		cout << ans%1000000007 << endl;
	}
	return 0;
}