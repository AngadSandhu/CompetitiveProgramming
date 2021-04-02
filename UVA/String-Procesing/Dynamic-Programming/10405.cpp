#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1003
int dp[N][N];
int main(){
	FIO;
	string s,t;
  while(getline(cin,s)){
    getline(cin,t);
    if(s.empty() && t.empty()) break;
    memset(dp,0,sizeof dp);
    for(int i = 1 ; i <= s.size() ; i++){
      for(int j = 1 ; j <= t.size() ; j++){
        if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
    cout << dp[s.size()][t.size()] << endl;
  }
	return 0;
}