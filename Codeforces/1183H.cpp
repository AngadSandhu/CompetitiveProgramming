#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 105
const ll maxi = 1000000000000;
ll dp[N][N];
int n;
ll k,cnt,cost;
char s[N];
int last[30];
int main(){
	cin >> n >> k;
	scanf("%s",s+1);
	n++;
	s[0] = '`';
	dp[0][1] = 1;
	memset(last,0,sizeof last);
	for(int i = 0 ; i < n ; i++) dp[i][1] = 1;
	for(int i = n-1 ; i >=0 ; i--){
		for(int j = 2 ; j <= n-i ; j++){
			for(int k = 1 ; k < 28 ; k++){
				if(last[k]==0) continue;
				dp[i][j] += dp[last[k]][j-1];
				dp[i][j] = min(maxi,dp[i][j]);
			}
		}
		last[s[i]-'`'] = i;
	}
	for(int i = n ; i>0 && cnt<k; i--){
		if(dp[0][i]>k-cnt) cost += (k-cnt)*(n-i), cnt = k;
		else cnt += dp[0][i], cost += dp[0][i]*(n-i);
	}
	cout << (cnt<k?-1:cost) << endl;
	return 0;
}
