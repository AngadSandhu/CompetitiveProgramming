#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 105
ll memo[2][105];
int n;
ll dp(bool mustBranch, int level){
  if(level == n) return 1;
  ll &ret = memo[mustBranch][level];
  if(ret != -1) return ret;
  ll ans = 0;
  if(mustBranch){
    ans = dp(1,level+1) + dp(0,level+1);
  }else{
    ans = dp(1,level+1);
  }
  return ret = ans;
}

int main(){
	FIO;
	while(cin >> n, n > 0){
    memset(memo,-1,sizeof memo);
    cout << dp(0,1) << endl;
  }
	return 0;
}