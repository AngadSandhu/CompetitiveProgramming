#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int &i : a) cin >> i;
	sort(a.begin(),a.end());
	vector<vector<int>> freq(200005);
	for(int i = 0 ; i < n ;i++){
		int x = a[i], c = 0;
		while(x>0){
			freq[x].push_back(c);
			c++;
			x/=2;
		}
	}
	for(auto &v : freq) sort(v.begin(),v.end());
	int mn = INT_MAX;
	for(int i = 0 ; i<=200005 ;i++){
		if(freq[i].size()>=k){
			mn = min(mn,accumulate(freq[i].begin(),freq[i].begin()+k,0));
		}
	}
	cout << mn << endl;
}
