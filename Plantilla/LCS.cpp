int lcs(string const &s, string const &t){
  int dp[s.size()+1][t.size()+1] = {};
  for(int i = 1 ; i <= s.size() ; i++){
      for(int j = 1 ; j <= t.size() ; j++){
        if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
    return dp[s.size()][t.size()];
}