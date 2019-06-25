#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long dp[105][2];
int nn,k,d;
long long f(int n, bool tk){
	if(dp[n][tk]!=-1) return dp[n][tk]%mod;
	long long ret = 0;
	if(n==d && tk) return 1;
	if(n==0) return 1;
	for(int i = 1 ; i <= k && i <= n  ; i++){
		if(tk==1 && n<d) continue;
		if(i>=d or tk==0){
			ret += f(n-i,0)%mod;
		}else{
			ret += f(n-i,1)%mod;
		}
	}
	return dp[n][tk] = ret%mod;
}
int main() {
	cin >> nn >> k >> d;
	memset(dp,-1,sizeof(dp));
	cout<< f(nn,1)%mod << endl;
	return 0;
}
