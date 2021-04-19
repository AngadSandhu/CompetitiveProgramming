#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 200005
int memo[30];
int pos[30][N];
int n,k;
int dp(int chr){
  if(chr == k) return 0;
  int &ret = memo[chr];
  if(ret != -1) return ret;
  int ans = 0;
  for(int j = 0 ; j < 26 ; j++){
    bool flag = 1;
    for(int i = 0 ; i < n ; i++){
      if(pos[chr][i] == -1 || pos[j][i] == -1) flag = 0;
      if(pos[chr][i] >= pos[j][i]) flag = 0;
    }
    if(flag) ans = max(ans,1 + dp(j));
  }
  return ret = ans;
}
int main(){
	FIO;
  memset(memo,-1,sizeof memo);
  memset(pos,-1,sizeof pos);
	cin >> n >> k;
  for(int i = 0 ; i < n ; i++){
    string s; cin >> s;
    for(int j = 0 ; j < s.size() ; j++) pos[s[j]-'A'][i] = j;
  }
  int ans = 0;
  for(int i = 0 ; i < 26 ; i++){
    ans = max(ans,1+dp(i));
  }
  cout << ans << endl;
	return 0;
}