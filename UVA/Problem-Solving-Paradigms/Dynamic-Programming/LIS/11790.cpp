#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 10005
int memo[N][2];
vector<int> a,h;
int n;
int dp(int p, bool isIncreasing){
  int &ret = memo[p][isIncreasing];
  if(ret != -1) return ret;
  int ans = 0;
  for(int i = p+1 ; i <= n ; i++){
    if(isIncreasing && a[p] < a[i]) ans = max(ans, h[i] + dp(i,1));
    else if(!isIncreasing && a[p] > a[i]) ans = max(ans, h[i] + dp(i,0));
  }
  return ret = ans;
}
int main(){
	FIO;
  int t, caso = 0; cin >> t;
  while(t--){
    memset(memo,-1,sizeof memo);
    cin >> n;
    a.resize(n+1);
    h.resize(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= n ; i++) cin >> h[i];
    a[0] = -1;
    h[0] = 0;
    int in = dp(0,1);
    a[0] = INT_MAX;
    h[0] = 0;
    int dec = dp(0,0);

    if(in >= dec){
      printf("Case %d. Increasing (%d). Decreasing (%d).\n",++caso,in,dec);
    }else{
      printf("Case %d. Decreasing (%d). Increasing (%d).\n",++caso,dec,in);
    }
  }
	return 0;
}