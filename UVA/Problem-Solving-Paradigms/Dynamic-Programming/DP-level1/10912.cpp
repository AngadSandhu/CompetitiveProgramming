#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 30
int l,s;
int memo[27][N][1000];
int dp(int prev, int pos, int sum){
  if(pos == l) return sum == s;
  int &ret = memo[prev][pos][sum];
  if(ret != -1) return ret;
  int ans = 0;
  for(int i = prev + 1 ; i < 26 ; i++){
    ans += dp(i,pos+1,sum + i+1);
  }
  return ret = ans;
}
int main(){
  int caso = 0;
	while(cin >> l >> s){
    if(l == 0 && s == 0) break;
    memset(memo,-1,sizeof memo);
    if(l > 26 || s > 26*26){
      printf("Case %d: 0\n",++caso);
    }else{
      int ans = 0;
      for(int i = 0 ; i < 26 ;i++) ans += dp(i,1,i+1);
      printf("Case %d: %d\n",++caso,ans);
    }
  }
	return 0;
}