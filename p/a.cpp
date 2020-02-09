#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while(t--){
		int n,m,k; cin >> n >> m >> k;
		vector<int> a(n);
		for(int &i : a) cin >> i;
		int ans = -1;
		k = min(k,m-1);
		for(int i = -1, j = n-k ; i < k ; i++, j++){
			int mini = INT_MAX;
			for(int l = i+1, r = j + k - m ; r < j ; l++, r++){
				//cout << "i: " << i << " j: " << j << " a[l]: "<<  a[l] << " a[r]: " << a[r] << endl;
				mini = min(mini,max(a[l],a[r]));
			}
			ans = max(ans,mini);
		}
		cout << ans << endl;
	}
	return 0;
}
