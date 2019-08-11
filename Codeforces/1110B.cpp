#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100005];
vector<pair<int,int>>dif;
int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n ; i++) scanf("%d",&a[i]);
	for(int i = n-2 ; i >=0 ; i--) dif.push_back({a[i+1]-a[i],i});
	sort(dif.begin(),dif.end());
	int ans = 0;
	for(int i = 0 ; i < dif.size() && i<n-k; i++){
		ans += dif[i].first;
	}
	cout << ans + k<< endl;
	return 0;
	
}
