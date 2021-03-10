#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 
int pref(string &a, string &b){
  int ret = 0;
  for(int i = 0 ;i < a.size() && i < b.size() ; i++){
    if(a[i]!=b[i]) break;
    ret ++;
  }
  return ret;
}
int main(){
	FIO;
	int t,caso = 0; cin >> t;
  while(t--){
    caso++;
    int n,k; cin >> n >> k;
    vector<string> ar(n);
    for(int i = 0 ; i < n ; i++) cin >> ar[i];
    sort(ar.begin(),ar.end());
    int ans = 0, mini = INT_MAX;
    for(int i = 1 ; i < n ; i++){
      mini = min(mini,pref(ar[i],ar[i-1]));
      if((i+1)%k==0) ans += mini, mini = INT_MAX,i++;
    }
    cout << "Case #" << caso << ": " << ans << endl;
  }
	return 0;
}