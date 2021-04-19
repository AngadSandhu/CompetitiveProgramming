#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10004 
int dp[N];
int main(){
	FIO;
  dp[0] = 0;
	for(int i = 1 ; i < N ; i++){
    dp[i] = INT_MAX;
    for(int j = 1 ; j*j <= i ; j++){
      dp[i] = min(dp[i], 1 + dp[i-j*j]);
    }
  }
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    cout << dp[n] << endl;
  }
	return 0;
}