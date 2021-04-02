#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int dp[N][N];
int main(){
	FIO;
	int T; cin >> T; cin.ignore();
  while(T--){
    string s,t;
    getline(cin,s);
    getline(cin,t);
    for(int i = 0 ; i <= s.size() ; i++) dp[i][0] = i;
    for(int i = 0 ; i <= t.size() ; i++) dp[0][i] = i;

    for(int i = 1 ; i <= s.size() ; i++){
      for(int j = 1 ; j <= t.size() ; j++){
        dp[i][j] = INT_MAX;
        if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
        else{
          dp[i][j] = min(dp[i][j],1 + dp[i-1][j]);
          dp[i][j] = min(dp[i][j],1 + dp[i][j-1]);
          dp[i][j] = min(dp[i][j],1 + dp[i-1][j-1]);
        }
      }
    }
    cout << dp[s.size()][t.size()] << endl;
  }
	return 0;
}