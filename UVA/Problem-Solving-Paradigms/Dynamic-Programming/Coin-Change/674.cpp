#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 7500
int coins[] = {50,25,10,5,1};
int types = 5;
ll dp[N];
int main(){
  memset(dp,0,sizeof dp);
  dp[0] = 1;
  for(int j = 0 ; j < types ; j++){
    for(int i = 1 ; i < N ; i++){
      if(i - coins[j] >= 0) dp[i] += dp[i-coins[j]];
    }
  }
  int C;
  while(cin >> C){
    cout << dp[C] << endl;
  }
	return 0;
}