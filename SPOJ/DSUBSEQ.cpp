#include<bits/stdc++.h>
using namespace std;
#define N 100005
char s[N];
int last[30];
int n;
long long dp[N];
const int mod = 1000000007;
int main(){
	int t; cin >> t;
	while(t--){
		scanf("%s",s+1);
		s[0] = '.';
		int n = strlen(s);
		for(int i = n-1 ; i >= 0 ; i--){
			dp[i] = 1;
			for(int j = 0 ; j < 27 ; j++){
				if(last[j]==0) continue;
				dp[i] += dp[last[j]]%mod;
				dp[i] %= mod;
			}
			last[s[i]-'A'] = i;
		}
		memset(last,0,sizeof last);
		cout << dp[0]%mod << endl;
	}
	return 0;
}
