#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define N 

int main(){
	FIO;
  int t; cin >> t;
  int caso = 1;
  while(t--){
    int n,c; cin >> n >> c;
    if(c < n-1 || c > n*(n+1)/2 -1){
      cout << "Case #" << caso++ << ": " << "IMPOSSIBLE" << endl;
      continue;
    }
    vector<int> a(n);
    for(int i = 0 ; i < n; i++) a[i] = i+1;
    vector<int> ans(n,1);
    int cnt = c - (n-1);
    for(int i = 2 ; i <= n && cnt > 0; i++){
      ans[n-i] += min(i-1,cnt);
      cnt -= min(i-1,cnt);
    }
    // for(int i = 0 ; i < n ; i++) cout << ans[i] << " "; cout << endl;
    for(int i = n-1 ; i >= 0 ; i--){
      reverse(a.begin()+i,a.begin()+i+ans[i]);
    }
    cout << "Case #" << caso++ << ": ";
    for(int x : a) cout << x << " "; cout << endl;
  }	
	return 0;
}