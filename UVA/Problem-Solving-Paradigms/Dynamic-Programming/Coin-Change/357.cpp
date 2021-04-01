#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 30005
int coins[] = {1,5,10,25,50};
int types = 5;
ll dp[N];
int main(){
  memset(dp,0,sizeof dp);
  dp[0] = 1;
  for(int j = 0; j < types ; j++){
    for(int i = coins[j] ; i < N ; i++){
      dp[i] += dp[i-coins[j]];
    }
  }
  int C;
  while(cin >> C){
    if(dp[C] > 1)
      printf("There are %lld ways to produce %d cents change.\n", dp[C],C);
    else
      printf("There is only 1 way to produce %d cents change.\n", C);

  }
	return 0;
}