#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(ww) ww.begin(),ww.end()
#define N 1000005
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
int main(){
	FIO;
	int t; cin>>t;
	while(t--){
		int n; cin >> n;
		vector<int> ar(n);
		for(int &i : ar) cin >> i;
		int cant1 = 0;
		vector<pair<int,int>> v(2);
		ll ans = 0;
		v[0] = {-1,0};
		v[1] = {-1,0};
		for(int i = 0 ; i < n ; i++){
			if(ar[i]%2==0){
				ans += 1ll*cant1*(cant1+1)/2;
				cant1 = 0;
				v[1] = v[0];
				v[0] = {i,ar[i]};
			}else cant1++;
			if(v[0].second%4==0) ans += v[0].first + 1;
			else if(v[0].second%2==0) ans += v[1].first + 1;
		}
		ans += 1ll*cant1*(cant1+1)/2;
		cout << ans << endl;
	}
	return 0;
}