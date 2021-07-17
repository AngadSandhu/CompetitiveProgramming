#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int dp[N][2];
int main(){
	FIO;
	int t; cin >> t;
  while(t--){
    string s; cin >> s;
    int n = s.size();
    for(int i = 0 ; i < n ; i++){
      int c = s[i]-'0';
      if(s[i] != '?'){
        dp[i][c] = 1;
        dp[i][!c] = 0;
      }else dp[i][0] = dp[i][1] = 1;
    }
    for(int i = 1 ; i < n ; i++){
      int c = s[i]-'0';
      if(s[i] != '?'){
        dp[i][c] = 1 + dp[i-1][!c];
      }else{
        dp[i][1] = 1 + dp[i-1][0];
        dp[i][0] = 1 + dp[i-1][1];
      }
    }
    ll ans = 0, last = INT_MIN;
    for(int i = 0 ; i < n ; i++){
      if(s[i] != '?'){
        int c = s[i]-'0';
        ans += dp[i][c];
      }else{
        ans += max(dp[i][0], dp[i][1]);
      }
      //cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << ans << endl;
  }
	return 0;
}