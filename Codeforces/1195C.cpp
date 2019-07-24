#include<bits/stdc++.h>
using namespace std;
#define N 100005
typedef long long ll;
ll player[N][2];
ll n;
ll dp[N][2];
ll f(int p, int id){
	if(dp[p][id]!=-1) return dp[p][id];
	if(p==n-1) return player[p][id];
	ll ret = max(player[p][id] + f(p+1,!id),f(p+1,id));
	return dp[p][id] = ret;
}
int main(){
	cin >> n;
	for(int i = 0; i<n ; i++){
		cin >>player[i][0];
	}
	for(int i = 0; i<n ; i++){
		cin >> player[i][1];
	}
	memset(dp,-1,sizeof(dp));
	cout << max(f(0,1),f(0,0))<< endl;
	return 0;
}
