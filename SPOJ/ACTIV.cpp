#include<bits/stdc++.h>
using namespace std;
const int mod = 100000000;
pair<int,int> act[100005];
int n;
int memo[100005];
int dp(int p){
	if(memo[p]!=-1) return memo[p];
	if(p==n-1) return 1;
	if(p>n-1) return 0;
	memo[p] = 1 + dp(p+1)%mod + dp(lower_bound(act,act+n,make_pair(act[p].second,act[p].second))-act)%mod;
	return memo[p] = memo[p]%mod;
}
int main(){
	while(cin >> n){
		if(n<0) break;
		for(int i = 0 ; i < n ; i ++){
			int a,b; cin >> a >> b;
			act[i] = {a,b};
		}
		sort(act,act+n);
		//cout << lower_bound(act,act+n,make_pair(act[2].second,INT_MIN))-act << endl;
		memset(memo,-1,sizeof(memo));
		for(int i = 0 ; i < 7-log10(dp(0)); i ++) cout << 0;
		cout << dp(0) << endl;
	}
	return 0;
}
