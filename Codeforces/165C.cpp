#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000005
int n,k;
string s;
int main(){	
	cin >> k >> s;
	n = s.size();
	int cnt = 0, r1 = 0,r2=0;
	ll ans = 0,ans0=0,cnt0=0;
	for(int i = 0 ; i < n; i++){
		if(s[i]=='1')cnt++;
		if(cnt==k)break;
		r1++; r2++;
	}
	r2++;
	for(int i = 0 ; i < n ; i++){
		if(s[i]=='1') cnt0=0;
		else cnt0++;
		ans0 += cnt0;
	}
	for(int l = 0 ; l < n ; l++){
		if(l>r2) r2 = l;
		while(cnt<k && r2 < n){
			if(s[r2]=='1') cnt++;
			r2++;
		}
		while(cnt==k && s[r2]=='0'&& r2 < n) r2++;
		while(cnt==k && l<n){
			ans += r2-r1;
			if(s[l]=='1')break;
			l++;
		}
		cnt--; r1 = r2;
		cnt = max(0,cnt);
	} 
	if(k==0) cout << ans0 << endl;
	else cout << ans << endl;
	return 0;
}
