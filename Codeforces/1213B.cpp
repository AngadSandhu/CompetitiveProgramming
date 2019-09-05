#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
typedef long long ll;
 
using namespace std;
int main(){
	int t;cin >> t;
	while(t--){
		int n; cin>> n;
		vector<int> a(n),mnn(n);
		for(int &i : a) cin >> i;
		int mn = INT_MAX;
		for(int i = n-1 ; i >=0 ; i--){
			mn = min(mn,a[i]);
			mnn[i] = mn;
		}
		int res = 0;
		for(int i =0 ; i < n; i ++){
			if(mnn[i]<a[i]) res ++;
		}
		cout << res << endl;
	}
	return 0;
}
