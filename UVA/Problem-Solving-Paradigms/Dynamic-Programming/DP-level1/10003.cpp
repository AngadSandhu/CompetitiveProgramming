#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int c[55];
int L,n;
int f(int l, int r){
	int m = INT_MAX;
	if(dp[l][r]!=-1) return dp[l][r];
	for(int i = 0 ; i < n ; i++){
		if(c[i]<r && c[i]>l) m = min(m,f(l,c[i])+f(c[i],r)+r-l);
	}
	if(m == INT_MAX) m = 0;
	return dp[l][r] = m;
}
int main() {
	while(cin >> L , L>0){
		memset(dp,-1,sizeof(dp));
		cin >> n;
		for(int i = 0 ; i < n ; i ++){
			cin >> c[i];
		}
		printf("The minimum cutting is %d.\n",f(0,L));
	}
	return 0;
}