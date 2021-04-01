#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 30005
int coins[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
int types = 11;
ll dp[N];
int main(){
  memset(dp,0,sizeof dp);
  dp[0] = 1;
  for(int j = 0 ; j < types ; j++){
    for(int i = 1 ; i < N ; i++){
      if(i - coins[j] >= 0) dp[i] += dp[i-coins[j]];
    }
  }
  string s;
  while(cin >> s){
    string E = s.substr(0,s.size()-3);
    string D = s.substr(E.size()+1);
    int M = 100*stoi(E) + stoi(D);
    if(M == 0) break;
    // cout << M << endl;
    // cout << E << " " << D << endl;
    string ans = string(23,' ');
    for(int i = 0 ; i < s.size() ; i++){
      ans[5-i] = s[s.size()-i-1];
    }
    string ansDp = to_string(dp[M]);
    for(int i = 0 ; i < ansDp.size() ; i++){
      ans[ans.size()-i-1] = ansDp[ansDp.size()-i-1];
    }
    cout << ans << endl;
  }
	return 0;
}