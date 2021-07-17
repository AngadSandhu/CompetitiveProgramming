#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 600005
int par[N],dp[N];
int n,k;
string s;
void update(int x){
  if(s[x] == '1') dp[x] = dp[2*x];
  else if(s[x] == '0') dp[x] = dp[2*x + 1];
  else dp[x] = dp[2*x] + dp[2*x + 1];
  if(x != 1) update(par[x]);
}
int main(){
	FIO;
  cin >> k;
  cin >> s;
  n = s.size();
  reverse(s.begin(),s.end());
  s = " " + s;
  memset(dp,0,sizeof dp);
  for(int i = (1<<k) ; i < (1<<(k+1)) ; i++){
    dp[i] = 1;
  }
  for(int i = 1 ; i < (1<<k) ; i++){
    par[2*i] = i;
    par[2*i+1] = i;
  }
  for(int i = n ; i >= 1 ; i--){
    update(i);
  }
  int q; cin >> q;
  while(q--){
    int p; char c; cin >> p >> c;
    s[n-p+1] = c;
    update(n-p+1);
    cout << dp[1] << endl;
  }
	return 0;
}