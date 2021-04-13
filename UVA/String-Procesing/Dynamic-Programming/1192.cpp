#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 1005
int dp[N][N];
int solve(string s,string t){
  for(int i = 0 ; i <= s.size() ; i++) dp[i][0] = -7*i;
  for(int i = 0 ; i <= t.size() ; i++) dp[0][i] = -7*i;
  for(int i = 1 ; i <= s.size() ; i++){
    for(int j = 1 ; j <= t.size() ; j++){
      dp[i][j] = INT_MIN;
      if(s[i-1] == t[j-1]) dp[i][j] = 5 + dp[i-1][j-1];
      else{
        dp[i][j] = max(dp[i][j],-4 + dp[i-1][j-1]);
        dp[i][j] = max(dp[i][j],-7 + dp[i-1][j]);
        dp[i][j] = max(dp[i][j],-7 + dp[i][j-1]);
      }
    }
  }
  return dp[s.size()][t.size()];
}
int main(){
	string s,t;
  cin >> s >> s;
  vector<pair<int,string>> ans;
  while(cin >> t >> t) ans.pb({solve(s,t),t});
  int maxi = 0;
  vector<string> ansStrings;
  // for(int i = 0 ; i < ans.size() ; i++) cout << ans[i].first << " " << ans[i].second << endl; cout << endl;
  for(int i = 0 ; i < ans.size() ; i++){
    if(maxi <= ans[i].first){
      if(maxi < ans[i].first) ansStrings.clear();
      maxi = ans[i].first;
      ansStrings.pb(ans[i].second);
    }
  }
  cout << "The query sequence is:\n" << s << "\n\n";
    cout << "The most similar sequences are:\n\n";
    for(int i = 0;  i < ansStrings.size() ; i++){
      if(i) cout << endl;
      cout << ansStrings[i] << endl << "The similarity score is: " << maxi << endl;
    }
	return 0;
}