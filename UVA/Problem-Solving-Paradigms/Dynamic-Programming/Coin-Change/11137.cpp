#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10005
int coins[22];
int types = 21;
ll dp[N];
int main(){
  for(int i = 1 ; i <= types ; i++) coins[i] = i*i*i;
  memset(dp,0,sizeof dp);
  dp[0] = 1;
  for(int j = 1 ; j <= types ; j++){
    for(int i = coins[j] ; i < N ; i++){
      dp[i] += dp[i-coins[j]];
    }
  }
  int C;
  while(cin >> C){
    cout << dp[C] << endl;
  }
	return 0;
}