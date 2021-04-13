#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1003
int dp[N][N];
string s,t;
int n,m;
int main(){
	FIO;
  int caso = 0;
  while(getline(cin,s)){
    if(s == "#") break;
    getline(cin,t);
    n = s.size(), m = t.size();
    memset(dp,0,sizeof dp);
    for(int i = 1 ; i <= n; i++){
      for(int j = 1 ; j <= m ; j++){
        if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
    printf("Case #%d: you can visit at most %d cities.\n",++caso,dp[n][m]);
  }
	return 0;
}