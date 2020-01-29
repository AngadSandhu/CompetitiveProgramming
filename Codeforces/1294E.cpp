#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> ar;
int cant[200005];
int main(){
	int n,m; cin >> n >> m;
	ar.resize(n);
	for(int i = 0 ; i < n ; i++){
		ar[i].resize(m);
		for(int j = 0 ; j < m ; j++){
			cin >> ar[i][j];
		}
	}
	ll ans = 0;
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j <= n ; j++) cant[j] = 0;
		for(int j = 0 ; j < n ; j ++){
			int val = (ar[j][i]-i-1)/m;
			if(val>=n || val < 0 || (ar[j][i]-i-1)%m!=0) continue;
			val = (j-val+n)%n;
			cant[val]++;
		}
		int mini = INT_MAX;
		for(int i = 0 ; i < n ; i++){
			mini = min(mini,i+n-cant[i]);
		}
		ans += mini;
	}
	cout << ans << endl;
	return 0;
}
