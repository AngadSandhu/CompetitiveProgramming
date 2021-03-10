#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 55
ll dp[N][N*N];
ll pairs[N][N][2];
ll ar[N][N];
int n,k,p;
ll f(int index, int cap){
  if(dp[index][cap] != -1) return dp[index][cap];
  if(index == n) return 0;
  ll ret = f(index+1,cap);
  for(int i = 0 ; i < k ; i++){
    if(cap- pairs[index][i][1] >= 0) ret = max(ret, pairs[index][i][0] + f(index+1,cap- pairs[index][i][1]) );
  }
  return dp[index][cap] = ret;
}
int main(){
	FIO;
  int t; cin >> t;
  int caso = 0;
  while(t--){
    caso ++;
    memset(dp,-1,sizeof dp);
    cin >> n >> k >> p;
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < k ; j++){
        cin >> ar[i][j];
      }
    }
    for(int i = 0 ; i < n ; i++){
      ll sum = 0;
      for(int j = 0 ; j < k ; j++){
        sum += ar[i][j];
        pairs[i][j][0] = sum;
        pairs[i][j][1] = j+1;
      }
    }
    cout << "Case #" << caso << ": " << f(0,p) << endl;
  }
	
	return 0;
}