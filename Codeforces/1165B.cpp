#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
	cin >> n;
	vector<int> ar(n);
	for(int i = 0 ; i < n ; i++) cin >> ar[i];
	sort(ar.begin(),ar.end());
	
	int ans = 0, cur = 1;
	for(int i = 0 ; i < n ; i++){
		while(i < n && ar[i] < cur) i++;
		if(i < n && ar[i]>=cur) cur++,ans++;
	}	
	cout << ans << endl;
	return 0;
}

