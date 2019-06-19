#include<bits/stdc++.h>
using namespace std;
int dp[105];
const int mod = 1e9 + 7;
int nn, k, d;
int c = 0;
int f(int n){
	int ret  = 0;
	if(n==0) return dp[n] = 1;
	for(int i = 1 ; i <= k && i<=n; i++){
		ret += f(n-i)%mod;
	}
	return dp[n] = ret%mod;
}
int main(){
	cin >> nn >> k >> d;
	cout << f(nn-d) << endl;
	return 0;
}
