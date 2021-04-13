#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
int n,s;
ll memo[2][N][N];
ll dp(bool isLastLocked, int pos, int totalSecure){
  if(pos == n) return totalSecure == s;
  ll &ret = memo[isLastLocked][pos][totalSecure];
  if(ret != -1) return ret;
  return ret = dp(0,pos+1,totalSecure) + dp(1,pos+1,totalSecure + isLastLocked);
}
int main(){
	FIO;
	while(cin >> n >> s , n > 0){
    memset(memo,-1,sizeof memo);
    cout << dp(1,0,0) << endl;
  }
	return 0;
}