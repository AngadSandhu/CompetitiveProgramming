#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int freq[100005];
int a[1000005];
vector<int> x;
int n;
bool check(){
	for(int i =0  ; i < n ; i++){
		int p = lower_bound(all(x),a[i])- x.begin();
		if(freq[p]>1) return false;
	}
	return true;
}
int main(){
	cin >> n;
	for(int i =0; i < n ; i++){
		cin >> a[i], x.push_back(a[i]);
	}
	sort(all(x));
	x.resize(unique(x.begin(),x.end()) - x.begin());
	for(int i =0 ; i< n ;i++){
		int p = lower_bound(all(x),a[i])- x.begin();
		freq[p]++;
	}
	int l = 0,mn = INT_MAX,pr,pl;
	for(int r = 0 ; r <= n ; r++){
		while(check() && l<=r){
			mn = min(mn,r-l);
			pl = lower_bound(all(x),a[l])-x.begin();
			freq[pl]++;
			l++;
		}
		pr = lower_bound(all(x),a[r])-x.begin();
		freq[pr]--;
	}
	cout << mn << endl;
	return 0;
}
