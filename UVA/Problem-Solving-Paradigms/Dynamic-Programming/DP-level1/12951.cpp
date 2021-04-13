#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int memo[2][N];
int n,c;
int ar[N];
int dp(bool have, int pos){
  if(pos == n) return 0;
  int &ret = memo[have][pos];
  if(ret != -1) return ret;
  int ans = 0;
  if(have){
    ans = max(dp(1,pos+1),ar[pos] + dp(0,pos+1));
  }else{
    ans = max(dp(0,pos+1),-ar[pos] - c + dp(1,pos+1));
  }
  return ret = ans;
}
int main(){
	FIO;
	while(cin >> n >> c){
    for(int i = 0 ; i < n ; i++) cin >> ar[i];
    memset(memo,-1,sizeof memo);
    cout << dp(0,0) << endl;
  }
	return 0;
}